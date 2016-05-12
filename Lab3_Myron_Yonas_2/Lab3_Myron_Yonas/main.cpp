#include "InfixCalculator.h"
#include <iostream>
#include <string>

using namespace std;

void main()
{
	string exp = "((2+1)*3+1)";
	Infixcalc calculator(exp);
	cout <<"Example: "<< calculator.getinfixExp() << endl;
	calculator.calculate();
	do
	{
		cout << "\nEnter Infix expression to evaluate or [Q] to quit: ";
		cin >> exp; cin.sync();
		Infixcalc calculator(exp);
		if (exp == "Q" || exp == "q")
			cout << "\nThank you." << endl;
		else if (calculator.isInfixExpValid(calculator.getinfixExp()))
			calculator.calculate();
		else
			cout << "\nInvalid Expression!" << endl;
	} while (exp != "Q" && exp != "q");

	system("pause");

}