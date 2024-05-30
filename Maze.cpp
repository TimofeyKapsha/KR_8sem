#include "Maze.h"
#include <ctime> // подключение библиотек
#include <cstdlib>
#include <iostream>

using namespace std;

bool Mazecreate::no_ways(int x, int y, int** maze, int rows, int colls) // реализация метода проверки наличия пути в лабиринте
{
    int way_counter = 0; // счётчик невозможных путей для движения

    if (x != 1) // проверка выхода за нижнюю границу столбцов
    {
        if (maze[y][x - 2] == 1)
        {
            way_counter++;
        }
    }
    else
    {
        way_counter++;
    }

    if (y != 1) // проверка выхода за нижнюю границу строк
    {
        if (maze[y - 2][x] == 1)
        {
            way_counter++;
        }
    }
    else
    {
        way_counter++;
    }

    if (x != colls - 2) // проверка выхода за верхнюю границу столбцов
    {
        if (maze[y][x + 2] == 1)
        {
            way_counter++;
        }
    }
    else
    {
        way_counter++;
    }

    if (y != rows - 2) // проверка выхода за верхнюю границу столбцов
    {
        if (maze[y + 2][x] == 1)
        {
            way_counter++;
        }
    }
    else
    {
        way_counter++;
    }

    if (way_counter == 4) // если двигаться некуда вернуть 1 иначе 0
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


void Mazecreate::mazemake(int** maze, int rows, int colls) // метод, реализующий лабиринт
{
    int x = 3, y = 3, key = 0, a = 0; // x,y - точка, от которой начинается формирования путей в лабиринте, key - переменная, отвечающая за изменение направления
                                      // a - временна переменная для задания условия выхода из цикла 
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < colls; j++) { // инициализация массива нулями
            maze[i][j] = 0;
        }
    }


    while (a < 10000) // цикл для "прорывания" путей в лабиринте
    {
        maze[y][x] = 1; a++; // начальная точка для "прорывания" путей
        while (true)
        {
            key = rand() % 4; // рандомное изменение направления "прорывания" путей
            switch (key) // условный оператор формирующий путь в направлении зависящего от значения key
            {
            case 0: // "прорывание" 2-х клеток вверх
                if (y != 1)
                {
                    if (maze[y - 2][x] == 0)
                    {
                        maze[y - 1][x] = 1;
                        maze[y - 2][x] = 1;
                        y -= 2;
                    }
                }
            case 1: // "прорывание" 2-х клеток вниз
                if (y != rows - 2)
                {
                    if (maze[y + 2][x] == 0)
                    {
                        maze[y + 1][x] = 1;
                        maze[y + 2][x] = 1;
                        y += 2;
                    }
                }
            case 2: // "прорывание" 2-х клеток влево
                if (x != 1)
                {
                    if (maze[y][x - 2] == 0)
                    {
                        maze[y][x - 1] = 1;
                        maze[y][x - 2] = 1;
                        x -= 2;
                    }
                }
            case 3: // "прорывание" 2-х клеток вправо
                if (x != colls - 2)
                {
                    if (maze[y][x + 2] == 0)
                    {
                        maze[y][x + 1] = 1;
                        maze[y][x + 2] = 1;
                        x += 2;
                    }
                }
            }

            if (no_ways(x, y, maze, rows, colls)) // если доступных путей нет, выход из цикла
            {
                break;
            }
        }

        if (no_ways(x, y, maze, rows, colls)) // если достигнут тупик, то перемещаемся в позицию, шде можно прорывать новые клетки
        {
            do
            {
                x = 2 * (rand() % ((colls - 1) / 2)) + 1;
                y = 2 * (rand() % ((rows - 1) / 2)) + 1;
            } while (maze[y][x] != 1);
        }
    }
}

int Mazecreate::create_range(int rows, int colls) // реализация метода, ограничивающую функцию rand()
{
    if (rows > colls)
    {
        return rows;
    }
    else
    {
        return colls;
    }
}

bool Mazecreate::check_out(int rows, int colls, int res) // реализация метода, проверяющего выход за допустимые границы функции rand()
{
    if (res >= rows || res >= colls)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void Mazecreate::start_point(int** maze, int rows, int colls) // реализация метода, задающего точку входа в лабиринт
{
    int temp = create_range(rows, colls); // переменная, хранящая результат выполнения метода create_range

    for (int i = 0; i < rows; i++) { // вложенный цикл для задания координат входа в лабиринт
        for (int j = 0; j < colls; j++) {

            start_x = rand() % (temp - 0 + 1);
            start_y = start_x;

            if (!check_out(rows, colls, start_x)) // проверка выполнения ограничений
            {
                continue;
            }

            if (maze[start_x][start_y] == 1) // проверка, что позиция входа не является стеной
            {
                maze[start_x][start_y] = 2; // присвоение точке входа в массиве лабиринт значения 2
                return;
            }
        }
    }
}

void Mazecreate::end_point(int** maze, int rows, int colls) // реализация метода, задающего точку выхода в лабиринт
{
    int temp = create_range(rows, colls); // переменная, хранящая результат выполнения метода create_range

    for (int i = 0; i < rows; i++) { // вложенный цикл для задания координат входа в лабиринт
        for (int j = 0; j < colls; j++) {

            end_x = rand() % (temp - 0 + 1);
            end_y = end_x;

            if (!check_out(rows, colls, end_x)) // проверка выполнения ограничений
            {
                continue;
            }

            if (maze[end_x][end_y] == 1) // проверка, что позиция выхода не является стеной
            {
                maze[end_x][end_y] = 3; // присвоение точке входа в массиве лабиринт значения 3
                return;
            }
        }
    }
}

void Mazecreate::visual(int** maze, int rows, int colls) // метод, реализующий вывод лабиринта в консоль 
{
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < colls; j++) {
            switch (maze[i][j]) // выбор текущего элемента лабиринта
            {
           // case 4: cout << "- "; break; 
            case 3: cout << "^ "; break; // случай 3 - вывод точки выхода из лабиринта
            case 2: cout << "* "; break; // случай 2 - вывод точки входа в лабиринт
            case 1: cout << "  "; break; // случай 1 - вывод клетки-прохода
            case 0: cout << "0 "; break; // случай 0 - вывод клетки-стены
            }
        }
        cout << '\n';
    }
}

bool Mazecreate::check_input(int rows, int colls) // метод проверки корректности входных данных
{
    if (rows % 2 != 0 || colls % 2 != 0) // если число столбцов или строк чётное вернуть 0 иначе вернуть 1
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
void Mazecreate::clear_memory(int** maze, int rows) // метод, реализующий очистку памяти динамического массива
{
    for (int i = 0; i < rows; i++)
    {
        delete[] maze[i];
    }

    delete[] maze;
}