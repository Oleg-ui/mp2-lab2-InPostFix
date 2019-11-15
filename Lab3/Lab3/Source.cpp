#include <iostream>
#include <string>
#include "InPostFix.h"


using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	
	string expression;
	double result;
	
	cout << "Введите арифметическое выражение: ";
	cin >> expression;
	
	try
	{
		InPostFix Exp = expression;
		
		cout << "Инфиксная форма: " << Exp.GetInfix() << endl;

		cout << "Перевод..." << endl;
		
		Exp.Postfix_translation();
		
		cout << "Постфиксная форма: " << Exp.GetPostfix() << endl;
	
		cout << "Ответ: " << Exp.Expression_calculation() << endl;
	}
	
	catch (const char* n)
	{
		cout << n << endl;
	}
	
	
	system("pause");
	return 0;
}