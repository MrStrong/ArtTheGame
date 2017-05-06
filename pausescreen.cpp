#include "pausescreen.h"
#include <iostream>

using namespace std;

pausescreen::pausescreen()
{
	animation_change = 1;
	animate_this_frame = false;
	menuSelect = 1;
	if(pauseOverlayimage.LoadFromFile("pausescreen.png"))
		cout << "loading pausescreen.png" << endl;
	if(cursorimage[1].LoadFromFile("pausec1.png"))
		cout << "Loading pausec1.png" << endl;
	if(cursorimage[2].LoadFromFile("pausec2.png"))
		cout << "Loading pausec2.png" << endl;
	if(cursorimage[3].LoadFromFile("pausec3.png"))
		cout << "Loading pausec3.png" << endl;
	if(cursorimage[4].LoadFromFile("pausec4.png"))
		cout << "Loading pausec4.png" << endl;
	if(cursorimage[5].LoadFromFile("pausec5.png"))
		cout << "Loading pausec5.png" << endl;
	if(cursorimage[6].LoadFromFile("pausec6.png"))
		cout << "Loading pausec6.png" << endl;
	if(cursorimage[7].LoadFromFile("pausec7.png"))
		cout << "Loading pausec7.png" << endl;
	if(cursorimage[8].LoadFromFile("pausec8.png"))
		cout << "Loading pausec8.png" << endl;
	if(cursorimage[9].LoadFromFile("pausec9.png"))
		cout << "Loading pausec9.png" << endl;
	if(cursorimage[10].LoadFromFile("pausec10.png"))
		cout << "Loading pausec10.png" << endl;
	if(cursorimage[11].LoadFromFile("pausec11.png"))
		cout << "Loading pausec11.png" << endl;
	if(cursorimage[12].LoadFromFile("pausec12.png"))
		cout << "Loading pausec12.png" << endl;

	pauseOverlay.SetImage(pauseOverlayimage);
	cursor.SetImage(cursorimage[1]);
	cursor.SetX(800 - 52);
	cursor.SetY(44-42);

}

sf::Sprite  pausescreen::getPauseOverlay()
{
	return pauseOverlay;
}

sf::Sprite pausescreen::getCursor()
{
	return cursor;
}
void pausescreen::animateCursor()
{
	if(animate_this_frame == true)
	{
		animate_this_frame = false;
		if(animation_change != 12)
			animation_change ++;
		else
			animation_change = 1;
		cursor.SetImage(cursorimage[animation_change]);
	}
	else
		animate_this_frame = true;
}

void pausescreen::moveSelection()
{
	if(menuSelect == 1)
	{
		cursor.SetY(44-42);
	}

	else if(menuSelect == 2)
	{
		cursor.SetY(189-42);
	}

	else if(menuSelect == 3)
	{
		cursor.SetY(333-42);
	}

	else if(menuSelect == 4)
	{
		cursor.SetY(621-42);
	}
	else
		cout << "Panic" << endl;


}
