#pragma once
#include "Piece.h"

class Knight:public Piece
{
public:
	Knight(Position p, std::string color, Board* b);
	void print();
	bool move(Position destination, Player p);
	bool Hint(Position destination);
	char getPiece();
};

