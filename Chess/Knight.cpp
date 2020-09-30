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

bool Knight::move(Position destination, Player pl) {
	if(((abs(this->p.ri - destination.ri) == 2 && abs(this->p.ci - destination.ci) == 1)) || 
		((abs(this->p.ri - destination.ri) == 1 && abs(this->p.ci - destination.ci) == 2))) {

		update(destination, this);
		return true;
	}
	else {
		return false;
	}
}

bool Knight::Hint(Position destination) {
	if (((abs(this->p.ri - destination.ri) == 2 && abs(this->p.ci - destination.ci) == 1)) ||
		((abs(this->p.ri - destination.ri) == 1 && abs(this->p.ci - destination.ci) == 2))) {

		return true;
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
