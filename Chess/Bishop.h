#pragma once
#include "Piece.h"

class Bishop : public Piece
{
public:
	Bishop(Position p, std::string color, Board* b);
	virtual void print();
	bool move(Position destination, std::string color);
	bool Hint(Position destination);
	char getPiece();
};

