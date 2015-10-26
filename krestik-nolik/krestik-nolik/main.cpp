#include <SFML\Graphics.hpp>
#include <iostream>
#include <sstream>
#include "config.h"

using namespace sf;

void is_victory(int pole[3][3], bool & result, int is_cross) {//�������� �� ������
	int x;
	int y;
	bool flag;
	for (y = 0; y < 3; y++) {//�������� �� �����������
		flag = true;
		for (x = 0; x < 3; x++) {
			if (pole[y][x] != is_cross) {
				flag = false;
			}
		}
		if (flag) {
			result = true;
		}
	}
	for (x = 0; x < 3; x++) {//�������� �� ���������
		flag = true;
		for (y = 0; y < 3; y++) {
			if (pole[y][x] != is_cross) {
				flag = false;
			}
		}
		if (flag) {
			result = true;
		}
	}
	//�������� �� ����������
	{
		flag = true;
		if (pole[0][0] != is_cross || pole[1][1] != is_cross || pole[2][2] != is_cross)
		{
			flag = false;
		}
		if (flag)
		{
			result = true;
		}
		if (pole[0][2] != is_cross || pole[1][1] != is_cross || pole[2][0] != is_cross)
		{
			flag = false;
		}
		if (flag)
		{
			result = true;
		}
	}
}

