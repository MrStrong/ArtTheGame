#ifndef GAMEOVER_H_
#define GAMEOVER_H_

#include<iostream>
#include <SFML/Graphics.hpp>

class gameover
{
	private:
	sf::Image cursorimage[13];
	sf::Image gameoverImage;
	sf::Sprite cursor;
	sf::Sprite GameOver;
	int animation_change;
	bool animate_this_frame;

	public:
	gameover();
	sf::Sprite getGameOver();
	sf::Sprite getCursor();
	void animateCursor();
	void moveSelection();
	int menuSelect;

};



#endif




