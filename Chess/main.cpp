#include <iostream>
#include "Game.h"
#include <Windows.h>



int main() {
    Game g;
    g.InputNames();
    system("cls");
    g.Init();

    g.Play();
    
}