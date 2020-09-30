#include "Rook.h"
#include <iostream>

Rook::Rook(Position p, std::string color, Board* b) :Piece(p, color, b) {
	
}

bool Rook::move(Position destination, Player pl) {
	if (Helper::checkHorizontalMove(p, destination) && Helper::checkHorizontalPath(p, destination, board)) {
		SetFirstMove();
		update(destination, this);
		return true;
	}
	else if (Helper::checkVerticalMove(p, destination) && Helper::checkVerticalPath(p, destination, board)) {
		SetFirstMove();
		update(destination, this);
		return true;
	}
	else {
		return false;
	}
}

bool Rook::Hint(Position destination) {
	if (Helper::checkHorizontalMove(p, destination) && Helper::checkHorizontalPath(p, destination, board)) {
		return true;
	}
	else if (Helper::checkVerticalMove(p, destination) && Helper::checkVerticalPath(p, destination, board)) {
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