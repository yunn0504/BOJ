/*

#include<iostream>

using namespace std;

int data1[1001][1001];
int table1[1001][1001];

int travel(int, int);

int main(void)
{
	int n, m;
	int i, j;
	cin >> n >> m;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			cin >> data1[i][j];
		}
	}
	table1[1][1] = data1[1][1];
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			if (table1[i][j] + data1[i + 1][j] > table1[i + 1][j])
			{
				table1[i + 1][j] = table1[i][j] + data1[i + 1][j];
			}
			if (table1[i][j + 1] < table1[i][j] + data1[i][j + 1])
			{
				table1[i][j + 1] = table1[i][j] + data1[i][j + 1];
			}
			if (table1[i + 1][j + 1] < table1[i][j] + data1[i + 1][j + 1])
			{
				table1[i + 1][j + 1] = table1[i][j] + data1[i + 1][j + 1];
			}
		}
	}
	cout << table1[n][m] << endl;
	return 0;
}
*/