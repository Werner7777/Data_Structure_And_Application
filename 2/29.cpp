#include<iostream>

using namespace std;

int stepCount = 0;
int d(int x[], int n, int& stepCount)
{
	for(int i=0;i<n;i+=2)
	{
		stepCount+=2;
		x[i]+=2; 
	}
	stepCount++;
	int i=1;
	while(i<n/2)
	{
		x[i]+=x[i+1];
		i++;
		stepCount+=3;
	}
	stepCount++;
	return stepCount;
}

int main(){
	int x[3] = {0, 1, 2};
	int n = 3;
	int s=0;
	cout << d(x, n, s) << endl;
}
