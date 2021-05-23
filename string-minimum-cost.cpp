#include <iostream>
#include <string>
using namespace std;

string alphabet = "abcdefghijklmnopqrstuvwxyz";
int num(char A);
bool prov(int number, int**& A, int k);
char newl(int number, int** A, int k);
bool full(int**& A, int k);
void empty(int** A, int k);

int main()
{
	int n, k;
	cout << "Enter n and k: ";
	cin >> n >> k;
	
	string res = "a";
	int t = 0;

	int ** A = (int**)new int[k];
	for (int i = 0; i < k; i++)
	{
		A[i] = (int*) new int[k];
		for (int j = 0; j < k; j++)
			A[i][j] = 0;
	}
	while (res.length() < n)
	{
		int last = res.length() - 1;
		if (prov(num(res[last]), A, k))
		{
			res += newl(num(res[last]), A, k);
			if (!prov(num(res[last]), A, k))
			{
				A[k-1][t] = 1;
				t++;
			}
		}
		else
		{
			if (!full(A, k))
			{
				res[last] = newl(num(res[last]) + 1, A, k);
				A[num(res[last])][num(res[last])] = 0;
			}
			else
			{
				empty(A, k);
				t = 0;
			}
		}
	}
	cout << res << endl;
}

bool prov(int number, int**& A, int k)
{
	bool flag = false;
	for (int i = 0; i < k; i++)
		if (A[number][i] == 0)
			flag = true;
	return flag;
}

char newl(int number, int** A, int k)
{
	for (int i = 0; i < k; i++)
		if (A[number][i] == 0)
		{
			A[number][i] = 1;
			return alphabet[i];
		}
}

bool full(int**& A, int k)
{
	bool flag = true;
	for (int i = 0; i < k; i++)
		for (int j = 0; j < k; j++)
			if (A[i][j] == 0)
				flag = false;
	return flag;
}

void empty(int** A, int k)
{
	for (int i = 0; i < k; i++)
		for (int j = 0; j < k; j++)
			A[i][j] = 0;
}


int num(char A)
{
	for (char i = 'a'; i <= 'z'; i++)
		if (A == i) return ((int)i % 96 - 1);
}
