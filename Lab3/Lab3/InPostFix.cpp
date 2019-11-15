#include "InPostFix.h"
#include <vector>
#include <stack>
#include <iostream>


using namespace std;

int InPostFix::Priority_operations(char a, char b)
{
	if ((a == '*' || a == '/') && (b == '*' || b == '/') || (a == '+' || a == '-') && (b == '+' || b == '-'))
		return 0;
	if ((a == '+' || a == '-') && (b == '*' || b == '/'))
		return -1;
	if ((a == '*' || a == '/') && (b == '+' || b == '-'))
		return 1;
	if (b == '^' && a != '~')
		return -1;
	if (a == '^' && b != '~')
		return 1;
	if (a == '~')
		return 1;
	if (b == '~')
		return -1;
	throw "Error in priority";
}

bool InPostFix::This_is_the_number(char v)
{
	if (int(v) >= 48 && int(v) <= 57)
		return true;
	return false;
}

bool InPostFix::This_is_the_operator(char v)
{
	if (v == '~' || v == '-' || v == '+' || v == '/' || v == '*' || v == '^' || v == '(' || v == ')')
		return true;
	else
		return false;
}

bool InPostFix::Parenthesis_check()
{
	int LeftBrackets = 0;
	int	RightBrackets = 0;
	for (int i = 0; i < Infix.size(); i++)
	{
		if (Infix[i] == '(')
			LeftBrackets++;
		else if (Infix[i] == ')')
			RightBrackets++;
		if (RightBrackets > LeftBrackets)
			throw "Error Brackets";
	}
	if (LeftBrackets == RightBrackets)
		return true;
	else return false;
}

bool InPostFix::Checking_operations_and_operands()
{
	for (int i = 0; i < Infix.size(); i++)
		if (!This_is_the_number(Infix[i]) && !This_is_the_operator(Infix[i]))
			return false;
	int Operands = 0;
	int Operations = 0;
	for (int i = 0; i < Infix.size(); i++)
	{
		if (Infix[i] == '(' || Infix[i] == ')')
		{
			i++;
			if (i == Infix.size())
				break;
		}

		if (Infix[i] == '-' || Infix[i] == '+' || Infix[i] == '/' || Infix[i] == '*' || Infix[i] == '^')
			Operations++;

		if (!This_is_the_operator(Infix[i]))
		{
			while (!This_is_the_operator(Infix[i]))
			{
				i++;
				if (i == Infix.size())
					break;
			}
			i--;
			Operands++;
		}
	}
	if (Operands == Operations + 1)
		return true;
	else return false;
}

void InPostFix::Space_in_line(string& str)
{
	if (str.empty())
		return;
	if (str.back() != ' ')
		str += ' ';
}

string InPostFix::Postfix_translation()
{
	if (!Parenthesis_check())
		throw "Error Brackets";
	for (int j = 0; j < Infix.size(); j++)
	{
		if (Infix[0] == '-')
			Infix[0] = '~';
		if (Infix[j] == '-' && (Infix[j - 1] == '(' || Infix[j - 1] == '~'))
			Infix[j] = '~';
	}
	int count = -1;
	stack<char> Set;
	for (int i = 0; i < Infix.size(); i++)
	{
		if (This_is_the_operator(Infix[i]))
		{
			if ((Set.empty() || Infix[i] == '(') && Infix[i] != '~')
			{
				if (Infix[i] != '(')
					Space_in_line(Postfix);
				Set.push(Infix[i]);
				count++;
				continue;
			}
			else if ((Set.empty() || Set.top() == '~') && Infix[i] == '~')
			{
				Set.push(Infix[i]);
				count++;
				continue;
			}
			else if (Infix[i] == ')')
			{
				while (Set.top() != '(')
				{
					Space_in_line(Postfix);
					Postfix += Set.top();
					Set.pop();
					count--;
				}
				Set.pop();
				count--;
			}
			else if ((Set.top()) == '(' || Priority_operations(Infix[i], Set.top()) == 1)
			{
				Set.push(Infix[i]);
				Space_in_line(Postfix);
				count++;
			}
			else if (Priority_operations(Infix[i], Set.top()) == -1)
			{
				Space_in_line(Postfix);
				while (!(Set.empty()))
				{
					if (Set.top() == '(')
						break;
					Postfix += Set.top();
					Set.pop();
					Space_in_line(Postfix);
					count--;
				}
				Set.push(Infix[i]);
				count++;
			}
			else if (Priority_operations(Infix[i], Set.top()) == 0)
			{
				Space_in_line(Postfix);
				Postfix += Set.top();
				Set.pop();
				Set.push(Infix[i]);
				Space_in_line(Postfix);
			}
		}
		else
			Postfix += Infix[i];
		if (i == Infix.size() - 1)
		{
			for (count; count >= 0; count--)
			{
				Space_in_line(Postfix);
				Postfix += Set.top();
				Set.pop();
			}
		}
	}
	return Postfix;
}

double InPostFix::Expression_calculation()
{
	if (!Checking_operations_and_operands() || Postfix == "")
		throw "Error Operand";
	stack<double> Result;
	string str;
	for (int i = 0; i < Postfix.size(); i++)
	{
		if (Postfix[i] == ' ')
			continue;
		if (!This_is_the_operator(Postfix[i]))
		{
			while (Postfix[i] != ' ')
			{
				str += Postfix[i];
				i++;
			}
			Result.push(atof(str.c_str()));
			str = "";
		}
		else
		{
			if (Postfix[i] == '~')
			{
				double a = Result.top();
				Result.pop();
				Result.push(-a);
				continue;
			}
			double a = Result.top();
			Result.pop();
			double b = Result.top();
			Result.pop();
			if (Postfix[i] == '+')
				Result.push(b + a);
			else if (Postfix[i] == '-')
				Result.push(b - a);
			else if (Postfix[i] == '*')
				Result.push(b * a);
			else if (Postfix[i] == '/')
			{
				if (a == 0.0)
					throw "Error Division";
				Result.push(b / a);
			}
			else if (Postfix[i] == '^')
				Result.push(pow(b, a));
		}
	}
	return Result.top();
}