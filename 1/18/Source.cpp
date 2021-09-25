// currency class with operator overloading

#include <iostream>
#include "myExceptions.h"

#ifndef Currency_
#define Currency_


using namespace std;

enum signType { pluss, minuss };

class currency
{
    friend    void operator>>(istream&, currency&);
public:
    // constructor
    currency(int = 0);
    // destructor
    ~currency() {}
    void operator=(const int&);
    void operator=(double);
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
    currency operator+(const currency&) const;
    currency& operator+=(const currency& x)
    {
        amount += x.amount; return *this;
    }
    void output(ostream&) const;
    currency operator-(const currency&) const;
    currency operator%(const int&) const;
    currency operator*(const double&) const;
    currency operator/(const double&) const;
private:
    long amount;
};

#endif // !Currency_

currency::currency(int i)
{// Create a currency object.
    *this = i;
}

void currency::operator=(const int& i)
{// Set currency value.
    amount = i;
}

void currency::operator=(double theAmount)
{// Set currency value.
    if (theAmount < 0)
        amount = (long)((theAmount - 0.001) * 100);
    else
        amount = (long)((theAmount + 0.001) * 100);
    // 2 decimal digits only
}

currency currency::operator+(const currency& x) const
{// Add x and *this.
    currency result;
    result.amount = amount + x.amount;
    return result;
}

void currency::output(ostream& out) const
{// Insert currency value into stream out.
    long theAmount = amount;
    if (theAmount < 0) {
        out << '-';
        theAmount = -theAmount;
    }
    long dollars = theAmount / 100; // dollars
    out << '$' << dollars << '.';
    int cents = theAmount - dollars * 100; // cents
    if (cents < 10) out << '0';
    out << cents;
}

// overload <<
ostream& operator<<(ostream& out, const currency& x)
{
    x.output(out); return out;
}

void operator>>(istream& is, currency &x) {
    is >> x.amount;
}

currency currency::operator-(const currency& x) const {
    currency result;
    result.amount = amount - x.amount;
    return result;
}

currency currency::operator%(const int &d) const {
    currency result;
    result.amount = amount %d;
    return result;
}

currency currency::operator*(const double& x) const {
    currency result;
    result.amount = amount * x;
    return result;
}

currency currency::operator/(const double& x) const {
    currency result;
    result.amount = amount / x;
    return result;
}

int main() {
    currency test1;
    cin >> test1;
    cout << "input function's output is" << test1 << "\n";
    currency test2;
    cin >> test2;
    test1 = test1 - test2;
    cout << "subtract function's output is" << test1 << "\n";
    test1 = test1 % 67;
    cout << "percent function's output is" << test1 << "\n";
    test1 = test1 * 100;
    cout << "multiply function's output is" << test1 << "\n";
    test1 = test1 / 100;
    cout << "divide function's output is" << test1 << "\n";
}