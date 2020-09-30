#include "Game.h"
#include <iostream>
#include <Windows.h>
#include "Helper.h"

Game::Game() {
    color[0] = "White";
    color[1] = "Black";
    turn = 1;
}
void Game::Init() {
	turn = 1;
	this->b.Init("Text.txt");
}
void Game::changeTurn() {
	turn = 3 - turn;
}

void Game::PrintBoard() {
	this->b.printBoard();
}

void Game::InputNames() {
	std::cout << "Enter player 1 (White / small) name\n";
	std::cin >> playerNames[0];
		
	std::cout << "Enter player 2 (White / small) name\n";
	std::cin >> playerNames[1];
}

void Game::Save() {
	this->b.saveBoard();
}
void Game::Load() {
	this->b.loadBoard();
}
void Game::End() {

}
void getRowColbyLeftClick(int& rpos, int& cpos)
{
    HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
    DWORD Events;
    INPUT_RECORD InputRecord;
    SetConsoleMode(hInput, ENABLE_PROCESSED_INPUT | ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS);
    do
    {
        ReadConsoleInput(hInput, &InputRecord, 1, &Events);
        if (InputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
        {
            cpos = InputRecord.Event.MouseEvent.dwMousePosition.X;
            rpos = InputRecord.Event.MouseEvent.dwMousePosition.Y;
            break;
        }
    } while (true);
}
void gotoRowCol(int rpos, int cpos)
{
    COORD scrn;
    HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
    scrn.X = cpos;
    scrn.Y = rpos;
    SetConsoleCursorPosition(hOuput, scrn);
}

bool Game::ValidSelection(int ri, int ci) {
    if (color[turn] == (this->b.getPieceColorAt(ri,ci))) {
        return true;    
    }
    return false;
}


void Game::Play() {
    this->PrintBoard();
    int ri=0, ci=0;
    while (true) {
        
        do {
            
            getRowColbyLeftClick(ri, ci);
            cout << ri << "\t" << ci << endl;
        } while (!Game::ValidSelection(ri, ci));

	}
}