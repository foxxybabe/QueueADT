#ifndef INFIXCALCULATOR_H
#define INFIXCALCULATOR_H

#include "Stacks.h"
#include <iostream>
#include <string>

using namespace std;

class Infixcalc
{
private:
	Stack<char>opStack;//stack for operators	
	Stack<int>valStack;//stack for operands
	char operand1;
	char operand2;
	char op;
	int result;
	string infixExp;
	char ch;
	int a;//used for converting char values to int
public:
	Infixcalc();
	Infixcalc(string);
	char check(char);
	int precedence(char);
	int math(char, int, int);
	int calculate();
	string getinfixExp();
	int getresult();
	bool isInfixExpValid(string);
};
Infixcalc::Infixcalc(){}
Infixcalc::Infixcalc(string input)
{
	infixExp = input;
}

/*isInfixExpValid(): accepts an infix string as argument
set exp to value of parameter
set openBracket to zero
For i=zero to exp[i]!= null character
set n to exp[i]
set m to exp[i+1]
if i==zero
set k to '5'
else
set k to exp[i-1]
end if

if n== '5'
return false
else if n=='3'
if m=='1' or m=='3'
increment openBracket by 1
continue
else
return false
end if
else if n=='1'
if exp[i+1]== null cahracter or m=='2' or m=='4'
continue
else
return false
end if
else if n=='2'
if i==zero or exp[i+1]== null cahracter
return false
else if exp[i]=='/' and exp[i+1]=='0'
return false
else if k=='1' or k=='4'
if m=='1' or m=='3'
continue
else
return false
end if
else
return false
end if
end if
else if n=='4'
if openBracket!=0
decrement openBracket by one
continue
else
return false
end if
end if
end loop

if openBracket > zero
return false
else
return true
end if
end method

*/
bool Infixcalc::isInfixExpValid(string exp)//returns true if an infix expression is valid or false otherwise
{
	char n, m, k;
	int openBracket = 0;
	for (int i = 0; exp[i] != '\0'; i++)//iterate through the expression
	{
		n = check(exp[i]);
		m = check(exp[i + 1]);
		if (i == 0)
			k = '5';
		else
			k = check(exp[i - 1]);

		if (n == '5')//invalid character in expression
			return false;
		else if (n == '3')  //for an opening bracket
		{
			if (m == '1' || m == '3')//check if next character is a digit or another opening bracket
			{
				openBracket++;
				continue;
			}
			else
				return false;
		}
		else if (n == '1')//for a digit/operand
		{
			if (exp[i + 1] == '\0' || m == '2' || m == '4')//check if next char is null character or an operator or a closing bracket
				continue;
			else
				return false;
		}
		else if (n == '2')//for an operator
		{
			if (i == 0 || exp[i + 1] == '\0')//check if operator is at the begining or end of expression
				return false;
			else if (exp[i] == '/' && exp[i + 1] == '0')//check if operator is division and next char in exp is '0'
				return false;
			else if (k == '1' || k == '4')//check if previous char in exp is an operand or a closing bracket
				if (m == '1' || m == '3')//check if next char in exp is an operand or an opening bracket
					continue;
				else
					return false;
			else
				return false;
		}
		else if (n == '4')//for a closing bracket
		{
			if (openBracket)//check if there is a matching open bracket
			{
				openBracket--;
				continue;
			}
			else     //more closing brackets than opening brackets
				return false;
		}
	}
	if (openBracket > 0)//more opening brackets than closing brackets
		return false;
	else
		return true;
}
/*
function check to return value to determine switch case

if char is an operand, return for case 1
if char is an operator, return char for case 2
if char is a '(;, return for case 3
if ')', return for case 4
else return case 5, which is invalid input

*/
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
/*
function precedence for returning priority of operators
if parenthesis, then return lowest priority 0
if plus or minus, return higher priority 1
if multiplication or division, return highest priority 2
*/
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
/*
math function to perform mathmetaical operations with char parameters and return int answer
if -, peform a-b, return answer
if +, perform a+b, return answer
if /, perform a/b, return answer 
if *, perform a*b, return answer
*/
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
/*
calculate() is the main operating function of the class to calculate the infix expression
for int i=0, ch is string[i], i++
	char c=checkfunction(ch) check function returns character for switch statement
	switch(c)
	case 1:(c is operand)
		int a=ch-48; make a usuable int value instead of the character
		push to operand stack
		break
	case 2: (c is operator)
		if operator stack is empty 
			push c into operator stack
			break
		else if c has higher precedence than the top operater in the stack
			push c into operator stack
			break
		else 
			while c has less or equal precedence than the top of the stack, and while stack is full
				assign variable for first 2 operands in operand stack and delete them from the operand stack
				assign variable for first in operator stack and delete operator
				call math function for result of these variables
				push result into operand stack
			push c into operator stack
			break
	case 3: if c is '('
		push into operator stack
	case 4: if c is ')'
		while '(' is not at the top of operator stack
				assign variable for first 2 operands in operand stack and delete them from the operand stack
				assign variable for first in operator stack and delete operator
				call math function for result of these variables
				push result into operand stack
		pop operator stack to get rid of '(;
		break
	case 5: if expression invalid
		cout expression invalid
		return 0,
		break;
	(end of switch)
	while list is still full
		perform all last operations: 
		assign variable for first 2 operands in operand stack and delete them from the operand stack
		assign variable for first in operator stack and delete operator
		call math function for result of these variables
		push result into operand stack

	cout result or top or operand stack
*/
int Infixcalc::calculate()
{
	char c;
	for (int i = 0; ch = infixExp[i]; i++)
	{
		c = check(ch);
		switch (c)
		{
		case '1':
			a = ch - 48;//convert char to int
			valStack.push(a);
			break;
		case '2':
			if (opStack.listlength() == 0)
			{
				opStack.push(ch);

			}
			else if (precedence(ch) > precedence(opStack.peek()))
			{
				opStack.push(ch);
			}
			else
			{
				while ((opStack.listlength() == 1) && (precedence(ch) <= precedence(opStack.peek())))
				{

					operand2 = valStack.peek();
					valStack.pop();
					operand1 = valStack.peek();
					valStack.pop();
					op = opStack.peek();
					opStack.pop();
					result = math(op, operand1, operand2);
					valStack.push(result);


				}
				opStack.push(ch);
			}
			break;
		case  '3':
			opStack.push(ch);
			break;
		case '4':

			while (opStack.peek() != '(')
			{
				operand2 = valStack.peek();
				valStack.pop();
				operand1 = valStack.peek();
				valStack.pop();
				op = opStack.peek();
				opStack.pop();
				result = math(op, operand1, operand2);
				valStack.push(result);
			}
			opStack.pop();
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
		valStack.pop();
		operand1 = valStack.peek();
		valStack.pop();
		op = opStack.peek();
		opStack.pop();
		result = math(op, operand1, operand2);
		valStack.push(result);
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