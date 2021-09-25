#include<iostream>

using namespace std;

template <class T> T fill(T(&n)[5]) {
	n[4] = 5;
	return n[4];
}

int main() {
	int n[5];
	for (int i = 0; i < 3; i++)
	{
		n[i] = i;
	}
	cout << fill(n) << endl;
}