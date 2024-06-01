#include <iostream>
void swap(int array[], int firstIndex, int secondIndex) {
  int temp = array[firstIndex];
  array[firstIndex] = array[secondIndex];
  array[secondIndex] = temp;
}

int pivot(int array[], int pivotIndex, int endIndex) {
  int swapIndex = pivotIndex;

  for (int i = pivotIndex + 1; i <= endIndex; i++) {
    if (array[i] < array[pivotIndex]) {
      swapIndex++;
      swap(array, swapIndex, i);
    }
  }

  swap(array, pivotIndex, swapIndex);

  return swapIndex;
}

void quickSort(int array[], int leftIndex, int rightIndex) {
  if (leftIndex >= rightIndex) return;

  int pivotIndex = pivot(array, leftIndex, rightIndex);
  quickSort(array, leftIndex, pivotIndex - 1);
  quickSort(array, pivotIndex + 1, rightIndex);
}

int main(int argc, char* argv[]) {
  int array[] = {4, 6, 1, 7, 3, 2, 5};

  int size = sizeof(array) / sizeof(array[0]);

  int returnedIndex = pivot(array, 0, size - 1);

  std::cout << "Returned: " << returnedIndex << "\n\n";

  for (auto value : array) {
    std::cout << value << " ";
  }

  return 0;
}

// clang++ -std=c++20 QuickSort.cpp -o QuickSort ; ./QuickSort
