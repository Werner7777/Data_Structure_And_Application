#include<iostream>
#include"arrayList.h"

using namespace std;

template<class T> 
class arrayListWithEqual:public arrayList<T>{
public:
	bool operator!=(arrayList<T> x){

		if(this->size()!=x.size())
			return true;
		else{
			for(size_t i=0;i<x.size();i++){
			if(this->get(i)!=x.get(i))
				return true;
			else
				;
			}
			return false;
		}
	}
};

int main(){

	arrayListWithEqual<int> a;
	a.insert(0,1);
	a.insert(1,2);
	a.insert(2,3);
	arrayListWithEqual<int> b;
        b.insert(0,1);
	b.insert(1,3);
	cout << (a!=b) << endl;
}
