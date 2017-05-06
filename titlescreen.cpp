#include "titlescreen.h"
#include <iostream>
using namespace std;

titlescreen::titlescreen()
{
	if((title_background_image.LoadFromFile("titlebackground.jpg")))
		cout << "loading titlebackground.jpg" << endl;

	if((cursor_image[1].LoadFromFile("cursor1.png")))
		cout << "loading cursor1.png" << endl;
	if((cursor_image[2].LoadFromFile("cursor2.png")))
		cout << "loading cursor2.png" << endl;
	if((cursor_image[3].LoadFromFile("cursor3.png")))
		cout << "loading cursor3.png" << endl;
	if((cursor_image[4].LoadFromFile("cursor4.png")))
		cout << "loading cursor4.png" << endl;
	if((cursor_image[5].LoadFromFile("cursor5.png")))
		cout << "loading cursor5.png" << endl;
	if((cursor_image[6].LoadFromFile("cursor6.png")))
		cout << "loading cursor6.png" << endl;
	if((cursor_image[7].LoadFromFile("cursor7.png")))
		cout << "loading cursor7.png" << endl;
	if((cursor_image[8].LoadFromFile("cursor8.png")))
		cout << "loading cursor8.png" << endl;
	if((cursor_image[9].LoadFromFile("cursor9.png")))
		cout << "loading cursor9.png" << endl;
	if((cursor_image[10].LoadFromFile("cursor10.png")))
		cout << "loading cursor10.png" << endl;
	if((cursor_image[11].LoadFromFile("cursor11.png")))
		cout << "loading cursor11.png" << endl;
	if((cursor_image[12].LoadFromFile("cursor12.png")))
		cout << "loading cursor12.png" << endl;
	if((cursor_image[13].LoadFromFile("cursor13.png")))
		cout << "loading cursor13.png" << endl;

	title_background.SetImage(title_background_image);
	cursor.SetImage(cursor_image[1]);
	selectedOption = 1;
	animation_change = 1;
	changing_this_frame = false;
}

void titlescreen::moveSelection(int select)
{
	if(select == 1)
	{
		cursor.SetX(600 - 61);
		cursor.SetY(100 - 48);
	}

	else if(select == 2)
	{
		cursor.SetX(750 - 61);
		cursor.SetY(225 - 48);
	}
	else if(select == 3)
	{
		cursor.SetX(450 - 61);
		cursor.SetY(350 - 48);
	}
	else if(select == 4)
	{
		cursor.SetX(700 - 61);
		cursor.SetY(600 - 48);
	}

	Sleep(100);
}

void titlescreen::animateCursor()
{

	if(changing_this_frame == true)
	{
		cursor.SetImage(cursor_image[animation_change]);
		animation_change++;
		if(animation_change == 14)
			animation_change = 1;
		changing_this_frame = false;
	}
	else
	{
		changing_this_frame = true;
	}

}

sf::Sprite titlescreen::getcursor()
{
	return cursor;
}

sf::Sprite titlescreen::gettitle_background()
{
	return title_background;
}
