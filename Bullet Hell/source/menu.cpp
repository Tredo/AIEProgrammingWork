#include "menu.h"
#include "vector2d.h"
#include "AIE.h"

Sprite pbutton;
Sprite pbuttonhover;
Sprite qbutton;
Sprite qbuttonhover;

extern int k = 0;
extern int j = 0;

int iMouseX, iMouseY;

extern int i = 1;
int PMenu = -1;

//switch case variable

extern int test = 1;

void InitPMenu()
{
	qbutton.setX(500);
	qbutton.setY(650);
	qbutton.setWidth(100);
	qbutton.setHeight(50);
	qbuttonhover.setX(500);
	qbuttonhover.setY(2000);
	qbuttonhover.setWidth(100);
	qbuttonhover.setHeight(50);
	pbutton.setX(500);
	pbutton.setY(600);
	pbutton.setWidth(100);
	pbutton.setHeight(50);
	pbuttonhover.setX(500);
	pbuttonhover.setY(2000);
	pbuttonhover.setWidth(100);
	pbuttonhover.setHeight(50);
	PMenu = CreateSprite( "./images/PMenu.png", 800, 1000, true );
	MoveSprite(PMenu, 400, 500);
	pbuttonhover.setSprite( CreateSprite("./images/playbuttonhover.png", 100, 50, true));
	pbutton.setSprite( CreateSprite("./images/playbutton.png", 100, 50, true));
	qbuttonhover.setSprite( CreateSprite("./images/quitbuttonhover.png", 100, 50, true));
	qbutton.setSprite( CreateSprite("./images/quitbutton.png", 100, 50, true));
	j++;
}

void DrawPauseMenu()
{
	ClearScreen();
	DrawSprite(PMenu);
	DrawSprite(pbutton.getSprite());
	DrawSprite(pbuttonhover.getSprite());
	DrawSprite(qbutton.getSprite());
	DrawSprite(qbuttonhover.getSprite());
	FrameworkUpdate();
}


void UpdatePauseMenu()
{
	GetMouseLocation(iMouseX, iMouseY);
	MoveSprite(pbutton.getSprite(), pbutton.getX(), pbutton.getY());
	MoveSprite(qbutton.getSprite(), qbutton.getX(), qbutton.getY());
	if(iMouseX > (pbutton.getX() - 50) && iMouseX < (pbutton.getX() + 50) && iMouseY > (pbutton.getY() - 25) && iMouseY < (pbutton.getY() + 25))
	{
		MoveSprite(pbuttonhover.getSprite(), pbutton.getX(), pbutton.getY());
	}
	else
	{
		MoveSprite(pbuttonhover.getSprite(), 1500, 1500);
	}

	if(GetMouseButtonDown(0) == true && iMouseX > (pbutton.getX() - 50) && iMouseX < (pbutton.getX() + 50) && iMouseY > (pbutton.getY() - 25) && iMouseY < (pbutton.getY() + 25))
	{
		i = 1;
	}
	else
	{
		i = 3;
	}

	if(iMouseX > (qbutton.getX() - 50) && iMouseX < (qbutton.getX() + 50) && iMouseY > (qbutton.getY() - 25) && iMouseY < (qbutton.getY() + 25))
	{
		MoveSprite(qbuttonhover.getSprite(), qbutton.getX(), qbutton.getY());
	}
	else
	{
		MoveSprite(qbuttonhover.getSprite(), 1500, 1500);
	}

	if(GetMouseButtonDown(0) == true && iMouseX > (qbutton.getX() - 50) && iMouseX < (qbutton.getX() + 50) && iMouseY > (qbutton.getY() - 25) && iMouseY < (qbutton.getY() + 25))
	{
		test = 0;
	}
	
}
