//1260 DFS,BFS

#include<iostream>
#include<fstream>
#include<string>
#include<queue>
#include<stack>

using namespace std;

void DFS(int, int);
void BFS(int, int);
int check(int);
void init(int);

int graph[1001][1001];
int visit[1001];
int find[1001];
stack<int> stack1;
queue<int> queue1;

int main()
{
	int n, m, v;
	int i, j;
	int x, y;
	ifstream f;
	f.open("input2.txt");

	cin >> n >> m >> v;
	for (i = 1; i <= m; i++)
	{
		cin >> x >> y;
		graph[x][y] = graph[y][x] = 1;
	}
	/*for (i = 1; i <= n; i++) {
	for (j = 1; j <= n; j++) {
	cout << graph[i][j];
	}
	cout << endl;
	}*/
	DFS(v, n);
	init(n);
	cout << endl;
	BFS(v, n);
}
void DFS(int v, int n)
{
	int i;
	cout << v << " ";
	visit[v] = 1;
	for (i = 1; i <= n; i++) {
		if (graph[v][i] == 1 && visit[i] == 0)
			DFS(i, n);
	}
	if (check(n)) return;
}
void BFS(int v, int n)
{
	int i;
	visit[v] = 1;
	queue1.push(v);
	while (!queue1.empty()) {
		v = queue1.front();
		queue1.pop();
		for (i = 1; i <= n; i++) {
			if (graph[v][i] == 1 && visit[i] == 0) {
				queue1.push(i);
				visit[i] = 1;
			}
		}
		visit[v] = 2;
		cout << v << " ";
	}
}
int check(int n)
{
	int i;
	for (i = 1; i <= n; i++) {
		if (visit[i] == 0)
			return 0;
	}
	return 1;
}
void init(int n)
{
	int i;
	for (i = 1; i <= n; i++) {
		visit[i] = 0;
	}
}