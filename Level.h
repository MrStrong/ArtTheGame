#ifndef LEVEL_H_
#define LEVEL_H_

#include <iostream>
#include <SFML/Graphics.hpp>

class Level
{
	private:
		sf::Image bg1i;
		sf::Image bg2i;
		sf::Sprite bg1;
		sf::Sprite bg2;

	public:
		sf::Sprite getBg1();
		sf::Sprite getBg2();
		void bgmoveleft();
		void bgmoveright();
		Level();
		void setupLevel1();
		void setupLevel2();

		//int platformX;
		//int platformY;
		int platformX[100];
		int platformY[100];
		int no_platforms;
		int groundLevel;
};

#endif
