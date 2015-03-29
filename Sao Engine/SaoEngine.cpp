#include "SaoEngine.h"
#include <glut.h>

namespace SaoEngine {
	/**
	*	function pointers used to store start and update functions
	**/

	void (*startPtr)(void);
	void (*updatePtr)(void);

	/**
	*	functions that handles the storage of function pointers
	**/

	void StartFunc(void(*func)(void)) { startPtr = func; }
	void UpdateFunc(void(*func)(void)) { updatePtr = func; }


	/** 
	*	Camera global instance
	**/
	
	Camera *camera = new Camera;
	void SetCameraPosition(Vector3 pos) { camera->position = pos; }
	void SetCameraPosition(float x, float y, float z) { camera->position = Vector3(x, y, z); }

	void SetCameraLookAt(Vector3 lookat) { camera->lookAt = lookat; }
	void SetCameraLookAt(float x, float y, float z) { camera->lookAt = Vector3(x, y, z); }

	void SetCameraUp(Vector3 Up) { camera->up = Up; }
	void SetCameraUp(float x, float y, float z) { camera->up = Vector3(x, y, z); }

	/**
	*	Window Preferences
	**/

	int windowWidth = 800, windowHeight = 600;
	void SetWindowWidth(int width) { windowWidth = width; }
	void SetWindowHeight(int height) { windowHeight = height; }

	int GetWindowWith() { return windowWidth; }
	int GetWindowHeight() { return  windowHeight; }


	int windowHandle = 0; char* windowName = "A Game created using Sao Engine";
	Color3 windowColor = Color3(0.0f, 0.0f, 0.0f);

	void SetWindowName(char* name) { windowName = name; }
	void SetWindowColor(Color3 color) { windowColor = color; windowColor.toString(); }

	/**	
	*	Function that handles keyboard smooth press
	**/

	unsigned char inputKey;
	bool keyHold[256];
	bool GetKey(unsigned char key) { return keyHold[key]; }

	/** 
	*	Function that handles keyboard single press
	**/

	bool keyPressed = false;
	bool keyDown[256];
	bool keyUp[256];

	bool GetKeyDown(unsigned char key) { return keyDown[key]; }
	bool GetKeyUp(unsigned char key) { return keyUp[key]; }

	/**
	*	Function that handles special keys single press
	**/

	bool specialKeyPressed = false;
	bool specialKeyDown[21];
	int inputSpecialKey = 0;
	bool GetSpecialKey(int key) { return specialKeyDown[key]; }

	/** 
	*	variable used in printing text in the gameScene
	**/

	char text[1000];

	void AddText(float x, float y, char* string) {
		void* font = GLUT_BITMAP_HELVETICA_12;
		sprintf(text, string);
		char* stringPtr;

		glPushMatrix();
		glColor3f(1.0f, 0.0f, 0.0f);
		glNormal3f(0.0f, 0.0f, 1.0f);
		glRasterPos2f(x, y);
		for(stringPtr = string; *stringPtr != '\0'; stringPtr++)
			glutBitmapCharacter(font, *stringPtr);
		glPopMatrix();
	}

	void AddText(float x, float y, char* string, Vector3 pos, Color3 color) {
		void* font = GLUT_BITMAP_HELVETICA_12;
		sprintf(text, string);
		char* stringPtr;

		glPushMatrix();
		glTranslatef(pos.X, pos.Y, pos.Z);
		glColor3f(color.R, color.G, color.B);
		glNormal3f(0.0f, 0.0f, 1.0f);
		glRasterPos2f(x, y);
		for(stringPtr = string; *stringPtr != '\0'; stringPtr++)
			glutBitmapCharacter(font, *stringPtr);
		glPopMatrix();
	}

	/**
	*	Time global instance
	**/

	Time *t = new Time;
	float GetElapsedTime() { return t->ElapsedTime(); }
	float GetDeltaTime() { return t->DeltaTime(); }
	float GetFixedDeltaTime() { return 0.02f; }

	/**
	*	Glut functionalities
	**/

	void GameScene() {
		//glClearColor(0.0f,0.0f,0.0f,1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glLoadIdentity();

		gluLookAt(camera->position.X, camera->position.Y, camera->position.Z,
			camera->lookAt.X, camera->lookAt.Y, camera->lookAt.Z,
			camera->up.X, camera->up.Y, camera->up.Z);

		t->Observe();
		
		if(updatePtr != NULL) updatePtr();

		if(keyDown[inputKey]) {
			keyPressed = true;
			keyDown[inputKey] = false;
		}

		if(keyUp[inputKey]) {
			keyPressed = false;
			keyUp[inputKey] = true;
		}
		if(specialKeyDown[inputSpecialKey]) {
			specialKeyPressed = true;
			specialKeyDown[inputSpecialKey] = false;
		}

		glFlush();
		glutSwapBuffers();
		
	}

	/**
	*	Keyboard functionalities
	**/

	void KeyDown(unsigned char key, int x, int y) {
		inputKey = key;
		if(!keyPressed) keyDown[key] = true;
		
		keyHold[key] = true;

		if(key == 27) exit(0);
	}

	void KeyUp(unsigned char key, int x, int y) {
		keyHold[key] = false;

		keyPressed = false;
		specialKeyPressed = false;
	}

	void SpecialKey(int key, int x, int y) {
		inputSpecialKey = key;
		if(!specialKeyPressed) specialKeyDown[key];
	}

	/**
	*	Window properties
	**/

	void ResizeWindow(int width, int height) {
		if(height == 0) height = 1;

		float aspectRatio = 0.0f;
		aspectRatio = 1.0 * width / height;

		glViewport(0, 0, width, height);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();

		gluPerspective(45, aspectRatio, 0.1, 1000);
		
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		
	}

	void Timer(int extra) {
		glutPostRedisplay();
		glutTimerFunc(10, Timer, extra);
	}

	void Initialize(int argc, char** argv) {
		srand(time(0));
		glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA | GLUT_MULTISAMPLE);

		glutInitWindowPosition(0, 0);
		glutInitWindowSize(windowWidth , windowHeight );

		glutTimerFunc(0, Timer, 0);

		windowHandle = glutCreateWindow(windowName);
		if(startPtr != NULL) startPtr();
		glutDisplayFunc(&GameScene);
		glutReshapeFunc(&ResizeWindow);
		
		glEnable(GL_TEXTURE_2D);
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_COLOR_MATERIAL);
		glEnable(GL_LIGHTING);
		glEnable(GL_LIGHT0);
		glEnable(GL_NORMALIZE);

		glShadeModel(GL_SMOOTH);
		glClearColor(windowColor.R, windowColor.G, windowColor.B, 1.0);

		glutKeyboardFunc(&KeyDown);
		glutKeyboardUpFunc(&KeyUp);
		glutSpecialFunc(&SpecialKey);
		
		glutMainLoop();
	}
}