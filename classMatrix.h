#pragma once

#include <iostream>
#include <vector>

using namespace std;

enum alert {Invalidvalue = -1};

class classMatrix
{
private:

	vector <vector <float>>  _matrix; // Матрица
	unsigned _n; // Количество строк
	unsigned _m; // Количество столбцов

public:
	classMatrix(); //конструктор
	classMatrix(unsigned i, unsigned j); // конструктор ixj размерности
	void setN(unsigned n); //setter строки
	void setM(unsigned m); //setter столбцы
	void setNxM(unsigned n, unsigned m); // setter строки + столбцы
	unsigned getM() const; //getter столбцов
	unsigned getN() const; //getter строк
	float determN1(); //определитель для матрицы 1х1
	float determN2(); //определитель для матрицы 2х2
	float determN3(); //определитель для матрицы 3х3
	float cellAccess(unsigned i, unsigned j); //доступ к отдельному элементу
	void cellChange(float value, unsigned i, unsigned j);
	void allMatrixOneValue(float value); //заполнение всей матрицы 1 знач.
	void randomMatrix(); //заполнение матрицы случайными числами
	classMatrix operator +(const classMatrix& data) const; //оператор сложения матриц 
	classMatrix operator -(const classMatrix& data) const; //оператор вычитания матриц
	classMatrix operator *(float value) const; //оператор умножения матрицы на число
	vector <vector <float> > getMyMatrix(); // Возвращает матрицу
	void printMatrix(classMatrix a); //Вывод матрицы

};

