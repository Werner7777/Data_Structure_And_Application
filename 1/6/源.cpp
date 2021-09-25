#include<iostream>

using namespace std;

template<class T>bool is_shorted(T(&a)[4]) {
	for (size_t i = 0; i < size(a); i++)
	{
		if (a[i] != i)
		{
			return false; break;
		}
	}
	return true;
}

int main() {
	int a[4] = { 1, 1, 2, 3 };
	cout << is_shorted(a) << endl;
}