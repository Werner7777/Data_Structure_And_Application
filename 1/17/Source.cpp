#include<iostream>
#include "myExceptions.h"

using std::cin;
using std::istream;
using std::cout;

enum signType { pluss, minuss };

class currency
{
public:
	// constructor
	currency(signType theSign = pluss,
		unsigned long theDollars = 0,
		unsigned int theCents = 0);
	// destructor
	~currency() {}
	void setValue(signType, unsigned long, unsigned int);
	void setValue(double);
	signType getSign() const
	{
		if (amount < 0) return minuss;
		else return pluss;
	}
	unsigned long getDollars() const
	{
		if (amount < 0) return (-amount) / 100;
		else return amount / 100;
	}
	unsigned int getCents() const
	{
		if (amount < 0) return -amount - getDollars() * 100;
		else return amount - getDollars() * 100;
	}
	currency add(const currency&) const;
	currency& increment(const currency& x)
	{
		amount += x.amount; return *this;
	}
	currency input(istream&);
	void output() const;
	currency subtract(const currency&) const;
	currency percent() const;
	currency multiply(const double&) const;
	currency divide(const double&) const;
private:
	long amount;
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

	amount = theDollars * 100 + theCents;
	if (theSign == minuss) amount = -amount;
}

void currency::setValue(double theAmount)
{// Set currency value.
	if (theAmount < 0)
		amount = (long)((theAmount - 0.001) * 100);
	else
		amount = (long)((theAmount + 0.001) * 100);
	// 2 decimal digits only
}

currency currency::add(const currency& x) const
{// Add x and *this.
	currency y;
	y.amount = amount + x.amount;
	return y;
}

void currency::output() const
{// Output currency value.
	long theAmount = amount;
	if (theAmount < 0) {
		cout << '-';
		theAmount = -theAmount;
	}
	long dollars = theAmount / 100; // dollars
	cout << '$' << dollars << '.';
	int cents = theAmount - dollars * 100; // cents
	if (cents < 10) cout << '0';
	cout << cents;
}

currency currency::input(istream& is) {
	double money;
	is >> money;
	this->setValue(money);
	return *this;
}

currency currency::subtract(const currency& x) const{
	currency result;
	result.amount = amount - x.amount;
	return result;
}

currency currency::percent() const {
	currency result;
	result.amount = amount / 100;
	return result;
}

currency currency::multiply(const double& x) const {
	currency result;
	result.amount = amount * x;
	return result;
}

currency currency::divide(const double& x) const {
	currency result;
	result.amount = amount / x;
	return result;
}

int main() {
	currency test1;
	test1.input(cin);
	cout << "input function's output is" << test1.getSign() << " " << test1.getDollars() << " " << test1.getCents() << "\n";
	currency test2;
	test2.input(cin);
	test1 = test1.subtract(test2);
	cout << "subtract function's output is" << test1.getSign() << " " << test1.getDollars() << " " << test1.getCents() << "\n";
	test1 = test1.percent();
	cout << "percent function's output is" << test1.getSign() << " " << test1.getDollars() << " " << test1.getCents() << "\n";
	test1 = test1.multiply(100);
	cout << "multiply function's output is" << test1.getSign() << " " << test1.getDollars() << " " << test1.getCents() << "\n";
	test1 = test1.divide(100);
	cout << "divide function's output is" << test1.getSign() << " " << test1.getDollars() << " " << test1.getCents() << "\n";
}