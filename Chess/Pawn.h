#pragma once
#include "Piece.h"


class Pawn :public Piece
{
public:
	Pawn(Position p, std::string color, Board* b);
	void print();
	bool move(Position destination, std::string color);
	bool Hint(Position destination);
	char getPiece();
};

