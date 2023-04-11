#include "SimpleScene.h"

SimpleScene::SimpleScene(SceneStack _stack, SceneContext _context)
	: Scene(_stack, _context), m_context(_context)
{
	m_window = _context.window;
	glfwGetWindowSize(m_window, &vw, &vh);

}

void SimpleScene::draw()
{

}

bool SimpleScene::update(float deltaTime)
{

	return false;
}

bool SimpleScene::processInput(GLFWwindow* window)
{

	return false;
}

void SimpleScene::mouse_callback(GLFWwindow* window, double xposIn, double yposIn)
{

}

void SimpleScene::scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{

}

void SimpleScene::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_RELEASE)
		glfwSetWindowShouldClose(window, true);

}
