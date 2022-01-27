#pragma once
#include <string>
#include "SFML/Window.hpp"
#include<iostream>
#include "sfml/Graphics.hpp"
#include "Board.h";

class Game
{
private:
	sf::RenderWindow window;
	Board b;
	sf::Texture t1;
	sf::Sprite s1;
	bool isGameOver = false;
	bool isMove = false;
	bool isSourceSelected = false;
	bool inputTaken = false;
	bool moveMade = false;
	float dx = 0, dy = 0;
	int x1, x2, y1, y2;



public:
	Game(int width, int height);
	void update();
	void render();
	void run();
	void processEvents();
	/*void run();
	void processEvents();
	void update();
	void render();*/
};

