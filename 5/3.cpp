#include<iostream>

using namespace std;

template<class T>
void changeLength2D(T**& a, T OldRows, T OldColumns,T NewRows,T NewColumns)
{
	if (NewRows < 0 || NewColumns < 0)
		throw "new length must be >= 0";
	T** temp = new T*[NewRows];
	int number1 = min(OldRows, NewRows);
	int number2 = min(OldColumns, NewColumns);
	for(int i = 0;i<number1;i++){
		temp[i]=new T[number2];
		copy(a[i], a[i]+number2,temp[i]);
	}
        for(int i=0;i<OldRows;i++){

                delete[] a[i];
        }

	delete[] a;
	a = temp;
}

int main(){

	int Rows = 3,Columns = 3;
	int** a = new int*[Rows];
	for(int i=0;i<Rows;i++){
	
		a[i]=new int[Columns];
	}
	a[0][0]=0;
	cout << a[1] << endl;
	changeLength2D(a, Rows, Columns,Rows+2,Columns+2);
	cout << a[0][0] << endl;
	for(int i=0;i<Rows;i++){

                delete[] a[i];
        }
	delete[] a;
	a=NULL;
	}
