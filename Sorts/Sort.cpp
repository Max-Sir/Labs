#include<stdio.h>
#include<conio.h>
#include<iostream>
#include <vector>
#include <time.h>
using namespace  std;

void swap_(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

void out(int * m, int size)
{
	for (int i = 0; i < size; i++)
		cout << m[i]<<' '; cout << "\b\n";
}

int s_len(char* str)
{
	int i = 0,n=0;
	while(str[i++]!='\0')
	{
		n++;
	}
	return n;
}

int a_to_i(char* str)
{
	int num=0;
	for(int i=0,len=s_len(str);i<s_len(str);i++)
	{
		num= 10*num+(str[i]-'0');
		len--;
	}
	return num;
}

int int_len(int x)
{
	int len = 0;
	while(x>0)
	{
		len++;
		x /= 10;
	}
	return len;
}

int count_10(int num)
{
	int c=1;
	for (int i = 0; i < int_len(num); i++)
	{
		c *= 10;
	}
	return c;
}

char * i_to_a(int num)
{
	int i = 0;
	int ct = int_len(num);
	int dec = 0,r=0;
	char* s=(char*)calloc(1,1);
		while (i < ct)
		{
			dec = count_10(num);
			r = num % dec;
			s[i++] = ((num-r)/dec)+'0';
			num -= (((num - r) / dec) + '0');
			s = (char*)realloc(s, sizeof(char) * i);
		}
		return s;
}

void bubble(int * m, int size)
{
	for(int i=0;i<size-1;i++)
		for(int j=size-1;j>i;j--)
		{
			if(m[j-1]>m[j])
			{
				swap_(m[j - 1], m[j]);
			}
			out(m, size);
		}
	
}
void paste(int* m,int size)
{
	for(int i=1;i<size;i++)
	{
		int j = i - 1;
		int tmp = m[i];
		while (j >= 0 && tmp < m[j])
			m[j-- + 1] = m[j]/*,out(m, size)*/;
		m[j+1] = tmp;
	/*	for (int i = 0; i < size; i++)
			cout << m[i]; cout << endl;*/
	}
}

void shaker(int * m,int size)
{
	int l = 0, r = size-1;
	do
	{
		for(int i=l;i<r;i++)
		{
			if (m[i] > m[i + 1])
			{
				std::swap(m[i], m[i + 1]);
				out(m, size);
			}
			out(m, size);
		}
		r--;
		for(int j=r;j>l;j--)
		{
			if (m[j-1] > m[j])
			{
				std::swap(m[j], m[j - 1]);
				out(m, size);
			}
			out(m, size);
		}
		out(m, size);
	} while (l < r);
}
void selection_sort(int * m, int size) {
	for (int i = 0; i < size - 1; i++) {
		int min = i;
		for (int j = i + 1; j < size; j++) {
			if (m[j] < m[min]) {
				min = j;
			}
		}

		if (min != i) {
			swap(m[i], m[min]);
		}
	}
}
void Shell(int *m,int size)
{
	int flag;
	for(int gap= size / 2;gap>0;gap/=2)
	{
		do
		{
			flag = 0;
			for(int i=0,j=gap;j<size;i++,j++)
				if(m[i]>m[j])
				{
					std::swap(m[i], m[j]);
					flag = 1; out(m, size);
				}out(m, size);
			
		}
		while (flag);
		out(m, size);
	}
	out(m, size);
}

int sum(int k,...)
{
	int s = 0;
	int* p = &k;
	*p++;
	//int* in = *((int*)p + 1);
	for(int i=0;i<k;i++)
	{
		s += *(p + i);
	}
	return s;//
}
//void ShellSort(int array[], int size)               // * ∆k = (b∆k−1)/2  ∆0 = N
//{
//	int step, i, j, tmp;
//
//	// Выбор шага
//	for (step = size / 2; step > 0; step /= 2)
//		// Перечисление элементов, которые сортируются на определённом шаге
//		for (i = step; i < size; i++)
//			// Перестановка элементов внутри подсписка, пока i-тый не будет отсортирован
//			for (j = i - step; j >= 0 && array[j] > array[j + step]; j -= step)
//			{
//				tmp = array[j];
//				array[j] = array[j + step];
//				array[j + step] = tmp;
//			}
//}

//int main()
//{
//	int m[] = {0,4,3,2,5,1};
//	bubble(m, 6);
//	//paste(m, 6);
//	//shaker(m, 7);
//	//selection_sort(m, 7);
//	/*Shell(m, 7);
//	cout << endl << endl;	
//	out(m, 7);*/
//	//cout << sum(4, 5, 5, 6, 8);
//	return 0;
//}
//int mmain()
//{
//	char c[]="0515125";
//	int x = 12345678;
//	cout << i_to_a(x);
//	free(i_to_a(x));
//}
int len(char* s)
{
	int l, i= l = 0;
	while (s[i++]!='\0')
	{
		l++;
	}
	return l;
}

void print(char* s)
{
	for (int i = 0; i < len(s); i++)
	{
		std::cout << s[i];
	}
	puts("\n");
}

void fun(char* s,char c)
{
	int n = len(s);
	for (int i = 0;i<len(s);i++)
	{
		if (s[i] == c)
		{
			for (int i1 = 0; i1 < len(s)-1; i1++)
			{
				s[i] = s[i + 1];
			}
			n--;
			s = (char*)realloc(s, n);
		}
			
	}
}

//int main()
//{
//	char* s = (char*)malloc(100 * sizeof(char));
//	for (int i = 0; i < 100; i++)
//	{
//		int po = 0 + rand() % 2;
//		;
//	}
//	print(s);
//	
//}

//Поменять 1 и 2 местами
int main()
{
	int i, i1, i2, j1, j2;
	char s[20], c;
	for (int i = 0; i < 20; i++)
	{
		std::cin >> s[i];
	}
	for (i = 0; i < 20; i++)
		if (!i || ((s[i - 1] == ' ') && (s[i] != ' ')))
		{
			i1 = i;
			while (s[i] != ' ') i++;
			i2 = i;
			break;
		}
	for (i; i < 20; i++)
		if (!i || ((s[i - 1] == ' ') && (s[i] != ' ')))
		{
			j1 = i;
			while (s[i] != ' ') i++;
			j2 = i;
			break;
		}
	for (i = i1; i < (i1 + j2-1) / 2; i++)
	{
		c = s[i];
		s[i] = s[i + j1];
		s[i + j1] = c;
	}
	printf("%s\n", s);
	return 0;
}