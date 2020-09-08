#include<iostream>

using namespace std;

//void sort_second_diag(int** a, int _n)
//{
//	for (int i = 0; i < _n - 1; i++)
//	{
//		int min = i;
//		for (int j = i + 1,; j < _n && n>0; j++)
//			if (a[j] < a[min])
//				min = j;
//		if(i!=j)
//			swap(a[i],a[min])
//	}
//}

//void selection_sort(int* m, int size) {
//	for (int i = 0; i < size - 1; i++) {
//		int min = i;
//		for (int j = i + 1; j < size; j++) {
//			if (m[j] < m[min]) {
//				min = j;
//			}
//		}
//
//		if (min != i) {
//			swap(m[i], m[min]);
//		}
//	}
//}

int s_len(char* s)
{
	int n=0;
	while (n++ != '\0');
	return n;
}

void print(char* s)
{
	for (int i = 0; i < s_len(s); i++)
		printf("%c", s[i]);
	puts("\n");
}

char* input(char* s)
{
	s = (char*)realloc(s, (s_len(s) + 2) * sizeof(char));
	s[s_len(s)] = ':'; s[s_len(s) + 1] = ' ';
	print(s);
	char* str = (char*)malloc(100);
	int i = 0;
	do 
	{
		scanf_s("%c", &str[i]);
	} while (str[i++] != '\n');
	return str;
}

auto main() -> int
{
	char* s = (char*)malloc(100 * sizeof(char));
	s = input("Entrt");
}