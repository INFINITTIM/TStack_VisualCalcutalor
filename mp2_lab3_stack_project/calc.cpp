#include "calc.h"

TCalc::TCalc()
{
	LLStack<double> stack_with_numbers;
	LLStack<char> Stack_with_symbol;
}

void TCalc::SetInfix(std::string str)
{
	infix = str;
}

std::string TCalc::GetInfix()
{
	return infix;
}

void TCalc::SetPostfix(std::string str)
{
	postfix = str;
}

std::string TCalc::GetPostfix()
{
	return postfix;
}

int TCalc::Priority(Function a)
{
	if (a == DEGREE)
		return 3;
	if (a == MULT || a == DIV)
		return 2;
	if (a == PLUS || a == MINUS)
		return 1;
	return 0;
}

double TCalc::Factorial(double n)
{
	if (n <= 1) return 1;
	return n * Factorial(n - 1);
}

bool TCalc::Check(std::string str) {
	LLStack<char> s;

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') {
			s.push('(');
			if (str[i + 1] == ')')
				return false;
		}
		else if (str[i] == ')') {
			if (s.isEmpty()) {
				return false; 
			}
			s.pop();
		}
	}
	return s.isEmpty();
}

/*
void TCalc::ToPostfix()
{
	postfix = "";
	Stack_with_symbol.clear();
	string infix_time = '(' + infix + ')';
	for (int i = 0; i < infix_time.size(); i++)
	{
		if (infix_time[i] >= '0' && infix_time[i] <= '9' || infix_time[i] == '.')
			postfix += infix_time[i];
		if (infix_time[i] == '(')
			Stack_with_symbol.Push(infix_time[i]);
		if (infix_time[i] == ')')
		{
			while (Stack_with_symbol.Top() != '(')
			{
				postfix += ' ';
				postfix += Stack_with_symbol.Pop();
			}
			Stack_with_symbol.Pop();
		}
		if (infix_time[i] == '+' || infix_time[i] == '-' || infix_time[i] == '*' || infix_time[i] == '/' || infix_time[i] == '^')
		{
			postfix += ' ';
			while ((Priority(infix_time[i]) <= Priority(Stack_with_symbol.Top())) && (!Stack_with_symbol.Empty()))
			{
				postfix += Stack_with_symbol.Pop();
				postfix += ' ';
			}
			Stack_with_symbol.Push(infix_time[i]);
		}
	}
}*/
/*
double TCalc::CalculatorPostfix()
{
	stack_with_numbers.clear();
	for (int i = 0; i < postfix.size(); i++)
	{
		if (postfix[i] >= '0' && postfix[i] <= '9' || postfix[i] == '.')
		{
			size_t idx;
			double tmp = stod(&postfix[i], &idx);
			stack_with_numbers.Push(tmp);
			i += idx - 1;
		}
		if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/'|| postfix[i] == '^')
		{
			double second_number = stack_with_numbers.Pop();
			double first_number = stack_with_numbers.Pop();
			double res = 0;
			switch (postfix[i])
			{
			case'+':
				res = first_number + second_number;
				break;
			case'-':
				res = first_number - second_number;
				break;
			case'*':
				res = first_number * second_number;
				break;
			case'/':
				res = first_number / second_number;
				break;
			case'^':
				res = pow(first_number, second_number);
				break;
			}
			stack_with_numbers.Push(res);
		}
	}
	double result_with_stack = stack_with_numbers.Pop();
	if (!(stack_with_numbers.Empty()))
		throw - 1;
	return result_with_stack;
}*/

