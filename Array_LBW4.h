#ifndef Array_LBW4_H
#define Array_LBW4_H

#include <iostream>
#include <vector>
#include "LBWork4.h"
#include <string>

void FillKeyboard(std::vector<std::vector<int>> &matrix);
void FillRandom(std::vector<std::vector<int>> &matrix, int n, int m);
void FillOutTFiles(std::vector<std::vector<int>> &matrix, int &n, int &m);

int Matrix1(std::vector<std::vector<int>> &matrix, int n, int m);
int Matrix2(std::vector<std::vector<int>> &matrix, int n, int m);

#endif