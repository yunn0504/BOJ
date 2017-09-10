#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

int main()
{
	int n;
	int i, j;
	int b, c;
	int temp;
	long long int count = 0;
	vector<int> v1;
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &temp);
		v1.push_back(temp);
	}
	scanf("%d %d", &b, &c);
	for (i = 0; i < n; i++)
	{
		v1[i] = v1[i]-b;
		count++;
	}
	for (i = 0; i < n; i++)
	{
		if (v1[i] >= 1)
		{
			count += (int)ceil((double)v1[i] / (double)c);
		}
	}
	printf("%d", count);
}