double TCalc::Calculator()
{
	if (!Check(infix))
		throw - 1;
	std::string infix_time = '(' + infix + ')';
	Stack_with_symbol.clr();
	stack_with_numbers.clr();
	std::string check_string = "";

	double const pi = 3.1415926535;

	for (int i = 0; i < infix_time.size(); i++)
	{
		char tmp = infix_time[i];

		// Обработка функций
		if (tmp >= 'a' && tmp <= 'z')
		{
			check_string += tmp;
			if (check_string == "sin")
			{
				Stack_with_symbol.push(SIN);
				check_string.clear();
				i++;
			}
			else if (check_string == "cos")
			{
				Stack_with_symbol.push(COS);
				check_string.clear();
				i++;
			}
			else if (check_string == "exp")
			{
				Stack_with_symbol.push(EXP);
				check_string.clear();
				i++;
			}
			else if (check_string == "pi")
			{
				stack_with_numbers.push(pi);
			}
		}

		// Обработка чисел
		if ((tmp >= '0' && tmp <= '9') || tmp == '.')
		{
			size_t idx;
			double num = std::stod(&infix_time[i], &idx);
			stack_with_numbers.push(num);
			i += idx - 1; // Увеличиваем индекс на количество прочитанных символов
		}

		// Обработка скобок
		if (tmp == '(')
		{
			if (infix_time[i + 1] == '-' && i + 1 < infix_time.size())
			{
				size_t idx;
				double num = std::stod(&infix_time[i+1], &idx);
				stack_with_numbers.push(num);
				i += idx;
			}
			Stack_with_symbol.push(OPENED_BRECKET);
		}

		// Обработка закрывающей скобки
		if (tmp == ')')
		{
			Function a = Stack_with_symbol.pop();
			while (a != OPENED_BRECKET && a != SIN && a != COS && a != EXP)
			{
				double second_number = stack_with_numbers.pop();
				double first_number = stack_with_numbers.pop();
				double res = 0;

				switch (a)
				{
				case PLUS:
					res = first_number + second_number;
					break;
				case MINUS:
					res = first_number - second_number;
					break;
				case MULT:
					res = first_number * second_number;
					break;
				case DIV:
					if (second_number == 0)
						throw - 1;
					res = first_number / second_number;
					break;
				case DEGREE:
					res = pow(first_number, second_number);
					break;
				}
				stack_with_numbers.push(res);
				a = Stack_with_symbol.pop();
			}

			// Обработка функций
			if (a == SIN || a == COS || a == EXP)
			{
				double func_number_rad = stack_with_numbers.pop();
				//double func_number_rad = func_number * (pi / 180);
				double ress = 0;

				switch (a)
				{
				case SIN:
					ress = func_number_rad;
					for (int i = 3; i <= 25; i += 2) {
						double term = pow(func_number_rad, i) / Factorial(i);
						if (i % 4 == 3) {
							ress -= term; 
						}
						else {
							ress += term;
						}
					}
					ress = std::round(ress * 1000000) / 1000000;
					break;
				case COS:
					ress = 1; // Инициализация результата
					for (int i = 2; i <= 25; i += 2) {
						double term = pow(func_number_rad, i) / Factorial(i);
						if (i % 4 == 0) {
							ress += term; 
						}
						else {
							ress -= term;
						}
					}
					ress = std::round(ress * 1000000) / 1000000;
					break;
				case EXP:
					ress = 1; // Инициализация результата
					double term = 1; // Первый член (1)
					for (int i = 1; i <= 20; i++) { // Цикл от 1 до 13
						term *= func_number_rad / i; // Вычисляем текущий член ряда
						ress += term; // Добавляем текущий член к результату
					}
					ress = std::round(ress * 100000) / 100000;
					break;
				}
				stack_with_numbers.push(ress);
			}
			//continue;
		}

		// Обработка операторов
		if (tmp == '+' || tmp == '-' || tmp == '*' || tmp == '/' || tmp == '^')
		{
			Function op;
			switch (tmp)
			{
			case '+': op = PLUS; break;
			case '-': op = MINUS; break;
			case '*': op = MULT; break;
			case '/': op = DIV; break;
			case '^': op = DEGREE; break;
			}

			while (!Stack_with_symbol.isEmpty() && Priority(op) <= Priority(Stack_with_symbol.top()))
			{
				double second_number = stack_with_numbers.pop();
				double first_number = stack_with_numbers.pop();
				double res = 0;
				Function a = Stack_with_symbol.pop();

				switch (a)
				{
				case PLUS:
					res = first_number + second_number;
					break;
				case MINUS:
					res = first_number - second_number;
					break;
				case MULT:
					res = first_number * second_number;
					break;
				case DIV:
					if (second_number == 0)
						throw -1;
					res = first_number / second_number;
					break;
				case DEGREE:
					res = pow(first_number, second_number);
					break;
				}
				stack_with_numbers.push(res);
			}
			Stack_with_symbol.push(op);
		}
	}

	double result_with_stack = stack_with_numbers.pop();
	if (!stack_with_numbers.isEmpty())
		throw - 1;

	return result_with_stack;
}