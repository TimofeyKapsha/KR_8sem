#include "Stack.h"
#include "Maze.h" // подключение библиотек
#include "Hero.h"
#include <iostream>

using namespace std;

bool Hero::way(int** maze, int rows, int colls) // метод поиска  выхода из лабиринта
{
	Stack stack_obj; // объявление экземпляра класса стек
	Mazecreate maze_obj; // объявление экземпляра класса лабиринт

	this->mazemake(maze, rows, colls); // обращение к наследованному методу создания лабиринта
	this->start_point(maze, rows, colls); // обращение к наследованному методу задания точки входа в лабиринт
	this->end_point(maze, rows, colls); // обращение к наследованному методу задания точки выхода из лабиринта
	this->visual(maze, rows, colls); // обращение к наследованному методу визуализации лабиринта

	this->point.x = this->start_x; // присвоение полю x структуры координаты x входа
	this->point.y = this->start_y; // присвоение полю y структуры координаты y входа
	stack_obj.push(this->point); // занесение в стек координат входа в лабиринт

	
	bool** map = new bool* [rows]; // объявления булевсеого массива размерности лабиринта где каждой клетке соответствует значение true - если путь есть и false - если его нет

	for (int i = 0; i < rows; i++)
	{
		map[i] = new bool[colls]; 
	}

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < colls; j++) { // инициализация массива значениями true
			map[i][j] = true;
		}
	}

	cout << '\n';

	int last_direction = -1; // инициализация еачального положения
	Point last_point = this->point; // экземпляр структуры, отвечающий за текущее перемещения героя
	while (!stack_obj.is_empty()) // цикл выполняется до тех пор, пока в стеке не останется ни одного элемента (пути не существует), либо пока не прервётся (путь найден)
	{
		system("pause"); // нажатием любой клавиши происходит движение героя по одному из направлений
		system("cls"); // очищает экран
		maze[last_point.y][last_point.x] = 1; // изменение координат героя в лабиринте
		maze[this->point.y][this->point.x] = 2;
		this->visual(maze, rows, colls); // визуализация лабиринта с текущим положением героя
		cout << "стартовое положение: " << "x: " << this->start_x << ' ' << "y: " << this->start_y << '\n';
		cout << "текущее положение: " << "x: " << this->point.x << ' ' << "y: " << this->point.y << ' ' << "текущее направление: " << this->point.direction << '\n';
		cout << "конечное положение: " << "x: " << this->end_x << ' ' << "y: " << this->end_y << '\n';

		if (this->point.x == this->end_x && this->point.y == this->end_y) // условие выхода из цикла (путь найден)
		{
			cout << "\n\n\nwin!!\n\n\n";
			return true;
		}

		if (last_direction == this->point.direction) this->point.direction++; // если направление не задано, задаём его

		for (int i = 0; i <= 4; i++) { // цикл до 4 (4 направления - вверх, вниз, влево, вправо)
			this->point.direction = i; // текущее направление
			if (this->point.direction == 0) // направление вверх
			{
				if (this->point.y - 1 >= 0 && maze[this->point.y - 1][this->point.x] != 0 && map[this->point.y - 1][this->point.x] != false)
				{ // если не вышли за границ лабиринта и после текущего шага нет стены и направление не было пройдено
					Point temp; // объявление временного экземпляра перемещения героя
					temp.x = this->point.x; // присвоение текущего положения героя с направлением
					temp.y = this->point.y - 1;
					temp.direction = this->point.direction;
					map[this->point.y - 1][this->point.x] = false; // метка того, что в данную клетку было совершено движение
					last_point = this->point; // последнее перемещение- текущее
					this->point = temp;
					stack_obj.push(temp); // занесение текущего положения в стек
					last_direction = this->point.direction;
					break;
					// Примечание: всё написанное ниже работает по аналогии
				}
			}
			else if (this->point.direction == 1) // направление влево
			{
				if (this->point.x - 1 >= 0 && maze[this->point.y][this->point.x - 1] != 0 && map[this->point.y][this->point.x - 1] != false)
				{
					Point temp;
					temp.x = this->point.x - 1;
					temp.y = this->point.y;
					temp.direction = this->point.direction;
					map[this->point.y][this->point.x - 1] = false;
					last_point = this->point;
					this->point = temp;
					stack_obj.push(temp);
					last_direction = this->point.direction;
					break;
				}
			}
			else if (this->point.direction == 2) // направление вниз
			{
				if (this->point.y + 1 >= 0 && maze[this->point.y + 1][this->point.x] != 0 && map[this->point.y + 1][this->point.x] != false)
				{
					Point temp;
					temp.x = this->point.x;
					temp.y = this->point.y + 1;
					temp.direction = this->point.direction;
					map[this->point.y + 1][this->point.x] = false;
					last_point = this->point;
					this->point = temp;
					stack_obj.push(temp);
					last_direction = this->point.direction;
					break;
				}
			}
			else if (this->point.direction == 3) // направление вправо
			{
				if (this->point.x + 1 >= 0 && maze[this->point.y][this->point.x + 1] != 0 && map[this->point.y][this->point.x + 1] != false)
				{
					Point temp;
					temp.x = this->point.x + 1;
					temp.y = this->point.y;
					temp.direction = this->point.direction;
					map[this->point.y][this->point.x + 1] = false;
					last_point = this->point;
					this->point = temp;
					stack_obj.push(temp);
					last_direction = this->point.direction;
					break;
				}
			}
			else // если по всем 4-м направлениям тупики или ранее посещённые клетки, то удаляется элемент из стека 
			{
				last_point = this->point;
				stack_obj.pop();
				this->point = stack_obj.peek();
			}
		}
	}
	return false;	
}