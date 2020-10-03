#pragma once
#include "Piece.h"
class Board;

class Rook : public Piece
{
public:
	Rook(Position p, std::string color, Board* b);
	void print();
	bool move(Position destination, std::string color);
	bool Hint(Position destination);
	char getPiece();
};

