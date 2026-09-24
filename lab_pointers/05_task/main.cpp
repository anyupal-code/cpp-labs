#include "matrix_utils.h"
#include <iostream>

int main() {
    int rows = 3, cols = 4;
    int** matrix = createMatrix(rows, cols);

    fillMatrix(matrix, rows, cols);
    std::cout << "Матрица " << rows << "x" << cols << ":\n";
    printMatrix(matrix, rows, cols);

    std::cout << "\nРесайз до 5x6:\n";
    resizeMatrix(matrix, rows, cols, 5, 6);
    printMatrix(matrix, rows, cols);

    freeMatrix(matrix, rows);
    matrix = nullptr;

    return 0;
}