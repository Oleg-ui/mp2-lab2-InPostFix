#include <string>
#include <stack>

using namespace std;

class InPostFix
{
	string Infix;                                 //��������� ����� ������ (������� �������������� ���������)
	
	string Postfix;                               //����������� ����� ������ (������������)

	int Priority_operations(char a, char b);      //���������� �������� ����������� ��� �������� �� Infix � Postfix
	
	bool This_is_the_number(char s);              //�������� �������� ������ (�����?)
	
	bool This_is_the_operator(char s);            //�������� �������� ������ (��������? ������?)
	
	bool Parenthesis_check();                     //�������� �� ����������� ����� ������ � �� ���������� ����������
	
	bool Checking_operations_and_operands();      //�������� �� ���������� ����������� �������� � �������
	
	void Space_in_line(string& str);              //������ ������ ����� ���������� (�������� ��� �������� � Postfix)
	
public:
	
	string GetInfix()                             //�������� ��������� ���������
	{ 
		return Infix; 
	}
	

	string GetPostfix()                           //�������� ����������� ���������
	{ 
		return Postfix; 
	}
	
	string Postfix_translation();                 //��������� ��������� ��������� � ����������� �����
	
	double Expression_calculation();              //���������� ���������� � ����������� �����
	
	InPostFix(string tmp = "")
	{
		Infix = tmp;
		Postfix = "";
	}
	
	InPostFix(InPostFix& v)
	{
		Infix = v.Infix;
		Postfix = v.Postfix;
	}
};