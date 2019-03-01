#include <C:/Library/SFML-2.4.2/include/SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main()
{


	ifstream Creatures;
	Creatures.open("Creatures.txt", ios::in);
	int CreaturePos[8][8] = { 0 };
	string line;
	int row = 8;
	int column = 8;

	if (Creatures.is_open())
	{

		getline(Creatures, line);
		std::istringstream stream(line);


		for (int i = 0; i < 16; i += 2)
		{
			int XAxis = line[i] - 48 - 1;
			int YAxis = line[i + 1] - 48 - 1;

			CreaturePos[XAxis][YAxis] = 2;
		}
		//CHECK ROWS
		for (int column = 0; column < 8; column++) // For every column
		{
			int count = 0;
			for (int row = 0; row < 8; row++) // For every square in every row
			{
				if (CreaturePos[row][column] != 0)
				{
					count++;
					if (count > 1)
					{
						for (int row = 0; row < 8; row++)
						{
							if (CreaturePos[row][column] == 2)
							{
								CreaturePos[row][column] = 1;
							}
						}
					}
				}
			}
		}
		//CHECK COLUMNS

		for (int row = 0; row < 8; row++) // For every across
		{
			int count = 0;
			for (int column = 0; column < 8; column++) // For down in every across
			{
				if (CreaturePos[row][column] != 0)
				{
					count++;
					if (count > 1)
					{
						for (int column = 0; column < 8; column++)
						{
							if (CreaturePos[row][column] == 2)
							{
								CreaturePos[row][column] = 1;
							}
						}
					}
				}
			}
		}
		//CHECK DIAGONAL	
	/*	for (int column = 8; column > 0; column--) // For every across
		{
			int count = 0;
			for (int x = row, y = column; x >= 0, y >= 0; x++, y++)
					{
						if (CreaturePos[x][y] != 0)
						{
							count++;
							if (count > 1)
							{
								if (CreaturePos[x][y] != 0)
									{
										CreaturePos[x][y] = 1;
									}
								}
							}
					}
			}
			DIAGONAL
					count = 0;
					for (int x = row, y = column - 1; x >= 0, y >= 0; ++x, --y)
					{
						if (CreaturePos[x][y] != 0)
						{
							count++;
							if (count > 1)
							{
								for (x = x + 1, y = column - 1; x >= 0, y >= 0; ++x, --y)
								{
									if (CreaturePos[x][y] == 2)
									{
										CreaturePos[x][y] = 1;
									}
								}
							}
						}
					}
			*/
			//PRINT 2D ARRAY
			for (int i = 0; i < 8; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					cout << CreaturePos[j][i];
				}
				cout << "\n";
			}

			//SFML GRID
			sf::RenderWindow window(sf::VideoMode(435, 440), "Survival Game!", sf::Style::Close);
			window.clear();

			sf::RectangleShape shapeArray[8][8];


			//Square with an unsafe creature
			sf::RectangleShape SquareUnsafeCreature(sf::Vector2f(50, 50));
			SquareUnsafeCreature.setFillColor(sf::Color(250, 0, 0));
			SquareUnsafeCreature.setOutlineThickness(5);
			SquareUnsafeCreature.setOutlineColor(sf::Color(10, 0, 0));

			//Square with a safe creature
			sf::RectangleShape SquareSafeCreature(sf::Vector2f(50, 50));
			SquareSafeCreature.setFillColor(sf::Color(0, 250, 0));
			SquareSafeCreature.setOutlineThickness(5);
			SquareSafeCreature.setOutlineColor(sf::Color(10, 0, 0));

			//Square Without a Creature
			sf::RectangleShape SquareNoCreature(sf::Vector2f(50, 50));
			SquareNoCreature.setFillColor(sf::Color(250, 250, 250));
			SquareNoCreature.setOutlineThickness(5);
			SquareNoCreature.setOutlineColor(sf::Color(10, 0, 0));


			while (window.isOpen())
			{
				sf::Event event;

				for (int i = 0; i < 8; i++)
				{
					for (int j = 0; j < 8; j++)
					{
						if (CreaturePos[i][j] == 0)
						{
							shapeArray[i][j] = SquareNoCreature;
						}
						else if (CreaturePos[i][j] == 1)
						{
							shapeArray[i][j] = SquareUnsafeCreature;
						}
						else if (CreaturePos[i][j] == 2)
						{
							shapeArray[i][j] = SquareSafeCreature;
						}

						shapeArray[i][j].setPosition(sf::Vector2f((55 * i), (450 / 8)*j));

					}
					for (int i = 0; i < 8; i++)
					{
						for (int j = 0; j < 8; j++)
						{
							window.draw(shapeArray[i][j]);
						}
					}
					window.display();

					while (window.pollEvent(event))
					{
						if (event.type == sf::Event::Closed)
						{
							window.close();
						}
					}

				}

				system("pause");
				return 0;

			}
		}
	}
