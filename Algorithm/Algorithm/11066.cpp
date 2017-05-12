//11066 파일합치기

#include<iostream>
#include<fstream>

using namespace std;
const int max = 2100000000;

int data1[501][501];
int data2[501][501];

int main()
{
	int t; //케이스수
	int k; //입력수
	int i, j,l;
	int i2;
	int min;
	ifstream f;
	f.open("input.txt");
	cin >> t;
	for (i2 = 1; i2 <= t; i2++) {
		cin >> k;
		for (i = 1; i <= k; i++) {
			cin >> data1[1][i];
			data2[1][i] = data1[1][i];
		}
		for (i = 2; i <= k; i++) {
			for (j = i; j <= k; j++) {
				data1[i][j] = data1[i - 1][j - 1] + data1[1][j];
				if (i == 2)
					data2[i][j] = data1[i][j];
			}
		}
		for (i = 3; i <= k; i++)
		{
			for (j = i; j <= k; j++)
			{
				data2[i - 1][j - 1] > data2[i - 1][j] ? min = data2[i - 1][j] : min = data2[i - 1][j - 1];
				if (i >= 4) {
					for (l = 2; l <= i - 2; l++)
					{
						if (data2[i - l][j - l] + data2[l][j] < min)
							min = data2[i - l][j - l] + data2[l][j];
					}
				}
				//cout << min << " ";
				data2[i][j] = min + data1[i][j];
				//cout << data2[i][j] << " ";
			}
			//cout << endl;
		}
		cout << data2[i - 1][j - 1] << endl;
	}
}