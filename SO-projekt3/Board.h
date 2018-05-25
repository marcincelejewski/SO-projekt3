
#pragma once
class Board
{
public:
	~Board();
	Board(int h,int v);//-1 - bok planszy, 0 - puste pole
	const int h, v; //liczba wierszy(horizontal), liczba kolumn(vertical)
	int **board;
};

