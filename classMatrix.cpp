#include "classMatrix.h"
#include <vector>

using namespace std;

classMatrix::classMatrix()
{
}

classMatrix::classMatrix(unsigned i, unsigned j) {
	setN(i);
	setM(j);
	_matrix.resize(i);
	for (unsigned k = 0;k < i;k++)
	{
		_matrix[k].resize(j);
	}
}

float classMatrix::determN1() {
	if (_n == _m) {
		return	_matrix[0][0];
	}
}

float classMatrix::determN2() {
	if (_n == _m) {
		return _matrix[0][0] * _matrix[1][1] - _matrix[0][1] * _matrix[1][0];
	}
}

float classMatrix::determN3() {
	if (_n == _m){
		return _matrix[0][0] * (_matrix[1][1] * _matrix[2][2] - _matrix[1][2] * _matrix[2][1]) -
			   _matrix[0][1] * (_matrix[1][0] * _matrix[2][2] - _matrix[1][2] * _matrix[2][0]) +
			   _matrix[0][2] * (_matrix[1][0] * _matrix[2][1] - _matrix[1][1] * _matrix[2][0]);
	}
}

void classMatrix::setN(unsigned n)
{
	_n = n;
}

void classMatrix::setM(unsigned m)
{
	_m = m;
}

void classMatrix::setNxM(unsigned n, unsigned m)
{
	setN(n);
	setM(m);
}

unsigned classMatrix::getN() const {
	return _matrix.size();
}

unsigned classMatrix::getM() const {
	return _matrix[0].size();
	//return _m;
}

float classMatrix::cellAccess(unsigned i, unsigned j)
{	
	if ((i < _n) && (j < _m))
		return _matrix[i][j];
	else
 	 	return Invalidvalue;
}

void classMatrix::cellChange(float value, unsigned i, unsigned j)
{
	if ((i < _n) && (j < _m))
		_matrix[i][j] = value;
}

void classMatrix::allMatrixOneValue(float value)
{
	for (unsigned i = 0; i < _n; i++)
		for (unsigned j = 0; j < _m; j++)
			_matrix[i][j] = value;
}

void classMatrix::randomMatrix()
{
	for (unsigned i = 0; i < _n; i++)
		for (unsigned j = 0; j < _m; j++)
			_matrix[i][j] = rand() % 10;
}

classMatrix classMatrix::operator +(const classMatrix& data) const {
	if ((this->_n == data._n) && (this->_m == data._m))
	{
		unsigned n = _n;
		unsigned m = _m;
		classMatrix temp(n, m);
		for (unsigned i = 0;i < n;i++) {
			for (unsigned j = 0; j < m; j++) {
				temp._matrix[i][j] = _matrix[i][j] + data._matrix[i][j];
			}
		}
		return temp;
	}
}

classMatrix classMatrix::operator -(const classMatrix& data) const {
	if ((this->_n == data._n) && (this->_m == data._m))
	{
		unsigned n = _n;
		unsigned m = _m;
		classMatrix temp(n, m);
		for (unsigned i = 0;i < n;i++) {
			for (unsigned j = 0; j < m; j++) {
				temp._matrix[i][j] = _matrix[i][j] - data._matrix[i][j];
			}
		}
		return temp;
	}
}

classMatrix classMatrix::operator *(float value) const
{
	unsigned n = _n;
	unsigned m = _m;
	classMatrix temp(n, m);
	for (unsigned i = 0; i < n; i++)
		for (unsigned j = 0; j < m; j++)
			temp._matrix[i][j] = _matrix[i][j] * value;
	return temp;
}

vector <vector <float> > classMatrix::getMyMatrix() {
	return _matrix;
}

void classMatrix::printMatrix(classMatrix a)
{
	unsigned n = a.getN();
	unsigned m = a.getM();
	vector <vector <float> > myMatrix;
	myMatrix = a.getMyMatrix();
	for (unsigned i = 0; i < n; i++)
	{
		for (unsigned j = 0; j < m; j++)
		{
			cout << myMatrix[i][j] << "         ";
		}
		cout << endl;
	}
	cout << "-----------------------------------------------" << endl ;
}