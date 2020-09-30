#include "Bishop.h"
#include <iostream>

Bishop::Bishop(Position p, std::string color, Board* b) :Piece(p, color, b) {

}

bool Bishop::move(Position destination, Player pl) {
	if (Helper::checkDiagonalMove(this->p, destination) && Helper::checkDiagonalPath(p, destination, this->board))
	{
		update(destination, this);
		return true;
	}
	else {
		return false;
	}
}

bool Bishop::Hint(Position destination) {
	if (Helper::checkDiagonalMove(this->p, destination) && Helper::checkDiagonalPath(p, destination, this->board))
	{
		return true;
	}
	else {
		return false;
	}

}

void Bishop::print() {
	if (this->getColor() == "Black") {
		std::cout << "B";
	}
	else {
		std::cout << "b";
	}
}
char Bishop::getPiece() {
	if (this->getColor() == "Black") {
		return 'B';
	}
	else {
		return 'b';
	}
}
