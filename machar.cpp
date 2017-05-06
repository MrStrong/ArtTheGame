#include "mchar.h"
#include "Level1.h"
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;


artey::artey()
{
	arteyImage.LoadFromFile("Artey-Still.png");
	arteyImageL1.LoadFromFile("Artey - Left1.png");
	arteyImageL2.LoadFromFile("Artey - Left2.png");
	alternateImage = 1;
	goingUp = true;
	Artey.SetImage(arteyImage);
	Artey.SetX(0);
	Artey.SetY(0);
	isGoingBackwards = false;
	isGoingForwards = false;
	isOnPlatform = false;
	health = 6;

	if(heart[1].LoadFromFile("halfheart.png"))
		cout << "loading halfheart.png" << endl;
	if(heart[2].LoadFromFile("fullheart.png"))
		cout << "loading fullheart.png" << endl;


	if(!arteyImageL[0].LoadFromFile("Artey-Still.png"));
		cout << "loading Artey-Still.png" << endl;
	if(!arteyImageL[1].LoadFromFile("Artey - SL1.png"));
		cout << "loading Artey - SL1.png" << endl;
	if(!arteyImageL[2].LoadFromFile("Artey - SL2.png"));
		cout << "loading Artey - SL2.png" << endl;
	if(!arteyImageL[3].LoadFromFile("Artey - SL3.png"));
		cout << "loading Artey - SL3.png" << endl;
	if(!arteyImageL[4].LoadFromFile("Artey - SL4.png"));
		cout << "loading Artey - SL4.png" << endl;
	if(!arteyImageL[5].LoadFromFile("Artey - SL5.png"));
		cout << "loading Artey - SL5.png" << endl;
	if(!arteyImageL[6].LoadFromFile("Artey - SL6.png"));
		cout << "loading Artey - SL6.png" << endl;
	if(!arteyImageL[7].LoadFromFile("Artey - SL7.png"));
		cout << "loading Artey - SL7.png" << endl;
	if(arteyImageL[8].LoadFromFile("Artey - SL8.png"));
		cout << "loading Artey - SL8.png" << endl;
	if(!arteyImageL[9].LoadFromFile("Artey - SL9.png"));
		cout << "loading Artey - SL9.png" << endl;
	if(!arteyImageL[10].LoadFromFile("Artey - SL10.png"));
		cout << "loading Artey - SL10.png" << endl;

	if(!arteyImageR[0].LoadFromFile("Artey-Still.png"));
		cout << "loading Artey-Still.png" << endl;
	if(!arteyImageR[1].LoadFromFile("Artey - SR1.png"));
		cout << "loading Artey - SR1.png" << endl;
	if(!arteyImageR[2].LoadFromFile("Artey - SR2.png"));
		cout << "loading Artey - SR2.png" << endl;
	if(!arteyImageR[3].LoadFromFile("Artey - SR3.png"));
		cout << "loading Artey - SR3.png" << endl;
	if(!arteyImageR[4].LoadFromFile("Artey - SR4.png"));
		cout << "loading Artey - SR4.png" << endl;
	if(!arteyImageR[5].LoadFromFile("Artey - SR5.png"));
		cout << "loading Artey - SR5.png" << endl;
	if(!arteyImageR[6].LoadFromFile("Artey - SR6.png"));
		cout << "loading Artey - SR6.png" << endl;
	if(!arteyImageR[7].LoadFromFile("Artey - SR7.png"));
		cout << "loading Artey - SR7.png" << endl;
	if(arteyImageR[8].LoadFromFile("Artey - SR8.png"));
		cout << "loading Artey - SR8.png" << endl;
	if(!arteyImageR[9].LoadFromFile("Artey - SR9.png"));
		cout << "loading Artey - SR9.png" << endl;
	if(!arteyImageR[10].LoadFromFile("Artey - SR10.png"));
		cout << "loading Artey - SR10.png" << endl;

	if(!arteyImageJ[0].LoadFromFile("Artey-Still.png"));
		cout << "loading Artey-Still.png" << endl;
	if(!arteyImageJ[1].LoadFromFile("Artey - SJ1.png"));
		cout << "loading Artey - SJ1.png" << endl;
	if(!arteyImageJ[2].LoadFromFile("Artey - SJ2.png"));
		cout << "loading Artey - SJ2.png" << endl;
	if(!arteyImageJ[3].LoadFromFile("Artey - SJ3.png"));
		cout << "loading Artey - SJ3.png" << endl;
	if(!arteyImageJ[4].LoadFromFile("Artey - SJ4.png"));
		cout << "loading Artey - SJ4.png" << endl;
	if(!arteyImageJ[5].LoadFromFile("Artey - SJ5.png"));
		cout << "loading Artey - SJ5.png" << endl;
	if(!arteyImageJ[6].LoadFromFile("Artey - SJ6.png"));
		cout << "loading Artey - SJ6.png" << endl;
	if(!arteyImageJ[7].LoadFromFile("Artey - SJ7.png"));
		cout << "loading Artey - SJ7.png" << endl;
	if(arteyImageJ[8].LoadFromFile("Artey - SJ8.png"));
		cout << "loading Artey - SJ8.png" << endl;
	if(!arteyImageJ[9].LoadFromFile("Artey - SJ9.png"));
		cout << "loading Artey - SJ9.png" << endl;
	if(!arteyImageJ[10].LoadFromFile("Artey - SJ10.png"));
		cout << "loading Artey - SJ10.png" << endl;

	for(int i = 1; i < 4; i++)
	{
		HalfHeart[i].SetImage(heart[1]);
		FullHeart[i].SetImage(heart[2]);
	}
	HalfHeart[2].SetX(178);
	HalfHeart[3].SetX(2 * 178);
	FullHeart[2].SetX(178);
	FullHeart[3].SetX(178 * 2);
}

