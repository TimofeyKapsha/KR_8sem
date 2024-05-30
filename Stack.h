#pragma once
#ifndef STACK_H
#define STACK_H

#include <vector>
#include "Stack.h" // подключение библиотек
#include "Hero.h"

using namespace std;

class Stack // объявление класса стек
{
public:

	vector<Point> elements; // массив для хранения элементов стека 

   
	void push(Point point); // метод для занесения элемента в стек
	
	void pop(); // метод для удаления элемента из стека

	Point peek(); // метод, возвращающий верхний элемент стека
	
	bool is_empty(); // метод проверки стека на пустоту (1 - пустой, 0 - не пустой)
};
#endif