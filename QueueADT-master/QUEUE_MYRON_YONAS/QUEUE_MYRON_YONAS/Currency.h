#ifndef CURRENCY_H
#define CURRENCY_H
#include <iostream>
#include <string>
using namespace std;

class Currency
 {
private:
	string billname;
	string coinname;
	int bill;
	int coin;
public:
	Currency();
	Currency(string,string);
	virtual Currency* Normalize();
	void setbillname(string);
	void setcoinname(string);
	void setbill(int);
	void setcoin(int);
	string getbillname();
	string getcoinname();
	int getbill();
	int getcoin();
	Currency operator + (const Currency &);
	Currency  operator - (Currency &);
	friend ostream &operator << (ostream &, Currency &);
	friend istream &operator >> (istream &,  Currency &);
};

#endif