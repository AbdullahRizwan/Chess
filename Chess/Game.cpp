#include "Game.h"
#include <iostream>
#include <Windows.h>


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
    system("cls");
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
    if(b.getPieceAt(ri,ci)!=nullptr)
        if (color[turn-1] == (this->b.getPieceColorAt(ri,ci))) {
            return true;    
        }
    return false;
}

void Hint() {



}

void Game::Play() {
    this->PrintBoard();
    int sri=0, sci=0;
    int dri = 0, dci = 0;
    while (true) {
        b.ResetHint();
        this->PrintBoard();
        do {
            //check source
            getRowColbyLeftClick(sri, sci);
        } while (!Game::ValidSelection(sri, sci) && (sri < 8 || sci < 8));
        b.ResetHint();
        Hint(sri, sci);
        do {
            //check source
            getRowColbyLeftClick(dri, dci);
            if (dri == sri && sci == dci) {
                sri = 0;
                dri = 0;
                this->changeTurn();
                break;
           }
        } while (!Game::ValidDestinationSelection(sri,sci,dri, dci) && ( dri < 8 || dci < 8));

        gotoRowCol(8, 0);
        cout << "Turn = " << this->turn;
        this->changeTurn();

	}
}

void Game::Hint(int ri,int ci) {
    b.SetHint(ri,ci);
    system("cls");
    this->PrintBoard();
}
bool Game::ValidDestinationSelection(int sri, int sci, int ri, int ci) {
    return this->b.movePiece(sri, sci, ri, ci);
}
