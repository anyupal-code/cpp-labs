#pragma once

// Создаёт зубчатый массив rows x cols, все элементы = 0
int** createMatrix(int rows, int cols);

// Заполняет: matrix[i][j] = i * j
void fillMatrix(int** matrix, int rows, int cols);

// Печатает матрицу
void printMatrix(int** matrix, int rows, int cols);

// Освобождает всю память
void freeMatrix(int** matrix, int rows);

// Изменяет размер матрицы, сохраняя старые данные в левом верхнем углу
void resizeMatrix(int**& matrix, int& rows, int& cols, int newRows, int newCols);
