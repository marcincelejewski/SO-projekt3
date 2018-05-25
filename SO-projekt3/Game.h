#include <memory>
#include <curses.h>
#include <vector>
#include "Board.h"
#include "Snake.h"

#pragma once
class Game
{
public:
	Game(std::shared_ptr<Board> const &b, int snakes_num);
	~Game();
	void init_board();
	std::shared_ptr<Board> board;
	int snakes_num;
	std::vector<std::unique_ptr<Snake> > snakes;
};

