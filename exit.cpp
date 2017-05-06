#include<iostream>
#include <SFML/Graphics.hpp>
#include "exit.h"

using namespace std;

Exit::Exit()
{
	if(LevelExitImage[1].LoadFromFile("Exit.png"));
		cout << "Loading Exit.png" << endl;
	if(LevelCompleteScreenImage.LoadFromFile("LevelComplete.png"))
		cout << "Loading LevelComplete.png" << endl;

	LevelExit.SetImage(LevelExitImage[1]);
	LevelCompleteScreen.SetImage(LevelCompleteScreenImage);

	x = 0;
	y = 0;
	//	May not be needed in the constuructor, depending on level select algorithm
}

void Exit::setupLevelExit(int i, int tempx, int tempy)
{
	if(i == 1)
	{
		x = tempx;
		y = tempy;
	}
	else
		cout << "Invalid Level" << endl;

	LevelExit.SetX(x);
	LevelExit.SetY(y);
}

int Exit::getX()
{
	return x;
}

int Exit::getY()
{
	return y;
}

sf::Sprite Exit::getLevelExit()
{
	return LevelExit;
}

void Exit::setX(int tempx)
{
	x = tempx;
	LevelExit.SetX(x);
}

void Exit::setY(int tempy)
{
	y = tempy;
	LevelExit.SetX(y);
}

sf::Sprite Exit::getLevelCompleteScreen()
{
	return LevelCompleteScreen;
}
