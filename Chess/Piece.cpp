#include "Piece.h"



Piece::Piece(Position p, std::string _color, Board* board) {
	this->p = p;
	this->color = _color;
	this->board = board;
	this->isFirstMove = true;
}

void Piece::SetKing() {
	this->isKing = true;
}
bool Piece::CheckKing() {
	return Piece::isKing;
}

bool Piece::CheckFirstMove() {
	return Piece::isFirstMove;
}

void Piece::SetFirstMove() {
	isFirstMove = false;
}

std::string Piece::getColor() {
	return this->color;
}

bool Piece::IsValidMove(Position dest, std::string pcolor) {
	return (pcolor == this->color) &&  !isMyPiece (pcolor,board->getPieceAt(dest.ri,dest.ci));
}

bool Piece::isMyPiece(std::string pcolor, Piece *pc) {
	return (pc != nullptr && pcolor == pc->color);
}

void Piece::update(Position dest, Piece* pc) {
	this->board->resetPos(p.ri, p.ci);
	this->board->setPos(dest.ri, dest.ci, pc);
	this->p.ri = dest.ri;
	this->p.ci = dest.ci;
}

bool Piece::checkVerticalMove(Position start, Position end) {
	return (start.ci == end.ci);
}

bool Piece::checkVerticalPath(Position start, Position end, Board* b) {
	if (start.ri == end.ri && start.ci == end.ci)
		return false;
	if(b->getPieceAt(start.ri, start.ci)!= nullptr && b->getPieceAt(end.ri, end.ci)!= nullptr)
		if ((b->getPieceAt(start.ri,start.ci)->getColor() == (b->getPieceAt(end.ri, end.ci)->getColor())))
			return false;
	if (end.ri > start.ri) {
		for (int i = start.ri + 1; i < end.ri; i++) {
			if (b->getPieceAt(i, start.ci) != nullptr) {
				return false;
			}
				
		}
	}
	else {
		for (int i = start.ri - 1; i > end.ri; i--) {
			if (b->getPieceAt(i,start.ci) != nullptr) {
				return false;	
			}
		}
	}
	return true;
}

bool Piece::checkHorizontalMove(Position start, Position end) {
	return (start.ri == end.ri);
}


bool Piece::checkHorizontalPath(Position start, Position end, Board* b) {
	if (start.ri == end.ri && start.ci == end.ci)
		return false;
	if (b->getPieceAt(start.ri, start.ci) != nullptr && b->getPieceAt(end.ri, end.ci) != nullptr)
		if ((b->getPieceAt(start.ri, start.ci)->getColor() == (b->getPieceAt(end.ri, end.ci)->getColor())))
			return false;
	if (end.ci >= start.ci) {

		for (int i = start.ci + 1; i < end.ci; i++) {
			if (b->getPieceAt(start.ri,i) != nullptr) {
			
					return false;
		
			}

		}
	}
	else {
		for (int i = start.ci - 1; i > end.ci; i--) {
			if (b->getPieceAt(start.ri, i) != nullptr) {
				
					return false;
				
			}
		}
	}
	return true;
}

bool Piece::checkDiagonalMove(Position start, Position end) {
	return abs(start.ri - end.ri) == abs(start.ci - end.ci);
}


bool Piece::checkDiagonalPath(Position start, Position end, Board* b) {
	int r = start.ri;
	int c = start.ci;
	if (start.ri > end.ri && start.ci > end.ci) {
		r--;
		c--;
	}
	else if (start.ri < end.ri && start.ci > end.ci) {
		r++;
		c--;
	}
	else if (start.ri > end.ri && start.ci < end.ci) {
		r--;
		c++;
	}
	else {
		r++;
		c++;
	}
	if (r == end.ri && c == end.ci)
		return false;
	while (r != end.ri && c != end.ci && r <8 && r>=0 && c<8 && c>=0) {
		if (b->getPieceAt(r, c) != nullptr)
			if (b->getPieceAt(r, c)->getColor() == b->getPieceAt(start.ri, start.ci)->getColor())
				return false;
		if (start.ri > end.ri && start.ci > end.ci) {
			r--;
			c--;
		}
		else if (start.ri < end.ri && start.ci > end.ci) {
			r++;
			c--;
		}
		else if (start.ri > end.ri && start.ci < end.ci) {
			r--;
			c++;
		}
		else {
			r++;
			c++;
		}
	}
	return true;
}
Position::Position() {

}

Position::Position(int ri, int ci) {
	this->ri = ri;
	this->ci = ci;
}