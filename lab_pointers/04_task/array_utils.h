#pragma once

// 1. Меняет только элементы массива
void modifyElementsOnly(int* arr, int size);

// 2. Перевыделяет массив (меняет и указатель, и размер)
void reallocateArray(int*& arr, int& size);

// 3. «По значению» — копия указателя, массив тот же
void fakeByValue(int* arr, int size);