#pragma once

#include <iostream>
#include "stack.h"
#include "string"

enum Function
{
	OPENED_BRECKET,
	PLUS,
	MINUS,
	MULT,
	DIV,
	DEGREE,
	SIN,
	COS,
	EXP
};


class TCalc
{
private:
	std::string infix;
	std::string postfix;

	TStack<double> stack_with_numbers;
	TStack<Function> Stack_with_symbol;

	bool Check(std::string str);
	int Priority(Function a);
	double Factorial(double number);
public:
	TCalc();

	void SetInfix(std::string str);
	std::string GetInfix();

	void SetPostfix(std::string str);
	std::string GetPostfix();

	void ToPostfix();

	double CalculatorPostfix();
	double Calculator();
};