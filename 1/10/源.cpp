#include<iostream>

using namespace std;

int abc(int a, int b, int c) 
{
	if (a < 0 && b < 0 && c < 0)
		throw 1;
	if (a == 0 && b == 0 && c == 0)
		throw 2;
	return a + b + c;
}

int main() {
	int a = 2, b = 0, c = 4;
	try { cout << abc(2, 0, 4) << endl; }
	catch (int e)
	{
		
		
	}
}