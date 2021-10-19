using namespace std;

#include"arrayList.h"
#include<iostream>
#include <iterator>

template<class T>
class arrayListWithTrimToSize : public arrayList<T> 
{
   public:
      // constructor and destructor
      arrayListWithTrimToSize(int initialCapacity = 10)
            : arrayList<T>(initialCapacity) {}

      void trimToSize();
};

template<class T>
void arrayListWithTrimToSize<T>::trimToSize()
{// Make array length equal to max{listSize, 1}

   if (arrayList<T>::arrayLength == arrayList<T>::listSize)
      return;

   if (arrayList<T>::listSize == 0)
      {// replace with array of length 1
         delete [] arrayList<T>::element;
         arrayList<T>::element = new T[1];
         arrayList<T>::arrayLength  = 1;
         return;
      }


   // need to change array length and copy eleements into new array
   changeLength1D(arrayList<T>::element, arrayList<T>::listSize, arrayList<T>::listSize);
   arrayList<T>::arrayLength = arrayList<T>::listSize;
}

int main(){
	arrayListWithTrimToSize<int> a;
	a.trimToSize();
}
