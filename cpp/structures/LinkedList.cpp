#include <iostream>
#include <ostream>

class Node {
 public:
  int value;
  Node* next;

  Node(int value) {
    this->value = value;
    this->next = nullptr;
  }
};

class LinkedList {
 private:
  Node* head;
  Node* tail;
  int length;

 public:
  LinkedList(int value) {
    Node* newNode = new Node(value);
    this->head = newNode;
    this->tail = newNode;
    this->length = 1;
  }

  Node* get(int index) {
    if (index < 0 || index >= this->length) return nullptr;

    Node* temp = this->head;

    for (int i = 0; i < index; i++) {
      temp = temp->next;
    }

    return temp;
  }

  bool set(int index, int value) {
    Node* temp = this->get(index);

    if (temp != nullptr) {
      temp->value = value;
      return true;
    } else {
      return false;
    }
  }

  void append(int value) {
    Node* newNode = new Node(value);

    if (this->length == 0) {
      this->head = newNode;
      this->tail = newNode;
    } else {
      this->tail->next = newNode;
      this->tail = newNode;
    }

    this->length += 1;
  }

  void prepend(int value) {
    Node* newNode = new Node(value);

    if (this->length == 0) {
      this->head = newNode;
      this->tail = newNode;
    } else {
      newNode->next = this->head;
      this->head = newNode;
    }

    this->length += 1;
  }

  bool insert(int index, int value) {
    if (index < 0 || index > this->length) return false;

    if (index == 0) {
      this->prepend(value);
      return true;
    }

    if (index == this->length) {
      this->append(value);
      return true;
    }

    Node* newNode = new Node(value);
    Node* temp = this->get(index - 1);

    newNode->next = temp->next;
    temp->next = newNode;

    this->length += 1;

    return true;
  }

  Node* remove(int index) {
    if (index < 0 || index >= this->length) return nullptr;

    if (index == 0) {
      return this->removeFirst();
    }

    if (index == this->length - 1) {
      return this->removeLast();
    }

    Node* prev = this->get(index - 1);
    Node* temp = prev->next;

    prev->next = temp->next;
    temp->next = nullptr;

    this->length -= 1;

    return temp;
  }

  Node* removeFirst() {
    if (this->length == 0) return nullptr;

    Node* temp = this->head;
    this->head = this->head->next;
    temp->next = nullptr;

    this->length -= 1;

    if (this->length == 0) {
      this->tail = nullptr;
    }

    return temp;
  }

  Node* removeLast() {
    Node* temp = this->head;
    Node* prev = this->head;

    if (this->length == 0) return nullptr;

    while (temp->next != nullptr) {
      prev = temp;
      temp = temp->next;
    }

    this->tail = prev;
    this->tail->next = nullptr;
    this->length -= 1;

    if (this->length == 0) {
      this->head = nullptr;
      this->tail = nullptr;
    }

    return temp;
  }

  void reverse() {
    Node* temp = this->head;
    this->head = this->tail;
    this->tail = temp;

    Node* after = temp->next;
    Node* before = nullptr;

    for (int i = 0; i < this->length; i++) {
      after = temp->next;
      temp->next = before;
      before = temp;
      temp = after;
    }
  }

  void print() {
    Node* temp = this->head;
    while (temp != nullptr) {
      std::cout << temp->value << " -> ";
      temp = temp->next;
    }

    std::cout << "nullptr" << std::endl;
  }

  void getHead() { std::cout << "Head: " << this->head->value << std::endl; }
  void getTail() { std::cout << "Tail: " << this->tail->value << std::endl; }
  void getLength() { std::cout << "Length: " << this->length << std::endl; }
};

int main(int argc, char* argv[]) {
  LinkedList* list = new LinkedList(0);
  list->append(1);
  list->append(2);
  list->append(3);
  list->append(4);
  list->print();

  list->reverse();
  list->print();

  delete list;

  return 0;
}

// clang++ -std=c++20 LinkedList.cpp -o LinkedList ; ./LinkedList
