#include<cstdio>
#include<queue>
#include<vector>

using namespace std;

int graph[1002][1002];
int visit[1002][1002];
int find1[1002][1002];
int nx[4] = { -1,1,0,0 }; //상 하 좌 우
int ny[4] = { 0,0,-1,1 };
int run = 0;
int count1 = 0;

typedef struct xy
{
	int x;
	int y;
}xy;

queue<xy> qu;
queue<xy> qu2;

int main()
{
#ifdef _DEBUG
	freopen("input2.txt", "rt", stdin);
#endif
	int n, m;
	int i, j;
	scanf("%d %d", &n, &m);
	for (i = 0; i <= m + 1; i++)
	{
		for (j = 0; j <= n + 1; j++)
		{
			if ((0 < i && i < m + 1) && (0 < j && j < n + 1))
			{
				scanf("%d", &graph[i][j]);
				if (graph[i][j] == 1) {
					xy temp;
					temp.x = i;
					temp.y = j;
					qu.push(temp);
					find1[i][j] = 1;
				}
			}
			else {
				graph[i][j] = -2;
			}
		}
	}
	while (1)
	{
		while (!qu.empty()) {
			xy temp;
			temp = qu.front();
			//printf("%d %d\n", temp.x, temp.y);
			for (int k = 0; k < 4; k++)
			{
				if ((graph[temp.x + nx[k]][temp.y + ny[k]] == 0) && (find1[temp.x + nx[k]][temp.y + ny[k]] == 0)) //안익은 사과면서 탐색안된 사과
				{
					xy temp2;
					temp2.x = temp.x + nx[k];
					temp2.y = temp.y + ny[k];
					find1[temp.x + nx[k]][temp.y + ny[k]] = 1;
					qu2.push(temp2);
					//printf("%d %d\n", temp2.x, temp2.y);
				}
			}
			qu.pop();
		}
		if (!qu2.empty()) {
			while (!qu2.empty()) {
				xy temp3;
				temp3 = qu2.front();
				qu2.pop();
				graph[temp3.x][temp3.y] = 1;
				qu.push(temp3);
			}
		}
		else {
			for (i = 1; i <= m + 1; i++)
				for (j = 1; j <= n + 1; j++)
					if (graph[i][j] == 0)
						count1 = -1;
			break;
		}
		count1++;
	}
	printf("%d\n", count1);
	return 0;
}