#include<iostream>
#include "arrayList.h"

using namespace std;
template<class T>
class arrayListWithOverloadIndex:public arrayList<T>{
public:
	T& operator[](size_t i){
	
		arrayList<T>::checkIndex(i);
		return arrayList<T>::element[i];
	}
};

int main(){

	arrayListWithOverloadIndex<int> a;
	a.insert(0, 1);
	a.output(cout);
}
