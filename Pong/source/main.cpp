//////////////////////////////////////////////////////////////////////////
#define _USE_MATH_DEFINES

#include "AIE.h"
#include "KeyCodes.h"
#include <string>
#include <cmath>
#include <assert.h>
#include <crtdbg.h>
#include <ctime>
#include <conio.h>
#include "VectorMath.h"

const int SCREEN_X = 1280;
const int SCREEN_Y = 720;

const int PLAYER1_X = 100;
const int PLAYER1_W = 50;
const int PLAYER1_H = 100;

const int PLAYER2_X = 1200;
const int PLAYER2_W = 50;
const int PLAYER2_H = 100;

const int BALL_W = 30;
const int BALL_H = 30;

bool pause = false;

struct vector2
{
	float x;
	float y;
};

struct movableObject
{
	vector2 position;
	vector2 speed;
	int sprite;
	int width;
	int height;
};

// global variables 
unsigned int bgImage = -1;
unsigned int menu = -1;
movableObject player1 = {PLAYER1_X, (SCREEN_Y/2), 0, 0, -1 , PLAYER1_W, PLAYER1_H};
movableObject player2 = {PLAYER2_X, (SCREEN_Y/2), 0, 0, -1, PLAYER2_W, PLAYER2_H};
movableObject ball = {500, 500, 2, 1, -1, BALL_W, BALL_H};

bool g_gameOver = false;
bool bmenu = true;

int player1Score = 0;
int player2Score = 0;
int frameCounter = 0;

// updates the position of the ball
// adds the balls current velocity to its current position to get the 
// new position
void updateBallPosition(movableObject &obj) 
{
	obj.position = vectorAdd(obj.position, obj.speed);
}

// check if the ball's edges are within the paddle
// returns true if a collision occurred
bool checkPaddleCollision(movableObject& ball, movableObject& player) 
{
	int speed = ball.speed.x;
	
	int ballHalfW = ball.width/2;
	int playerHalfW = player.width/2;
	int playerHalfH = player.height/2;
		
	if(speed < 0)
	{
		if(ball.position.x - ballHalfW < player.position.x + playerHalfW && 
			ball.position.y > player.position.y - playerHalfH &&
			ball.position.y < player.position.y + player.height)
			{
				return true;
			}
	}
	else {
		if(ball.position.x + ballHalfW > player.position.x - playerHalfW && 
			ball.position.y > player.position.y - playerHalfH &&
			ball.position.y < player.position.y + player.height){
				return true;
		}
	}
	return false;
}



// will test if an object has gone outside the screen boundaries
// if the object has gone off the screen, this function will also modify
// the objects speed so that it will move back onto the screen
// returns true if the object's x or y coordinate is off the screen
bool testOnScreen(movableObject& obj)
{
	if(obj.position.x > SCREEN_X) {
		obj.speed.x *= -1;
		return true;
	}
	if(obj.position.x < 0) {
		obj.speed.x *= -1;
		return true;
	}
	if(obj.position.y > SCREEN_Y) {
		obj.speed.y *= -1;
	}
	if(obj.position.y < 0) {
		obj.speed.y *= -1;
	}
	return false;
}

// Resets the position of the ball in the middle of the screen
// Sets the ball's X and Y speed to random values
void ResetBall()
{
	//reset to middle of screen
	ball.position.x = SCREEN_X/2;
	ball.position.y = SCREEN_Y/2;
	//resets the value of the ball's X and Y vectors to a random value
	ball.speed.x = rand()%5;
	srand(time(NULL));
	ball.speed.x += 1;
	ball.speed.y = rand()%5;
	srand(time(NULL));
	ball.speed.y += 1;

}

// Paddle Movement AI
// Finds if the ball's Y is greater than or less than the paddle's Y
// and moves accordingly
//BUG: Snaps to center instead of moving slowly towards it
//BUG: Snaps to Y position of second paddle when ball collides with second paddle
//BUG: Does not move based off of speed variable, moves based off of ball.speed.x
//BUG: Cannot lose because of movespeed scaling off of ball speed

void AImove(movableObject &player, movableObject& ball)
{
	float speed = 1;
	srand (time(NULL));

		
	if(ball.speed.x < 0)
	{
		if(player.position.y > ball.position.y)
		{
			while(player.position.y > ball.position.y)
			{
				player.position.y -= speed;
			}
		}
		else if(player.position.y < ball.position.y)
		{
			while(player.position.y < ball.position.y)
			{
				player.position.y += speed;
			}
		}
	}
	if(ball.speed.x > 0)
	{
		if(player.position.y > SCREEN_Y/2)
		{
			while(player.position.y > SCREEN_Y/2)
			{
				player.position.y -= speed;
			}
		}
		else if(player.position.y < SCREEN_Y/2)
		{
			while(player.position.y < SCREEN_Y/2)
			{
				player.position.y += speed;
			}
		}
	}
}

