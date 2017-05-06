#ifndef TITLESCREEN_H_
#define TITLESCREEN_H_

#include <iostream>
#include <SFML/Graphics.hpp>

class titlescreen
{
		private:
			sf::Image title_background_image;
			sf::Image cursor_image[14];
			int animation_change;

			sf::Sprite cursor;
			sf::Sprite title_background;

		public:
			titlescreen();


			int selectedOption;
			bool changing_this_frame;
			void moveSelection(int select);
			void animateCursor();

			sf::Sprite getcursor();
			sf::Sprite gettitle_background();



			bool isonbg;

};

#endif
