// 1158 조세퍼스 문제

#include<iostream>
#include<string>
#include<algorithm>
#include<fstream>
using namespace std;

int main(void)
{
	int n, m;
	int i, j;
	int count = 0;
	int data[5001];
	cin >> n >> m;
	for (i = 1; i <= n; i++)
		data[i] = i;
	i = 0;
	j = 0;
	cout << "<";
	while (count != n)
	{
		i++;
		if (i > n)
			i = 1;
		if (data[i] != 0)
			j++;
		if (j == m) {
			j = 0;
			count++;
			cout << data[i];
			if (count < n)
				cout << ", ";
			data[i] = 0;
		}
	}
	cout << ">\n";
}
