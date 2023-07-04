#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;

int* genRandArray(int size, int MaxValue)
{
    int* arr = new int[size + 1];
    arr[0] = size;
    for(int i = 1; i <= size; i++)
        arr[i] = rand()%MaxValue;
    return arr;
}

void print(int* arr)
{
    cout << arr[0] << " : ";
    for(int i = 1; i <= arr[0]; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int** genRandMatrix(int size, int maxValue)
{
    int** matrix = new int*[size];
    for(int i = 0; i < size; i++)
        matrix[i] = genRandArray(rand()%10, maxValue);
    return matrix;
}

void printMatrix(int** matrix, int size)
{
    cout << size << endl;
    for(int i = 0; i < size; i++)
        print(matrix[i]);
}

int main()
{
    srand(time(0));
    int size = rand()%10;
    int maxValue = 100;
    int** matrix = genRandMatrix(size, maxValue);
    printMatrix(matrix, size);
}