// Maps keybindings for player1 movement
void move(movableObject &player)
{
	
	
		if(IsKeyDown ('W') && player.position.y > player.height/2)
			{
				player.position.y -= 2;
			}
	
		else if (IsKeyDown ('S') && player.position.y < SCREEN_Y - (player.height/2)) 
			{
				player.position.y += 2;
			}
	
}

// Maps keybindings for player2 movement
void move2(movableObject &player)
{
	
		if(IsKeyDown (GLFW_KEY_SPECIAL+27) && player.position.y > player.height/2)
			{
				player.position.y -= 2;
			}
	
		else if (IsKeyDown (GLFW_KEY_SPECIAL+28) && player.position.y < SCREEN_Y - (player.height/2)) 
			{
				player.position.y += 2;
			}

}

// checks to see if the ball has passed into the 10 pixels buffer zone on the sides of the screen
// if the ball has passed into the buffer zone, awards a point to the appropriate player
// then calls resetball function to start the next round
void score()
{
	// Player 1 Loses, Player 2 Score +1
	if(ball.position.x < 10)
	{
		player2Score++;
		ResetBall();
	}
	// Player 2 Loses, Player 1 Score +1
	if(ball.position.x > (SCREEN_X - 10))
	{
		player1Score++;
		ResetBall();
	}
}
//this doesn't work
bool pauseCheck()
{
	if(IsKeyDown(GLFW_KEY_SPECIAL+38))
	{
		return true;
	}
	else
	{
		return false;
	}
}

//this also doesnt work
void drawMenu()
{
			
		/*menu = CreateSprite( "./images/menu.png", SCREEN_X, SCREEN_Y, true );
		MoveSprite(menu, SCREEN_X>>1, SCREEN_Y>>1);
		DrawSprite(menu);*/
		DrawString("Test text 1", 300, 350);
		DrawString("Test text 2", 300, 400);
		DrawString("Test text 3", 300, 450);
		DrawString("Test text 4", 300, 500);
		

}

// initialize all the variables in the game
void initGame() 
{
	//srand(time(0));

	// Now load some sprites
	bgImage = CreateSprite( "./images/bg.png", SCREEN_X, SCREEN_Y, true );
	MoveSprite(bgImage, SCREEN_X>>1, SCREEN_Y>>1);

	player1.sprite = CreateSprite( "./images/banana.png", PLAYER1_W, PLAYER1_H, true );
	player2.sprite = CreateSprite( "./images/chocolate.png", PLAYER2_W, PLAYER2_H, true );
	ball.sprite = CreateSprite( "./images/ball.png", BALL_W, BALL_H, true );

}

// destroy all the sprites and clean up any memory
void destroyGame() 
{
	DestroySprite(bgImage);
	DestroySprite(player1.sprite);
	DestroySprite(player2.sprite);
	DestroySprite(ball.sprite);
}

// update the game logic here
void updateGame() 
{
	
	updateBallPosition(ball);
	testOnScreen(ball);
	score();
	
	//move(player1);
	move2(player2);
	
	//if(ball.speed.x < 0)
		AImove(player1, ball);
			
	if(g_gameOver == false) 
	{
		if( abs(player1Score - player2Score) >= 3)
		{
			// Game Over
			g_gameOver = true;
		}
	}
	//if the ball is moving towards the left the game will 
	//check for paddle collision with player1
	if(ball.speed.x < 0) {
		if(checkPaddleCollision(ball, player1) == true)  {
			ball.speed.x *= -1;
		}
	}
	//if the ball is moving towards the right the game will
	//check for paddle collision with player2
	else {
		if(checkPaddleCollision(ball, player2) == true)  {
			ball.speed.x *= -1;
		}
	}

	//moves the sprites to the position of the hitboxes
	MoveSprite(player1.sprite, player1.position.x, player1.position.y);

	MoveSprite(player2.sprite, player2.position.x, player2.position.y);

	MoveSprite(ball.sprite, (int)ball.position.x, (int)ball.position.y);
	
}


// draws each frame of the game
void drawGame() 
{	
	DrawSprite(bgImage);
	DrawSprite(ball.sprite);
	DrawSprite(player1.sprite);
	DrawSprite(player2.sprite);

	//positions names and scores
	static char outScore1[10] = {'\n'};
	static char outScore2[10] = {'\n'};

	sprintf(outScore1, "BANANA: %d", player1Score);
	sprintf(outScore2, "CHOCOLATE: %d", player2Score);
	
	DrawString(outScore1, 350, 620, SColour(0,0,0,255));
	DrawString(outScore2, 750, 620, SColour(0,0,0,255));
			
	if(g_gameOver == true) 
	{
		DrawString("You suck", 500, 500);	
	}
}

// entry point of the program
int main( int arc, char* argv[] )
{	
	Initialise(SCREEN_X, SCREEN_Y, false );

		initGame();
		
		do 
		{
			frameCounter++;

			if(frameCounter > 5000)
				frameCounter = 0;
			
			
			ClearScreen();
		
			updateGame();

			drawGame();
		} 
		while ( FrameworkUpdate() == false );
	

	destroyGame();
	
	Shutdown();

	return 0;
}

