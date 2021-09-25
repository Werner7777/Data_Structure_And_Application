#include<iostream>

using namespace std;

template<class T> 
void accumulate(T k, T m, int& init) {
	for (auto i = k; i < m; i++)
	{
		init += *i;
	}
}

template<class T>
void Accum1(int(&a)[]) {
	

}

int main() {
	int a[] = { 0, 1, 2, 3, 4 }, i(0);
	accumulate(a, a + size(a), i);
	cout << i << endl;
}