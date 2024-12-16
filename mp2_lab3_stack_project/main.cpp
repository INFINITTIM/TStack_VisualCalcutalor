#include <iostream>
#include <iomanip>

#include "stack.h"
#include "calc.h"

int main()
{
	TCalc a;

	std::string str = "3*34/sin(pi/2)+5^(exp(2)+(3+(-3)*45+(34+2)+11*(-1)))";

	a.SetInfix(str);

	double res;

	try
	{
		res = a.Calculator();

		std::cout << res << std::endl;

		//std::cout << std::fixed << std::setprecision(20) << res << std::endl;
	}
	catch (...)
	{
		std::cout << "incorrect";
	}
}