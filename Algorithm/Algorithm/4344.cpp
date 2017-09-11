//4344 평균은 넘겠지

#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int main(void)
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif
	int t;
	int n;
	vector<int> v1;
	int i, j;
	int temp;
	int sum=0;
	int count=0;
	double avg;
	scanf("%d", &t);
	for (i = 1; i <= t; i++)
	{
		scanf("%d", &n);
		for (j = 1; j <= n; j++)
		{
			scanf("%d", &temp);
			sum = sum + temp;
			v1.push_back(temp);
		}
		avg = (double)sum / (double)n;
		for (j = 0; j < n; j++)
		{
			if (v1[j] > avg)
				count++;
		}
		//실수 정확도 중요
		printf("%.3lf%%\n", ((double)count / (double)n)*100.0);
		count = 0;
		sum = 0;
		avg = 0;
		v1.clear();
	}
	return 0;
}