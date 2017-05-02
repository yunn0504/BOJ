//1520 내리막길 !!
#include<stdio.h>
#include<iostream>
#include<fstream>
using namespace std;

int maze[502][502];
int table[502][502];
int ax[4] = { 0,0,-1,1 }; //상 하 좌 우
int ay[4] = { -1,1,0,0 };
char at[4] = { 'l','r','u','d' };

void travel(int x,int y);

int main()
{
	ifstream f;
	f.open("input.txt");
	int m, n;
	int i, j;
	f >> m >>n;
	for (i = 0; i <= m+1; i++) {
		for (j = 0; j <= n+1; j++) {
			if (i == 0 || j == 0 || i == m + 1 || j == n + 1)
				maze[i][j] = 10001;
			else
			{
				f >> maze[i][j];
				table[i][j] = 0;
			}
			//cout << maze[i][j] << " ";
		}
		//cout << endl;
	}
	travel(1, 1);
	cout << table[m][n]<<endl;
}

void travel(int x, int y)
{
	int i;
	cout << x << " " << y <<" ";
	table[x][y]++;
	for (i = 0; i < 4; i++) {
		if (maze[x + ax[i]][y + ay[i]] < maze[x][y])
		{
			cout << at[i] << endl;
			//cout << maze[x + ax[i]][y + ay[i]] << " " << maze[x][y] << endl;
			travel(x + ax[i], y + ay[i]);
		}
	}
	return;
}