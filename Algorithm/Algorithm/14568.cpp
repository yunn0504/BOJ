//14568 �����й蹮��
//������ 1���̻� A�� ������ ¦���� C�� B���� 2���̻� ���ƾ���
//3�߷����� �´����Ǹ� ���
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