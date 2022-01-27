#include "Square.h"

void Square::draw(sf::RenderWindow& window)
{
	if (isSelected) {
		body.setOutlineThickness(3);
		body.setOutlineColor(sf::Color::Red);
	}
	else {
		body.setOutlineThickness(0);
	}
	body.setPosition(startingCoordinate.x + x * size, startingCoordinate.y - y * size);
	switch (piece)
	{
	case KING: (color == WHITE) ? currentTexture = &t_whiteKing : currentTexture = (&t_blackKing);
		break;
	case QUEEN: (color == WHITE) ? currentTexture = (&t_whiteQueen) : currentTexture = (&t_blackQueen);
		break;
	case BISHOP:(color == WHITE) ? currentTexture = (&t_whiteBishop) : currentTexture = (&t_blackBishop);
		break;
	case KNIGHT:(color == WHITE) ? currentTexture = (&t_whiteKnight) : currentTexture = (&t_blackKnight);
		break;
	case ROOK: (color == WHITE) ? currentTexture = (&t_whiteRook) : currentTexture = (&t_blackRook);
		break;
	case PAWN: (color == WHITE) ? currentTexture = (&t_whitePawn) : currentTexture = (&t_blackPawn);
		break;
	case EMPTY: //currentTexture = nullptr;
		currentTexture = &empty;
		//currentTexture = nullptr;
		//body.setTexture(nullptr);
		break;
	default: body.setFillColor(sf::Color::Transparent);
		break;
	}
	body.setTexture(currentTexture);



	window.draw(body);
}

Square::Square()
{

	isSelected = false;
	body.setSize(sf::Vector2f(size, size));
	//body.setOutlineColor(sf::Color::Red);
	//body.setOutlineThickness(1);
	empty.loadFromFile("empty1.png");

	t_whitePawn.loadFromFile("WhitePawn.png");
	t_whiteRook.loadFromFile("WhiteRook.png");
	t_whiteKnight.loadFromFile("WhiteKnight.png");
	t_whiteBishop.loadFromFile("WhiteBishop.png");
	t_whiteKing.loadFromFile("WhiteKing.png");
	t_whiteQueen.loadFromFile("WhiteQueen.png");

	//currentTexture = &t_whiteQueen;

	t_blackPawn.loadFromFile("BlackPawn.png");
	t_blackRook.loadFromFile("BlackRook.png");
	t_blackKnight.loadFromFile("BlackKnight.png");
	t_blackBishop.loadFromFile("BlackBishop.png");
	t_blackKing.loadFromFile("BlackKing.png");
	t_blackQueen.loadFromFile("BlackQueen.png");
	//body.setTexture(&t_whiteBishop);
	piece = EMPTY;
	color = NONE;
}

void Square::setSpace(Square* space)
{
	color = space->getColor();
	piece = space->getPiece();
}

void Square::setEmpty()
{
	color = NONE;
	piece = EMPTY;
}

Piece Square::getPiece()
{
	return piece;
}

Color Square::getColor()
{
	return color;
}

void Square::setPieceAndColor(Piece p, Color c)
{
	piece = p;
	color = c;
}

void Square::promote(Square* space)
{
	color = space->color;
	piece = QUEEN;
}
