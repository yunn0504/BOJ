//11053 가장 긴 증가하는 부분수열
#include<iostream>

using namespace std;

int main(void)
{
	int n;
	int data[1001];
	int table[1001];
	int i, j;
	int max = 0;
	cin >> n;
	for (i = 1; i <= n; i++) {
		cin >> data[i];
		table[i] = 1;
	}

	table[1] = 1;
	for (i = 2; i <= n; i++)
	{
		for (j = 1; j < i; j++)
		{
			if (data[i] > data[j])
			{
				if (table[j] > max)
					max = table[j];
			}
		}
		table[i] = table[i] + max;
		//cout << table[i] <<" ";
		max = 0;
	}
	for (i = 1; i <= n; i++)
	{
		if (table[i] > max)
			max = table[i];
	}
	cout << max << endl;
}