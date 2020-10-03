#include "Bishop.h"
#include <iostream>

Bishop::Bishop(Position p, std::string color, Board* b) :Piece(p, color, b) {

}

bool Bishop::move(Position destination, std::string color) {
	if (checkDiagonalMove(this->p, destination) && checkDiagonalPath(p, destination, this->board))
	{
		update(destination, this);
		return true;
	}
	else {
		return false;
	}
}

bool Bishop::Hint(Position destination) {
	if (checkDiagonalMove(this->p, destination) && checkDiagonalPath(p, destination, this->board))
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
