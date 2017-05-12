//2294 동전2 DP,범위제한 중요
//n=3 k=15 1,5,12 동전이 있을때 1 5 12의 경우는 1개만 필요
//15원은 14,10,3(15-1, 15-5, 15-12)원에 각동전(1,5,12)을 1개씩 더해서 만들수 있음
//그러므로 14,10,3원을 만들수 있는 동전갯수중 가장작은 동전갯수를 구함
//2,5,12일때 3원을 만들기 위해 1원과 비교하는데 1원은 -1(구할수없음)이므로 비교하지 않음
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
			if(coin[i]<=10000) //<-동전의 액면이 10000이 넘어갈때 예를들어 15000이면 tabel 배열의 이상한곳 접근
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