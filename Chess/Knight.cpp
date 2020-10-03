#include "Knight.h"
#include <iostream>

Knight::Knight(Position p, std::string color, Board* b) :Piece(p, color, b) {

}

void Knight::print() {
	if (this->getColor() == "Black") {
		std::cout << "H";
	}
	else {
		std::cout << "h";
	}
}

bool Knight::move(Position destination, std::string color) {
	if (((abs(this->p.ri - destination.ri) == 2 && abs(this->p.ci - destination.ci) == 1)) ||
		((abs(this->p.ri - destination.ri) == 1 && abs(this->p.ci - destination.ci) == 2))) {
		if (this->board->getPieceAt(destination.ri, destination.ci) == nullptr) {
			update(destination, this);
			return true;
		}
		else if (this->color != this->board->getPieceAt(destination.ri, destination.ci)->getColor()) {
			update(destination, this);
			return true;
		}
		else
			return false;
	}
	else {
		return false;
	}
}

bool Knight::Hint(Position destination) {
	if (((abs(this->p.ri - destination.ri) == 2 && abs(this->p.ci - destination.ci) == 1)) ||
		((abs(this->p.ri - destination.ri) == 1 && abs(this->p.ci - destination.ci) == 2)) ) {
		if (this->board->getPieceAt(destination.ri, destination.ci) == nullptr) {
			return true;
		}
		else if (this->color != this->board->getPieceAt(destination.ri, destination.ci)->getColor())
			return true;
		else
			return false;
	}
	else {
		return false;
	}
}
char Knight::getPiece() {
	if (this->getColor() == "Black") {
		return 'H';
	}
	else {
		return 'h';
	}
}
