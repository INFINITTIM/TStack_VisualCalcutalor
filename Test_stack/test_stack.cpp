#include "../mp2_lab3_stack_project/stack.h"
#include "../mp2_lab3_stack_project/calc.h"
#include "../mp2_lab3_stack_project/calc.cpp"

#include "gtest.h"


TEST(TStack, can_create_stack_with_positive_size)
{
  ASSERT_NO_THROW(TStack<int> m(5));
}

TEST(TStack, throws_when_create_stack_with_negative_length)
{
	ASSERT_ANY_THROW(TStack<int> m(-5));
}

TEST(TStack, can_create_copied_stack)
{
	TStack<int> m(5);

	ASSERT_NO_THROW(TStack<int> m1(m));
}

TEST(TStack, copied_stack_is_equal_to_source_one)
{
	TStack<int> m(5);
	TStack<int> m1(m);
	EXPECT_EQ(m, m1);
}

TEST(TStack, empty_stack)
{
    TStack<int>m(5);
    ASSERT_NO_THROW(m.Empty() == true);
}

TEST(TStack, no_empty_stack)
{
    TStack<int>m(5);
    m.Push(1);
    ASSERT_NO_THROW(m.Empty() == false);
}
TEST(TStack, full_stack)
{
    TStack<int>m(2);
    m.Push(5);
    m.Push(2);
    ASSERT_NO_THROW(m.Full() == true);
}
TEST(TStack, no_full_stack) {
    TStack<int>m(5);
    m.Push(5);
    m.Push(10);
    ASSERT_NO_THROW(m.Full() == false);
}
TEST(TStack, empty_stack_with_pop_element) {
    TStack<int>m(1);
    m.Push(2);
    m.Pop();
    ASSERT_NO_THROW(m.Empty() == true);
}
TEST(TStack, pop_function) {
    TStack<int>m(3);
    m.Push(2);
    m.Push(3);
    m.Push(10);
    int a = 3;
    m.Pop();
    ASSERT_NO_THROW(m.Top() == a);
}

TEST(TStack, clear_stack) {
    TStack<int>m(2);
    m.Push(5);
    m.clear();
    ASSERT_NO_THROW(m.Empty() == true);
}
TEST(TStack, compare_stacks) {
    TStack<int>m(2);
    m.Push(5);
    m.Push(2);
    TStack<int>m1(m);
    ASSERT_NO_THROW(m == m1);

}
TEST(TStack, no_compare_stack) {
    TStack<int>m(2);
    TStack<int>m1(m);
    m.Push(5);
    m.Push(10);
    m1.Push(10);
    m1.Push(5);
    ASSERT_NO_THROW(m != m1);
}

TEST(TStack, check_clear_stack) {
    TStack<int>m(5);
    m.Push(2);
    m.Push(3);
    m.clear();
    ASSERT_NO_THROW(m.Empty());
}

TEST(TStack, stacks_with_different_size_are_not_equal)
{
    const int size1 = 5, size2 = 10;
    TStack<int> s1(size1), s2(size2);
    for (int i = 0; i < size1; i++) s1.Push(i);
    for (int j = 0; j < size2; j++) s2.Push(j);
    EXPECT_EQ(s1 != s2, 1);
}

TEST(TCalc, add_in_calc)
{
    TCalc a;
    std::string str = "2+2";
    a.SetInfix(str);
    double res = 4;
    double my_res = a.Calculator();
    EXPECT_EQ(res, my_res);
}

TEST(TCalc, sub_in_calc)
{
    TCalc a;
    std::string str = "10-2";
    a.SetInfix(str);
    double res = 8;
    double my_res = a.Calculator();
    EXPECT_EQ(res, my_res);
}


TEST(TCalc, mult_in_calc)
{
    TCalc a;
    std::string str = "2*22";
    a.SetInfix(str);
    double res = 44;
    double my_res = a.Calculator();
    EXPECT_EQ(res, my_res);
}

TEST(TCalc, div_in_calc)
{
    TCalc a;
    std::string str = "4/2";
    a.SetInfix(str);
    double res = 2;
    double my_res = a.Calculator();
    EXPECT_EQ(res, my_res);
}

TEST(TCalc, cant_div_for_none_in_calc)
{
    TCalc a;
    std::string str = "4/0";
    a.SetInfix(str);
    double my_res;
    ASSERT_ANY_THROW(my_res = a.Calculator());
}

TEST(TCalc, degree_in_calc)
{
    TCalc a;
    std::string str = "4^2";
    a.SetInfix(str);
    double res = 16;
    double my_res = a.Calculator();
    EXPECT_EQ(res, my_res);
}

TEST(TCalc, sin_in_calc)
{
    TCalc a;
    std::string str = "sin(pi)";
    a.SetInfix(str);
    double res = 0;
    double my_res = a.Calculator();
    EXPECT_EQ(res, my_res);
}

TEST(TCalc, cos_in_calc)
{
    TCalc a;
    std::string str = "cos(pi)";
    a.SetInfix(str);
    double res = -1;
    double my_res = a.Calculator();
    EXPECT_EQ(res, my_res);
}


TEST(TCalc, exp_in_calc)
{
    TCalc a;
    std::string str = "exp(2)";
    a.SetInfix(str);
    double res = 7.38906;
    double my_res = a.Calculator();
    EXPECT_EQ(res, my_res);
}


TEST(TCalc, hard_expression_in_calc)
{
    TCalc a;
    std::string str = "3*34/sin(pi/2)+5^(exp(2)+(3+(-3)*45+(34+2)+11*(-1)))";
    a.SetInfix(str);
    double res = 102;
    double my_res = a.Calculator();
    EXPECT_EQ(res, my_res);
}

TEST(TCalc, wrong_scobs)
{
    TCalc m;
    std::string str2 = "((2+5)+5";
    m.SetInfix(str2);
    ASSERT_ANY_THROW(m.Calculator());
}

TEST(TCalc, wrong_arg)
{
    TCalc m;
    std::string str = "1+1+-";
    m.SetInfix(str);
    ASSERT_ANY_THROW(m.Calculator());
}