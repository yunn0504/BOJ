#include<cstdio>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

int backtrack(char maze[10][10], int n,int m);
bool tilt(int n);

int main(void)
{
	int n, m;
	char maze[10][10];
	char ma[10] = { 'a','b','c','d','e' };
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d %d", &n, &m);
	//printf("%p", maze);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%c", &maze[i][j]);
			if (maze[i][j] == '\n')
				scanf("%c", &maze[i][j]);
		}
	}
	backtrack(maze, n,m);
	return 0;
}

int backtrack(char maze[10][10], int n,int m)
{
	char temp;
	char maze2[10][10];

	int i, j;
	memcpy(maze2, maze, sizeof(maze2));
	for(i=1;i<=4;i++)
	{
		tilt(maze2, n,m,i);

	return 0;
}
bool tilt(char maze[10][10], int n)
{
	int i, j;
	while (1) {
		
	}
}