/*#include<iostream>
#include<vector>
#include<list>

using namespace std;

void g(int n, vector<int>& result) {
	if (n == 1) {
		result.push_back(1);
	}
	else
	{
		g(n - 1, result);
		result.push_back(n);
		g(n - 1, result);
	}
}

int main() {
	int n(4); vector<int> v{};
	g(n, v);
	for (auto& element : v)
		cout << element << endl;
}*/

#include <algorithm>
#include <iterator>
#include<vector>
#include <iostream>


template<typename T>
void Func(int n, std::vector<T>& idxs)
{
	// 基础部分
	if (n == 1) {
		idxs.push_back(1);
	}
	else {
		// 递归部分
		Func(n - 1, idxs);
		idxs.push_back(n);
		Func(n - 1, idxs);
	}
}

int main(int argc, char** argv)
{

	std::vector<int> idxs;
	Func(4, idxs);
	std::copy(idxs.begin(), idxs.end(), std::ostream_iterator<int>(std::cout, " "));
} 
