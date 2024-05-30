﻿#include <iostream>
#include "Maze.h"
#include "Stack.h"
#include <ctime>
#include "Hero.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus"); // русификация текста

	cout << "Здравствуй, дорогой пользователь! Эта программа реализует алгоритм поиска пути из лабиринта с использованием динамической структуры данных - стек. " <<
		"Программа состоит из 3-х классов и 1 структуры:\n1) Класс Stack (Stack.h, Stack.cpp): реализует стек на базе вектора для нахождения выхода из лабиринта.\n" <<
		"2) Класс Maze (Maze.h, Maze.cpp): в зависимости от количества строк и столбцов рандомно генерирует лабиринт с точкой входа и точкой выхода.\n" <<
		"3) Класс Hero (Hero.h, Hero.cpp): непосредственно алгоритм поиска выхода из лабиринта с использованием раннее описанных классов.\n" <<
		"4) Структура Point (объявлена в Hero.h): вспомогательная структура для хранения текущего положения героя.\n\n\n" <<
		"Примечание: особенности программной реализации не предполагают ввода чётного количества строк и столбцов!!! Учитывайте это при вводе данных.\n\n\n" <<
		"После ввода корректного количества строк и столбцов и вывода лабиринта с начальным, текущим и конечным положением используйте любую клавишу для перемещения.\n\n\n" <<
		"Приятного использования ;)\n\n\n";

	Hero hero_obj(1, 1); // создание объекта класса герой
	Mazecreate maze_obj; // создание объекта класса лабиринт

	srand((unsigned)time(NULL));

	int rows = 0, colls = 0; // инициализация переменных, в которых будет храниться число строк и число столбцов   

	cout << "Введите количество строк и столбцов лабиринта (при вводе необходимо учесть, что для работы программы допустимы лишь нечётные количества строк и столбцов:\n";

	do
	{
		cout << "\nВведите количество строк: ";
		cin >> rows;
		cout << "\nВведите количество столбцов: ";
		cin >> colls;
		cout << '\n';

		if (maze_obj.check_input(rows, colls) != 0)
		{
			cout << "Вы ввели чётное количество строк или столбцов! Пожалуйста введите нечётное:\n";
		}
	} while (maze_obj.check_input(rows, colls) != 0);

	int** maze = new int* [rows]; // объявление динамического массива, хранящего лабиринт

	for (int i = 0; i < rows; i++) // инициализация массива, хранящего лабиринт
	{
		maze[i] = new int[colls];
	}

	hero_obj.way(maze, rows, colls); // вызов метода поиска пути в лабиринте
	hero_obj.clear_memory(maze, rows); // вызов метода, очищающего динамический массив

	system("pause");

	return 0;
}