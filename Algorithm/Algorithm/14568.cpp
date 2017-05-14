//14568 사탕분배문제
//사탕은 1개이상씩 A는 사탕이 짝수개 C는 B보다 2개이상 많아야함
//3중루프로 맞는조건만 계산
#include<iostream>

using namespace std;

int data1[101];

int main(void)
{
	int n;
	int i, j, k;
	for (i = 0; i <= 100; i++)
	{
		for (j = 0; j <= 100; j++)
		{
			for (k = 0; k <= 100; k++)
			{
				if (i > 0 && j > 0 && k > 0) {
					if (i % 2 == 0 && k >= j + 2) {
						if (i + j + k <= 100) {
							data1[i + j + k]++;
						}
					}
				}
			}
		}
	}
	cin >> n;
	cout << data1[n];
}