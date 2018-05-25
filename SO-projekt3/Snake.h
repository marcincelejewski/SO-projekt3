#pragma once
#include <mutex>
#include "Head.h"
class Snake
{
public:
	Snake();
	~Snake();
	Snake(std::shared_ptr<Head> const &h, int old_x, int old_y, int **board);//pozycja startowa 
	void operator()() const;
	std::shared_ptr<Head> head;
	int id, old_x, old_y;//id-ciala wspolrzedne poprzednika glowy
	static std::mutex mutex;
};

