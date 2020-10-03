#include "King.h"
#include <iostream>

King::King(Position p, std::string color, Board* b) :Piece(p, color, b) {

}

void King::print() {
	if (this->getColor() == "Black") {
		std::cout << "K";
	}
	else {
		std::cout << "k";
	}
}

bool King::move(Position destination, std::string color) {
	if (checkHorizontalMove(this->p, destination) && checkHorizontalPath(this->p, destination, this->board)){
		if ((abs(p.ri - destination.ri)) == 1 || (abs(p.ci - destination.ci)) == 1) {
			SetFirstMove();
			update(destination, this);
			return true;
		}
		return false;
	}
	else if (checkVerticalMove(this->p, destination) && checkVerticalPath(this->p, destination, this->board)){
		if ((abs(p.ri - destination.ri)) == 1 || (abs(p.ci - destination.ci)) == 1) {
			SetFirstMove();
			update(destination, this);
			return true;
		}
		return false;
	}
	else if (checkDiagonalMove(this->p, destination) && checkDiagonalPath(this->p, destination, this->board)) {
		if ((abs(p.ri - destination.ri)) == 1 || (abs(p.ci - destination.ci)) == 1) {
			SetFirstMove();
			update(destination, this);
			return true;
		}
		return false;
	}
	else {
		return false;
	}
}

bool King::Hint(Position destination) {
	if (checkHorizontalMove(this->p, destination) && checkHorizontalPath(this->p, destination, this->board)) {
		if ((abs(p.ri - destination.ri)) == 1 || (abs(p.ci - destination.ci)) == 1) {
			return true;
		}
		return false;
	}
	else if (checkVerticalMove(this->p, destination) && checkVerticalPath(this->p, destination, this->board)) {
		if ((abs(p.ri - destination.ri)) == 1 || (abs(p.ci - destination.ci)) == 1) {
			return true;
		}
		return false;
	}
	else if (checkDiagonalMove(this->p, destination) && checkDiagonalPath(this->p, destination, this->board)) {
		if ((abs(p.ri - destination.ri)) == 1 || (abs(p.ci - destination.ci)) == 1) {
			return true;
		}
		return false;
	}
	else {
		return false;
	}
}

char King::getPiece() {
	if (this->getColor() == "Black") {
		return 'K';
	}
	else {
		return 'k';
	}
}