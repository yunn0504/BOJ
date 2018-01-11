#include<cstdio>

int main()
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	int n;
	int arr[101];
	int arr2[101];
	int i, j;
	int temp;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		arr[i] = i;
		scanf("%d", &arr2[i]);
	}
	for (i = 2; i <= n; i++)
	{
		for (j = i; j > i - arr2[i]; j--)
		{
			temp = arr[j];
			arr[j] = arr[j - 1];
			arr[j - 1] = temp;
		}
	}
	for (i = 1; i <= n; i++)
		printf("%d ", arr[i]);
	printf("\n");
	return 0;
}