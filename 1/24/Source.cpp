#include<iostream>

using namespace std;

template<class T>bool judgeArray(T* a, int x,int len) {
	if (*a != x && len != 0)
	{
		judgeArray(a + 1, x, len - 1);
	}
	else if (*a == x)
		return true;
	else 
		return false;
}

int main(){
	int a[] = { 0, 1, 2, 3, 4 }, i = 5;
	cout << judgeArray(a, i, sizeof(a)) << endl;
}