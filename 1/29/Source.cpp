#include<iostream>
#include<vector>

using namespace std;

template<class T>
void copy(T k, T m, vector<int>& result){
	for (T i = k; i < m; i++)
	{
		result.push_back(*i);
	}
}

int main() {
	vector<int> v1= { 0, 1, 2 };
	vector<int> v2;
	copy(v1.begin(), v1.end(), v2);
	for (auto& w : v2) {
		cout << w << endl;
	}
}