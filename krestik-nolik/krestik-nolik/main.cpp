#include <SFML\Graphics.hpp>
#include <iostream>
#include <sstream>


using namespace sf;
using namespace std;

void is_victory(int pole[3][3], bool & result, int is_cross) {
	int x;
	int y;
	bool flag;
	for (y = 0; y < 3; y++) {
		flag = true;
		for (x = 0; x < 3; x++) {
			if (pole[y][x] != is_cross) {
				flag = false;
			}
		}
		if (flag) {
			result = true;
			std::cout << "victory \n";
		}
	}
	for (x = 0; x < 3; x++) {
		flag = true;
		for (y = 0; y < 3; y++) {
			if (pole[y][x] != is_cross) {
				flag = false;
			}
		}
		if (flag) {
			result = true;
			std::cout << "victory \n";
		}
	}
	{
		flag = true;
		if (pole[0][0] != is_cross || pole[1][1] != is_cross || pole[2][2] != is_cross)
		{
			flag = false;
		}
		if (flag)
		{
			result = true;
			std::cout << "victory\n";
		}
	}
	{
		flag = true;
		if (pole[0][2] != is_cross || pole[1][1] != is_cross || pole[2][0] != is_cross)
		{
			flag = false;
		}
		if (flag)
		{
			result = true;
			std::cout << "victory\n";
		}
	}
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(600, 400), "Krestiki-noliki");

	Image map_image;
	map_image.loadFromFile("images/pole.png");
	Texture map;
	map.loadFromImage(map_image);
	Sprite s_map;
	s_map.setPosition(0, 0);
	s_map.setTexture(map);

	Image menu_image;
	menu_image.loadFromFile("images/button.png");
	Texture menu;
	menu.loadFromImage(menu_image);
	Sprite s_menu;
	s_menu.setTexture(menu);
	s_menu.setPosition(400, 0);

	Image x_image;
	x_image.loadFromFile("images/XO.png");
	Texture t_x;
	t_x.loadFromImage(x_image);

	Image o_image;
	o_image.loadFromFile("images/XO.png");
	Texture t_o;
	t_o.loadFromImage(o_image);

	bool cross_move = true;
	int pole[3][3] = { { 0,0,0 }, {0, 0, 0}, {0, 0, 0} };
	int button_coor[2][6] = { {100,150,170,220,240,290 }, { 400,600 } };
	int coor[] = { 50,150,250,350 };
	bool victory = false;
	while (window.isOpen())
	{
		if (!victory) {
			Vector2i pixelPos = Mouse::getPosition(window);//забираем коорд курсорa

			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();


				int i;
				i = 0;
				int k;
				//«аполнение игрового пол€

				if (event.type == sf::Event::MouseButtonReleased)
				{
					if (event.key.code == sf::Mouse::Left)
					{
						if (coor[0] < pixelPos.x && pixelPos.x < coor[3] && coor[0] < pixelPos.y && pixelPos.y < coor[3]) {
							if (cross_move == true)
							{
								k = 1;
								cross_move = false;
							}
							else {
								k = 2;
								cross_move = true;
							}
						}

						if (coor[0] < pixelPos.x && pixelPos.x < coor[1])//1 проверка по x
						{
							if (coor[0] < pixelPos.y && pixelPos.y < coor[1])//1 проверка по y
							{
								if (pole[0][0] == 0)
								{
									pole[0][0] = k;

								}
							}

							else if (coor[1] < pixelPos.y && pixelPos.y < coor[2])//2 проверка по y
							{
								if (pole[1][0] == 0)
								{
									pole[1][0] = k;
								}
							}

							else if (coor[2] < pixelPos.y && pixelPos.y < coor[3])//3 проверка по y
							{
								if (pole[2][0] == 0)
								{
									pole[2][0] = k;
								}
							}
						}

						else if (coor[1] < pixelPos.x && pixelPos.x < coor[2])//2 проверка по x
						{
							if (coor[0] < pixelPos.y && pixelPos.y < coor[1])//1 проверка по y
							{
								if (pole[0][1] == 0)
								{
									pole[0][1] = k;
								}
							}

							else if (coor[1] < pixelPos.y && pixelPos.y < coor[2])//2 проверка по y
							{
								if (pole[1][1] == 0)
								{
									pole[1][1] = k;
								}
							}

							else if (coor[2] < pixelPos.y && pixelPos.y < coor[3])//3 проверка по y
							{
								if (pole[2][1] == 0)
								{
									pole[2][1] = k;
								}
							}
						}

						else if (coor[2] < pixelPos.x && pixelPos.x < coor[3])//3 проверка по x
						{
							if (coor[0] < pixelPos.y && pixelPos.y < coor[1])//1 проверка по y
							{
								if (pole[0][2] == 0)
								{
									pole[0][2] = k;
								}
							}

							else if (coor[1] < pixelPos.y && pixelPos.y < coor[2])//2 проверка по y 
							{
								if (pole[1][2] == 0)
								{
									pole[1][2] = k;
								}
							}

							else if (coor[2] < pixelPos.y && pixelPos.y < coor[3])//3 проверка по y
							{
								if (pole[2][2] == 0)
								{
									pole[2][2] = k;
								}
							}
						}
					}

				}

				
				/* нопки

					Vector2i pixelPos = Mouse::getPosition(window);
					if (event.type == sf::Event::MouseButtonPressed)
					{
						if (event.key.code == sf::Mouse::Left)
						{
							if (button_coor[1][0] < pixelPos.x && pixelPos.x < button_coor[1][1])
							{
								if (button_coor[0][0] < pixelPos.y && pixelPos.y < button_coor[0][1])
								{
									window.clear();
								}
								else if (button_coor[0][2] < pixelPos.y && pixelPos.y < button_coor[0][3])
								{
									//pravile
								}
								else if (button_coor[0][4] < pixelPos.y && pixelPos.y < button_coor[0][5])
								{
									window.close();
								}
							}
						}
					}*/
				
				

			}

			is_victory(pole, victory, 1);
			is_victory(pole, victory, 2);

			window.clear();
			window.draw(s_map);
			window.draw(s_menu);

			Sprite my_sprite;
			int x;
			int y;
			for (y = 0; y < 3; y++) {
				for (x = 0; x < 3; x++) {
					if (pole[y][x] == 1) {
						my_sprite.setTexture(t_x);
						my_sprite.setTextureRect(IntRect(120, 105, 75, 90));
					}
					else if (pole[y][x] == 2) {
						my_sprite.setTextureRect(IntRect(240, 105, 60, 90));
						my_sprite.setTexture(t_o);
					}

					my_sprite.setPosition(x * 100 + 50, y * 100 + 50);
					if (pole[y][x] == 2 || pole[y][x] == 1)
					{
						window.draw(my_sprite);
					}
				}

			}
			window.display();
		}
	}
	/*Font font; 
	font.loadFromFile("Sensei-Medium.ttf");

	Text t_game_over("", font, 60);
	t_game_over.setColor(Color(255, 255, 255));
	t_game_over.setStyle(sf::Text::Bold | sf::Text::Underlined);

	new_score_text.setString("game over"));
	new_score_text.setPosition(300, 650);
	window.draw(new_score_text);*/

	return 0;
}