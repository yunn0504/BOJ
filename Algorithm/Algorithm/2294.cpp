//2294 ����2 DP,�������� �߿�
//n=3 k=15 1,5,12 ������ ������ 1 5 12�� ���� 1���� �ʿ�
//15���� 14,10,3(15-1, 15-5, 15-12)���� ������(1,5,12)�� 1���� ���ؼ� ����� ����
//�׷��Ƿ� 14,10,3���� ����� �ִ� ���������� �������� ���������� ����
//2,5,12�϶� 3���� ����� ���� 1���� ���ϴµ� 1���� -1(���Ҽ�����)�̹Ƿ� ������ ����
//
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int coin[110];
int table[10100];

int main(void)
{
	int n,k;
	int i, j;
	cin >> n >> k;
	for (i = 1; i <= n; i++) {
		cin >> coin[i];
			if(coin[i]<=10000) //<-������ �׸��� 10000�� �Ѿ�� ������� 15000�̸� tabel �迭�� �̻��Ѱ� ����
		table[coin[i]] = 1;
	}
	for (i = 1; i <= k; i++) {
		for (j = 1; j <= n; j++) {
			if (i >= coin[j]) {
				if (table[i] == 0)
					table[i] = table[i-coin[j]]+1;
				else if(table[i]>=table[i-coin[j]]+1 && table[i-coin[j]]>=0) 
					table[i] = table[i - coin[j]]+1;
			}
		}
		if (table[i] == 0)
			table[i] = -1;
		//cout << table[i] << " ";
	}
	cout << table[k] << endl;
	return 0;
}