#include<iostream>
#include "myExceptions.h"

using std::cin;
using std::istream;
using std::cout;

enum signType{pluss, minuss};

class currency
{
public:
	currency(signType theSign = pluss,
		unsigned long theDollars = 0, 
		unsigned int theCents = 0);
	~currency(){}
	void setValue(signType, unsigned long, unsigned int);
	void setValue(double);
	signType getsign() const { return sign; }
	unsigned long getDollars() const { return dollars; }
	unsigned int getCents()const { return cents; }
	currency add(const currency&) const;
	currency& increment(const currency&);
	currency input(istream&);
	void output() const;
	currency subtract(const currency&) const;
	currency percent() const;
	currency multiply(const double &) const;
	currency divide(const double&) const;
private:       
	signType sign;
	unsigned long dollars;
	unsigned int cents;
};

currency::currency(signType theSign, unsigned long theDollars,
	unsigned int theCents)
{// Create a currency object.
	setValue(theSign, theDollars, theCents);
}

void currency::setValue(signType theSign, unsigned long theDollars,
	unsigned int theCents)
{// Set currency value.
	if (theCents > 99)
		// too many cents
		throw illegalParameterValue("Cents should be < 100");
	sign = theSign;
	dollars = theDollars;
	cents = theCents;
}

void currency::setValue(double theAmount)
{// Set currency value.
	if (theAmount < 0) {
		sign = minuss;
		theAmount = -theAmount;
	}
	else sign = pluss;

	dollars = (unsigned long)theAmount;
	// extract integer part
	cents = (unsigned int)((theAmount + 0.001 - dollars) * 100);
	// get two decimal digits
}

currency& currency::increment(const currency& x)
{// Increment by x.
	*this = add(x);
	return *this;
}
 
void currency::output() const
{// Output currency value.
	if (sign == minuss) cout << '-';
	cout << '$' << dollars << '.';
	if (cents < 10) cout << '0';
	cout << cents;
}

currency currency::input(istream& is) {
	double money;
	is >> money;
	this->setValue(money);
	return *this;
}

currency currency::add(const currency& x) const

{// Add x and *this.
	long a1(0), a2(0), a3(0);
	currency result;
	// convert invoking object to signed integers
	
	a1 = dollars * 100 + cents;
	if (sign == minuss) a1 = -a1;
	
	// convert x to signed integer
	a2 = x.dollars * 100 + x.cents;
	if (x.sign == minuss) a2 = -a2;
	
	a3 = a1 + a2;
	
	// convert to currency representation
	if (a3 < 0) { result.sign = minuss; a3 = -a3; }
	else result.sign = pluss;
	result.dollars = a3 / 100;
	result.cents = a3 - result.dollars * 100;

	return result;
}

currency currency::subtract(const currency& x) const
{// Add x and *this.
	long a1, a2, a3;
	currency result;
	// convert invoking object to signed integers
	a1 = dollars * 100 + cents;
	if (sign == minuss) a1 = -a1;

	// convert x to signed integer
	a2 = x.dollars * 100 + x.cents;
	if (x.sign == minuss) a2 = -a2;

	a3 = a1 - a2;

	// convert to currency representation
	if (a3 < 0) { result.sign = minuss; a3 = -a3; }
	else result.sign = pluss;
	result.dollars = a3 / 100;
	result.cents = a3 - result.dollars * 100;

	 return result;
}

currency currency::percent() const {
	currency result;
	double m = cents / 100.0;
	m += dollars;
	m = m / 100 + 0.001;
	if (currency::getsign() == minuss)
		m = -m;
	result.setValue(m);
	return result;
}

currency currency::multiply(const double& x) const{
	currency result;
	double m =  cents / 100.0;
	m += dollars;
	m = m * x + 0.001;
	if (currency::getsign() == minuss)
		m = -m;
	result.setValue(m);
	return result;
}

currency currency::divide(const double& x) const {
	currency result;
	double m = cents / 100.0;
	m += dollars;
	m = m / x;
	if (currency::getsign() == minuss)
		m = -m;
	result.setValue(m);
	return result;
}

int main(){
	currency test1;
	test1.input(cin);
	cout << "input function's output is" << test1.getsign() << " " << test1.getDollars() << " " << test1.getCents() << "\n";
	currency test2;
	test2.input(cin);
	test1 = test1.subtract(test2);
	cout << "subtract function's output is" << test1.getsign() << " " << test1.getDollars() << " " << test1.getCents() << "\n";
	test1 = test1.percent(); 
	cout << "percent function's output is" << test1.getsign() << " " << test1.getDollars() << " " << test1.getCents() << "\n";
	test1 = test1.multiply(100);
	cout << "multiply function's output is" << test1.getsign() << " " << test1.getDollars() << " " << test1.getCents() << "\n";
	test1 = test1.divide(100);
	cout << "divide function's output is" << test1.getsign() << " " << test1.getDollars() << " " << test1.getCents() << "\n";
}