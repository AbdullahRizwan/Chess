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

bool King::move(Position destination, Player pl) {
	if (Helper::checkHorizontalMove(this->p, destination) && Helper::checkHorizontalPath(this->p, destination, this->board)){
		if ((abs(p.ri - destination.ri)) == 1 || (abs(p.ci - destination.ci)) == 1) {
			SetFirstMove();
			update(destination, this);
			return true;
		}
		return false;
	}
	else if (Helper::checkVerticalMove(this->p, destination) && Helper::checkVerticalPath(this->p, destination, this->board)){
		if ((abs(p.ri - destination.ri)) == 1 || (abs(p.ci - destination.ci)) == 1) {
			SetFirstMove();
			update(destination, this);
			return true;
		}
		return false;
	}
	else if (Helper::checkDiagonalMove(this->p, destination) && Helper::checkDiagonalPath(this->p, destination, this->board)) {
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
	if (Helper::checkHorizontalMove(this->p, destination) && Helper::checkHorizontalPath(this->p, destination, this->board)) {
		if ((abs(p.ri - destination.ri)) == 1 || (abs(p.ci - destination.ci)) == 1) {
			return true;
		}
		return false;
	}
	else if (Helper::checkVerticalMove(this->p, destination) && Helper::checkVerticalPath(this->p, destination, this->board)) {
		if ((abs(p.ri - destination.ri)) == 1 || (abs(p.ci - destination.ci)) == 1) {
			return true;
		}
		return false;
	}
	else if (Helper::checkDiagonalMove(this->p, destination) && Helper::checkDiagonalPath(this->p, destination, this->board)) {
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