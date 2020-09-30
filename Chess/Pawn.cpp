#include "Pawn.h"
#include <iostream>

Pawn::Pawn(Position p, std::string color, Board* b):Piece(p,color,b) {

}

bool Pawn::move(Position destination, Player pl) {
	if (Helper::checkVerticalMove(this->p, destination) && Helper::checkVerticalPath(this->p,destination,this->board)) {
		if ((abs(p.ri - destination.ri)) == 2  && CheckFirstMove()) {
			SetFirstMove();
			update(destination, this);
			return true;
		}
		else if((abs(p.ri - destination.ri)) == 1 ) {
			SetFirstMove();
			update(destination, this);
			return true;
		}
		else {
			return false;
		}
	}
	else if ((abs(p.ri - destination.ri) == 1 && abs(p.ci - destination.ci)) == 1){
		if (this->board->getPieceAt(destination.ri, destination.ci) != nullptr) {
			SetFirstMove();
			update(destination, this);
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

bool Pawn::Hint(Position destination) {
	if (Helper::checkVerticalMove(this->p, destination) && Helper::checkVerticalPath(this->p, destination, this->board)) {
		if ((abs(p.ri - destination.ri)) == 2 && CheckFirstMove()) {
			return true;
		}
		else if ((abs(p.ri - destination.ri)) == 1) {
			return true;
		}
		else {
			return false;
		}
	}
	else if ((abs(p.ri - destination.ri) == 1 && abs(p.ci - destination.ci)) == 1) {
		if (this->board->getPieceAt(destination.ri, destination.ci) != nullptr) {
			return true;
		}
		else
			return false;
	}
	else {
		return false;
	}

}

void Pawn::print() {
	if (this->getColor() == "Black") {
		std::cout << "P";
	}
	else {
		std::cout << "p";
	}
}
char Pawn::getPiece() {
	if (this->getColor() == "Black") {
		return 'P';
	}
	else {
		return 'p';
	}
}