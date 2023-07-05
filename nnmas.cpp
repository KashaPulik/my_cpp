#include <iostream>
#include <stdlib.h>

using namespace std;

int** create_matrix(int size, int maxVal)
{
    int** matrix = new int*[size];
    for(int i = 0; i < size; i++)
        matrix[i] = new int[size];
    for(int i = 0; i < size; i++)
        for(int j = 0; j < size; j++)
            matrix[i][j] = rand()%maxVal;
    return matrix;
}

int* a_init(int** matrix, int* arr, int size)
{
    int n = size - 1;
    int i, j, g = 0;
    while (n >= 0) {
        i = 0;
        j = n--;
        while (j < size)
            arr[g++] = matrix[i++][j++];
    }
    n = 1;
    while (n < size) {
        j = 0;
        i = n++;
        while(i < size)
            arr[g++] = matrix[i++][j++];
    }
    return arr;
}

int* b_init(int** matrix, int* arr, int size)
{
    int n = 0;
    int i, j, g = 0;
    while (n < size) {
        j = 0;
        i = n++;
        while (i >= 0)
            arr[g++] = matrix[i--][j++];
    }
    n = 1;
    while (n < size) {
        i = size - 1;
        j = n++;
        while (j < size)
            arr[g++] = matrix[i--][j++];
    }
    return arr;
}

int* c_init(int** matrix, int* arr, int size)
{
    int center = size % 2 == 0 ? size / 2 - 1 : size / 2;
    int n = size - 1;
    int b = size - center;
    int g = 0;
    int i = center, j = center;
    while (g < size * size) {
        while (i > center)
            arr[g++] = matrix[i--][j];
        while (j < b)
            arr[g++] = matrix[i][j++];
        while (i < b)
            arr[g++] = matrix[i++][j];
        
    }
}

void print_matrix(int** matrix, int size)
{
    for(int i = 0; i < size; i++) {
        cout << endl;
        for(int j = 0; j < size; j++)
            cout << matrix[i][j] << " ";
    }
    cout << endl;
}

void print_arr(int* arr, int size)
{
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int size = 4;
    int** matrix = create_matrix(size, 10);
    print_matrix(matrix, size);
    int* arr = new int[size * size];
    b_init(matrix, arr, size);
    print_arr(arr, size * size);
}