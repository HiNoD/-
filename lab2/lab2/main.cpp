#include <SFML/Graphics.hpp>
#include <iostream>
#include "map.h"

using namespace sf;
class Player { // класс Игрока
public:
	float x, y, w, h, dx, dy, speed = 0;
	int dir = 0;
	String File;
	Image image;
	Texture texture;
	Sprite sprite;

	Player(String F, float X, float Y, float W, float H) { //Конструктор с параметрами(формальными) для класса Player. При создании объекта класса мы будем задавать имя файла, координату Х и У, ширину и высоту
		File = F;
		w = W; h = H;
		image.loadFromFile("images/" + File);
		image.createMaskFromColor(Color(255, 255, 255));//убираем ненужный цвет
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		x = X; y = Y;
		sprite.setTextureRect(IntRect(0, 0, w, h));
	}
	void update(float time) //функция "оживления" объекта класса. 
	{
		switch (dir)//реализуем поведение в зависимости от направления.
		{
		case 0: dx = speed; dy = 0; break;
		case 1: dx = -speed; dy = 0; break;
		case 2: dx = 0; dy = speed; break;
		case 3: dx = 0; dy = -speed; break;
		}

		x += dx*time;
		y += dy*time;

		speed = 0;//зануляем скорость, чтобы персонаж остановился.
		sprite.setPosition(x, y);
	}
};
int main()
{
	RenderWindow window(sf::VideoMode(800, 600), "Dark Castle");
	Player p("hero.png", 24, 32, 24, 32);

	//Карта
	Image map_image;
	map_image.loadFromFile("images/map.png");
	Texture map;
	map.loadFromImage(map_image);
	Sprite s_map;
	s_map.setTexture(map);

	Clock clock;
	float CurrentFrame = 0;//хранит текущий кадр
	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 600;
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		//Управление
		if (Keyboard::isKeyPressed(Keyboard::W)) {
			p.dir = 3; p.speed = 0.1;
			CurrentFrame += 0.005*time;
			if (CurrentFrame > 3) CurrentFrame -= 3;
			p.sprite.setTextureRect(IntRect(100 * int(CurrentFrame), 60, 165, 170));
		}
		if (Keyboard::isKeyPressed(Keyboard::S)) {
			p.dir = 2; p.speed = 0.1;
			CurrentFrame += 0.005*time;
			if (CurrentFrame > 3) CurrentFrame -= 3;
			p.sprite.setTextureRect(IntRect(100 * int(CurrentFrame), 60, 165, 170));
		}
		if (Keyboard::isKeyPressed(Keyboard::A)) {
			p.dir = 1; p.speed = 0.1;
			CurrentFrame += 0.005*time;
			if (CurrentFrame > 3) CurrentFrame -= 3;
			p.sprite.setTextureRect(IntRect(100 * int(CurrentFrame), 60, 165, 170));
		}
		if (Keyboard::isKeyPressed(Keyboard::D)) {
			p.dir = 0; p.speed = 0.1;
			CurrentFrame += 0.005*time;
			if (CurrentFrame > 3) CurrentFrame -= 3;
			p.sprite.setTextureRect(IntRect(100 * int(CurrentFrame), 60, 165, 170));
		}
		p.update(time);

		window.clear();
		for (int i = 0; i < HEIGHT_MAP; i++)
			for (int j = 0; j < WIDTH_MAP; j++)
			{
				if (TileMap[i][j] == ' ')  s_map.setTextureRect(IntRect(0, 0, 32, 32));
				if (TileMap[i][j] == 's')  s_map.setTextureRect(IntRect(32, 0, 32, 32));
				if ((TileMap[i][j] == '0')) s_map.setTextureRect(IntRect(64, 0, 32, 32));


				s_map.setPosition(j * 32, i * 32);//по сути раскидывает квадратики.

				window.draw(s_map);//рисуем квадратики на экран
			}
		window.draw(p.sprite);
		window.display();
	}

	return 0;
}