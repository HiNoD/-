#include<SFML\Graphics.hpp>
#include <iostream>
#include<sstream>


using namespace sf;
using namespace std;

int main()
{
	sf::RenderWindow window(sf::VideoMode(600, 400), "Krestiki-noliki");
	
	Image map_image;
	map_image.loadFromFile("images/pole.png");
	Texture map;
	map.loadFromImage(map_image);
	Sprite s_map;
	s_map.setTexture(map);
	
	Image x_image;
	x_image.loadFromFile("images/XO.png");
	Texture x;
	x.loadFromImage(x_image);

	Sprite s_x;
	Sprite s_x1;
	Sprite s_x2;
	Sprite s_x3;
	Sprite s_x4;

	Image o_image;
	o_image.loadFromFile("images/XO.png");
	Texture o;
	o.loadFromImage(o_image);

	Sprite s_o;
	Sprite s_o1;
	Sprite s_o2;
	Sprite s_o3;
	Sprite s_o4;

	int coor1[] = { 50,50,150,150 };
	int coor2[] = { 150,50,250,150 };
	int coor3[] = { 250,50,350,150 };
	int coor4[] = { 50,150,150,250 };
	int coor5[] = { 150,150,250,250 };
	int coor6[] = { 250,150,350,250 };
	int coor7[] = { 50,250,150,350 };
	int coor8[] = { 150,250,250,350 };
	int coor9[] = { 250,250,350,350 };

	while (window.isOpen())
	{

		Vector2i pixelPos = Mouse::getPosition(window);//забираем коорд курсора
		std::cout << pixelPos.x << "\n";//смотрим на координату Х позиции курсора в консоли (она не будет больше ширины окна)

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
				Vector2i localPosition = sf::Mouse::getPosition(window);//узнавать где курсор

				if (event.type == sf::Event::MouseButtonPressed)
				{
					if (event.key.code == sf::Mouse::Left)
					{
						if (coor1[0] << pixelPos.x << coor1[2])//1
						{
							if (coor1[1] << pixelPos.y << coor1[3])
							{
								s_x.setTexture(x);
								s_x.setTextureRect(IntRect(120, 105, 75, 90));
								s_x.setPosition(50, 50);
							}
						}
						
						if (coor2[0] << pixelPos.x << coor2[2])//2
						{
							if (coor2[1] << pixelPos.y << coor2[3])
							{
								s_o.setTexture(o);
								s_o.setTextureRect(IntRect(240, 105, 60, 90));
								s_o.setPosition(50, 50);
							}
						}

						if (coor3[0] << pixelPos.x << coor3[2])//3
						{
							if (coor3[1] << pixelPos.y << coor3[3])
							{
								s_x1.setTexture(x);
								s_x1.setTextureRect(IntRect(120, 105, 75, 90));
								s_x1.setPosition(50, 50);
							}
						}

						if (coor4[0] << pixelPos.x << coor4[2])//4
						{
							if (coor4[1] << pixelPos.y << coor4[3])
							{
								s_o1.setTexture(o);
								s_o1.setTextureRect(IntRect(240, 105, 60, 90));
								s_o1.setPosition(50, 50);
							}
						}

						if (coor5[0] << pixelPos.x << coor5[2])//5
						{
							if (coor5[1] << pixelPos.y << coor5[3])
							{
								s_x2.setTexture(x);
								s_x2.setTextureRect(IntRect(120, 105, 75, 90));
								s_x2.setPosition(50, 50);
							}
						}

						if (coor6[0] << pixelPos.x << coor6[2])//6
						{
							if (coor6[1] << pixelPos.y << coor6[3])
							{
								s_o2.setTexture(o);
								s_o2.setTextureRect(IntRect(240, 105, 60, 90));
								s_o2.setPosition(50, 50);
							}
						}

						if (coor7[0] << pixelPos.x << coor7[2])//7
						{
							if (coor7[1] << pixelPos.y << coor7[3])
							{
								s_x3.setTexture(x);
								s_x3.setTextureRect(IntRect(120, 105, 75, 90));
								s_x3.setPosition(50, 50);
							}
						}
						if (coor8[0] << pixelPos.x << coor8[2])//8
						{
							if (coor8[1] << pixelPos.y << coor8[3])
							{
								s_o3.setTexture(o);
								s_o3.setTextureRect(IntRect(240, 105, 60, 90));
								s_o3.setPosition(50, 50);
							}
						}

						if (coor9[0] << pixelPos.x << coor9[2])//9
						{
							if (coor9[1] << pixelPos.y << coor9[3])
							{
								s_x4.setTexture(x);
								s_x4.setTextureRect(IntRect(120, 105, 75, 90));
								s_x4.setPosition(50, 50);
							}
						}
					}
				}
		}

		window.clear();
		window.draw(s_map);
		window.draw(s_x);
		window.draw(s_o);
		window.draw(s_x1);
		window.draw(s_o1);
		window.draw(s_x2);
		window.draw(s_o2);
		window.draw(s_x3);
		window.draw(s_o3);
		window.draw(s_x4);
		window.display();
	}

	return 0;
}