void bot(int pole[3][3], int y, int x, int nolik, int krest) {
	int  s = 0,r = 0,n=0;
	// �o�������� ��������� �� ����
	for (y = 0; y < 3; y++) {
		for (x = 0; x < 3; x++) {
			if (pole[y][x] == krest) {
				s++;
			}
		}
	}
	//������� ���������, ����� � ���
	if (s == 1) {
		if (pole[1][1] != krest) {
			pole[1][1] = nolik;
		}
		else {
			pole[0][0] = nolik;
		}
	}
	if (s < 6 && s > 1) {
		for (y = 0; y < 3; y++) {//������
			if (pole[y][0] == krest && pole[y][1] == krest) {
				pole[y][2] = nolik;
			}
			else if (pole[y][1] == krest && pole[y][2] == krest) {
				pole[y][0] = nolik;
			}
			else if (pole[y][0] == krest && pole[y][2] == krest) {
				pole[y][1] = nolik;
			}
		}
		for (x = 0; x < 3; x++) {//�������
			if (pole[0][x] == krest && pole[1][x] == krest) {
				pole[2][x] = nolik;
			}
			else if (pole[1][x] == krest && pole[2][x] == krest) {
				pole[0][x] = nolik;
			}
			else if (pole[0][x] == krest && pole[2][x] == krest) {
				pole[1][x] = nolik;
			}
		}
		if (pole[1][1] == nolik) {
				
				if (pole[0][1] == krest && pole[1][2] == krest && pole[0][2] == 0) {//������� ������
					pole[0][2] = nolik;
				}
				else if (pole[2][1] == krest && pole[1][2] == krest && pole[2][2] == 0) {
						pole[2][2] = nolik;
				}
				else if (pole[2][1] == krest && pole[1][0] == krest && pole[2][0] == 0) {
						pole[2][0] = nolik;
				}
				else if (pole[0][1] == krest && pole[1][0] == krest && pole[0][0] == 0) {
						pole[0][0] = nolik;
				}
		}
		else {
			if (pole[0][2] == krest || pole[2][2] == krest) {//������� ������
				if (pole[2][0] != 0){
					pole[0][0] = nolik;
				}
				else {
					pole[2][0] = nolik;
				}
			}
			else if (pole[2][0] == krest) {
				pole[0][2] = nolik;
			}
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

	Image pravila_image;
	pravila_image.loadFromFile("images/pravila.png");
	Texture pravila;
	pravila.loadFromImage(pravila_image);
	Sprite s_pravila;
	s_pravila.setTexture(pravila);
	s_pravila.setPosition(0, 0);

	Image x_image;
	x_image.loadFromFile("images/XO.png");
	Texture t_x;
	t_x.loadFromImage(x_image);

	Image o_image;
	o_image.loadFromFile("images/XO.png");
	Texture t_o;
	t_o.loadFromImage(o_image);

	Image krestik;
	krestik.loadFromFile("images/XO.png");
	Texture t_krestik;
	t_krestik.loadFromImage(krestik);
	Sprite s_krestik;
	s_krestik.setTexture(t_krestik);
	s_krestik.setTextureRect(IntRect(0, 0, 40, 50));
	s_krestik.setPosition(550, 0);

	Font font;
	font.loadFromFile("CyrilicOld.ttf");
	Text t_pravila("", font, 20);
	t_pravila.setColor(Color(0, 0, 0));
	t_pravila.setStyle(Text::Bold | Text::Underlined);
	t_pravila.setString("������ �� ������� ������ �� ��������� ������\n ���� 3�3 ����� (���� ������ ��������, \n������ ������ ������). ������, �����������\n � ��� 3 ����� ������ �� ���������, �����������\n ��� ���������, ����������. ������ ���\n ������ �����, �������� ��������.");
	t_pravila.setPosition(50, 100);

	Text string2("", font,70);
	string2.setColor(Color(0, 0, 0));
	string2.setStyle(Text::Bold | Text::Underlined);
	string2.setPosition(100, 100);

	bool cross_move = true;
	bool victory = false;
	bool is_pravila = false;
	bool you_win = false;
	bool you_loss = false;
	int pole[3][3] = { { 0,0,0 },{ 0, 0, 0 },{ 0, 0, 0 } };
	int i, k, o, p,n;
	i = 0, o = 0, p = 0, n = 0;
	while (window.isOpen()){
		Vector2i pixelPos = Mouse::getPosition(window);//�������� ����� ������a

		sf::Event event;
		while (window.pollEvent(event)){
			if (event.type == Event::Closed)
				window.close();



			//���������� �������� ����, ��� ��� � ���� ����� �� ������� ��� ����, �� � �������� �� ����������� �����, ������� �� ��������, � ������ �� �������

			if (event.type == Event::MouseButtonReleased){
				if (event.key.code == Mouse::Left) {
					if (!is_pravila) {//������ � ������� ����
						if (coor[0] < pixelPos.x && pixelPos.x < coor[1]) {//1 �������� �� x
							if (coor[0] < pixelPos.y && pixelPos.y < coor[1]) {//1 �������� �� y
								if (pole[0][0] == 0) {
									pole[0][0] = krest;
									bot(pole, o, p, nolik, krest);
								}
							}

							else if (coor[1] < pixelPos.y && pixelPos.y < coor[2]) {//2 �������� �� y
								if (pole[1][0] == 0) {
									pole[1][0] = krest;
									bot(pole, o, p, nolik, krest);
								}
							}

							else if (coor[2] < pixelPos.y && pixelPos.y < coor[3]) {//3 �������� �� y
								if (pole[2][0] == 0) {
									pole[2][0] = krest;
									bot(pole, o, p, nolik, krest);
								}
							}
						}

						else if (coor[1] < pixelPos.x && pixelPos.x < coor[2]) {//2 �������� �� x
							if (coor[0] < pixelPos.y && pixelPos.y < coor[1]) {//1 �������� �� y
								if (pole[0][1] == 0) {
									pole[0][1] = krest;
									bot(pole, o, p, nolik, krest);
								}
							}

							else if (coor[1] < pixelPos.y && pixelPos.y < coor[2]) {//2 �������� �� y
								if (pole[1][1] == 0) {
									pole[1][1] = krest;
									bot(pole, o, p, nolik, krest);
								}
							}

							else if (coor[2] < pixelPos.y && pixelPos.y < coor[3]) {//3 �������� �� y
								if (pole[2][1] == 0) {
									pole[2][1] = krest;
									bot(pole, o, p, nolik, krest);
								}
							}
						}

						else if (coor[2] < pixelPos.x && pixelPos.x < coor[3]) {//3 �������� �� x
							if (coor[0] < pixelPos.y && pixelPos.y < coor[1]) {//1 �������� �� y
								if (pole[0][2] == 0) {
									pole[0][2] = krest;
									bot(pole, o, p, nolik, krest);
								}
							}

							else if (coor[1] < pixelPos.y && pixelPos.y < coor[2]) {//2 �������� �� y 
								if (pole[1][2] == 0) {
									pole[1][2] = krest;
									bot(pole, o, p, nolik, krest);
								}
							}

							else if (coor[2] < pixelPos.y && pixelPos.y < coor[3]) {//3 �������� �� y
								if (pole[2][2] == 0) {
									pole[2][2] = krest;
									bot(pole, o, p, nolik, krest);
								}
							}
						}
					
					//������
					if (button_coor[1][0] < pixelPos.x && pixelPos.x < button_coor[1][1]) {
						if (button_coor[0][0] < pixelPos.y && pixelPos.y < button_coor[0][1]) {
							window.close();
							main();

						}
						else if (button_coor[0][2] < pixelPos.y && pixelPos.y < button_coor[0][3]) {
							n++;
							if (n == 1) {
								is_pravila = true;
							}
						}
						else if (button_coor[0][4] < pixelPos.y && pixelPos.y < button_coor[0][5]) {
							window.close();
						}

					}
				}
				

			if (button_coor[0][6] > pixelPos.y) {
				is_pravila = false;
				n = 0;
			}
			}
			}

		}

		is_victory(pole, you_win, krest);//������ ���������
		is_victory(pole, you_loss, nolik);//������ �������

		window.clear();
		window.draw(s_map);
		window.draw(s_menu);
		if (is_pravila) {
			window.draw(s_pravila);
			window.draw(t_pravila);
			window.draw(s_krestik);
		}
		Sprite my_sprite;
		int x;
		int y;
		for (y = 0; y < 3; y++) {
			for (x = 0; x < 3; x++) {
				if (pole[y][x] == krest) {//���� ������ �������� ���������, ������� ���
					my_sprite.setTexture(t_x);
					my_sprite.setTextureRect(IntRect(120, 105, 75, 90));
				}
				else if (pole[y][x] == nolik) {//���� ������ �������� �������, ������� ���
					my_sprite.setTextureRect(IntRect(240, 105, 60, 90));
					my_sprite.setTexture(t_o);
				}

				my_sprite.setPosition(x * 110 + 50, y * 100 + 50);//����� �� ������ ������� ���������
				if (pole[y][x] == nolik || pole[y][x] == krest)
				{
					window.draw(my_sprite);
				}
			}

		}
		if (you_win) {
			string2.setString("�� �������\n");
			window.draw(string2);
		}
		else if (you_loss) {
			string2.setString("�� ��������\n");
			window.draw(string2);
		}
		window.display();

	}
	return 0;
}