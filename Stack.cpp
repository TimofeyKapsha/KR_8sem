#include <vector>
#include "Stack.h" // подключение библиотек
#include "Hero.h"
#include <iostream>

using namespace std;


void Stack::push(Point point) // реализация метода занесения элемента в стек
{
    elements.push_back(point); // занесение элемента в стек
}

void Stack::pop() // реализация метода извлечение элемента из стека
{
    if (is_empty()) // проверка стека на наличие в нём элементов
    {
        cout << "Стек пустой\n";
        return;
    }
    
    elements.pop_back(); // извлечение элемента из стека
}

Point Stack::peek() // реализация метода просмотра верхнего элемента стека
{
    if (is_empty()) // проверка стека на наличие в нём элементов
    {
        cout << "Стек пустой\n";
        Point null; // объявление временной переменной, возвращающей отрицательные значения координат и направления движения, что символизирует отсутствие элементов в стека
        null.x = -1;
        null.y = -1;
        null.direction = -1;
        return null;
    }
    return elements.back();
}


bool Stack::is_empty() // реализация метода проверки стека на пустоту
{
   
    return elements.empty();
}