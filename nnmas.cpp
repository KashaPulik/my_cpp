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
    int g = 0;
    while(n >= 0) {
        for(int i = 0; i < size - n; i++) {
            for(int j = n; j < size; j++) {
                arr[g] = matrix[i][j];
                ++g;
            }
        }
        --n;
    }
    return arr;
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
    int size = 5;
    int** matrix = create_matrix(size, 10);
    print_matrix(matrix, size);
    int* arr = new int[size * size];
    a_init(matrix, arr, size);
    print_arr(arr, 20);
}