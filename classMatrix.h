#pragma once

#include <iostream>
#include <vector>

using namespace std;

enum alert {Invalidvalue = -1};

class classMatrix
{
private:

	vector <vector <float>>  _matrix; // �������
	unsigned _n; // ���������� �����
	unsigned _m; // ���������� ��������

public:
	classMatrix(); //�����������
	classMatrix(unsigned i, unsigned j); // ����������� ixj �����������
	void setN(unsigned n); //setter ������
	void setM(unsigned m); //setter �������
	void setNxM(unsigned n, unsigned m); // setter ������ + �������
	unsigned getM() const; //getter ��������
	unsigned getN() const; //getter �����
	float determN1(); //������������ ��� ������� 1�1
	float determN2(); //������������ ��� ������� 2�2
	float determN3(); //������������ ��� ������� 3�3
	float cellAccess(unsigned i, unsigned j); //������ � ���������� ��������
	void cellChange(float value, unsigned i, unsigned j);
	void allMatrixOneValue(float value); //���������� ���� ������� 1 ����.
	void randomMatrix(); //���������� ������� ���������� �������
	classMatrix operator +(const classMatrix& data) const; //�������� �������� ������ 
	classMatrix operator -(const classMatrix& data) const; //�������� ��������� ������
	classMatrix operator *(float value) const; //�������� ��������� ������� �� �����
	vector <vector <float> > getMyMatrix(); // ���������� �������
	void printMatrix(classMatrix a); //����� �������

};

