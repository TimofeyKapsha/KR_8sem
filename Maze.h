#pragma once

#ifndef MAZE_h
#define MAZE_h

class Mazecreate // объявление класса лабиринт
{
public:
    int start_x = 0, start_y = 0, end_x = 0, end_y = 0; // инициализация переменных, хранящих координаты входа и выхода из лабиринта
    bool check_input(int, int); // метод проверки на допустимые входные данные
    void mazemake(int**, int, int); // метод, формирующий случайным образом лабиринт
    void visual(int**, int, int); // медод для вывода лабиринта в консоль
    bool no_ways(int, int, int**, int, int); // метод для проверки тупиков в лабиринте
    bool check_out(int, int, int); // метод для правильного формирования ограничений на функцию rand()
    void start_point(int**, int, int); // метод, задающий рандомную точку входа в лабиринт
    void end_point(int**, int, int); // метод, задающий рандомную точку выхода из лабиринта
    int create_range(int, int); // метод для создания границ функции rand()
    void clear_memory(int**, int); // метод для очистки памяти динамического массива
};

#endif 