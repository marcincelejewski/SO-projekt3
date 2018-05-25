// SO-projekt3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Game.h"
#include <memory>

const int v_size = 28;
const int h_size = 36;


int main()
{
	std::shared_ptr<Board> board = std::make_shared <Board>(h_size, v_size);
	std::unique_ptr<Game>(new Game(board,4));
}


