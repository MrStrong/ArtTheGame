#include "platformMED.h"
#include "background.h"
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;

platformMED::platformMED(int tempx, int tempy)
{
	x = tempx;
	y = tempy;
	platformWidth = 200;
	if(platformImageMED.LoadFromFile("Platform-MED.png"));
		cout << "loading Platform-MED.png" << endl;
	MEDplatform.SetImage(platformImageMED);

	MEDplatform.SetX(x);
	MEDplatform.SetY(y);
}

platformMED::platformMED()
{
	;
}

int platformMED::getX()
{
	return x;
}

int platformMED::getY()
{
	return y;
}

void platformMED::setX(int tempx)
{
	x = tempx;
	MEDplatform.SetX(x);
}

void platformMED::setY(int tempy)
{
	y = tempy;
	MEDplatform.SetY(y);
}

sf::Sprite platformMED::getMEDplatform()
{
	return MEDplatform;
}
