#include "test_framework.h"

int add(int x, int y) {
    return x + y;
}

TEST(ArithmeticTest, BasicOperations) {
    int a = 5, b = 3;
    int sum = a + b;
    int difference = a - b;
    int product = a * b;
    int quotient = a / b;

    ASSERT_TRUE(sum == 8);
    ASSERT_TRUE(difference == 2);
    ASSERT_FALSE(product != 15);
    ASSERT_FALSE(quotient != 1);
}

TEST(FunctionTest, AddFunction) {
    ASSERT_TRUE(add(2, 3) == 5);
    ASSERT_TRUE(add(-1, 1) == 0);
    ASSERT_TRUE(add(0, 0) == 0);
    ASSERT_TRUE(add(-5, -5) == -10);
}

int main() {
    TestRegistry::instance().runAll();
    return 1;
}
