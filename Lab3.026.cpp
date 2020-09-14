#include<bits/stdc++.h>
using namespace std;
class Matrix
{
	int** data= nullptr;
	int m;
	int n;
public:
	Matrix()
	{
		cout << "default";
	}

	Matrix operator*(const Matrix& other) const
	{

    //cout<<endl<<"Multiply"<<endl;
    //this->print();
    //cout<<"\n*\n";
    //other.print();
		Matrix tmp(m, other.n);
		
		tmp.m = this->m;
		tmp.n = other.n;
		if (this->n == other.m)
			for (int i = 0; i < this->m; i++)
			{
				for (int k = 0; k < this->n; k++)
				{
					for (int j = 0; j < tmp.n; j++)
					{
						tmp.data[i][k] = this->data[i][j] * other.data[j][k];
					}
				}
			}
      //cout<<"\n=\n";
  		//tmp.print();
      return tmp;
	}

	Matrix(int m, int n) :m(m), n(n)
	{
		alloc();
	}

	Matrix(const Matrix& other): m(other.m),n(other.n)
	{
		alloc();
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				this->data[i][j] = other.data[i][j];
			}
		}
	}

	void print() const
	{
    cout<<endl;
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cout << setw(3)<< this->data[i][j] << " ";
			}
			cout << endl << endl;
		}
	}

	void set_mn(int m,int n)
	{
		this->m = m;
		this->n = n;
	}
	void alloc()
	{
		this->data = new int* [m];
		for (int i = 0; i < m; ++i)
		{
			this->data[i] = new int[n];
		}
	}

	void randomize()
	{
		for (auto i = 0; i < m; ++i)
		{
			for (auto j = 0; j < n; ++j)
			{
				data[i][j] = 1 + rand() % 10;
			}
		}
	}
	
	void free()
	{
		for (int i = 0; i < m; ++i)
		{
			delete data[i];
		}
		delete data;
	}

	friend Matrix& operator --(Matrix& x);

	~Matrix()
	{
		free();
	}
};




Matrix& operator --(Matrix& x)//prefix
{
	for (int i = 0; i < x.m; ++i)
	{
		for (int j = 0; j < x.n; ++j)
		{
			--x.data[i][j];
		}
	}
	return x;
}

auto main(void)->int
{
  Matrix obj;
	srand(time(NULL));
	Matrix a(5, 6);
	a.randomize();
	a.print();
  vector<Matrix> g;
	auto b(a);
	Matrix c(6,5);
  Matrix v(1,1);
	c.randomize();
  c.print();
	--c;
	c.print();
	auto x = a * c;
  g.emplace_back(a);
  g.emplace_back(b);
  g.emplace_back(c);
	x.print();
  for(auto i: g)
  {
    i.print();
  }
	
	return 0;
}
