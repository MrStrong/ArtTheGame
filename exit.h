#ifndef EXIT_H_
#define EXIT_H_

#include<iostream>
#include <SFML/Graphics.hpp>

class Exit
{
	private:
		sf::Image LevelExitImage[10];
		sf::Sprite LevelExit;
		sf::Image LevelCompleteScreenImage;
		sf::Sprite LevelCompleteScreen;
		int x;
		int y;

	public:
		Exit();
		sf::Sprite getLevelExit();
		sf::Sprite getLevelCompleteScreen();
		void setupLevelExit(int i, int tempx, int tempy);
		int getX();
		int getY();
		void setX(int tempx);
		void setY(int tempy);

};


#endif
