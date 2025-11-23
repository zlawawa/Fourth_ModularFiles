#ifndef H_H
#define H_H

#include <vector>
#include <string>

void FillKeyboard(std::vector<std::vector<int>> &matrix);
void FillRandom(std::vector<std::vector<int>> &matrix, int n, int m);
void FillOutTFiles(std::vector<std::vector<int>> &matrix, int &n, int &m);
// void ClearMatrix(std::vector<std::vector<int>> &matrix);

int taskMatrix28(std::vector<std::vector<int>> &matrix);
int taskMatrix55();
int taskDArray6();
int taskDArray16();

#endif