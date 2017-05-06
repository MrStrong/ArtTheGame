#include<iostream>
#include <SFML/Graphics.hpp>

#include "Level.h"

#include "mchar.h"
#include "platformMED.h"
#include "titlescreen.h"
#include "pausescreen.h"
#include "gameover.h"
#include "exit.h"

//	Platforms.
//	224 pixels from top of artey image to the bottom of the feet
//	MED Platforms are 200 pixels wide, 45 pixels high
//	moving screen limitations arent done properly

using namespace std;


int main()
{
	float ElapsedFrameTime;
	float ElapsedTime;
	sf::Clock Clock;
	cout << "Art" << endl;
	cout << "Graphics Designer - Daniel O'Brien" << endl;
	cout << "Audio Designer - Jacques VanNiekerk" << endl;
	cout << "Programmer - Ben Issko" << endl;
	cout << "Project Manager - Rhys Fairweather" << endl;
	cout << "Project Caterer - Justin Wolf" << endl;
	cout << "Project Tester - Devon Boyd" << endl;
	cout << "Project Sceptic - Ryan Tootel" << endl;
	cout << "Based on a book by Andre Haynes" << endl;

	cin.get();
	cout<<"\a\a\a"; //	Andre's Audio Art!

	//	Create Objects
	artey Artey;
	titlescreen Title;
	pausescreen Pause;
	gameover GameOver;
	Exit Exit;
	Level level[10];
	level[1].setupLevel1();
	level[2].setupLevel2();
	level[0] = level[1];
	platformMED Platforms[100];

	Title.isonbg = true;
	bool test = false;
	bool isGameOver = false;
	bool isgamegoing = true;
	int currentlevel = 1;

	platformMED Platform1 = platformMED(level[0].platformX[0], level[0].platformY[0]);

	for(int counter = 0; counter <= level[0].no_platforms; counter++)
	{
		Platforms[counter] = Platform1;

		Platforms[counter].setX(level[0].platformX[counter]);
		Platforms[counter].setY(level[0].platformY[counter]);
	}

	sf::RenderWindow artWindow(sf::VideoMode(1200, 700, 32), "Art - The Game Alpha v1.o");
	cout << "Test" << endl;
	artWindow.UseVerticalSync(true);
	artWindow.SetFramerateLimit(60);

	sf::Event generalEvent;

	//	titlescreen loop
	while(artWindow.IsOpened())
	{
		Title.moveSelection(Title.selectedOption);
		while(1)
		{
			artWindow.GetEvent(generalEvent);

			if(generalEvent.Type == sf::Event::Closed)
				artWindow.Close();

			if((generalEvent.Type == sf::Event::KeyPressed) && (generalEvent.Key.Code == sf::Key::Down) && Title.selectedOption != 4)
			{
				Title.selectedOption ++;
				Title.moveSelection(Title.selectedOption);
			}

			if((generalEvent.Type == sf::Event::KeyPressed) && (generalEvent.Key.Code == sf::Key::Up) && Title.selectedOption != 1)
			{
				Title.selectedOption --;
				Title.moveSelection(Title.selectedOption);
			}

			if((generalEvent.Type == sf::Event::KeyPressed) && (generalEvent.Key.Code == sf::Key::Return))
			{
				if(Title.selectedOption == 1)
				{
					Title.isonbg = false;
					break;
				}
				else if(Title.selectedOption == 2)
				{
					;
					//	For future use
				}
				else if(Title.selectedOption == 3)
				{
					;
					//	For future use
				}
				else if (Title.selectedOption == 4)
				{
					return 0;
				}
				else
				{
					cout << "PANIC" << endl;
					exit(1);
				}
			}


			Title.animateCursor();
			artWindow.Clear();
			artWindow.Draw(Title.gettitle_background());
			artWindow.Draw(Title.getcursor());
			artWindow.Display();
		}
				if(Title.isonbg == false)
					break;
	}

	Exit.setupLevelExit(1, 400, -100);
	//	Level loop

	while(artWindow.IsOpened())
	{
		do
		{
			while(1)
			{
				artWindow.GetEvent(generalEvent);
				if(generalEvent.Type == sf::Event::Closed)
					artWindow.Close();

				ElapsedFrameTime = artWindow.GetFrameTime();
				ElapsedTime = Clock.GetElapsedTime();
				Clock.Reset();

				//	Falling function
				//	Falling function
				for(int gravitymultiplier = 1; Artey.getArtey().GetPosition().y < level[0].groundLevel; gravitymultiplier++)
				{
					if((Artey.getArtey().GetPosition().x + 30 >= Exit.getX() && Artey.getArtey().GetPosition().x + 140 <= Exit.getX() + 200) && Artey.getArtey().GetPosition().y + 224 <= Exit.getY() + 300 + 10 && Artey.getArtey().GetPosition().y + 224 >= Exit.getY( ) + 300 - 10)
						break;
					int temp = gravitymultiplier;
					if (temp == 0)
						temp = 1;


							for(int i = 0; i <= level[0].no_platforms; i++)
							{
								if((Artey.getArtey().GetPosition().y + 224 >= level[0].platformY[i] - temp -1) && (Artey.getArtey().GetPosition().y + 224 <= level[0].platformY[i] + temp + 1 ))
								{
									cout << "prebreak" << endl;
									if(Artey.getArtey().GetPosition().x + 135 >= level[0].platformX[i] && Artey.getArtey().GetPosition().x <= level[0].platformX[i] + Platform1.platformWidth - 33)
									{
										cout << "break" << endl;
										if(Artey.getArtey().GetPosition().y + 224 != level[0].platformY[i])
										{
											Artey.setY(level[0].platformY[i] - 224);
										}
										Artey.isOnPlatform = true;
										test = true;
										break;
									}
								}
							}
							if(test == true)
								break;



					cout << "fall" << endl;

					Artey.gravity(Artey.isGoingForwards, Artey.isGoingBackwards, gravitymultiplier);

					artWindow.Clear();
					if(level[0].getBg1().GetPosition().x <= 1200 + 4096 && level[0].getBg1().GetPosition().x >= 0 - 4096)
						artWindow.Draw(level[0].getBg1());
					if(level[0].getBg2().GetPosition().x <=1200 + 3104 && level[0].getBg2().GetPosition().x >= 0 - 3104)
						artWindow.Draw(level[0].getBg2());
					if(Exit.getX() <= 1200 + 200 && Exit.getX() >= 0 - 200)
						artWindow.Draw(Exit.getLevelExit());
					isGameOver = Artey.displayhealth(&artWindow);
					for(int counter = 0; counter <= level[0].no_platforms; counter++)
					{
						if(Platforms[counter].getX() <= 1200 + 200 && Platforms[counter].getX() >= 0 - 200)
							artWindow.Draw(Platforms[counter].getMEDplatform());
					}
					artWindow.Draw(Artey.getArtey());
					artWindow.Display();
					//	Empty the event buffer
					if(Artey.getArtey().GetPosition().y == level[0].groundLevel || Artey.isOnPlatform == true)
						while(artWindow.GetEvent(generalEvent))
							cout << "Pop" << endl;
				}
				if(Artey.getArtey().GetPosition().y > level[0].groundLevel)
				{
					Artey.setY(level[0].groundLevel);
					Artey.isOnPlatform = false;
				}
				test = false;
				Artey.isGoingForwards = false;
				Artey.isGoingBackwards = false;


				if((Artey.getArtey().GetPosition().x + 30 >= Exit.getX() && Artey.getArtey().GetPosition().x + 140 <= Exit.getX() + 200) && Artey.getArtey().GetPosition().y + 224 <= Exit.getY() + 300 + 10 && Artey.getArtey().GetPosition().y + 224 >= Exit.getY( ) + 300 - 10)
				{
					cout << "Level Complete" << endl;
					artWindow.Draw(Exit.getLevelCompleteScreen());
					artWindow.Display();
					while(1)
					{
						artWindow.GetEvent(generalEvent);
						if(generalEvent.Type == sf::Event::KeyPressed)
						{
							if(generalEvent.Key.Code == sf::Key::Return)
								goto newlevel;
						}
					}
				}


				if(generalEvent.Type == sf::Event::KeyPressed)
				{
					if((generalEvent.Key.Code == sf::Key::Escape))
					{
						cout << "Pause" << endl;

						//	Paused frame display


						while(1)
						{
							artWindow.GetEvent(generalEvent);
							if(generalEvent.Type == sf::Event::Closed)
								artWindow.Close();

							if(generalEvent.Type == sf::Event::KeyPressed)
							{
								if((generalEvent.Key.Code == sf::Key::Return))
								{
									if(Pause.menuSelect == 1)
										break;
									else if(Pause.menuSelect == 4)
										return 0;
								}
								else if(generalEvent.Key.Code == sf::Key::Escape)
									break;

								else if( (generalEvent.Key.Code == sf::Key::Up) && Pause.menuSelect != 1)
								{
									Pause.menuSelect--;
									Pause.moveSelection();
									Sleep(100);
								}
								else if((generalEvent.Key.Code == sf::Key::Down) && Pause.menuSelect != 4)
								{
									Pause.menuSelect++;
									Pause.moveSelection();
									Sleep(100);
								}
							}



							Pause.animateCursor();

							artWindow.Clear();
							if(level[0].getBg1().GetPosition().x <= 1200 + 4096 && level[0].getBg1().GetPosition().x >= 0 - 4096)
								artWindow.Draw(level[0].getBg1());
							if(level[0].getBg2().GetPosition().x <=1200 + 3104 && level[0].getBg2().GetPosition().x >= 0 - 3104)
								artWindow.Draw(level[0].getBg2());
							if(Exit.getX() <= 1200 + 200 && Exit.getX() >= 0 - 200)
								artWindow.Draw(Exit.getLevelExit());
							isGameOver = Artey.displayhealth(&artWindow);
							for(int counter = 0; counter <= level[0].no_platforms; counter++)
							{
								if(Platforms[counter].getX() <= 1200 + 200 && Platforms[counter].getX() >= 0 - 200)
									artWindow.Draw(Platforms[counter].getMEDplatform());
							}
							artWindow.Draw(Artey.getArtey());
							artWindow.Draw(Pause.getPauseOverlay());
							artWindow.Draw(Pause.getCursor());
							artWindow.Display();
						}
					}
					else if((generalEvent.Key.Code == sf::Key::Left))
					{
						Artey.moveLeft(2*ElapsedFrameTime);
					}

					else if((generalEvent.Key.Code == sf::Key::Right))
						Artey.moveRight(2*ElapsedFrameTime);

					else if((generalEvent.Key.Code == sf::Key::D) && level[0].getBg2().GetPosition().x  + 3104 != 1200)
					{
						level[0].bgmoveleft();

						for(int i = 0; i <= level[0].no_platforms; i++)
						{
							level[0].platformX[i] -= 10;
							//Platforms[i].MEDplatform.SetX(Platforms[i].MEDplatform.GetPosition().x - 10);
							Platforms[i].setX(Platforms[i].getX() - 10);
						}
						Exit.setX(Exit.getX() - 10);
					}

					else if((generalEvent.Key.Code == sf::Key::A) && level[0].getBg1().GetPosition().x != 0)
					{
						level[0].bgmoveright();

						for(int i = 0; i <= level[0].no_platforms; i++)
						{
							level[0].platformX[i] += 10;
							//Platforms[i].MEDplatform.SetX(Platforms[i].MEDplatform.GetPosition().x +10);
							Platforms[i].setX(Platforms[i].getX() + 10);
						}
						Exit.setX(Exit.getX() + 10);
					}

					else if ((generalEvent.Key.Code == sf::Key::Up) || generalEvent.Key.Code == sf::Key::Space)
					{
						for(int i = 18; i >= 0; i--)
						{
							if(artWindow.GetInput().IsKeyDown(sf::Key::Right))
								Artey.forwardJump(i);
							else if(artWindow.GetInput().IsKeyDown(sf::Key::Left))
								Artey.backJump(i);
							else if(!(artWindow.GetInput().IsKeyDown(sf::Key::Right)) && !(artWindow.GetInput().IsKeyDown(sf::Key::Left)))
								Artey.jump(i);

							artWindow.Clear();
							if(level[0].getBg1().GetPosition().x <= 1200 + 4096 && level[0].getBg1().GetPosition().x >= 0 - 4096)
								artWindow.Draw(level[0].getBg1());
							if(level[0].getBg2().GetPosition().x <=1200 + 3104 && level[0].getBg2().GetPosition().x >= 0 - 3104)
								artWindow.Draw(level[0].getBg2());
							if(Exit.getX() <= 1200 + 200 && Exit.getX() >= 0 - 200)
								artWindow.Draw(Exit.getLevelExit());
							isGameOver = Artey.displayhealth(&artWindow);
							for(int counter = 0; counter <= level[0].no_platforms; counter++)
							{
								if(Platforms[counter].getX() <= 1200 + 200 && Platforms[counter].getX() >= 0 - 200)
									artWindow.Draw(Platforms[counter].getMEDplatform());
							}
							artWindow.Draw(Artey.getArtey());
							artWindow.Display();
						}
						Sleep(20);
					}
					else if ((generalEvent.Key.Code == sf::Key::Z))
						Artey.reduceHP(1);
				}
				else
						Artey.resetArteyImage();

				artWindow.Clear();
				if(level[0].getBg1().GetPosition().x <= 1200 + 4096 && level[0].getBg1().GetPosition().x >= 0 - 4096)
					artWindow.Draw(level[0].getBg1());
				if(level[0].getBg2().GetPosition().x <=1200 + 3104 && level[0].getBg2().GetPosition().x >= 0 - 3104)
					artWindow.Draw(level[0].getBg2());
				if(Exit.getX() <= 1200 + 200 && Exit.getX() >= 0 - 200)
					artWindow.Draw(Exit.getLevelExit());
				isGameOver = Artey.displayhealth(&artWindow);
				for(int counter = 0; counter <= level[0].no_platforms; counter++)
				{
					if(Platforms[counter].getX() <= 1200 + 200 && Platforms[counter].getX() >= 0 - 200)
						artWindow.Draw(Platforms[counter].getMEDplatform());
				}
				artWindow.Draw(Artey.getArtey());
				artWindow.Display();

				if(isGameOver == true)
				{
					{
						cout << "Game Over" << endl;
						artWindow.Clear();
						if(level[0].getBg1().GetPosition().x <= 1200 + 4096 && level[0].getBg1().GetPosition().x >= 0 - 4096)
							artWindow.Draw(level[0].getBg1());
						if(level[0].getBg2().GetPosition().x <=1200 + 3104 && level[0].getBg2().GetPosition().x >= 0 - 3104)
							artWindow.Draw(level[0].getBg2());
						if(Exit.getX() <= 1200 + 200 && Exit.getX() >= 0 - 200)
							artWindow.Draw(Exit.getLevelExit());
						isGameOver = Artey.displayhealth(&artWindow);
						for(int counter = 0; counter <= level[0].no_platforms; counter++)
						{
							if(Platforms[counter].getX() <= 1200 + 200 && Platforms[counter].getX() >= 0 - 200)
								artWindow.Draw(Platforms[counter].getMEDplatform());
						}
						artWindow.Draw(Artey.getArtey());
						artWindow.Draw(GameOver.getGameOver());
						artWindow.Display();

						while(1)
						{
							artWindow.GetEvent(generalEvent);
							if((generalEvent.Type == sf::Event::KeyPressed) && (generalEvent.Key.Code == sf::Key::Return))
							{
								return 0;
							}
						}
					}
				}
			}

			newlevel:
			currentlevel++;
			if(currentlevel == 2)
			{
				isgamegoing = false;
				return 0;
			}

			level[0] = level[currentlevel];
			Artey.setX(0);
			Artey.setY(0);
			cout << "newlevelload" << endl;
		}while(1);

	}

	cin.get();
	return 0;
}

