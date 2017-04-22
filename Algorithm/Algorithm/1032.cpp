//1032 명령 프롬프트

#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
#include<string>
#include<stack>
#include<queue>

using namespace std;

int main()
{
	ifstream f;
	f.open("input.txt");
	int n;
	int i, j;
	string s1;
	string s2;
	string s3;

	cin >> n;
	cin >> s1;
	s3.resize(s1.length());
	for (i = 2; i <= n; i++)
	{
		cin >> s2;
		for (j = 0; j < s2.length(); j++)
		{
			if (s1[j] == s2[j])
				s3[j] = s1[j];
			else
			{
				if (s1[j] != '?' && s2[j] != '?')
					s3[j] = '!';
				else if (s1[j] == '?')
					s3[j] = s2[j];
				else if (s2[j] == '?')
					s3[j] = s1[j];
			}		
		}
		s1 = s3;
	}
	for (i = 0; i < s1.length(); i++)
		if (s1[i] == '!')
			s1[i] = '?';
	cout << s1;
}