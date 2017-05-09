//11052 ºØ¾î»§ ÆÇ¸ÅÇÏ±â

#include<iostream>
#include<algorithm>

using namespace std;

int main(void)
{
	int n;
	int data[1001];
	int table[1001];
	int i, j, k;

	cin >> n;
	table[0] = 0;
	for (i = 1; i <= n; i++) {
		cin >> data[i];
		table[i] = data[i];
	}
	for (i = 2; i <= n; i++) {
		k = 1;
		for (j = i - 1; j >= k; j--, k++) {
			if (table[j] + table[k] > table[i])
				table[i] = table[j] + table[k];
		}
	}
	cout << table[n] << endl;
}