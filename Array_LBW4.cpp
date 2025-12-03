#define _HAS_STD_BYTE 0
#define NOMINMAX
#include <iostream>
#include "Array_LBW4.h"
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
    matrix.resize(n);          
    for (int i = 0; i < n; i++) {
        matrix[i].resize(m);   
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
    matrix.resize(n);         
    for (int i = 0; i < n; i++) { matrix[i].resize(m); }
    int a, b;
    std::cout << "Введите диапазон рандомного ввода: ";
    std::cin >> a >> b;
    srand(time(0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrix[i][j] = rand() % (b - a + 1) + a;
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

int Matrix1(vector<vector<int>> &matrix, int n, int m) {
    std::cout << "\nИсходная матрица: \n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
    return 0;
}

int Matrix2(vector<vector<int>> &matrix, int n, int m) {
    std::cout << "Итоговая матрица: \n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
    return 0;
}
