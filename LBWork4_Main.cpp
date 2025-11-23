#define _HAS_STD_BYTE 0
#define NOMINMAX
#define WIN32_LEAN_AND_MEAN 

#include <iostream>
#include <vector>
#include <string>
#include "LBWork4.h"
#include <windows.h> 

using namespace std;

int ChooseMethod(){
    int choice;
    std::cout << "Выберите способ зполнения двумерного массива:\n";
    std::cout << "1. С клавиатуры;       \n";
    std::cout << "2. Случайными числами; \n";
    std::cout << "3. Из файла;           \n";
    std::cout << "0. Выход.            \n";
    std:cout << "Ваш выбор? ";
    std::cin >> choice;
    std::cout << "\n";
    return choice;
}

int ChooseTask(){
    int choice;
    std::cout << "Выберите задачу: \n";
    std::cout << "1. Задача №1 - Matrix28; \n";
    std::cout << "2. Задача №2 - Matrix55;\n";
    std::cout << "3. Задача №3 - DArray6;\n";
    std::cout << "4. Задача №4 - DArray16;\n";
    std::cout << "0. Выход. \n";
    std::cout << "Ваш выбор? ";
    std::cin >> choice;
    std::cout << "\n";
    return choice;
}

int main() {
    SetConsoleOutputCP(65001);

    std::vector<vector<int>> matrix;
    int Choice1, Choice2;
    Choice1 = ChooseMethod();
    Choice2 = ChooseTask();
    //do{
    if (Choice1 == 0 || Choice2 == 0){
        std::cout << "Выход из программы...\n";
        std::cout << "Работа завершена.\n";
        return 0;
    }

    bool completed1 = false, completed2 = false;
    switch (Choice1) {  
        case 1: {
            FillKeyboard(matrix);
            completed1 = true;
            break;
        }case 2: {
            int n, m;
            std::cout << "Введите размер массива n * m.\n";
            std::cout << "Введите количество строк: ";
            std::cin >> n;
            std::cout << "Введите количество столбцов: ";
            std::cin >> m;
            cin.ignore(1000, '\n');

            FillRandom(matrix, n, m);
            completed1 = true;
            break;
        }case 3: {
            int n, m;
            FillOutTFiles(matrix, n, m);
            completed1 = true;
            break;
        }default: {
            std::cout << "Вы неверно ввели данные.\n";
            std::cout << "\n";
            return 1;
        }
    }
    if (!completed1) {
        std::cout << "Ошибка заполнения матрицы!\n";
        return 1;
    }

    switch(Choice2){
        case 1: {
            int n, m;
            taskMatrix28(matrix);
            completed2 = true;
            break;
        }case 2: {
            taskMatrix55();
            completed2 = true;
            break;
        }case 3: {
            taskDArray6();
            completed2 = true;
            break;
        }case 4: {
            taskDArray16();
            completed2 = true;
            break;
        }default: {
            std::cout << "Ошибка выбора задачи!\n";
            break;
        }
    }
    if (completed2) {
    std::cout << "Работа завершена.\n";
    }  
    //}while (!(Choice1 == 0 || Choice2 == 0));
    return 0;
} 