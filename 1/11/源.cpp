#include<iostream>

using namespace std;

int abc(int a, int b, int c)
{
	int sum = a + b + c;
	if (a < 0 && b < 0 && c < 0)
		throw 1;
	if (a == 0 && b == 0 && c == 0)
		throw 2;
	if (sum = 1)
		throw "Too small";
	return sum;
}

int main() {
	int a = 0, b = 0, c = 1;
	try { cout << abc(a, b, c) << endl; }
	catch (int e)
	{
		cout << "test" << endl;
		return 1;
	}
	catch(const char*){
		cout << "test2";
		return 2;
	}
}