#include "stdafx.h"
#include "Board.h"



Board::~Board()
{
	for (int i = 0; i < v; i++) {
		delete[] board[i];
	}
	delete[] board;
}

Board::Board(int h, int v): h(h), v(v)
{
	board = new int*[v];
	for (int i = 0; i < v; i++) {
		board[i] = new int[h];
	}

	for (int i = 0; i < v; i++) {
		for (int j = 0; j < h; j++) {
			if (i == 0 || j == 0 || i==v-1 || j==h-1) {
				board[i][j] = -1;
				}
			else {
				board[i][j] = 0;
			}
		}
	}
}
