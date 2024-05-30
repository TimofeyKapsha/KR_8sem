#pragma once

#ifndef HERO_H
#define HERO_H

#include "Maze.h" // ����������� ���������
#include "Hero.h"

struct Point // ���������� ��������� ��� �������� �������� ��������� ����� 
{
	int x; // ������� ���������� �����
	int y;
	int direction; // ����������, ���������� �� ����������� ��������
};

class Hero : public Mazecreate // ���������� ������-���������� �����
{
public:
	Point point; // �������� ���������� ���������

	Hero(int i, int j) // 
	{
		this->point.x = j;
		this->point.y = i;
		this->point.direction = 0;
	}

	~Hero() {}

	bool way(int**, int, int); // ���������� ������, ������� ���� ����� �� ���������

};

#endif