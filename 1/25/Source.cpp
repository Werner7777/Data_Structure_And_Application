#include<iostream>
#include<vector>

using namespace std;

template<class T>
void SubsetGeneration(int k, int m,vector<T> &result)
{
	if (k==m)
	{
		for (auto& v : result)
			cout << v;
		cout << endl;
	} 
	else
			for (int j = 0; j < 2; j++)
			{
				result.push_back(j);
				SubsetGeneration(k + 1, m, result);
				result.erase(result.end() - 1);
			}
}

int main() {
	char a[] = { 0, 1, 2};
	vector<int> v;
	int i = sizeof(a);
	SubsetGeneration(0, i, v);
}