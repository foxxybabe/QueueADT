/*overloaded default constructor
set billname to nullstring
set coinname to nullstring
set bill to zero
set coin to zero
*/
/*constructor with parameters passed
set billname to par 1
set coinname to par 2
set bill to 0
set coin to 0
*/


/*Operator + ()overloads the '+' operator to add two currency objects
declare temp: a currency object
set temp.bill to left.bill + right.bill
set temp.coin to left.coin + right.coin
set temp.billname to right.billname (either object's bill name works)
set temp.coinname to right objects coinname
return normalized currency
*/

/*operator -() overloads the '-' operator to add two currency objects
declare temp: a currency object with billname and coinname
if billname == "Yuan"  (chinese currency)
set coin to bill*10 + coin [for left side operand]
set bill to zero      [for left side operand]
set right.coin to right.bill*10 + right.coin
set temp.coin to coin-right.coin
set temp.bill to zero
return normalized temp value
else
set coin to bill*100 + coin [for left side operand]
set bill to zero      [for left side operand]
set right.coin to right.bill*100 + right.coin
set temp.coin to coin-right.coin
set temp.bill to zero
return normalized temp value
end if
end method
*/

/*overloaded ostream operator <<()
display currency object attributes to monitor
*/
/*overloaded istream operator >>()
prompt user for bill amount
set bill to input value
prompt   user for coin value
set coin to input value
normalize object
*/
/*Normalize(): accepts a currency and put it in proper
declare cur as function argument
set cur to the currency passed to the method
set bill to bill + coin/100
set coin to coin %100
return cur
*/


#include <iostream>
#include <string>
#include "Currency.h"
#include "money.h"
using namespace std;

Currency::Currency()
{
	billname = "";
	coinname = "";
	bill = 0;
	coin = 0;
}
Currency::Currency(string b, string c)
{
	billname = b;
	coinname = c;
	bill = 0;
	coin = 0;
}
Currency* Currency::Normalize()
{
	bill +=coin / 100;
	coin = coin % 100;
	return this;
}
void Currency:: setbillname(string name)
{
	billname = name;
}
void Currency::setcoinname(string name)
{
	coinname = name;
}
void Currency::setbill(int amount)
{
	bill = amount;
}
void Currency::setcoin(int amount)
{
	coin = amount;
}
string Currency::getbillname()
{
	return billname;
}
string Currency::getcoinname()
{
	return coinname;
}
int Currency::getbill()
{
	return bill;
}
int Currency::getcoin()
{
	return coin;
}
Currency Currency::operator + (const Currency &right)
{
	Currency temp(billname,coinname);
	temp.bill=bill + right.bill;
	temp.coin = coin + right.coin;
	//temp.billname = right.billname;
	//temp.coinname = right.coinname;
	temp.Normalize();
	return temp;
}
Currency Currency::operator - (Currency &right)
{
	
	
	if (billname == "Yuan")
	{
		China temp;
		coin = (bill * 10 + coin);
		bill = 0;
		right.coin = (right.bill * 10) + right.coin;
		right.bill = 0;
		temp.coin = coin - right.coin;
		temp.bill = 0;
		temp.Normalize();
		return temp;
	}
	else
	{
		Currency temp(billname, coinname);

		coin = (bill * 100) + coin;
		bill = 0;
		right.coin = (right.bill * 100) + right.coin;
		right.bill = 0;
		temp.coin = coin - right.coin;
		temp.bill = 0;
		temp.Normalize();
		return temp;
	}

}
ostream &operator << (ostream &strm, Currency &obj)
{
	obj.Normalize();
	cout << obj.getbill() << " " << obj.getbillname() << " " << obj.getcoin() << " " << obj.getcoinname();
	return strm;
}
istream &operator >> (istream &strm, Currency &obj)
{
	cout << "Enter " << obj.getbillname() << " amount: " << endl;
	cin >> obj.bill;
	cout << "Enter " << obj.getcoinname() << " amount: " << endl;
	cin >> obj.coin;
	obj.Normalize();
	return strm;
}
