//1992 ÄõµåÆ®¸®

#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int arr[65][65];
int testsame(int size, int p, int q, int r, int s);
void quadtree(int size, int p, int q, int r, int s);
int main(void)
{
	ifstream f;
	f.open("input.txt");
	int i, j, n;
	string s;
	cin >> n;
	for (i = 1; i <= n; i++) {
		cin >> s;
		for (j = 1; j <= n; j++) {
			arr[i][j] = s[j - 1] - 48;
			//cout << arr[i][j];
		}
		//cout << endl;
	}
	quadtree(n, 1, n, 1, n);
	cout << endl;
}
void quadtree(int size, int p, int q, int r, int s)
{
	if (size <= 0)
		return;
	//cout <<endl<< p << q << r << s << endl;
	if (testsame(size, p, q, r, s)) {
		cout << "(";
		quadtree(size / 2, p, (p + q) / 2, r, (r + s) / 2);
		quadtree(size / 2, p, (p + q) / 2, (r + s) / 2 + 1, s);
		quadtree(size / 2, (p + q) / 2 + 1, q, r, (r + s) / 2);
		quadtree(size / 2, (p + q) / 2 + 1, q, (r + s) / 2 + 1, s);
		cout << ")";
	}
	else
		cout << arr[p][r];
}
int testsame(int size, int p, int q, int r, int s)
{
	int i, j, temp;
	temp = arr[p][r];
	for (i = p; i <= q; i++) {
		for (j = r; j <= s; j++) {
			if (temp != arr[i][j]) {
				//cout << i << j;
				return 1;
			}
		}
	}
	return 0;
}