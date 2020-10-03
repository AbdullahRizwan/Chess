#pragma once
#include "Piece.h"

class Knight:public Piece
{
public:
	Knight(Position p, std::string color, Board* b);
	void print();
	bool move(Position destination, std::string color);
	bool Hint(Position destination);
	char getPiece();
};

