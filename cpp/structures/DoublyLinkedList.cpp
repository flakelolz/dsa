#include <iostream>

class Node {
 public:
  int value;
  Node* next;
  Node* prev;

  Node(int value) {
    this->value = value;
    this->next = nullptr;
    this->prev = nullptr;
  }
};

class DoublyLinkedList {
 private:
  Node* head;
  Node* tail;
  int length;

 public:
  DoublyLinkedList(int value) {
    Node* newNode = new Node(value);
    this->head = newNode;
    this->tail = newNode;
    this->length = 1;
  }

  void append(int value) {
    Node* newNode = new Node(value);

    if (length == 0) {
      head = newNode;
      tail = newNode;
    } else {
      tail->next = newNode;
      newNode->prev = tail;
      tail = newNode;
    }

    length++;
  }

  void prepend(int value) {
    Node* newNode = new Node(value);

    if (length == 0) {
      head = newNode;
      tail = newNode;
    } else {
      newNode->next = head;
      head->prev = newNode;
      head = newNode;
    }

    length++;
  }

  Node* removeFirst() {
    if (length == 0) return nullptr;

    Node* temp = head;
    if (length == 1) {
      head = nullptr;
      tail = nullptr;
    } else {
      head = head->next;
      head->prev = nullptr;
      temp->next = nullptr;
    }

    length--;
    return temp;
  }

  Node* removeLast() {
    if (length == 0) return nullptr;

    Node* temp = tail;

    if (length == 1) {
      head = nullptr;
      tail = nullptr;
    } else {
      tail = tail->prev;
      tail->next = nullptr;
      temp->prev = nullptr;
    }

    length--;
    return temp;
  }

  Node* get(int index) {
    if (index < 0 || index >= length) return nullptr;

    Node* temp = head;

    if (index < length / 2) {
      for (int i = 0; i < index; i++) {
        temp = temp->next;
      }
    } else {
      temp = tail;
      for (int i = length - 1; i > index; i--) {
        temp = temp->prev;
      }
    }

    return temp;
  }

  bool set(int index, int value) {
    if (length == 0) return false;

    Node* temp = get(index);

    if (temp) {
      temp->value = value;
      return true;
    }

    return false;
  }

  bool insert(int index, int value) {
    if (index < 0 || index > length) return false;

    Node* newNode = new Node(value);
    if (index == 0) {
      prepend(value);
      return true;
    }
    if (index == length) {
      append(value);
      return true;
    }

    Node* before = get(index - 1);
    Node* after = before->next;

    newNode->prev = before;
    newNode->next = after;
    before->next = newNode;
    after->prev = newNode;

    length++;
    return true;
  }

  Node* remove(int index) {
    if (index < 0 || index >= length) return nullptr;
    if (index == 0) {
      return removeFirst();
    }
    if (index == length - 1) {
      return removeLast();
    }

    Node* temp = get(index);

    temp->next->prev = temp->prev;
    temp->prev->next = temp->next;
    temp->next = nullptr;
    temp->prev = nullptr;

    length--;
    return temp;
  }

  void print() {
    Node* temp = this->head;
    std::cout << " <- ";

    while (temp != nullptr) {
      std::cout << temp->value;

      if (temp->next != nullptr) {
        std::cout << " <-> ";
      }

      temp = temp->next;
    }
    std::cout << " -> " << std::endl;
  }

  void getHead() { std::cout << "Head: " << this->head->value << std::endl; }

  void getTail() { std::cout << "Tail: " << this->tail->value << std::endl; }

  void getLength() { std::cout << "Length: " << this->length << std::endl; }
};

int main(int argc, char* argv[]) {
  DoublyLinkedList* list = new DoublyLinkedList(0);
  list->prepend(1);
  list->prepend(2);
  list->prepend(3);

  list->print();

  list->remove(3);
  list->print();

  delete list;

  return 0;
}

// clang-format off
// clang++ -std=c++20 DoublyLinkedList.cpp -o DoublyLinkedList ; ./DoublyLinkedList

