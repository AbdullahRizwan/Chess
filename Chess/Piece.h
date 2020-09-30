#pragma once
#include <string>

#include "Player.h"
#include "Helper.h"


class Piece
{

protected:
	bool isKing;
	bool isFirstMove;
	Board* board;
	Position p;
	std::string color;

	bool isMyPiece(Player pl, Piece *p);
public:
	
	Piece(Position p, std::string _color, Board* board);
	virtual void print()=0;
	bool IsValidMove(Position dest, Player p);
	bool CheckKing();
	void SetKing();
	void SetFirstMove();
	bool CheckFirstMove();
	std::string getColor();
	//bool move(Position destination, Player p);
	void update(Position des, Piece* p);
	//bool Hint(Position destination);
	virtual char getPiece()=0;
};

