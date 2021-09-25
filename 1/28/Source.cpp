#include<iostream>

using namespace std;

void add(int &a, int b) {
	 a += b;
}

template<class T>
void accumulate(T k, T m, int& init,void (*operat)(int&, int)) {
	for (auto i = k; i < m; i++)
	{
		operat(init, *i);
	}
}

template<class T>
void Accum1(int(&a)[]) {


}

int main() {
	int a[] = { 0, 1, 2, 3, 4 }, i(0);
	accumulate(a, a + size(a), i, &add);
	cout << i << endl;
}