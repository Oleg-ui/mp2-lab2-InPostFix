#include <string>
#include <stack>

using namespace std;

class InPostFix
{
	string Infix;                                 //Инфиксная форма записи (обычное алгебраическое выражение)
	
	string Postfix;                               //Постфиксная форма записи (Переведенная)

	int Priority_operations(char a, char b);      //Приоритеты операций необходимые при переводе из Infix в Postfix
	
	bool This_is_the_number(char s);              //Проверка элемента строки (Число?)
	
	bool This_is_the_operator(char s);            //Проверка элемента строки (Операция? Скобка?)
	
	bool Parenthesis_check();                     //Проверка на соотношение числа скобок и их правильное размещение
	
	bool Checking_operations_and_operands();      //Проверка на корректное соотношение операций и операнд
	
	void Space_in_line(string& str);              //Ставит пробел между элементами (Работает при переводе в Postfix)
	
public:
	
	string GetInfix()                             //Получить инфиксное выражение
	{ 
		return Infix; 
	}
	

	string GetPostfix()                           //Получить постфиксное выражение
	{ 
		return Postfix; 
	}
	
	string Postfix_translation();                 //Переводит введенное выражение в постфиксную форму
	
	double Expression_calculation();              //Производит вычисления в постфиксной форме
	
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