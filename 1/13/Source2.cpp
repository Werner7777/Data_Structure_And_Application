#include<iostream>

using namespace std;

template<class T> void changeLength2D(T** (&a), size_t newRows,size_t newColumns, size_t oldRows, size_t oldColumns) 
{
	T** b = new T*[newRows];
	for (size_t i = 0; i < newColumns; i++)
		b[i] = new int[newColumns] {0, 1, 2, 3, 4};
	copy(a, a + min(newRows, oldRows)*min(newColumns, oldColumns), b);
	for (size_t i = 0; i < oldRows; i++)
	{
		delete[] a[i];
	}
	delete[] a;
	a = b;
}

template<class T>
void  make2dArray(T**& x, T numberOfRows, T* (&rowSize))
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
	int** x, r(5); int* c = new int[5];
	try { make2dArray(x, r, c); }
	catch (bad_alloc)
	{
		cerr << "Could not create x" << endl;
		exit(1);
	}
	try { changeLength2D(x, 4, 4, 5, 5); }
	catch (bad_alloc)
	{
		cerr << "Could not change the size of x" << endl;
		exit(1);
	}
}