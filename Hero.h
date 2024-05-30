#pragma once

#ifndef HERO_H
#define HERO_H

#include "Maze.h" // подключение библиотек
#include "Hero.h"

struct Point // объ€вление структуры дл€ хранени€ текущего положени€ геро€ 
{
	int x; // текущие координаты геро€
	int y;
	int direction; // переменна€, отвечающа€ за направление движени€
};

class Hero : public Mazecreate // объ€вление класса-наследника герой
{
public:
	Point point; // создание экземпл€ра структуры

	Hero(int i, int j) // 
	{
		this->point.x = j;
		this->point.y = i;
		this->point.direction = 0;
	}

	~Hero() {}

	bool way(int**, int, int); // объ€вление метода, который ищет выход из лабиринта

};

#endif