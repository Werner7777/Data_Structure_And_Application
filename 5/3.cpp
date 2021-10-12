#include<iostream>

using namespace std;

template<class T>
void changeLength2D(T*& a, T oldLength, T newLength)
{
	if (newLength < 0)
		throw "new length must be >= 0";
	T* temp = new T[newLength];
	int number = min(oldLength, newLength);
	copy(a, a+number,temp);
	delete[] a;
	a = temp;
}

int main(){

	int Length = 3;
	int* b = new int[Length];
	for(int i=0;i<Length;i++){
	
		b[i]=i;
	}
	cout << b[1] << endl;
	changeLength2D(b, Length, Length + 2);
	delete[] b;
	cout << b[1] << endl;
}
