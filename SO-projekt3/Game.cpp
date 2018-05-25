#include "stdafx.h"
#include "Game.h"
#include "Board.h"
#include "Head.h"
#include <cstdlib>
#include <ctime>

Game::Game(std::shared_ptr<Board> const &b, int snakes_num)
{
	//start
	initscr();
	start_color();
	curs_set(0);
	srand(time(NULL));

	init_pair(4, COLOR_WHITE, COLOR_WHITE);
	init_pair(5, COLOR_WHITE, COLOR_RED);
	init_pair(6, COLOR_WHITE, COLOR_GREEN);
	init_pair(7, COLOR_WHITE, COLOR_BLUE);
	init_pair(8, COLOR_WHITE, COLOR_YELLOW);
	this->snakes_num = snakes_num;
	board = b;	
	



	for (int i = 0; i < this->snakes_num; i++) {
		int div_h = (board->h / snakes_num )-1;
		int x = (std::rand() % div_h) + (i * div_h) ;
		int y  = (std::rand() % (board->v-2) + 1);
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
		snakes.emplace_back(new Snake(std::make_shared<Head>(i+5, x, y), x + xx, y + yy, this->board->board));
	}

	init_board();

	getch();
	endwin();
}


Game::~Game()
{
}


void Game::init_board()
{
	
	
	for (int i = 0; i < board->v; i++) {
		for (int j = 0; j < board->h; j++) {
			int k = board->board[i][j];
			switch(board->board[i][j]) {
			case -1:
				attron(COLOR_PAIR(4));
				mvprintw(i + 1, j * 2 + 1, "  ");
				break;
			case 5:
				attron(COLOR_PAIR(5));
				move(i + 1, j * 2 + 1);
				addch(ACS_CKBOARD);
				addch(ACS_CKBOARD);
				break;
			case 6:
				attron(COLOR_PAIR(6));
				move(i + 1, j * 2 + 1);
				addch(ACS_CKBOARD);
				addch(ACS_CKBOARD);
				break;
			case 7:
				attron(COLOR_PAIR(7));
				move(i + 1, j * 2 + 1);
				addch(ACS_CKBOARD);
				addch(ACS_CKBOARD);
				break;
			case 8:
				attron(COLOR_PAIR(8));
				move(i + 1, j * 2 + 1);
				addch(ACS_CKBOARD);
				addch(ACS_CKBOARD);
				break;
			case 105:
				attron(COLOR_PAIR(5));
				mvprintw(i + 1, j * 2 + 1, "  ");
				break;
			case 106:
				attron(COLOR_PAIR(6));
				mvprintw(i + 1, j * 2 + 1, "  ");
				break;
			case 107:
				attron(COLOR_PAIR(7));
				mvprintw(i + 1, j * 2 + 1, "  ");
				break;
			case 108:
				attron(COLOR_PAIR(8));
				mvprintw(i + 1, j * 2 + 1, "  ");
				break;
			}

		}
	}
	refresh();
}