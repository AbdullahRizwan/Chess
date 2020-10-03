#include "Rook.h"
#include <iostream>

Rook::Rook(Position p, std::string color, Board* b) :Piece(p, color, b) {
	
}

bool Rook::move(Position destination, std::string color) {
	if (checkHorizontalMove(p, destination) && checkHorizontalPath(p, destination, board)) {
		SetFirstMove();
		update(destination, this);
		return true;
	}
	else if (checkVerticalMove(p, destination) && checkVerticalPath(p, destination, board)) {
		SetFirstMove();
		update(destination, this);
		return true;
	}
	else {
		return false;
	}
}

bool Rook::Hint(Position destination) {
	if (checkHorizontalMove(p, destination) && checkHorizontalPath(p, destination, board)) {
		return true;
	}
	else if (checkVerticalMove(p, destination) && checkVerticalPath(p, destination, board)) {
		return true;
	}
	else {
		return false;
	} 
	
}

void Rook::print() {
	if (this->getColor() == "Black") {
		std::cout << "R";
	}
	else {
		std::cout << "r";
	}
}

char Rook::getPiece() {
	if (this->getColor() == "Black") {
		return 'B';
	}
	else {
		return 'b';
	}
}