/*
	This class represents a SimpleScene, which is a type of scene in the game engine. 
	It inherits from the Scene class and provides implementations for its pure virtual functions.

	The SimpleScene class is responsible for rendering the scene, updating the scene, and handling input events. 
	It has a constructor that initializes the class with a scene stack and a scene context.

	This class also includes functions for handling mouse movement, mouse scroll, and keyboard events.

	The SimpleScene class contains private variables for the viewport height and width, a pointer to a GLFW window, and a SceneContext object. 
	These variables are used to manage the SimpleScene's state and interactions with the game engine.

	Overall, the SimpleScene class serves as the entry point for a game and is responsible for managing the game's initial setup and processing input events from the player.
*/

#pragma once
#include "Scene.h"

class SimpleScene : public Scene
{
public:

	// SimpleScene constructor:
	// Initializes the SimpleScene class with the given scene stack and scene context.
	SimpleScene( SceneStack _scene, SceneContext _context);

	// Draw the object on the screen.
	virtual void draw() override;

	// Inherited from the Scene class, responsible for updating the scene. 
	// Takes deltaTime as input, which is the time elapsed since the last update.
	virtual bool update(float deltaTime) override;

	// Handling input events
	virtual bool processInput(GLFWwindow* window) override;

	// Overrides the mouse callback function from the Scene class. Responsible for handling mouse movement events.
	virtual void mouse_callback(GLFWwindow* window, double xposIn, double yposIn) override;

	// Overrides the scroll callback function from the Scene class. Responsible for handling mouse scroll events.
	virtual void scroll_callback(GLFWwindow* window, double xoffset, double yoffset) override;

	// Overrides the key callback function from the Scene class. Responsible for handling keyboard events.
	virtual void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) override;

private:

	int vh;
	int vw;

	GLFWwindow* m_window;
	SceneContext m_context;
};

