#ifndef MCHAR_H_
#define MCHAR_H_

#include <iostream>
#include <SFML/Graphics.hpp>

class artey
{
	private:
		sf::Image arteyImage;
		sf::Image arteyImageL1;
		sf::Image arteyImageL2;
		sf::Image arteyImageL[11];
		sf::Image arteyImageR[11];
		sf::Image arteyImageJ[11];
		sf::Image heart[3];
		int alternateImage;
		int health;
		bool goingUp;
		void setDefaultPosition();
		sf::Sprite HalfHeart[4];
		sf::Sprite FullHeart[4];
		sf::Sprite Artey;

	public:

		artey();

		void gravity(bool f, bool b, int gravitymultiplier);
		void moveRight(float ElapsedTime);
		void moveLeft(float ElapsedTime);
		void jump(float jumpmultiplier);
		void forwardJump(float jumpmultiplier);
		void backJump(float jumpmultiplier);
		void resetArteyImage();
		bool displayhealth(sf::RenderWindow* temp_window);
		bool isGoingForwards;
		bool isGoingBackwards;
		bool isOnPlatform;
		void reduceHP(int n);
		void increaseHP(int n);
		sf::Sprite getArtey();
		void setX(int i);
		void setY(int i);
};

#endif





