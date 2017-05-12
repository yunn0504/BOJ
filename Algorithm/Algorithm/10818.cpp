//10818 최소 최대 STL min_element,max_element
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void)
{
	int i, j;
	int n;
	vector<int> v1;
	
	cin >> n;
	int temp;
	for (i = 1; i <= n; i++)
	{
		cin >> temp;
		v1.push_back(temp);
	}
	cout << *(min_element(v1.begin(), v1.end())) <<" ";
	cout << *(max_element(v1.begin(), v1.end())) <<"\n";
	
	return 0;
}