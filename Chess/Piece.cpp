#include "Piece.h"

class Board;

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

bool Piece::IsValidMove(Position dest, Player p) {
	return (p.getColor() == this->color) &&  !isMyPiece (p,board->getPieceAt(dest.ri,dest.ci));
}

bool Piece::isMyPiece(Player p, Piece *pc) {
	return (pc != nullptr && p.getColor() == pc->color);
}

void Piece::update(Position dest, Piece* pc) {
	this->board->resetPos(p.ri, p.ci);
	this->board->setPos(dest.ri, dest.ci, pc);
	this->p.ri = dest.ri;
	this->p.ci = dest.ci;
}