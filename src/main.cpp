#include "../aleung-c_engine/includes/aleung-c_engine.hpp"

/*
** Just a simple key callback to quit the showcase with escape.
*/

void	key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	(void)window;
	(void)scancode;
	(void)mods;
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
    	exit(0);
    }
}

/*
**	This is the smallest minimum code for the aleung-c engine with the maximum of
**	functionalities.
*/

int		main(void)
{
	GameEngineController	*GameEngine = &GameEngineController::Instance();

	// GameEngine->DebugMode = true;

	GameEngine->InitEngine(1280, 720, "aleung-c engine showcase");

	// ----- Set the camera (default is camera in 0.0 0.0 -10.0)
	GameObject	*Camera = GameEngine->GetCamera();
	Camera->Transform.Position = glm::vec3(0.0, 0.0, -2.0);
	GameEngine->SetCameraLookAt(glm::vec3(0.0, 0.0, 0.0));


	// ******* From here, add any object you want in your scene ******* //
	// ----- Adding 3D object.
	GameObject		*Character = new GameObject("Character", "./ressources/Models/character_idle.obj");

	Character->Transform.Position = glm::vec3(0.0, 0.0, 4.0);

	// ----- Adding UI Element.
	GameUIObject	*UIElem = new GameUIObject("UI ELEM 1", "./ressources/UI_Elem_1.bmp");

	UIElem->Transform.Position = glm::vec3(0.0, 200.0, 0.0);

	// ----- Adding Textual Element.
	GameTextObject	*TextElem = new GameTextObject("UI ELEM 1", "hello_text");

	TextElem->Transform.Position = glm::vec3(800.0, 0.0, 0.0);


	// ******* The simplest Main loop ******* //
	GameEngine->CheckForOpenGLErrors();

	glfwSetKeyCallback(GameEngine->Window, key_callback);
	while (!glfwWindowShouldClose(GameEngine->Window))
    {
        glfwPollEvents();
        GameEngine->Draw();

        // let's rotate the player.
        Character->Transform.Rotation.y += 1.0;
    }
	return 0;
}
