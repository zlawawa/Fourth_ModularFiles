#define _HAS_STD_BYTE 0
#define NOMINMAX
#include <iostream>
#include "LBWork4.h"
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

void FillKeyboard(vector<vector<int>> &matrix) {
    matrix.clear();
    int n, m;
    std::cout << "Введите размер массива n * m \n";
    std::cout << "Введите количество строк: ";
    std::cin >> n;
    std::cout << "Введите количество столбцов: ";
    std::cin >> m;
    matrix.resize(n);          // cоздаем n строк
    for (int i = 0; i < n; i++) {
        matrix[i].resize(m);   // в каждой строке создаем m столбцов
    }
    std::cout << "Введите элементы матрицы: \n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> matrix[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
}

void FillRandom(vector<vector<int>> &matrix, int n, int m) {
    matrix.clear();
    matrix.resize(n);          // cоздаем n строк
    for (int i = 0; i < n; i++) {
        matrix[i].resize(m);   // в каждой строке создаем m столбцов
    }
    srand(time(0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrix[i][j] = rand() % 10 - 0;
        }
    }
    std::cout << "\nМатрица заполнена случайными числами! \n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

void FillOutTFiles(vector<vector<int>> &matrix, int &n, int &m) {
    ifstream f1("LBWork4.txt", ios::in);
    if (f1.is_open()) {
        f1 >> n >> m;
        matrix.resize(n);
        for (int i = 0; i < n; i++){
            matrix[i].resize(m);
        }
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                f1 >> matrix[i][j];
            }
        }
        f1.close();
    }else{
        std::cout << "Error! \n";
        return;
    }
    std::cout << "Матрица заполнена числами из файла 'LBWork4.txt'!\n";
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

//Matrix28
int taskMatrix28Console(vector<vector<int>> &matrix) {
    std::cout << "=== Задача №1 - Matrix28 === \n";
    vector<int> MaxsM;
    int n = matrix.size();
    int m = matrix[0].size();

    for (int i = 0; i < m; i++){
        MaxsM.push_back(-100000);
    }
    //ищем максимум столбцов
    for (int j = 0; j < m; j++) { 
        for (int i = 0; i < n; i++) {
            if (matrix[i][j] > MaxsM[j]){
                MaxsM[j] = matrix[i][j];
            }
        }
    }
    int MinOfMax = MaxsM[0]; //минимальный среди максимальных значений
    for (int i = 1; i < m; i++) {
        if (MaxsM[i] < MinOfMax) {
            MinOfMax = MaxsM[i];
        }
    }
    std::cout << "Максимальные эл-ты столбцов: ";
    for (int i = 0; i < m; i++) {
        std::cout << MaxsM[i];
        if (i < m - 1) {
            std::cout << " ";
        }
    }
    std::cout << "\n";
    std::cout << "Минимальный элемент среди максимальных в столбце: " << MinOfMax << "\n";
    return MinOfMax;
}

void taskMatrix28File(vector<vector<int>> &matrix) {
    ofstream f2("LBW4Answers.txt", ios::out);
    vector<int> MaxsM;

    if (f2.is_open()) {
        int n = matrix.size();
        int m = matrix[0].size();
        for (int i = 0; i < m; i++) {
            MaxsM.push_back(-10000);
        }
        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n; i++) {
                if (matrix[i][j] > MaxsM[j]) {
                    MaxsM[j] = matrix[i][j];
                }
            }
        }
        int MinOfMax = MaxsM[0];
        for (int i = 0; i < m; i++) {
            if (MaxsM[i] < MinOfMax) {
                MinOfMax = MaxsM[i];
            }
        }
        f2 << "Максимальные эл-ты столбцов: ";
        for (int i = 0; i < m; i++) {
            f2 << MaxsM[i];
            if (i < m - 1) {
                f2 << " ";
            }
        }
        f2 << "\n";
        f2 << "Минимальный элемент среди максимальных в столбце: " << MinOfMax << "\n";
    }
    f2.close();
    std::cout << "Ответы на задачу записаны в файл 'LBW4Answers.txt'. \n";
    std::cout << "======= Конец задачи =======\n\n";
}



//Matrix55
int taskMatrix55(){
    std::cout << "Задача №2 - Matrix58. \n";
    // int n,m;
    // std::cout << "Введите размерность матрицы.\n";
    // std::cout << "Введите кол-во столбцов - четное число: \n";
    // std::cout << "Введите кол-во строк - четное число: \n";
    // std::cin >> n >> m;
    // if (m % 2 == 0 && n % 2 ==0){
    //     // дописать формирование матрицы
    //     //и поменять местами половины главной диагонали?
    // }else{
    //     std::cout << "Вы ввели неверные данные. Перезапустите программу и попробуйте ещё раз.\n";
    // }
    std::cout << "Конец задачи.\n";
    std::cout << "\n";
    return 0;
}

//DArray6
int taskDArray6(){
    std::cout << "3. Задача №3 - DArray6.\n";

    std::cout << "Конец задачи.\n";
    std::cout << "\n";
    return 0;
}

//DArray16
int taskDArray16(){
    std::cout << "4. Задача №4 - DArray16. \n";

    std::cout << "Конец задачи. \n";
    std::cout << "\n";
    return 0;
}
