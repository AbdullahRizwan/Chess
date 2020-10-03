#pragma once
#include <string>


class Piece;
class Board
{
private:
	Piece* grid[8][8];
	bool hintarray[8][8];
public:
	void Init(std::string input);
	Piece* getPieceAt(int ri, int ci);
	std::string getPieceColorAt(int ri, int ci);
	void resetPos(int ri, int ci);
	void setPos(int ri, int ci, Piece* p);
	void loadBoard();
	void saveBoard();
	void printBoard();
	void SetHint(int ri, int ci);
	void ResetHint();
	bool movePiece(int sri, int sci, int dri,int dci);
};

