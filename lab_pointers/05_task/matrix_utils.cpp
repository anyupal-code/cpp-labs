#include "matrix_utils.h"
#include <iostream>
#include <algorithm>

int** createMatrix(int rows, int cols) {
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols]{};
    }
    return matrix;
}

void fillMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            matrix[i][j] = i * j;
}

void printMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << "\n";
    }
}

void freeMatrix(int** matrix, int rows) {
    if (!matrix) return;
    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void resizeMatrix(int**& matrix, int& rows, int& cols, int newRows, int newCols) {
    int** newMatrix = createMatrix(newRows, newCols);

    int copyRows = std::min(rows, newRows);
    int copyCols = std::min(cols, newCols);

    for (int i = 0; i < copyRows; ++i)
        for (int j = 0; j < copyCols; ++j)
            newMatrix[i][j] = matrix[i][j];

    freeMatrix(matrix, rows);

    matrix = newMatrix;
    rows = newRows;
    cols = newCols;
}