#include <iostream>
#include "Queue.h"
#include "money.h"
#include <string>
using namespace std;

void main()
{

	Queue<string> myQueue;
	Queue<int> myIntQueue;
	Queue<Currency> myCurrencyQueue;

	US usMoney;
	UK ukMoney;
	China chMoney;

	usMoney.setbill(10);
	usMoney.setcoin(150);
	ukMoney.setbill(80);
	ukMoney.setcoin(125);
	chMoney.setbill(56);
	chMoney.setcoin(85);
	chMoney.Normalize();

	cout << "Enqueue: 3 strings into Queue..." << endl;
	myQueue.insert("firstnode", 0);//doesnt matter what the second parameter is since it is only required for the base class
	myQueue.insert("2node", 0);//2nd parameter is supposed to be position to insert, but Queue always does it at the tail(rear)
	myQueue.insert("3node", 0);
	cout << "calling isempty()..." << endl;
	if (myQueue.listlength() == 0)
	{
		cout << "Queue is empty" << endl;
	}
	else
	{
		cout << "Queue has information." << endl;
	}
	cout << "Dequeue: 3 strings from Queue..." << endl;
	myQueue.print();
	cout << "calling isempty()..." << endl;
	if (myQueue.listlength() == 0)
	{
		cout << "Queue is empty" << endl;
	}
	else
	{
		cout << "Queue has information." << endl;
	}

	cout << "\n**************************************************************************\n";
	cout << "Enqueue: 3 ints into Queue..." << endl;
	myIntQueue.insert(10, 0);//doesnt matter what the second parameter is since it is only required for the base class
	myIntQueue.insert(20, 0);//2nd parameter is supposed to be position to insert, but Queue always does it at tail
	myIntQueue.insert(30, 0);
	cout << "calling isempty()..." << endl;
	if (myIntQueue.listlength() == 0)
	{
		cout << "Queue is empty" << endl;
	}
	else
	{
		cout << "Queue has information." << endl;
	}
	cout << "Dequeue: 3 ints from Queue..." << endl;
	myIntQueue.print();
	cout << "calling isempty()..." << endl;
	if (myIntQueue.listlength() == 0)
	{
		cout << "Queue is empty" << endl;
	}
	else
	{
		cout << "Queue has information." << endl;
	}

	cout << "\n**************************************************************************\n";
	cout << "Enqueue: 3 currencies into Queue..." << endl;
	myCurrencyQueue.insert(usMoney, 0);//doesnt matter what the second parameter is since it is only required for the base class
	myCurrencyQueue.insert(ukMoney, 0);//2nd parameter is supposed to be position to insert or delete, but Queue always does it in position 1 
	myCurrencyQueue.insert(chMoney, 0);
	cout << "calling isempty()..." << endl;
	if (myCurrencyQueue.listlength() == 0)
	{
		cout << "Queue is empty" << endl;
	}
	else
	{
		cout << "Queue has information." << endl;
	}
	cout << "Dequeue: 3 currencies from Queue..." << endl;
	myCurrencyQueue.print();

	cout << "calling isempty()..." << endl;
	if (myCurrencyQueue.listlength() == 0)
	{
		cout << "Queue is empty" << endl;
	}
	else
	{
		cout << "Queue has information." << endl;
	}

	system("pause");

}