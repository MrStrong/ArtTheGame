#ifndef PLATFORMMED_H_
#define PLATFORMMED_H_

#include <iostream>
#include <SFML/Graphics.hpp>

class background;

class platformMED
{
	private:
		sf::Image platformImageMED;
		int x;
		int y;
		sf::Sprite MEDplatform;

	public:
		platformMED(int tempx, int tempy);
		platformMED();

		int platformWidth;
		int getX();
		int getY();
		void setX(int temp);
		void setY(int temp);
		sf::Sprite getMEDplatform();
};

#endif
