
#include <iostream>
class Node {
 public:
  int value;
  Node* next;

  Node(int value) {
    this->value = value;
    next = nullptr;
  }
};

class Stack {
 private:
  Node* top;
  int height;

 public:
  Stack(int value) {
    Node* newNode = new Node(value);
    top = newNode;
    height = 1;
  }

  void push(int value) {
    Node* newNode = new Node(value);

    newNode->next = top;
    top = newNode;

    height++;
  }

  Node* pop() {
    if (height == 0) return nullptr;

    Node* temp = top;
    top = top->next;
    temp->next = nullptr;

    height--;
    return temp;
  }

  void print() {
    Node* temp = top;
    while (temp) {
      std::cout << temp->value << std::endl;
      temp = temp->next;
    }
  }

  void getTop() { std::cout << "Top: " << top->value << std::endl; }
  void getHeight() { std::cout << "Height: " << height << std::endl; }
};

int main(int argc, char* argv[]) {
  Stack* stack = new Stack(1);
  stack->push(2);
  stack->push(3);

  stack->print();

  return 0;
}

// clang++ -std=c++20 Stack.cpp -o Stack ; ./Stack
