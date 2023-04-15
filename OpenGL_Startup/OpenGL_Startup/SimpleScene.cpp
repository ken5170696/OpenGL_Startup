#include "SimpleScene.h"

SimpleScene::SimpleScene(SceneStack _stack, SceneContext _context)
	: Scene(_stack, _context), m_context(_context)
{
	m_window = _context.window;
	glfwGetWindowSize(m_window, &m_vw, &m_vh);

	// step 2-1: Generate a VBO

	// step 2-2: Bind buffer to the GL_ARRAY_BUFFER target

	// step 2-3: Copies the previously defined vertex data into the buffer's memory


	// step 3-1: Generate a VAO

	// step 3-2: Bind Vertex Array Object

	// step 3-3: Set Vertex Attributes Pointers and enable them


	// step 4-2: Create Vertex Shader

	// step 4-3: Attach source code to Vertex Shader and compile Vertex Shader.


	// step 5-2: Create Fragment Shader

	// step 5-3: Attach source code to Fragment Shader and compile Fragment Shader.


	// step 6-1: Create Shader program

	// step 6-2: Attach Shader to Shader program and link them.


	// step 6-3: Delete the shader objects.


}

void SimpleScene::draw()
{
	// Draw the object on the screen.

	// step 7: Draw the triangle on the screen!


}

bool SimpleScene::update(float deltaTime)
{
	// Update game logic.


	return false;
}

bool SimpleScene::processInput(GLFWwindow* window)
{
	// Handle user input here.


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
