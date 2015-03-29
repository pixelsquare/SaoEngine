#include "SaoEngine.h"
using namespace SaoEngine;

#define LEVEL_2_CONDITION score >= 3

#include <vector>

vector<GameObject> snake;
float snakeOffset = 2.5f;
int snakeLength = 5;

GameObject *headNode;
GameObject *tailNode;
int tailIndx = 0;

enum snakeDirection {
	left, right, up, down
} snakeDir;

Time *snakeMoveTimer = new Time;
float snakeUpdateTime = 0.5f;

vector<GameObject> food;
int foodCount = 3;

vector<GameObject> block;
int blockCount = 6;

char text[100];
int score = 0;
bool gameEnd = false;

void Start() {
	// creates the snake depends on the snake length that has been assigned
	for(int i = 0; i < snakeLength; i++) {
		GameObject *tmpSnake = new GameObject;
		tmpSnake->SetPosition(Vector3((((snakeLength - 1) - i) * snakeOffset) - 40.0f, 30.0f, 0.0f));
		snake.push_back(*tmpSnake);
	}

	snakeDir = snakeDirection::right;
	tailIndx = snakeLength - 1;
	headNode = &snake[0];
	tailNode = &snake[tailIndx];

	// Spawn food depends on food count with different colors
	for(int i = 0; i < foodCount; i++) {
		GameObject *tmpFood = new GameObject;
		if(i == 0) tmpFood->SetColor(Color3::Red); // 1st food sets to be color red
		else if(i == 1) tmpFood->SetColor(Color3::Green); // 2nd food sets to be color green
		else if(i == 2) tmpFood->SetColor(Color3::Yellow); // 3rd food sets to be color yellow
		// Sets the position of the foods
		tmpFood->SetPosition((float)Math::Random(-(GetWindowWith() * 0.05), GetWindowWith() * 0.05),
							 (float)Math::Random(-(GetWindowHeight() * 0.05), GetWindowHeight() * 0.05),
							 0.0f);
		food.push_back(*tmpFood);
	}

	// Spawn block depends on block count
	for(int i = 0; i < blockCount; i++) {
		GameObject *tmpBlock = new GameObject;
		// Sets the position of the block
		tmpBlock->SetPosition((float)Math::Random(-(GetWindowWith() * 0.05), GetWindowWith() * 0.05),
							 (float)Math::Random(-(GetWindowHeight() * 0.05), GetWindowHeight() * 0.05),
							 0.0f);
		block.push_back(*tmpBlock);
	}
}

void ResetSnake() {
	// Resets the position of the snake to the starting point
	for(int i = 0; i < snake.size(); i++) {
		snake[i].SetPosition(Vector3((((snakeLength - 1) - i) * snakeOffset) - 40.0f, 30.0f, 0.0f));
		snake[i].SetColor(Color3::White);
	}

	// Snake direction
	snakeDir = snakeDirection::right;
	// Snake tail offset
	tailIndx = snakeLength - 1;
	headNode = &snake[0];
	tailNode = &snake[tailIndx];

	snakeUpdateTime = 0.5f;
	score = 0;
}

void ResetFood() {
	// Resets and randomizes the position of the food
	for(int i = 0; i < food.size(); i++) {
		food[i].SetPosition((float)Math::Random(-(GetWindowWith() * 0.05), GetWindowWith() * 0.05),
							 (float)Math::Random(-(GetWindowHeight() * 0.05), GetWindowHeight() * 0.05),
							 0.0f);
	}
}

void ResetBlock()
{
	// Resets and randomizes the position of the food
	for(int i = 0; i < block.size(); i++) {
		block[i].SetPosition((float)Math::Random(-(GetWindowWith() * 0.05), GetWindowWith() * 0.05),
							 (float)Math::Random(-(GetWindowHeight() * 0.05), GetWindowHeight() * 0.05),
							 0.0f);
	}
}

void SnakeRandomColor() {
	Color3 tmpColor;
	int randomizer = 0;
	// set the randomize color of the snake when the food has been eaten
	randomizer = Math::Random(0, 3);
	if(randomizer == 0) tmpColor = Color3::Red;
	else if(randomizer == 1) tmpColor = Color3::Green;
	else if(randomizer == 2) tmpColor = Color3::Yellow;

	// Randomize the color of the snake
	for(int i = 0; i < snake.size(); i++) {
		snake[i].SetColor(tmpColor);
	}
}

