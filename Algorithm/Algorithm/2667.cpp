//2667 단지번호붙이기 그래프순회

#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<fstream>

using namespace std;

int map[26][26];
int visit[26][26];
int yi[4] = { -1,1,0,0 }; //상 하 좌 우
int xj[4] = { 0,0,-1,1 }; //상 하 좌 우

void DFS(int, int);
int count1 = 0;

int main(void)
{
	ifstream f;
	f.open("input.txt");
	int n;
	int i, j;
	int m=0;
	int group=0;
	vector<int> v1;
	char temp;

	cin >> n;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			cin >> temp;
			map[i][j] = temp - 48;
			//cout << map[i][j]<< " ";
			if (map[i][j])
				visit[i][j] = 0;
			else
				visit[i][j] = -1;
		}
		//cout << endl;
	}
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			if (visit[i][j] == 0) {
				DFS(i, j);
				group++;
				v1.push_back(count1);
				count1 = 0;
			}
		}
	}
	cout << group << endl;
	sort(v1.begin(), v1.end());
	for (i = 0; i < v1.size(); i++)
		cout << v1[i] << "\n";
	return 0;
}
void DFS(int i, int j)
{
	count1++;
	int k;
	visit[i][j] = 1;
	//cout << i << " " << j << endl;
	for (k = 0; k < 4; k++)
	{
		if (map[i + yi[k]][j + xj[k]] == 1 && visit[i + yi[k]][j + xj[k]] == 0) {
			DFS(i + yi[k], j + xj[k]);
		}
	}
}