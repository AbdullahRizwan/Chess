#include "Helper.h"

Position::Position() {

}

Position::Position(int ri, int ci) {
	this->ri = ri;
	this->ci = ci;
}

bool Helper::checkVerticalMove(Position start, Position end) {
	return (start.ci == end.ci);
}

bool Helper::checkVerticalPath(Position start, Position end, Board* b) {
	int r = start.ri;
	while (r != end.ri) {
		if (b->getPieceAt(r, end.ci) != nullptr)
			return false;
		if (start.ri > end.ri)
			r--;
		else
			r++;
	}
	return true;
}

bool Helper::checkHorizontalMove(Position start, Position end) {
	return (start.ri == end.ri);
}


bool Helper::checkHorizontalPath(Position start, Position end, Board* b) {
	int c = start.ci;
	while (c != end.ci) {
		if (b->getPieceAt(c, end.ri) != nullptr)
			return false;
		if (start.ci > end.ci)
			c--;
		else
			c++;
	}
	return true;
}

bool Helper::checkDiagonalMove(Position start, Position end) {
	return abs(start.ri - end.ri) == abs(start.ci - end.ci);
}


bool Helper::checkDiagonalPath(Position start, Position end, Board* b) {
	int r = start.ri;
	int c = start.ci;
	while (r != end.ri && c != end.ci) {
		if (b->getPieceAt(r, c) != nullptr)
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