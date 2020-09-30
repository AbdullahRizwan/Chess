#include "Queen.h"
#include <iostream>

Queen::Queen(Position p, std::string color, Board* b) :Piece(p, color, b) {

}

bool Queen::move(Position destination, Player pl) {
	if (Helper::checkVerticalMove(this->p, destination) && Helper::checkVerticalPath(this->p, destination, this->board)) {
		update(destination, this);
		return true;
	}
	else if (Helper::checkHorizontalMove(this->p, destination) && Helper::checkHorizontalPath(this->p, destination, this->board)) {
			update(destination, this);
			return true;
	}
	else if (Helper::checkDiagonalMove(this->p, destination) && Helper::checkDiagonalPath(this->p, destination, this->board)) {
		update(destination, this);
		return true;
	}
	else {
		return false;
	}
}

bool Queen::Hint(Position destination) {
	if (Helper::checkVerticalMove(this->p, destination) && Helper::checkVerticalPath(this->p, destination, this->board)) {
		return true;
	}
	else if (Helper::checkHorizontalMove(this->p, destination) && Helper::checkHorizontalPath(this->p, destination, this->board)) {
		return true;
	}
	else if (Helper::checkDiagonalMove(this->p, destination) && Helper::checkDiagonalPath(this->p, destination, this->board)) {
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
