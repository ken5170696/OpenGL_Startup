/*
	The SceneStack class manages a stack of game scenes in the engine, allowing for scene transitions and dynamic creation of scenes. 
	It includes functions for updating, rendering, and handling input events for scenes. 
	Scene types can be registered with the class for dynamic creation.


	To create a new scene, you will need to follow these steps:
		1. Create a new class that inherits from the Scene class.
		2. Define the necessary functions for your scene, such as draw(), update(), and processInput().
		3. Register your new scene with the SceneStack class by calling the registerScene() function with the SceneID for your new scene and the name of your new scene's class as the template argument.
		4. Use the pushState() function of the SceneStack class to add your new scene to the top of the scene stack and activate it.
		5. Once you have completed these steps, your new scene should be ready to use in your game.

	scene structure is referring to the book "SFML Game Development" 
*/
#pragma once
class Scene;

#include <utility>
#include <functional>
#include <map>
#include <vector>

#include "Scene.h"

class SceneStack
{
public:
	enum Action
	{
		Push,
		Pop,
		Clear,
	};

private:
	struct PendingChange
	{
		PendingChange(Action _action, SceneID::ID _sceneID) {
			action = _action;
			sceneID = _sceneID;
		};
		PendingChange(Action _action) {
			action = _action;
			sceneID = SceneID::ID::None;
		};
		Action action;
		SceneID::ID sceneID;
	};
private:
	SceneContext _context;
	std::vector<std::shared_ptr<Scene>> statesStack;
	std::vector<PendingChange> mPendingList;
	std::map<SceneID::ID, std::function<std::shared_ptr<Scene>()>> sceneFactories;

public:
	SceneStack(const SceneContext& context);

	void processInput(GLFWwindow* window);
	void update(float deltaTime);
	void draw();

	void mouse_callback(GLFWwindow* window, double xposIn, double yposIn);
	void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
	void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

	void pushState(SceneID::ID sceneID);
	void popState();
	void clearStates();
	bool isEmpty() const;
	int getStackNum() const;

	template<typename T>
	void registerScene(SceneID::ID sceneID);

	bool inStack(SceneID::ID sceneID)  const;

private:
	std::shared_ptr<Scene> createScene(SceneID::ID sceneID);
	void applyPendingChanges();
};

template<typename T>
void SceneStack::registerScene(SceneID::ID sceneID)
{
	sceneFactories[sceneID] = [this]()
	{
		return std::shared_ptr<Scene>(new T(*this, _context));
	};
}