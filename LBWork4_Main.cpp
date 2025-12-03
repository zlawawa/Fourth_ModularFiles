#define _HAS_STD_BYTE 0
#define NOMINMAX
#define WIN32_LEAN_AND_MEAN 

#include <iostream>
#include <vector>
#include <string>
#include "Array_LBW4.h"
#include <windows.h>

using namespace std;

int ChooseMethod(){
    int choice;
    std::cout << "\nВыберите способ заполнения двумерного массива:\n";
    std::cout << "1. С клавиатуры; \n";
    std::cout << "2. Случайными числами; \n";
    std::cout << "3. Из файла; \n";
    std::cout << "0. Выход. \n";
    std::cout << "Ваш выбор? ";
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
    do {
        switch (Choice1) {  
            case 1: {
                FillKeyboard(matrix);
                break;
            } case 2: {
                int n, m;
                std::cout << "Введите размер массива n * m.\n";
                std::cout << "Введите количество строк: ";
                std::cin >> n;
                std::cout << "Введите количество столбцов: ";
                std::cin >> m;
                cin.ignore(1000, '\n');
                FillRandom(matrix, n, m);
                break;
            } case 3: {
                int n, m;
                FillOutTFiles(matrix, n, m);
                break;
            } case 0: {
                std::cout << "Выход из программы...\n";
                std::cout << "Работа завершена.\n";
                return 0;
            } default: {
                std::cout << "Вы неверно ввели данные.\n";
                return 1;
            }
        }
        do {
            Choice2 = ChooseTask();
            switch(Choice2){
                case 1: {
                    int n, m;
                    taskMatrix28Console(matrix);
                    taskMatrix28File(matrix);
                    break;
                } case 2: {
                    taskMatrix55(matrix);
                    taskMatrix55File(matrix);
                    break;
                } case 3: {
                    taskDArray6(matrix);
                    taskDArray6File(matrix);
                    break;
                } case 4: {
                    taskDArray16(matrix);
                    taskDArrey16File(matrix);
                    cat();
                    break;
                } case 0: {
                    std::cout << "Выход из программы...\n";
                    std::cout << "Работа завершена.\n";
                    return 0;
                } default: {
                    std::cout << "Ошибка выбора задачи! Выберите ещё раз...\n";
                    std::cout << "\n";
                    break;
                }
            }
        } while (Choice2 != 0);
    } while (true);
    return 0;
} 
