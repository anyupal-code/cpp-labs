#pragma once

void printValue(const int* ptr);          // через указатель на константу
void printValueRef(const int& value);     // через константную ссылку
void tryModify(const int* ptr);           // попытка изменить (нельзя)
void setValue(int* ptr, int newValue);    // обычный указатель — можно менять