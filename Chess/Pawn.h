#pragma once
#include "Piece.h"
class Board;

class Pawn :public Piece
{
public:
	Pawn(Position p, std::string color, Board* b);
	void print();
	bool move(Position destination, Player p);
	bool Hint(Position destination);
	char getPiece();
};

