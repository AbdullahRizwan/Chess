#pragma once
#include <string>

#include "Player.h"
#include "Board.h"

struct Position {
	int ri;
	int ci;
	Position();
	Position(int ri, int ci);
};

class Piece
{

protected:
	bool isKing;
	bool isFirstMove;
	Board* board;
	Position p;
	std::string color;

	
public:
	bool isMyPiece(std::string color, Piece* p);
	Piece(Position p, std::string _color, Board* board);
	virtual void print()=0;
	bool IsValidMove(Position dest,std::string color);
	bool CheckKing();
	void SetKing();
	void SetFirstMove();
	bool CheckFirstMove();
	std::string getColor();
	virtual bool move(Position destination, std::string color)=0;
	void update(Position des, Piece* p);
	virtual bool Hint(Position destination)=0;
	virtual char getPiece()=0;
	static bool checkVerticalMove(Position start, Position end);
	static bool checkVerticalPath(Position start, Position end, Board* b);
	static bool checkHorizontalMove(Position start, Position end);
	static bool checkHorizontalPath(Position start, Position end, Board* b);
	static bool checkDiagonalMove(Position start, Position end);
	static bool checkDiagonalPath(Position start, Position end, Board* b);
};

