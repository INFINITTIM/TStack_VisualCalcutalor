#include <iostream>
#include <iomanip>

#include "stack.h"
#include "calc.h"

int main()
{
	TCalc a;

	std::string str = "(exp(2)+(sin(pi/2))-3+1000*3)*100+(-1)";

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