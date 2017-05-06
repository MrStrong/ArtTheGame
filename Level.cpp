#include <iostream>
#include <SFML/Graphics.hpp>
#include "Level.h"
using namespace std;

Level::Level()
{

}

void Level::setupLevel1()
{
	if(!bg1i.LoadFromFile("GrassyKnolls_1.jpg"))
		cout << "error opening grassyknolls_2.jpg" << endl;
	if(!bg2i.LoadFromFile("GrassyKnolls_2.jpg"))
		cout << "error opening grassyknolls_2.jpg" << endl;

	bg1.SetImage(bg1i);
	bg2.SetImage(bg2i);
	bg2.SetX(4096);

	groundLevel = 326;
	no_platforms = 15;

	//	initialise platforms
	for(int counter = 0; counter <= no_platforms; counter++)
	{
		platformX[counter] = 0;
		platformY[counter] = 0;
	}
	platformX[0] = 200;
	platformY[0] = 400;
	platformX[1] = 500;
	platformY[1] = 350;
	platformX[2] = 800;
	platformY[2] = 300;
	platformX[3] = 1200;
	platformY[3] = 350;
	platformX[4] = 1600;
	platformY[4] = 300;
	platformX[5] = 2000;
	platformY[5] = 250;
	platformX[6] = 2400;
	platformY[6] = 200;
	platformX[7] = 2800;
	platformY[7] = 250;
	platformX[8] = 3200;
	platformY[8] = 300;
	platformX[9] = 3600;
	platformY[9] = 330;
	platformX[10] = 4000;
	platformY[10] = 300;
	platformX[11] = 4300;
	platformY[11] = 200;
	platformX[12] = 4000;
	platformY[12] = 170;
	platformX[13] = 4100;
	platformY[13] = 180;
	platformX[14] = 4200;
	platformY[14] = 190;
	platformX[15] = 4750;
	platformY[15] = 200;
}

void Level::setupLevel2()
{
	if(!bg1i.LoadFromFile("GrassyKnolls_1.jpg"))
		cout << "error opening grassyknolls_2.jpg" << endl;
	if(!bg2i.LoadFromFile("GrassyKnolls_2.jpg"))
		cout << "error opening grassyknolls_2.jpg" << endl;

	bg1.SetImage(bg1i);
	bg2.SetImage(bg2i);
	bg2.SetX(4096);

	groundLevel = 326;
	no_platforms = 15;

	//	initialise platforms
	for(int counter = 0; counter <= no_platforms; counter++)
	{
		platformX[counter] = 0;
		platformY[counter] = 0;
	}
	platformX[0] = 200;
	platformY[0] = 400;
	platformX[1] = 500;
	platformY[1] = 350;
	platformX[2] = 800;
	platformY[2] = 300;
	platformX[3] = 1200;
	platformY[3] = 350;
	platformX[4] = 1600;
	platformY[4] = 300;
	platformX[5] = 2000;
	platformY[5] = 250;
	platformX[6] = 2400;
	platformY[6] = 200;
	platformX[7] = 2800;
	platformY[7] = 250;
	platformX[8] = 3200;
	platformY[8] = 300;
	platformX[9] = 3600;
	platformY[9] = 330;
	platformX[10] = 4000;
	platformY[10] = 300;
	platformX[11] = 4300;
	platformY[11] = 200;
	platformX[12] = 4000;
	platformY[12] = 170;
	platformX[13] = 4100;
	platformY[13] = 180;
	platformX[14] = 4200;
	platformY[14] = 190;
	platformX[15] = 4750;
	platformY[15] = 200;
}
void Level::bgmoveleft()
{
	bg1.Move(-10,0);
	bg2.Move(-10,0);
}

void Level::bgmoveright()
{
	bg1.Move(10,0);
	bg2.Move(10,0);
}

sf::Sprite Level::getBg1()
{
	return bg1;
}
sf::Sprite Level::getBg2()
{
	return bg2;
}
