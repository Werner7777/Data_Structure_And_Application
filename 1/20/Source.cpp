#include<iostream>
#include<vector>

using namespace std;

int recursionFibonacci(int n){
	if (n > 1)
		return recursionFibonacci(n - 1) + recursionFibonacci(n - 2);
	else if (n == 0)
		return  0;
	else if (n == 1)
		return 1;
}

int unrecursionFibonacci(const int n) {
	vector<int> vec = {0, 1};
	if (n == 0) {

		return 0;
	}
	else if (n == 1)
		return 1;
	else
		for (size_t i = 2; i <= n; i++)
		{
			vec.push_back(vec[i - 1] + vec[i - 2]);
		}
	return *(vec.end() - 1);
}

int main() {
	cout << recursionFibonacci(5) << endl;
	cout << unrecursionFibonacci(5) << endl;
}