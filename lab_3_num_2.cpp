//номер 2 пункт 1:
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

// конвертируем матрицу смежности в список смежности
vector<vector<int>> convert(vector<vector<int>> a);
int main()
{
    setlocale(LC_ALL, "rus");
    int n;
    int x1 = 0, x2 = 0;
    cin >> n;
    int** matrix = new int* [n];
    for (int i = 0; i < n; ++i)
    {
        matrix[i] = new int[n];
    }

    std::cout << "Сгенерированная матрица смежности:" << endl;
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = rand() % 100;
            if (i == j)
            {
                matrix[i][j] = 0;
            }
            if (0 <= matrix[i][j] && matrix[i][j] <= 30) {
                matrix[i][j] = 0;
            }
            else if (matrix[i][j] >= 31 && matrix[i][j] <= 100)
            {
                matrix[i][j] = 1;
            }

        }

    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = matrix[j][i];
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << endl;
    }
    cout << endl;
    cout << "Отождествление вершин: " << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "Введите номера вершин (x1 < x2): " << endl;
    cin >> x1 >> x2;
    for (x1; x1 < n; x1++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[x1][j] = matrix[x1][j] | matrix[x2][j];
        }
        for (int i = 0; i < n; i++)
        {
            matrix[i][x1] = matrix[i][x1] | matrix[i][x2];
        }
    }

    //удаление вершины
    n--;
    for (x2; x2 < n; x2++) {
        for (int i = 0; i < n; i++) {
            matrix[i][x2] = matrix[i][x2 + 1];
            for (int j = 0; j < n; j++) {
                matrix[x2][j] = matrix[x2 + 1][j];
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }

    vector<vector<int>> a;
    a.resize(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i].push_back(matrix[i][j]);
        }

    }

    vector<vector<int>> AdjList = convert(a);
    cout << "Список смежности:" << endl;
    for (int i = 0; i < AdjList.size(); i++)
    {
        cout << i + 1;
        for (int j = 0; j < AdjList[i].size(); j++) {
            cout << " -> " << AdjList[i][j];
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < n; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
vector<vector<int>> convert(vector<vector<int>> a)
{
    vector<vector<int>> adjList(a.size());
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a[i].size(); j++)
        {
            if (a[i][j] == 1)
            {
                adjList[i].push_back(j + 1);
            }
        }
    }
    return adjList;
}
////////////////////////////////////////////////////////////////////////////////
//номер 2 пункт 2

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> convert(vector<vector<int>> a);
int main()
{
    setlocale(LC_ALL, "rus");
    int n;
    int x1 = 0, x2 = 0;
    cin >> n;
    int** matrix = new int* [n];
    for (int i = 0; i < n; ++i)
    {
        matrix[i] = new int[n];
    }

    std::cout << "Сгенерированная матрица смежности:" << endl;
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = rand() % 100;
            if (i == j)
            {
                matrix[i][j] = 0;
            }
            if (0 <= matrix[i][j] && matrix[i][j] <= 30) {
                matrix[i][j] = 0;
            }
            else if (matrix[i][j] >= 31 && matrix[i][j] <= 100)
            {
                matrix[i][j] = 1;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = matrix[j][i];
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << endl;
    }
    std::cout << endl;
    std::cout << "Стягивания ребра : " << endl;
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cin >> x1 >> x2;
    if (matrix[x1][x2] == 1 || matrix[x2][x1] == 1)
    {
        for (x1; x1 < n; x1++)
        {
            for (int j = 0; j < n; j++)
            {
                matrix[x1][j] = matrix[x1][j] | matrix[x2][j];
            }
            for (int i = 0; i < n; i++)
            {
                matrix[i][x1] = matrix[i][x1] | matrix[i][x2];
            }
            matrix[x1][x1] = 0;

        }

        n--;
        for (x2; x2 < n; x2++) {
            for (int i = 0; i < n; i++) {
                matrix[i][x2] = matrix[i][x2 + 1];
                for (int j = 0; j < n; j++) {
                    matrix[x2][j] = matrix[x2 + 1][j];
                }
            }
        }
    }
    else {
        cout << "Вершины не смежны!" << endl;
    }

    //вывод
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << endl;
    }
    vector<vector<int>> a;
    a.resize(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i].push_back(matrix[i][j]);
        }

    }

    vector<vector<int>> AdjList = convert(a);
    cout << "Список смежности:" << endl;
    for (int i = 0; i < AdjList.size(); i++)
    {
        cout << i + 1;
        for (int j = 0; j < AdjList[i].size(); j++) {
            cout << " -> " << AdjList[i][j];
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < n; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
vector<vector<int>> convert(vector<vector<int>> a)
{
    vector<vector<int>> adjList(a.size());
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a[i].size(); j++)
        {
            if (a[i][j] == 1)
            {
                adjList[i].push_back(j + 1);
            }
        }
    }
    return adjList;
}
/////////////////////////////////////////////////////////////////////////////////
//номер 2 пункт 3


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> convert(vector<vector<int>> a);
int main()
{
    setlocale(LC_ALL, "rus");
    int n;
    int x1 = 0, x2 = 0;
    cin >> n;
    int** matrix = new int* [n + 1];
    for (int i = 0; i < n + 1; ++i)
    {
        matrix[i] = new int[n + 1];
    }

    std::cout << "Сгенерированная матрица смежности:" << endl;
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = rand() % 100;
            if (i == j)
            {
                matrix[i][j] = 0;
            }
            if (0 <= matrix[i][j] && matrix[i][j] <= 30) {
                matrix[i][j] = 0;
            }
            else if (matrix[i][j] >= 31 && matrix[i][j] <= 100)
            {
                matrix[i][j] = 1;
            }

        }

    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = matrix[j][i];
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << endl;
    }
    std::cout << endl;
    std::cout << "Расщепления вершины: " << endl;
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cin >> x1;
    for (int i = 0; i < n; i++) {
        matrix[i][n] = matrix[i][x1];
        matrix[n][i] = matrix[x1][i];
        matrix[n][n] = 0;
        matrix[x1][n] = 1;
        matrix[n][x1] = 1;
    }
    n++;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    std::cout << endl;
    vector<vector<int>> a;
    a.resize(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i].push_back(matrix[i][j]);
        }

    }

    vector<vector<int>> AdjList = convert(a);
    cout << "Список смежности:" << endl;
    for (int i = 0; i < AdjList.size(); i++)
    {
        cout << i + 1;
        for (int j = 0; j < AdjList[i].size(); j++) {
            cout << " -> " << AdjList[i][j];
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < n + 1; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
    return 0;
}
vector<vector<int>> convert(vector<vector<int>> a)
{
    vector<vector<int>> adjList(a.size());
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a[i].size(); j++)
        {
            if (a[i][j] == 1)
            {
                adjList[i].push_back(j + 1);
            }
        }
    }
    return adjList;
}