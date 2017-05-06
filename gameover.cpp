#include <iostream>
#include "gameover.h"

using namespace std;

gameover::gameover()
{
	menuSelect = 1;
	animate_this_frame = false;
	animation_change = 1;

	if((gameoverImage.LoadFromFile("GameOver.png")))
		cout << "loading GameOver.png" << endl;
	GameOver.SetImage(gameoverImage);
}

sf::Sprite gameover::getGameOver()
{
	return GameOver;
}
