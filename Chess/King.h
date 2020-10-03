#pragma once
#include "Piece.h"


class King:public Piece
{
public:
	King(Position p, std::string color, Board* b);
	void print();
	virtual bool move(Position destination, std::string color);
	virtual bool Hint(Position destination);
	char getPiece();
};

