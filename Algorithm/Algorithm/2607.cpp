//����� �ܾ�
//���� ���ĺ�����������, ���� �������� ������ �޶󵵵�
#include<cstdio>

int main()
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	int arr[26];
	int arr2[26];
	char word[11];
	int n,i,j;
	int count;
	scanf("%d", &n);
	scanf("%s", word);
	count = n - 1;
	for (j = 0; j < 26; j++) 
		arr[j] = 0;

	for (i = 0; word[i] != '\0'; i++)
	{
		arr[word[i] - 65] = 1;
	}

	for (i = 1; i < n; i++)
	{
		scanf("%s", word);
		for (j = 0; j < 26; j++)
			arr2[j] = 0;
		for (j = 0; word[j] != '\0'; j++)
		{
			arr2[word[j] - 65] = 1;
		}
		for (j = 0; j < 26; j++) {
			if (arr[j] != arr2[j]) {
				count--;
				break;
			}
		}
	}
	printf("%d", count);
	return 0;
}