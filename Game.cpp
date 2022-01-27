#include "Game.h"

Game::Game(int width, int height) :window(sf::VideoMode(width, height), "Chess")
{
	//t1.loadFromFile("BlackKing.png");
	//s1.setTexture(t1); 
}

void Game::update()
{
	if (!isGameOver) {
		if (inputTaken) {
			system("cls");
			//std::cout << "check" << std::endl;


			if (b.getSquare(x1, y1)->getColor() == b.turn)
			{
				bool isKingCapturingMove = b.getSquare(x2, y2)->getPiece() == KING;
				if (b.makeMove(x1, y1, x2, y2) == false)
				{
					std::cout << "Invalid move, try again." << std::endl;
				}
				else
				{
					if (isKingCapturingMove) {
						if (b.turn == WHITE)
						{
							std::cout << "WHITE WINS" << std::endl;
							isGameOver = true;

						}
						else

						{
							std::cout << "BLACK WINS" << std::endl;
							isGameOver = true;
						}
					}
					if (b.turn == BLACK)
						b.turn = WHITE;
					else
						b.turn = BLACK;

				}
			}
			b.printBoard();
			std::cout << "(" << x1 + 1 << "," << y1 + 1 << ")(" << x2 + 1 << "," << y2 + 1 << ")" << std::endl;

			inputTaken = false;
		}
	}
	else { 
		std::cout << "Game Over";
		exit(0);
	
	}
	
}

void Game::render() {
	window.clear();
	b.draw(window);
	window.draw(s1);

	window.display();

}

void Game::run()

{

	while (window.isOpen())
	{

		processEvents();
		update();
		render();
	}

}

void Game::processEvents()
{
	//std::cout << sf::Mouse::getPosition(window).x << " //" << sf::Mouse::getPosition(window).y << std::endl;
	sf::Event event;
	while (window.pollEvent(event))
	{
		sf::Vector2i pos = sf::Mouse::getPosition(window);
		switch (event.type)
		{
		case sf::Event::Closed:
			window.close();
			break;
		case sf::Event::MouseButtonPressed:
			if (event.key.code == sf::Mouse::Left)
			{
				Square* s;
				bool insideBoard = false;
				if (!isSourceSelected)
				{
					for (int i = 0; i < 8; i++) {
						for (int j = 0; j < 8; j++) {
							s = b.getSquare(i, j);
							if (s->body.getGlobalBounds().contains(sf::Vector2f(pos.x, pos.y))) {// check if mouse is in tile
								s->isSelected = true;
								x1 = i;
								y1 = j;
								isSourceSelected = true;
								insideBoard = true;    //source co ordinate sets
							}
						}
					}
				}
				else {
					for (int i = 0; i < 8; i++) {
						for (int j = 0; j < 8; j++) {
							s = b.getSquare(i, j);
							if (s->body.getGlobalBounds().contains(sf::Vector2f(pos.x, pos.y))) {
								isSourceSelected = false;
								x2 = i;
								y2 = j;

								insideBoard = false;
								inputTaken = true; //destination co ordinate sets
							}
						}
					}

				}
				if (!insideBoard) {
					std::cout << "out";
					for (int i = 0; i < 8; i++) {
						for (int j = 0; j < 8; j++) {
							s = b.getSquare(j, i);
							isSourceSelected = false;
							s->isSelected = false;


						}
					}
				}


			}

		default:
			break;
		}
		if (event.type == sf::Event::MouseButtonPressed) {
			if (event.key.code == sf::Mouse::Left) {
				if (s1.getGlobalBounds().contains(pos.x, pos.y)) {
					isMove = true;
					dx = pos.x - s1.getPosition().x;
					dy = pos.y - s1.getPosition().y;
				}
			}
		}
		if (event.type == sf::Event::MouseButtonReleased) {
			if (event.key.code == sf::Mouse::Left) {
				isMove = false;
			}
		}
		if (isMove) {
			s1.setPosition(pos.x - dx, pos.y - dy);
		}
	}



}

