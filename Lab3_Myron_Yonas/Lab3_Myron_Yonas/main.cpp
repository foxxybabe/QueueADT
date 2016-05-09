#include "Stacks.h"
#include "InfixCalculator.h"
#include <iostream>
#include <string>

using namespace std;

void main()
{
	
	Infixcalc calculator("5*(3+2)*5/5");
	cout << calculator.getinfixExp() << endl;

	calculator.calculate();
	
	system("pause");

}