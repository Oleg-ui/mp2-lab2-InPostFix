#include <iostream>
#include <string>
#include "InPostFix.h"


using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	
	string expression;
	double result;
	
	cout << "������� �������������� ���������: ";
	cin >> expression;
	
	try
	{
		InPostFix Exp = expression;
		
		cout << "��������� �����: " << Exp.GetInfix() << endl;

		cout << "�������..." << endl;
		
		Exp.Postfix_translation();
		
		cout << "����������� �����: " << Exp.GetPostfix() << endl;
	
		cout << "�����: " << Exp.Expression_calculation() << endl;
	}
	
	catch (const char* n)
	{
		cout << n << endl;
	}
	
	
	system("pause");
	return 0;
}