#pragma once
#include "Board.h"
#include "Helper.h"
#include <string>
#include <iostream>


using namespace std;

class Game
{
private:
	Board b;
	string playerNames[2];
	int turn;
	string color[2];
	
public:
	Game();
	void Init();
	void InputNames();
	void changeTurn();
	void Save();
	void Load();
	void End();
	void Play();
	void PrintBoard();
	void Hint(int ri, int ci);
	bool ValidSelection(int ri, int ci);
	bool ValidDestinationSelection(int sri, int sci, int ri, int ci);
};

