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

class Queue {
 private:
  Node* first;
  Node* last;
  int length;

 public:
  Queue(int value) {
    Node* newNode = new Node(value);
    first = newNode;
    last = newNode;
    length = 1;
  }

  void enqueue(int value) {
    Node* newNode = new Node(value);
    if (length == 0) {
      first = newNode;
      last = newNode;
    } else {
      last->next = newNode;
      last = newNode;
    }

    length++;
  }

  Node* dequeue() {
    if (length == 0) return nullptr;

    Node* temp = first;

    if (length == 1) {
      first = nullptr;
      last = nullptr;
    } else {
      first = first->next;
      temp->next = nullptr;
    }

    length--;
    return temp;
  }

  void print() {
    Node* temp = first;
    while (temp) {
      std::cout << temp->value << std::endl;
      temp = temp->next;
    }
  }

  void getFirst() { std::cout << "First: " << first->value << std::endl; }
  void getLast() { std::cout << "Last: " << last->value << std::endl; }
  void getLength() { std::cout << "Length: " << length << std::endl; }
};

int main(int argc, char* argv[]) {
  Queue* queue = new Queue(1);
  queue->enqueue(2);

  return 0;
}

// clang++ -std=c++20 Queue.cpp -o Queue ; ./Queue