void artey::moveLeft(float ElapsedTime)
{
		Artey.SetImage(arteyImageL[alternateImage]);
		alternateImage++;
		if(alternateImage == 10)
		{
			alternateImage = 1;
		}


	if(Artey.GetPosition().x <= -20)
	{
		Artey.SetX(-20);
	}
	Artey.SetX(Artey.GetPosition().x - 10);
	Sleep(20);
}

void artey::moveRight(float ElapsedTime)
{
		Artey.SetImage(arteyImageR[alternateImage]);
		alternateImage++;
		if(alternateImage == 10)
		{
			alternateImage = 1;
		}


	if(Artey.GetPosition().x >= 1060)
	{
		Artey.SetX(1060);
	}
	Artey.SetX(Artey.GetPosition().x + 10);
	Sleep(20);
}

void artey::jump(float jumpmultiplier)
{
	Artey.SetImage(arteyImageJ[alternateImage]);
	alternateImage++;
	if(alternateImage == 10)
	{
		alternateImage = 1;
	}
	//Artey.Move(0, jumpmultiplier * -1);
	Artey.SetY(Artey.GetPosition().y + jumpmultiplier * -1);
}

void artey::forwardJump(float jumpmultiplier)
{
	if(Artey.GetPosition().x <= 1060)
	{
		Artey.SetImage(arteyImageJ[alternateImage]);
		alternateImage++;
		if(alternateImage == 10)
		{
			alternateImage = 1;
		}
		Artey.SetX(Artey.GetPosition().x + 5);
		Artey.SetY(Artey.GetPosition().y + jumpmultiplier * -1);
	}
		//temp.Move(5, jumpmultiplier * -1);
	else
	{
		Artey.SetImage(arteyImageJ[alternateImage]);
		alternateImage++;
		if(alternateImage == 10)
		{
			alternateImage = 1;
		}
		Artey.SetY(Artey.GetPosition().y + jumpmultiplier * -1);
	}

	isGoingForwards = true;
}

void artey::backJump(float jumpmultiplier)
{
	if(Artey.GetPosition().x >= -30)
	{
		Artey.SetImage(arteyImageJ[alternateImage]);
		alternateImage++;
		if(alternateImage == 10)
		{
			alternateImage = 1;
		}
		Artey.SetX(Artey.GetPosition().x - 5);
		Artey.SetY(Artey.GetPosition().y + jumpmultiplier * -1);
	}
		//temp.Move(-5, jumpmultiplier * -1);
	else
	{
		Artey.SetImage(arteyImageJ[alternateImage]);
		alternateImage++;
		if(alternateImage == 10)
		{
			alternateImage = 1;
		}
		Artey.SetY(Artey.GetPosition().y + jumpmultiplier * -1);
	}

	isGoingBackwards = true;
}

void artey::resetArteyImage()
{
	Artey.SetImage(arteyImage);
	alternateImage = 1;
	goingUp = true;
}

void artey::gravity(bool f, bool b, int gravitymultiplier)
{
	if(f == true && b == false && Artey.GetPosition().x <= 1060)
	{
		Artey.SetImage(arteyImageJ[alternateImage]);
		alternateImage++;
		if(alternateImage == 10)
		{
			alternateImage = 1;
		}
		Artey.SetY(Artey.GetPosition().y + gravitymultiplier);
		Artey.SetX(Artey.GetPosition().x + 5);
		return;
	}
	else if(f == false && b == true&& Artey.GetPosition().x >= -30)
	{
		Artey.SetImage(arteyImageJ[alternateImage]);
		alternateImage++;
		if(alternateImage == 10)
		{
			alternateImage = 1;
		}
		Artey.SetY(Artey.GetPosition().y + gravitymultiplier);
		Artey.SetX(Artey.GetPosition().x - 5);
		return;
	}

	Artey.SetImage(arteyImageJ[alternateImage]);
	alternateImage++;
	if(alternateImage == 10)
	{
		alternateImage = 1;
	}
	Artey.SetY(Artey.GetPosition().y + gravitymultiplier);
}

bool artey::displayhealth(sf::RenderWindow* temp_window)
{
	if(health == 6)
	{
		temp_window->Draw(FullHeart[1]);
		temp_window->Draw(FullHeart[2]);
		temp_window->Draw(FullHeart[3]);
		return false;
	}
	else if(health == 5)
	{
		temp_window->Draw(FullHeart[1]);
		temp_window->Draw(FullHeart[2]);
		temp_window->Draw(HalfHeart[3]);
		return false;
	}
	else if(health == 4)
	{
		temp_window->Draw(FullHeart[1]);
		temp_window->Draw(FullHeart[2]);
		return false;
	}
	else if(health == 3)
	{
		temp_window->Draw(FullHeart[1]);
		temp_window->Draw(HalfHeart[2]);
		return false;
	}
	else if(health == 2)
	{
		temp_window->Draw(FullHeart[1]);
		return false;
	}
	else if(health == 1)
	{
		temp_window->Draw(HalfHeart[1]);
		return false;
	}
	else if(health == 0)
	{
		return true;
	}

	cout << "PANIC" << endl;
	return false;
}

void artey::reduceHP(int n)
{
	health -= n;
	if(health < 0)
		health = 0;
}


void artey::increaseHP(int n)
{
	health += n;
	if(health > 6)
		health = 6;
}

sf::Sprite artey::getArtey()
{
	return Artey;
}

void artey::setX(int i)
{
	Artey.SetX(i);
}
void artey::setY(int i)
{
	Artey.SetY(i);
}
