#include "../mp2_lab3_stack_project/stack.h"
#include "../mp2_lab3_stack_project/calc.h"
#include "../mp2_lab3_stack_project/calc.cpp"

#include "gtest.h"

TEST(LLStack, can_create_stack)
{
    ASSERT_NO_THROW(LLStack<int> m);
}

TEST(LLStack, can_create_copied_stack) {
    LLStack<int> m;
    m.push(1);
    ASSERT_NO_THROW(LLStack<int> m1(m));
}

TEST(LLStack, empty_stack) {
    LLStack<int> m;
    EXPECT_TRUE(m.isEmpty());
}

TEST(LLStack, no_empty_stack) {
    LLStack<int> m;
    m.push(1);
    EXPECT_FALSE(m.isEmpty());
}

TEST(LLStack, full_stack) {
    LLStack<int> m;
    EXPECT_FALSE(m.isFull());
}

TEST(LLStack, no_full_stack) {
    LLStack<int> m;
    m.push(5);
    m.push(10);
    EXPECT_FALSE(m.isFull());
}

TEST(LLStack, empty_stack_with_pop_element) {
    LLStack<int> m;
    m.push(2);
    m.pop();
    EXPECT_TRUE(m.isEmpty());
}

TEST(LLStack, pop_function) {
    LLStack<int> m;
    m.push(3);
    m.push(10);
    m.pop();
    EXPECT_EQ(m.top(), 3);
}

TEST(LLStack, clear_stack) {
    LLStack<int> m;
    m.push(5);
    m.clr();
    EXPECT_TRUE(m.isEmpty());
}

TEST(LLStack, compare_stacks) {
    LLStack<int> m;
    m.push(5);
    m.push(2);

    LLStack<int> m1(m);
    EXPECT_EQ(m, m1);
}

TEST(LLStack, no_compare_stack) {
    LLStack<int> m;
    LLStack<int> m1;
    m.push(5);
    m.push(10);

    m1.push(10);
    m1.push(5);

    EXPECT_NE(m, m1);
}

TEST(LLStack, throws_when_try_pop_elem_from_empty_stack) {
    LLStack<int> m;
    EXPECT_ANY_THROW(m.pop());
}

TEST(LLStack, throws_when_try_push_elem_when_no_memory) {
    LLStack<int> m;
    ASSERT_NO_THROW(m.push(3));
}

TEST(LLStack, copied_stack_is_equal_to_source_one) {
    LLStack<int> m;
    m.push(1);
    m.push(2);
    LLStack<int> m1(m);
    EXPECT_EQ(m, m1);
}

TEST(LLStack, stacks_with_different_content_not_equal) {
    LLStack<int> m;
    LLStack<int> m1;
    m.push(1);
    m1.push(2);
    EXPECT_NE(m, m1);
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
    double my_res = a.Calculator();
    EXPECT_EQ(-1, my_res);
}


TEST(TCalc, exp_in_calc)
{
    TCalc a;
    std::string str = "exp(2)";
    a.SetInfix(str);
    double my_res = a.Calculator();
    EXPECT_EQ(7.38906, my_res);
}


TEST(TCalc, hard_expression_in_calc)
{
    TCalc a;
    std::string str = "(exp(2)+(sin(pi/2))-3+1000*3)*100+(-1)";
    a.SetInfix(str);
    double my_res = a.Calculator();
    EXPECT_EQ(300537.906, my_res);
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