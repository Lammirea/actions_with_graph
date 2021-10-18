// lab_3_num_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <ctime>

using namespace std;
int main()
{
    setlocale(LC_ALL, "rus");
    int n1=0, n2 = 0;
    cin >> n1>>n2;
    int** m1 = new int* [n1];
    for (int i = 0; i < n1; ++i) {
        m1[i] = new int[n1];
    }
    int** m2 = new int* [n2];
    for (int i = 0; i < n2; ++i) {
        m2[i] = new int[n2];
    }
    srand(time(NULL));
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n1; j++)
        {
            m1[i][j] = rand() % 100;
            if (i == j) {
                m1[i][j] = 0;
            }
            if (0 <= m1[i][j] && m1[i][j] <= 30) {
                m1[i][j] = 0;
            }
            else if (m1[i][j]>=31 && m1[i][j]<=100)
            {
                m1[i][j] = 1;
            }
        }
    }
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n1; j++)
        {
            m1[i][j] = m1[j][i];
            cout << m1[i][j]<<"\t";
        }
        cout << endl;
    }
    cout << endl;
    cout << "Список смежности для первой матрицы:" << endl;
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n1; j++)
        {
            if (m1[i][j]==1)
            {
                cout << i+1 << "-->" << j+1 << endl;
            }
        }
    }
    cout << endl;
    srand(time(NULL));
    for (int i = 0; i < n2; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            m2[i][j] = rand() % 100;
            if (i == j) {
                m2[i][j] = 0;
            }
            if (0 <= m2[i][j] && m2[i][j] <= 30) {
                m2[i][j] = 0;
            }
            else if (m2[i][j] >= 31 && m2[i][j] <= 100)
            {
                m2[i][j] = 1;
            }
        }
    }
    for (int i = 0; i < n2; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            m2[i][j] = m2[j][i];
            cout << m2[i][j] << "\t";
        }
        cout << endl;
    }
    cout << "Список смежности для второй матрицы:" << endl;
    for (int i = 0; i < n2; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            if (m2[i][j] == 1)
            {
                cout << i + 1 << "-->" << j + 1 << endl;
            }
        }
    }
    cout << endl;
    for (int i = 0; i < n1; ++i) {
        delete[] m1[i];
    }
    delete[] m1;
    for (int i = 0; i < n2; ++i) {
        delete[] m2[i];
    }
    delete[] m2;
    return 0;
}

