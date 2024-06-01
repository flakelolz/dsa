#include <iostream>
class Node {
 public:
  int value;
  Node* left;
  Node* right;

  Node(int value) {
    this->value = value;
    left = nullptr;
    right = nullptr;
  }
};

class BinarySearchTree {
 public:
  Node* root;
  BinarySearchTree() { root = nullptr; }

  bool insert(int value) {
    Node* newNode = new Node(value);
    if (!root) {
      root = newNode;
      return true;
    }

    Node* temp = root;

    while (true) {
      if (newNode->value == temp->value) return false;

      if (newNode->value < temp->value) {
        if (!temp->left) {
          temp->left = newNode;
          return true;
        }

        temp = temp->left;
      } else {
        if (!temp->right) {
          temp->right = newNode;
          return true;
        }

        temp = temp->right;
      }
    }
  }

  bool contains(int value) {
    Node* temp = root;

    while (temp) {
      if (value < temp->value) {
        temp = temp->left;
      } else if (value > temp->value) {
        temp = temp->right;
      } else {
        return true;
      }
    }
    return false;
  }
};

int main(int argc, char* argv[]) {
  BinarySearchTree* tree = new BinarySearchTree();
  tree->insert(47);
  tree->insert(21);
  tree->insert(76);
  tree->insert(18);
  tree->insert(52);
  tree->insert(82);

  tree->insert(27);

  std::cout << "Contains 27: " << tree->contains(27) << std::endl;
  std::cout << "Contains 84: " << tree->contains(84) << std::endl;

  return 0;
}

// clang-format off
// clang++ -std=c++20 BinarySearchTree.cpp -o BinarySearchTree ; ./BinarySearchTree
