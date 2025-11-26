#ifndef H_H
#define H_H

#include <vector>
#include <string>

void FillKeyboard(std::vector<std::vector<int>> &matrix);
void FillRandom(std::vector<std::vector<int>> &matrix, int n, int m);
void FillOutTFiles(std::vector<std::vector<int>> &matrix, int &n, int &m);

int taskMatrix28Console(std::vector<std::vector<int>> &matrix);
void taskMatrix28File(std::vector<std::vector<int>> &matrix);

int taskMatrix55(std::vector<std::vector<int>> &matrix);
void taskMatrix55File(std::vector<std::vector<int>> &matrix);

int taskDArray6(std::vector<std::vector<int>> &matrixA);
int taskDArray6File(std::vector<std::vector<int>> &matrixA);

int taskMatrix55();
int taskDArray6();
int taskDArray16();

#endif
