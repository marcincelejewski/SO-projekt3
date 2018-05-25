#include "stdafx.h"
#include "Snake.h"
#include <cstdlib>
#include <ctime>

Snake::Snake()
{
}


Snake::~Snake()
{
}

Snake::Snake(std::shared_ptr<Head> const &h, int old_x, int old_y, int **board):head(h),id(h->id+100),old_x(old_x),old_y(old_y)
{
	board[head->y][head->x] = this->head->id;
	board[old_y][old_x] = this->id;
}

void Snake::operator()() const
{
	int next_move[3][2];

	
	int side = std::rand() % 4;
	int xx = 0;
	int yy = 0;

	switch (side) {
	case 0:
		xx = 1;
		break;
	case 1:
		yy = 1;
		break;
	case 2:
		xx = -1;
		break;
	case 3:
		yy = -1;
		break;
	}
}
