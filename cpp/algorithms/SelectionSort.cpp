#include <iostream>
void selectionSort(int array[], int size) {
  for (int i = 0; i < size; i++) {
    int minIndex = i;
    for (int j = i + 1; j < size; j++) {
      if (array[j] < array[minIndex]) {
        minIndex = j;
      }
    }

    if (i != minIndex) {
      int temp = array[i];
      array[i] = array[minIndex];
      array[minIndex] = temp;
    }
  }
}

int main(int argc, char* argv[]) {
  int array[] = {6, 4, 2, 4, 1, 3};
  int size = sizeof(array) / sizeof(array[0]);

  selectionSort(array, size);

  for (auto value : array) {
    std::cout << value << " ";
  }

  return 0;
}

// clang++ -std=c++20 SelectionSort.cpp -o SelectionSort ; ./SelectionSort
