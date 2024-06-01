#include <iostream>

void insertionSort(int array[], int size) {
  for (int i = 1; i < size; i++) {
    int temp = array[i];
    int j = i - 1;

    while (j > -1 && temp < array[j]) {
      array[j + 1] = array[j];
      array[j] = temp;
      j--;
    }
  }
}

int main(int argc, char* argv[]) {
  int array[] = {6, 4, 2, 5, 1, 3};
  int size = sizeof(array) / sizeof(array[0]);

  insertionSort(array, size);

  for (auto value : array) {
    std::cout << value << " ";
  }

  return 0;
}

// clang++ -std=c++20 InsertionSort.cpp -o InsertionSort ; ./InsertionSort
