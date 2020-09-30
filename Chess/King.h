#pragma once
#include "Piece.h"
class King:public Piece
{
public:
	King(Position p, std::string color, Board* b);
	void print();
	bool move(Position destination, Player p);
	bool Hint(Position destination);
	char getPiece();
};

