#include<iostream>

using namespace std;

template<class T>
void  make2dArray( T ** &x, T numberOfRows, T *(&rowSize) )
{
		x = new T * [numberOfRows];
		for (int i = 0; i < numberOfRows; i++) {
			x[i] = rowSize;
		}
}

template<class T>
void delete2dArray(T**& x, int numberOfRows)
{
	for (int i = 0; i < numberOfRows; i++)
		delete[] x[i];
	delete[] x;
	x = NULL;
}

int main() {
	int** x, r(5);int* c = new int [5];
	try { make2dArray(x, r, c); }
	catch (bad_alloc)
	{
		cerr << "Could not create x" << endl;
		exit(1);
	}
}