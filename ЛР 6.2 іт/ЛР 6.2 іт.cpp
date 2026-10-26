// ЛР 6.2 іт

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

void Create(int* a, const int size, const int Low, const int High);
void Print(int* a, const int size);
int  MaxOddIndex(int* a, const int size);
bool SwapLastWithMaxOdd(int* a, const int size);

int main()
{
    srand((unsigned)time(NULL));

    const int n = 10;
    int a[n];
    int Low = -20;
    int High = 20;

    Create(a, n, Low, High);
    cout << "First array:" << endl;
    Print(a, n);

    if (SwapLastWithMaxOdd(a, n))
    {
        cout << "Array after the swap:" << endl;
        Print(a, n);
    }
    else
        cout << "There are no odd elements; the array remains unchanged." << endl;

    return 0;
}

void Create(int* a, const int size, const int Low, const int High)
{
    for (int i = 0; i < size; i++)
        a[i] = Low + rand() % (High - Low + 1);
}

void Print(int* a, const int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(4) << a[i];
    cout << endl;
}

int MaxOddIndex(int* a, const int size)
{
    int maxIndex = -1;
    for (int i = 0; i < size; i++)
        if (a[i] % 2 != 0 && (maxIndex == -1 || a[i] > a[maxIndex]))
            maxIndex = i;
    return maxIndex;
}

bool SwapLastWithMaxOdd(int* a, const int size)
{
    int k = MaxOddIndex(a, size);
    if (k == -1)
        return false;
    int t = a[k];
    a[k] = a[size - 1];
    a[size - 1] = t;
    return true;
}