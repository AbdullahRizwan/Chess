#include "Pawn.h"
#include <iostream>

Pawn::Pawn(Position p, std::string color, Board* b):Piece(p,color,b) {

}

bool Pawn::move(Position destination, std::string color) {
	if (checkVerticalMove(this->p, destination) && checkVerticalPath(this->p, destination, this->board)) {
		if ((p.ri - destination.ri) == 2 && this->getColor() == "White" && CheckFirstMove() && this->board->getPieceAt(destination.ri, destination.ci) == nullptr) {
			update(destination, this);
			return true;
		}
		else if ((p.ri - destination.ri) == -2 && this->getColor() == "Black" && CheckFirstMove() && this->board->getPieceAt(destination.ri, destination.ci) == nullptr) {
			update(destination, this);
			return true;
		}
		else if ((p.ri - destination.ri) == 1 && this->getColor() == "White" && this->board->getPieceAt(destination.ri, destination.ci) == nullptr) {
			update(destination, this);
			return true;
		}
		else if ((p.ri - destination.ri) == -1 && this->getColor() == "Black" && this->board->getPieceAt(destination.ri, destination.ci) == nullptr) {
			update(destination, this);
			return true;
		}
		else {
			
			return false;
		}
	}
	else if ((((p.ri - destination.ri) == 1 && (p.ci - destination.ci)) == -1 && this->getColor() == "White") ||
		((p.ri - destination.ri) == -1 && (p.ci - destination.ci) == 1) && this->getColor() == "Black") {
		if (this->board->getPieceAt(destination.ri, destination.ci) != nullptr) {
			update(destination, this);
			return true;
		}
		else {
			return false;
		}
	}
	else if ((((p.ri - destination.ri) == 1 && (p.ci - destination.ci)) == 1 && this->getColor() == "White") ||
		((p.ri - destination.ri) == -1 && (p.ci - destination.ci) == -1) && this->getColor() == "Black") {
		if (this->board->getPieceAt(destination.ri, destination.ci) != nullptr) {
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
	if (checkVerticalMove(this->p, destination) && checkVerticalPath(this->p, destination, this->board)) {
		if ((p.ri - destination.ri) == 2 && this->getColor() == "White" && CheckFirstMove() && this->board->getPieceAt(destination.ri, destination.ci) == nullptr) {
			return true;
		}
		else if ((p.ri - destination.ri) == -2 && this->getColor() == "Black" && CheckFirstMove() && this->board->getPieceAt(destination.ri, destination.ci) == nullptr) {
			return true;
		}
		else if ((p.ri - destination.ri)== 1  && this->getColor() == "White" && this->board->getPieceAt(destination.ri, destination.ci) == nullptr) {
			return true;
		}
		else if ((p.ri - destination.ri) == -1 && this->getColor() == "Black" && this->board->getPieceAt(destination.ri, destination.ci) == nullptr) {
			return true;
		}
		else {
			return false;
		}
	}
	else if ((((p.ri - destination.ri) == 1 && (p.ci - destination.ci)) == -1  && this->getColor() == "White") ||
		((p.ri - destination.ri) == -1 && (p.ci - destination.ci) == 1) && this->getColor() == "Black" ) {
		if (this->board->getPieceAt(destination.ri, destination.ci) != nullptr) {
			return true;
		}
		else {
			return false;
		}
	}
	else if ((((p.ri - destination.ri) == 1 && (p.ci - destination.ci)) == 1 && this->getColor() == "White") ||
		((p.ri - destination.ri) == -1 && (p.ci - destination.ci) == -1) && this->getColor() == "Black") {
		if (this->board->getPieceAt(destination.ri, destination.ci) != nullptr) {
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