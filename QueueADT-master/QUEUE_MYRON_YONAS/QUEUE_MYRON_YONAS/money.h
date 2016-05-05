/*Normalize(): accepts a currency and put it in proper
declare cur as function argument
set cur to the currency passed to the method
set yuan to cur.bill
set fen to cur.coin

set cur.bill to (yuan += fen / 10)
set cur.coin to fen%10
return cur
*/


#ifndef MONEY_H
#define MONEY_H

#include <iostream>
#include <string>
#include "Currency.h"

using namespace std;

class US :public Currency
{ 
public:
	US() : Currency("Dollars", "Cents"){}
};

class UK :public Currency
{
public:
	UK() :Currency("Pounds", "Pence"){}

};

class Benin :public Currency
{
public:
	Benin() :Currency("Francs", "Centimes"){}

};

class Egypt:public Currency
{
public:
	Egypt() :Currency("Pounds", "Piastres"){}

};

class China:public Currency
{
public:
	China() :Currency("Yuan", "Fen"){}
	Currency* Normalize()
	{
		int yuan = this->getbill();
		int fen = this->getcoin();
		this->setbill(yuan += fen / 10);
		this->setcoin(fen % 10);
		return this;
	}//becuase China yuan=10fen, not 100fen
	
};
#endif