void SnakeMove() {
	// move the snake and tail according to the direction
	if(snakeMoveTimer->ElapsedTime() > snakeUpdateTime && !gameEnd) {
		if(snakeDir == snakeDirection::right) {
			tailNode->SetPosition(headNode->GetPosition().X + snakeOffset,
								  headNode->GetPosition().Y,
								  0.0f);
			headNode = tailNode;
		}
		else if(snakeDir == snakeDirection::left) {
			tailNode->SetPosition(headNode->GetPosition().X - snakeOffset,
								  headNode->GetPosition().Y,
								  0.0f);
			headNode = tailNode;
		}
		else if(snakeDir == snakeDirection::up) {
			tailNode->SetPosition(headNode->GetPosition().X,
							  	  headNode->GetPosition().Y + snakeOffset,
								  0.0f);

			headNode = tailNode;
		}
		else if(snakeDir == snakeDirection::down) {
			tailNode->SetPosition(headNode->GetPosition().X,
								  headNode->GetPosition().Y - snakeOffset,
								  0.0f);

			headNode = tailNode;
		}

		tailIndx--;
		if(tailIndx < 0)
			tailIndx = snakeLength - 1;
		tailNode = &snake[tailIndx];
		snakeMoveTimer->Reset();
	}
}

void KeyboardPress() {
	// Snake control
	if(GetKeyDown('w') && snakeDir != snakeDirection::down){
		snakeDir = snakeDirection::up;
	}
	else if(GetKeyDown('a') && snakeDir != snakeDirection::right) {
		snakeDir = snakeDirection::left;
	}
	else if(GetKeyDown('s') && snakeDir != snakeDirection::up) {
		snakeDir = snakeDirection::down;
	}
	else if(GetKeyDown('d') && snakeDir != snakeDirection::left) {
		snakeDir = snakeDirection::right;
	}

	if(GetKeyDown('='))
	{
		score++;
		snakeUpdateTime -= 0.025f;
	}

	if(GetKeyDown('b'))
		ResetSnake();
}

void SnakeCollision() {
	// Sets the boundary of the game when hit, resets the game
	if(headNode->GetPosition().X > (GetWindowWith() * 0.05) ||
		headNode->GetPosition().X < -(GetWindowWith() * 0.05) ||
		headNode->GetPosition().Y > (GetWindowHeight() * 0.05) ||
		headNode->GetPosition().Y < -(GetWindowHeight() * 0.05))
	{
		ResetFood();
		ResetSnake();
	}

	// When food was hit, reshuffles the position of the food
	for(int i = 0; i < food.size(); i++) {
		if(food[i].HasCollidedWith(*headNode)) {
			if(food[i].GetColor() == headNode->GetColor() || headNode->GetColor() == Color3::White) {
				ResetFood();
				SnakeRandomColor();
				score++;
				snakeUpdateTime -= 0.025f;// + 0.01f; // Snake Speed
			}
			else {
				ResetFood();
				ResetSnake();
			}
		}
	}
	
	// When block was hit, resets the snake and food
	for(int i = 0; i < block.size(); i++) {
		if(block[i].HasCollidedWith(*headNode) && LEVEL_2_CONDITION) {
				ResetFood();
				ResetSnake();
		}
	}
}

void Update() {
	for(int i = 0; i < snakeLength; i++) {
		snake[i].Draw(PrimitiveType::Cube);
	}

	SnakeMove();
	SnakeCollision();
	KeyboardPress();

	for(int i = 0; i < foodCount; i++) {
		food[i].Draw(PrimitiveType::Torus);
	}

	if (LEVEL_2_CONDITION)
	{
		for(int i = 0; i < blockCount; i++) {
			block[i].Draw(PrimitiveType::Cube);
		}
	}

	if(score == 15)
		ResetBlock();

	if(score >= 20){
		ResetSnake();
		ResetFood();
		ResetBlock();
		gameEnd = true;
	}

	if(gameEnd)
		snakeMoveTimer->Reset();

	sprintf(text, "Score: %i", score);
	AddText(0.0f, 0.0f, text);

	sprintf(text, "Speed: %f", snakeUpdateTime);
	AddText(0.0f, -1.0f, text);
}

int main(int argc, char** argv) {
	
	StartFunc(&Start);
	UpdateFunc(&Update);

	SetCameraPosition(Vector3::Forward * 80.0f);


	Initialize(argc, argv);
	return 0;
}  