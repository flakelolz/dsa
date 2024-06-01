#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class Node {
 public:
  std::string key;
  int value;
  Node* next;

  Node(std::string key, int value) {
    this->key = key;
    this->value = value;
    next = nullptr;
  }
};

class HashTable {
 private:
  static const int SIZE = 7;
  Node* dataMap[SIZE];

  int hash(std::string key) {
    int hash = 0;
    for (int i = 0; i < key.length(); i++) {
      int asciiValue = int(key[i]);
      hash = (hash + asciiValue * 23) % SIZE;
    }
    return hash;
  }

 public:
  void set(std::string key, int value) {
    int index = hash(key);
    Node* newNode = new Node(key, value);

    if (!dataMap[index]) {
      dataMap[index] = newNode;
    } else {
      Node* temp = dataMap[index];
      while (temp->next) {
        temp = temp->next;
      }

      temp->next = newNode;
    }
  }

  int get(std::string key) {
    int index = hash(key);
    Node* temp = dataMap[index];
    while (temp) {
      if (temp->key == key) {
        return temp->value;
      }
      temp = temp->next;
    }

    return 0;
  }

  std::vector<std::string> keys() {
    std::vector<std::string> allKeys;
    for (int i = 0; i < SIZE; i++) {
      Node* temp = dataMap[i];

      while (temp) {
        allKeys.push_back(temp->key);
        temp = temp->next;
      }
    }

    return allKeys;
  }

  void print() {
    for (int i = 0; i < SIZE; i++) {
      std::cout << i << ":" << std::endl;
      if (dataMap[i]) {
        Node* temp = dataMap[i];
        while (temp) {
          // clang-format off
          std::cout << "   {" << temp->key << ", " << temp->value << "}" << std::endl;
          // clang-format on
          temp = temp->next;
        }
      }
    }
  }
};

bool itemInCommon(std::vector<int> vec1, std::vector<int> vec2) {
  std::unordered_map<int, bool> map;

  for (int i : vec1) {
    map.insert({i, true});
  }

  for (int j : vec2) {
    if (map[j]) {
      return true;
    }
  }

  return false;
}

int main(int argc, char* argv[]) {
  HashTable* table = new HashTable();
  table->set("nails", 100);
  table->set("tile", 50);
  table->set("lumber", 80);
  table->set("bolts", 200);
  table->set("screws", 140);
  table->set("paint", 20);

  table->print();

  std::vector<std::string> keys = table->keys();

  for (auto key : keys) {
    std::cout << key << " - ";
  }

  std::vector<int> vec1 = {1, 3, 5};
  std::vector<int> vec2 = {2, 4, 5};

  std::cout << std::endl << "Common: " << itemInCommon(vec1, vec2) << std::endl;

  return 0;
}

// clang++ -std=c++20 HashTable.cpp -o HashTable ; ./HashTable
