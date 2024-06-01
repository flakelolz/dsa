#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

class Graph {
 private:
  std::unordered_map<std::string, std::unordered_set<std::string>> adjList;

 public:
  bool addVertex(std::string vertex) {
    if (adjList.count(vertex) == 0) {
      adjList[vertex];
      return true;
    }

    return false;
  }

  bool addEdge(std::string vertex1, std::string vertex2) {
    if (adjList.count(vertex1) != 0 && adjList.count(vertex2) != 0) {
      adjList.at(vertex1).insert(vertex2);
      adjList.at(vertex2).insert(vertex1);
      return true;
    }

    return false;
  }

  bool removeEdge(std::string vertex1, std::string vertex2) {
    if (adjList.count(vertex1) != 0 && adjList.count(vertex2) != 0) {
      adjList.at(vertex1).erase(vertex2);
      adjList.at(vertex2).erase(vertex1);
      return true;
    }

    return false;
  }

  bool removeVertex(std::string vertex) {
    if (adjList.count(vertex) == 0) return false;
    for (auto otherVertex : adjList.at(vertex)) {
      adjList.at(otherVertex).erase(vertex);
    }
    adjList.erase(vertex);
    return true;
  }

  void print() {
    for (auto [vertex, edges] : adjList) {
      std::cout << vertex << ": [ ";
      for (auto edge : edges) {
        std::cout << edge << " ";
      }
      std::cout << "]" << std::endl;
    }
  }
};

int main(int argc, char* argv[]) {
  Graph* graph = new Graph();
  graph->addVertex("A");
  graph->addVertex("B");
  graph->addVertex("C");
  graph->addVertex("D");
  graph->addEdge("A", "B");
  graph->addEdge("A", "C");
  graph->addEdge("A", "D");
  graph->addEdge("B", "D");
  graph->addEdge("C", "D");

  graph->removeVertex("D");

  graph->print();

  return 0;
}

// clang++ -std=c++20 Graph.cpp -o Graph ; ./Graph
