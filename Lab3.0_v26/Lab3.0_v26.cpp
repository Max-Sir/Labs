#include <iostream>
#include <cmath>
#include <ctime>
#include <math.h>
#include <algorithm>

using namespace std;

template<class T>
class Matrix
{
	T** a;
	unsigned m;
	unsigned n;
public:
	void alloc(int m,int n)
	{
		a = new T * [m];
		for (int i = 0; i < m; ++i)
		{
			a[i] = new T[n];
		}
	}

	void free()
	{
		for (int i = 0; i < m; ++i)
		{
			delete a[i];
		}
		delete a;
	}

	Matrix(unsigned m, unsigned n)
	{
		alloc(m, n);
	}

	void set_a(int** a)
	{
		this->a = a;
	}
	
	~Matrix()
	{
		free();
	}
	Matrix operator*(const Matrix& other)
	{
		Matrix tmp(m,other.n);
		tmp.m = this->m;
		tmp.n = other.n;
		if (this->n == other.m)
			for (int i = 0; i < this->m; i++)
			{
				for (int k = 0; k < this->n; k++)
				{
					for (int j = 0; j < tmp.n; j++)
					{
						tmp.a[i][k] = this->a[i][j] * other.a[j][k];
					}
				}
			}
		return tmp;
	}
	
	Matrix(const Matrix& other)
	{
		this->m = other.m;
		this->n = other.n;
		alloc(other.m, other.n);
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				this->a[i][j] = other.a[i][j];
			}
		}
	}

	friend Matrix& operator --(Matrix& x);
	
	void set_m(unsigned m)
	{
		this->m = m;
	}

	void set_n(unsigned n)
	{
		this->n = n;
	}

	void print()
	{
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cout<<this->a[i][j]<<" ";
			}
			cout << endl;
		}
	}
	Matrix(int m, int n,int **a)
	{
		this->m = m;
		this->n = n;
		this->a = a;
	}
	
};

template<class T>
Matrix<T>& operator --(Matrix<T>&x)//prefix
{
	for (int i = 0; i < x.m; ++i)
	{
		for (int j = 0; j < x.n; ++j)
		{
			--x.a[i][j];
		}
	}
	return *x;
}

auto main(void)->int
{
	int m[][2] = { {2,6}, {5,68} };
	Matrix<int> a_matrix(5,6);
	return 0;
}