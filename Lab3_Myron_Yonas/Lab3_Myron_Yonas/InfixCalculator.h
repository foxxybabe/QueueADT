#ifndef INFIXCALCULATOR_H
#define INFIXCALCULATOR_H

#include "Stacks.h"
#include <iostream>
#include <string>

using namespace std;

class Infixcalc
{
private:
	Stack<char>opStack;
	Stack<int>valStack;
	char operand1;
	char operand2;
	char op;
	int result;
	string infixExp;
	char ch;
	int a;
public:
	Infixcalc();
	Infixcalc(string);
	char check(char);
	int precedence(char);
	int math(char, int, int);
	int calculate();
	string getinfixExp();
	int getresult();
};
Infixcalc::Infixcalc()
{
}
Infixcalc::Infixcalc(string input)
{
	infixExp = input;
}
char Infixcalc::check(char a)
{
	if (a == '0' || a == '1' || a == '2' || a == '3' || a == '4' || a == '5' || a == '6' || a == '7' || a == '8' || a == '9')
	{
		return '1';
	}
	else if (a == '+' || a == '-' || a == '*' || a == '/')
	{
		return '2';
	}
	else if (a == '(')
	{
		return '3';
	}
	else if (a == ')')
	{
		return '4';
	}
	else//for invalid expression
	{
		return '5';
	}
}
int Infixcalc::precedence(char a)
{
	if ((a == '(') || (a == ')'))
	{
		return 0;
	}
	if ((a == '+') || (a == '-'))
	{
		return 1;
	}
	if ((a == '*') || (a == '/'))
	{
		return 2;
	}
}
int Infixcalc::math(char opr, int a, int b)
{
	if (opr == '-')
	{
		return a - b;
	}
	else if (opr == '+')
	{
		return a + b;
	}
	else if (opr == '*')
	{
		return a*b;
	}
	else if (opr == '/')
	{
		return a / b;
	}
}
int Infixcalc::calculate()
{
	for (int i = 0; ch = infixExp[i]; i++)
	{
		/*cout << "count: "<< i<<endl;
		cout << "opstack: " << endl;
		opStack.printlist();
		cout << "valstack: " << endl;
		valStack.printlist();*/
		int c = check(ch);
		switch (c)
		{
		case '1':
			a = ch - 48;//convert char to int
			valStack.insert(a, 1);
			break;
		case  '3':
			opStack.insert(ch, 1);
			break;
		case '2':
			if (opStack.listlength() == 0)
			{
				opStack.insert(ch, 1);

			}
			else if (precedence(ch) > precedence(opStack.peek()))
			{
				opStack.insert(ch, 1);
			}
			else
			{

				while ((opStack.listlength() == 1) && (precedence(ch) <= precedence(opStack.peek())))
				{

					operand2 = valStack.peek();
					valStack.deletenode(1);
					operand1 = valStack.peek();
					valStack.deletenode(1);
					op = opStack.peek();
					opStack.deletenode(1);
					result = math(op, operand1, operand2);
					valStack.insert(result, 1);
					opStack.deletenode(1);

				}
				opStack.insert(ch, 1);
			}
			break;
		case '4':

			while (opStack.peek() != '(')
			{
				operand2 = valStack.peek();
				valStack.deletenode(1);
				operand1 = valStack.peek();
				valStack.deletenode(1);
				op = opStack.peek();
				opStack.deletenode(1);
				result = math(op, operand1, operand2);
				valStack.insert(result, 1);


				/*cout << "opstack: " << endl;
				opStack.printlist();
				cout << "valstack: " << endl;
				valStack.printlist();*/
			}
			opStack.deletenode(1);
			break;
		case '5':
			cout << "Expression is invalid." << endl;
			return 0;
			break;
		}
		
	}

	while (opStack.listlength() == 1)
	{
		operand2 = valStack.peek();
		valStack.deletenode(1);
		operand1 = valStack.peek();
		valStack.deletenode(1);
		op = opStack.peek();
		opStack.deletenode(1);
		result = math(op, operand1, operand2);
		valStack.insert(result, 1);
	}
	cout << "result is: " << result << endl;
	return result;
}
string Infixcalc::getinfixExp()
{
	return infixExp;
}
int Infixcalc::getresult()
{
	return result;
}









#endif