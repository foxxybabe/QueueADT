
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
	Currency Normalize(Currency cur)
	{
		int yuan = cur.getbill();
		int fen = cur.getcoin();
		cur.setbill(yuan += fen / 10);
		cur.setcoin(fen % 10);
		this->setcoin(cur.getcoin());
		this->setbill(cur.getbill());
		return cur;
	}//becuase China yuan=10fen, not 100fen
	
};
#endif