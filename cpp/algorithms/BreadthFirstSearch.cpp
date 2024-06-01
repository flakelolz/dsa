#include <iostream>
#include <queue>

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

  void BFS() {
    std::queue<Node*> queue;
    queue.push(root);

    while (queue.size() > 0) {
      Node* currentNode = queue.front();
      queue.pop();
      std::cout << currentNode->value << " ";

      if (currentNode->left) {
        queue.push(currentNode->left);
      }
      if (currentNode->right) {
        queue.push(currentNode->right);
      }
    }
  }
};

int main(int argc, char* argv[]) {
  BinarySearchTree* tree = new BinarySearchTree();
  tree->insert(47);
  tree->insert(21);
  tree->insert(76);
  tree->insert(18);
  tree->insert(27);
  tree->insert(52);
  tree->insert(82);

  tree->BFS(); // 47 21 76 18 27 52 82

  return 0;
}

// clang-format off
// clang++ -std=c++20 BreadthFirstSearch.cpp -o BreadthFirstSearch ; ./BreadthFirstSearch
