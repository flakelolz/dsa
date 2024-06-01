#include <iostream>

void bubbleSort(int array[], int size) {
  for (int i = size - 1; i < size; i--) {
    for (int j = 0; j < i; j++) {
      if (array[j] > array[j + 1]) {
        int temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
      }
    }
  }
}

int main(int argc, char* argv[]) {
  int array[] = {6, 4, 2, 5, 1, 3};

  int size = sizeof(array) / sizeof(array[0]);

  bubbleSort(array, size);

  for (auto value : array) {
    std::cout << value << " ";
  }

  return 0;
}

// clang++ -std=c++20 BubbleSort.cpp -o BubbleSort ; ./BubbleSort
