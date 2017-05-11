//6603 ·Î¶Ç DFS,Backtrack

#include<iostream>

using namespace std;


int data1[14];
int visit[14];
int n;

void backtrack(int, int);

int main(void)
{
	int i;
	while (1) {
		cin >> n;
		if (n == 0)
			return 0;
		else
		{
			for (i = 1; i <= n; i++)
			{
				cin >> data1[i];
				visit[i] = 0;
			}
			for (i = 1; i <= n - 5; i++) {
				backtrack(i, 1);
			}
		}
		printf("\n");
	}
	return 0;
}
void backtrack(int i, int depth)
{
	int j;
	visit[i] = 1;
	if (depth >= 6) {
		for (j = 1; j <= n; j++) {
			if (visit[j] == 1)
				printf("%d ", data1[j]);
		}
		printf("\n");
		return;
	}
	for (j = i; j <= n; j++) {
		if (j>i) {
			backtrack(j, depth + 1);
			visit[j] = 0;
		}
	}
	visit[i] = 0;
}