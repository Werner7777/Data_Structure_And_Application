#include<iostream>

using namespace std;

int Ackermann(int i, int j) {
	if (i == 1 && j >= 1)
		return pow(2, j);
	else if (i >= 2 && j == 1)
		return Ackermann(i - 1, 2);
	else
		return Ackermann(i - 1, Ackermann(i, j - 1));
}

int main() {
	int i = 2, j = 2;
	cout << Ackermann(2, 2) << endl;
}