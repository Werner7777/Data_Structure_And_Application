#include<iostream>

using namespace std;

int recurrence(int n){
	if (n % 2 == 0)
		return n / 2;
	else
		return recurrence(3 * n + 1);
}

int unrecurrence(int n) {
	if (n % 2 == 0)
		return n / 2;
	else
		return (3*n+1)/2;
}

int main(){
	cout << recurrence(5) << endl;
	cout << unrecurrence(5) << endl;
}