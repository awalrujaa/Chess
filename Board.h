#pragma once
#include "Square.h"
#include "SFML/Graphics.hpp"
#include<iostream>

class Board
{
	sf::Texture backText;
	sf::Sprite backgroundImage;
	Square square[8][8];

	bool moveKing(Square* thisKing, Square* thatSpace);
	bool moveQueen(Square* thisQueen, Square* thatSpace);
	bool moveBishop(Square* thisBishop, Square* thatSpace);
	bool moveKnight(Square* thisKnight, Square* thatSpace);
	bool moveRook(Square* thisRook, Square* thatSpace);
	bool movePawn(Square* thisPawn, Square* thatSpace);


public:
	bool makeMove(int x1, int y1, int x2, int y2);
	Color turn = WHITE;
	char message[50] = "";
	void printBoard();
	Board();
	Square* getSquare(int x, int y) {
		return &square[x][y];
	}
	void setSquare(Square* s, int x, int y) {
		square[x][y] = *s;
	}

	void resetBoard();
	void draw(sf::RenderWindow& window);
};
