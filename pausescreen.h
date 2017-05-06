#ifndef PAUSESCREEN_H_
#define PAUSESCREEN_H_

#include<iostream>
#include <SFML/Graphics.hpp>

class pausescreen
{
	private:
	sf::Image cursorimage[13];
	sf::Image pauseOverlayimage;
	sf::Sprite cursor;
	sf::Sprite pauseOverlay;
	int animation_change;
	bool animate_this_frame;

	public:
	pausescreen();
	sf::Sprite getPauseOverlay();
	sf::Sprite getCursor();
	void animateCursor();
	void moveSelection();
	int menuSelect;

};



#endif



