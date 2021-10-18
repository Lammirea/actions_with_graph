// lab_3_num_3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	int n1;
	cout << "Введите размерность матриц:" << endl;
	cin >> n1;
	//выделение памяти под матрицу
	int** m1 = new int* [n1];
	for (int i = 0; i < n1; ++i)
	{
		m1[i] = new int[n1];
	}
	//выделение памяти под матрицу
	int** m2 = new int* [n1];
	for (int i = 0; i < n1; ++i)
	{
		m2[i] = new int[n1];
	}
	//генерация неориентированного графа
	srand(time(NULL));
	for (int i = 0; i < n1; i++)
	{
		for (int j = 0; j < n1; j++)
		{
			m1[i][j] = rand() % 100;
		  if (i == j) {
			m1[i][j] = 0;
		  }
		  if (m1[i][j] >= 0 && m1[i][j] <= 30) {
			  m1[i][j] = 0;
		  }
		  else if(m1[i][j] >= 31 && m1[i][j]<100)
		  {
			  m1[i][j] = 1;
		  }
		}
	}
	for (int i = 0; i < n1; i++)
	{
		for (int j = 0; j < n1; j++)
		{
			cout << m1[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	srand(time(NULL));
	//генерация неориентированного графа
	for (int i = 0; i < n1; i++)
	{
		for (int j = 0; j < n1; j++)
		{
		  m2[i][j] = rand() % 100;
		  if (i == j) {
			m2[i][j] = 0;
		  }
		  if (m2[i][j] >= 0 && m2[i][j] <= 30) {
			  m2[i][j] = 0;
		  }
		  else if(m2[i][j] >= 31 && m2[i][j]<100)
		  {
			  m2[i][j] = 1;
		  }
		}
	}
	for (int i = 0; i < n1; i++)
	{
		for (int j = 0; j < n1; j++)
		{
			cout << m2[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	int** resM = new int* [n1];
	for (int i = 0; i < n1; ++i)
	{
		resM[i] = new int[n1];
	}
	//объединение матриц:
	/*for (int i = 0; i < n1; i++)
	{
		for (int j = 0; j < n1; j++)
		{
			resM[i][j] = m1[i][j] | m2[i][j];
			cout << resM[i][j]<<" ";
		}
		cout << endl;
	}*/
	cout << endl;
	//пересечение матриц:
	/*for (int i = 0; i < n1; i++)
	{
		for (int j = 0; j < n1; j++)
		{
			resM[i][j] = m1[i][j] & m2[i][j];
			cout << resM[i][j] << " ";
		}
		cout << endl;
	}*/
	//кольцевая сумма:
	/*for (int i = 0; i < n1; i++)
	{
		for (int j = 0; j < n1; j++)
		{
			resM[i][j] = 0;
			if (m1[i][j] != m2[i][j])
			{
				resM[i][j] = m1[i][j] | m2[i][j];
			}
			cout << resM[i][j] << " ";
		}
		cout << endl;
	}*/

	//освобождение памяти
	for (int i = 0; i < n1; ++i)
	{
		delete[] m1[i];
	}
	delete[] m1;
	for (int i = 0; i < n1; ++i)
	{
		delete[] m2[i];
	}
	delete[] m2;
	for (int i = 0; i < n1; ++i)
	{
		delete[] resM[i];
	}
	delete[] resM;

	return 0;
}

