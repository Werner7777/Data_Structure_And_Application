#include<iostream>

using namespace std;

template<class T>void iota(T(&a)[3]) {
	for (size_t i = 0; i < size(a); i++)
	{
		a[i] = a[i] + i;
	}
}

int main() {
	int a[3] = { 1, 2, 3 };
	iota(a);

}