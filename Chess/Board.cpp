#include "Board.h"
#include <fstream>
#include "Pawn.h"
#include "King.h"
#include "Knight.h"
#include "Rook.h"
#include "Queen.h"
#include <Windows.h>
#include "Bishop.h"
#include <iostream>

void Board::Init(std::string input) {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			hintarray[i][j] = false;
		}
	}

	std::ifstream fileReader(input);
	if (fileReader.is_open()) {
		char c;
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				fileReader >> c;
				if (c == 'p') {
					Position p(i, j);
					this->grid[i][j] = new Pawn(p, "White", this);
				}
				else if (c == 'P') {
					Position p(i, j);
					this->grid[i][j] = new Pawn(p, "Black", this);
				}
				else if (c == 'k') {
					Position p(i, j);
					this->grid[i][j] = new King(p, "White", this);
				}
				else if (c == 'K') {
					Position p(i, j);
					this->grid[i][j] = new King(p, "Black", this);
				}
				else if (c == 'h') {
					Position p(i, j);
					this->grid[i][j] = new Knight(p, "White", this);
				}
				else if (c == 'H') {
					Position p(i, j);
					this->grid[i][j] = new Knight(p, "Black", this);
				}
				else if (c == 'b') {
					Position p(i, j);
					this->grid[i][j] = new Bishop(p, "White", this);
				}
				else if (c == 'B') {
					Position p(i, j);
					this->grid[i][j] = new Bishop(p, "Black", this);
				}
				else if (c == 'r') {
					Position p(i, j);
					this->grid[i][j] = new Rook(p, "White", this);
				}
				else if (c == 'R') {
					Position p(i, j);
					this->grid[i][j] = new Rook(p, "Black", this);
				}
				else if (c == 'q') {
					Position p(i, j);
					this->grid[i][j] = new Queen(p, "White", this);
				}
				else if (c == 'Q') {
					Position p(i, j);
					this->grid[i][j] = new Queen(p, "Black", this);
				}
				else {
					this->grid[i][j] = nullptr;

				}
			}
		}
	}

}

std::string Board::getPieceColorAt(int ri, int ci) {
	return grid[ri][ci]->getColor();
}


Piece* Board::getPieceAt(int ri, int ci) {
	return (grid[ri][ci]);
}

void Board::resetPos(int ri, int ci) {
	grid[ri][ci] = nullptr;
}

void Board::setPos(int ri, int ci, Piece *p) {
	grid[ri][ci] = p;
}

void Board::printBoard() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (hintarray[i][j]) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
			}
			else {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			}
			if (grid[i][j] != nullptr) {
				grid[i][j]->print();
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}
			else {
				std::cout << "-";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}
		}
		std::cout << std::endl;
	}
}

void Board::loadBoard() {
	Init("load.txt");
}

void Board::saveBoard() {
	std::ofstream fout("load.txt");
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (grid[i][j] != nullptr) {
				fout << grid[i][j]->getPiece();
			}
			else {
				fout << "-";
			}
		}
		fout << "\n";
	}
}

void Board::SetHint(int ri,int ci) {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (getPieceAt(ri,ci)->Hint(Position(i, j))) {
				hintarray[i][j] = true;
			}
		}
	}
}
void Board::ResetHint() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			hintarray[i][j] = false;
		}
	}
}

bool Board::movePiece(int sri, int sci, int dri, int dci) {
	return grid[sri][sci]->move(Position(dri, dci), grid[sri][sci]->getColor());
}