// Lab_06_1_rec.cpp
// < Клак Соломія >
// Лабораторна робота № 6.1
// Варіант 14

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int* p, const int size, const int Low, const int High, int i)
{
    p[i] = Low + rand() % (High - Low + 1);
    if (i < size - 1)
        Create(p, size, Low, High, i + 1);
}

void Print(int* p, const int size, int i)
{
    cout << setw(4) << p[i];
    if (i < size - 1)
        Print(p, size, i + 1);
    else
        cout << endl;
}

int Count(int* p, const int size, int i)
{
    if (i < size)
    {
        int k = (!(p[i] % 2 == 0 && i % 13 == 0)) ? 1 : 0;
        return k + Count(p, size, i + 1);
    }
    else
    {
        return 0;
    }
}

int Sum(int* p, const int size, int i)
{
    if (i < size)
    {
        int s = (!(p[i] % 2 == 0 && i % 13 == 0)) ? p[i] : 0;
        return s + Sum(p, size, i + 1);
    }
    else
    {
        return 0;
    }
}

void Zero(int* p, const int size, int i)
{
    if (i < size)
    {
        if (!(p[i] % 2 == 0 && i % 13 == 0))
            p[i] = 0;
        Zero(p, size, i + 1);
    }
}

int main()
{
    srand((unsigned)time(NULL)); 

    const int n = 25;            
    int p[n];

    const int Low = 15;         
    const int High = 94;

    Create(p, n, Low, High, 0);
    cout << "p  = ";
    Print(p, n, 0);

    cout << "Count = " << Count(p, n, 0) << endl;
    cout << "Sum   = " << Sum(p, n, 0) << endl;

    Zero(p, n, 0);
    cout << "p  = ";
    Print(p, n, 0);

    return 0;
}