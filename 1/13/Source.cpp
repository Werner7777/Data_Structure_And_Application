#include<iostream>

using namespace std;

template<class T> void changeLength1D(T* (&a), size_t newLength, size_t oldLength){
	T* b = new T[newLength];
	copy(a, a + min(newLength, oldLength), b);
	delete[] a;
	a = b;
}

int main() {
	int* a = new int[5];
	changeLength1D(a, 5, 4);
}