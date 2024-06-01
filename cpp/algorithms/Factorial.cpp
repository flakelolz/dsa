#include <iostream>

int factorial(int n) {
  if (n == 1) return 1;
  return n * factorial(n - 1);
}

int main(int argc, char* argv[]) {
  int n = 4;

  std::cout << factorial(n) << std::endl;

  return 0;
}

// clang++ -std=c++20 Factorial.cpp -o Factorial ; ./Factorial
