#include <iostream>
#include "Game.h"
#include <Windows.h>



int main() {
    Game g;
    g.InputNames();
    g.Init();

    g.Play();
    
}