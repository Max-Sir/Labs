#include "Matrix.h"
class Matrix
{
public:
	Matrix(const int **m,int rows,int cols)
	{
		Equality_to_Not_object(m, rows, cols);
	}
	Matrix()
	{

	}
	Matrix(const Matrix& other)
		:m(other.m),rows(other.rows),cols(other.cols)
	{
		this->m = new int* [rows];
		for (int i = 0; i < rows; i++)
		{
			m[i] = new int[cols];
		}
	}
	
	void Equality_to_Not_object(const int** m, int rows, int cols)
	{
		Allocate(rows, cols);
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				this->m[i][j] = m[i][j];
			}
		}
	}
	
	void Allocate()
	{
		this->m = new int* [this->rows];
		for (int i = 0; i < this->rows; i++)
		{
			m[i] = new int[this->cols];
		}
	}

	void Allocate(int rows, int cols)
	{
		this->m = new int* [rows];
		for (int i = 0; i < rows; i++)
		{
			m[i] = new int[cols];
		}
	}

	Matrix operator=(const Matrix& other)
	{
		this->m = m;
		this->rows = other.rows;
		this->cols = other.cols;
	}

	//void Matrix_Multipication(T** a, T** b, T** c, int m, int _k, int n)
	//{
	//	for (int i = 0; i < m; i++)
	//	{
	//		for (int k = 0; k < _k; k++)
	//		{
	//			for (int j = 0; j < n; j++)
	//				c[i][k] += a[i][j] * b[j][k];
	//		}
	//	}
	//}

	Matrix operator*(const Matrix& other)
	{
		Matrix tmp;
		tmp.rows = this->rows;
		tmp.cols = other.cols;
		if(this->cols==other.rows)
		for (int i = 0; i < this->rows; i++)
		{
			for (int k = 0; k < this->cols; k++)
			{
				for (int j = 0; j < tmp.cols; j++)
				{
					tmp.m[i][k] = this->m[i][j] * other.m[j][k];
				}
			}
		}
	}
	~Matrix()
	{
		for (int i = 0; i < this->rows; i++)
		{
			delete m[i];
		}
		delete m;
	}
private:
	int** m;
	int rows;//i
	int cols;//j
};