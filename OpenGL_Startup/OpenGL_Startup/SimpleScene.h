/*
	This is a startup scene.

*/

#pragma once
#include "Scene.h"

class SimpleScene : public Scene
{
public:
	SimpleScene( SceneStack _scene, SceneContext _context);

	virtual void draw() override;
	virtual bool update(float deltaTime) override;
	virtual bool processInput(GLFWwindow* window) override;

	virtual void mouse_callback(GLFWwindow* window, double xposIn, double yposIn) override;
	virtual void scroll_callback(GLFWwindow* window, double xoffset, double yoffset) override;
	virtual void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) override;

private:

	int vh;
	int vw;

	GLFWwindow* m_window;
	SceneContext m_context;
};

