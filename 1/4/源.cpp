#include<iostream>

using namespace std;

template<class T>T inner_product(T (&a)[2], T (&b)[2]){
	int sum(0);
	for (size_t i = 0; i <= size(a) - 1; i++)
	{
		sum += a[i] * b[i];
	}
	return sum;
}

int main() {
	int a[2] = { 0, 1 };
	int b[2] = { 3, 3 };
	cout << inner_product(a, b) << endl;
}