#include "Queen.h"
#include <iostream>

Queen::Queen(Position p, std::string color, Board* b) :Piece(p, color, b) {

}

bool Queen::move(Position destination, std::string color) {
	if (checkVerticalMove(this->p, destination) && checkVerticalPath(this->p, destination, this->board)) {
		update(destination, this);
		return true;
	}
	else if (checkHorizontalMove(this->p, destination) && checkHorizontalPath(this->p, destination, this->board)) {
			update(destination, this);
			return true;
	}
	else if (checkDiagonalMove(this->p, destination) && checkDiagonalPath(this->p, destination, this->board)) {
		update(destination, this);
		return true;
	}
	else {
		return false;
	}
}

bool Queen::Hint(Position destination) {
	if (checkVerticalMove(this->p, destination) && checkVerticalPath(this->p, destination, this->board)) {
		return true;
	}
	else if (checkHorizontalMove(this->p, destination) && checkHorizontalPath(this->p, destination, this->board)) {
		return true;
	}
	else if (checkDiagonalMove(this->p, destination) && checkDiagonalPath(this->p, destination, this->board)) {
		return true;
	}
	else {
		return false;
	}
}

void Queen::print() {
	if (this->getColor() == "Black") {
		std::cout << "Q";
	}
	else {
		std::cout << "q";
	}
}
char Queen::getPiece() {
	if (this->getColor() == "Black") {
		return 'Q';
	}
	else {
		return 'q';
	}
}
