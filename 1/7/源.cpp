#include<iostream>

using namespace std;

template<class T>T mismatch(T(&a)[4], T(&b)[4]) {
	size_t i = 0;
	for (; i <= min(size(a), size(b)); i++)
	{
		if (a[i] != b[i])
		{
			return i; break;
		}
	}
	if (size(a) != size(b))
		return i + 1;
	else
		return -1;
}

int main() {
	int a[4] = { 1, 1, 2, 3 };
	int b[4] = { 1, 1, 2, 4 };
	cout << mismatch(a, b) << endl;
}