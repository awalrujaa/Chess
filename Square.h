#pragma once
#include "sfml/Graphics.hpp"
#include<iostream>
enum Piece { KING, QUEEN, BISHOP, KNIGHT, ROOK, PAWN, EMPTY };
enum Color { WHITE, BLACK, NONE };

class Square
{
	sf::Texture* currentTexture;
	sf::Texture empty;
	sf::Texture t_whitePawn;
	sf::Texture t_whiteRook;
	sf::Texture t_whiteKnight;
	sf::Texture t_whiteBishop;
	sf::Texture t_whiteKing;
	sf::Texture t_whiteQueen;

	sf::Texture t_blackPawn;
	sf::Texture t_blackRook;
	sf::Texture t_blackKnight;
	sf::Texture t_blackBishop;
	sf::Texture t_blackKing;
	sf::Texture t_blackQueen;

	Piece piece;
	Color color;
	sf::Vector2f startingCoordinate = sf::Vector2f(72 + 3, 797 - 90 - 3);
	int size = 90;
	int x, y;
public:
	sf::Sprite test;
	sf::RectangleShape body;
	bool isSelected;
	void setSpace(Square*);
	void setEmpty();
	void setPieceAndColor(Piece, Color);
	void promote(Square*);
	Piece getPiece();
	Color getColor();
	void setX(int ex) { x = ex; }
	void setY(int why) { y = why; }
	int getX() { return x; }
	int getY() { return y; }
	void draw(sf::RenderWindow& window);
	Square();
};


