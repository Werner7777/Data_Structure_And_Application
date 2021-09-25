#include<iostream>

using namespace std;

template <class T>T count(T (&n)[5]) {
	return size(n);
}

int main() {
	int n[5];
	for (int i = 0; i < 4; i++)
	{
		n[i] = i;
	}
	cout << count(n) << endl;
}