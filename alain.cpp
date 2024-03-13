#include <iostream>
#include <random>
#include <vector>

std::vector<int> generate(int size)
{
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(1, 50);
    std::cout << "Maximum number" << generator.min() << "\n";
    std::cout << "minimum number" << generator.max() << "\n";
    std::vector<int> numbers(size);
    for (size_t i = 0; i < numbers.size(); ++i)
        numbers.at(i) = distribution(generator);
    return numbers;
}
void bubbleSort(std::vector<int> &numbers)
{
    int n = numbers.size();
    bool swapped;
    for (int i = 0; i < n - 1; ++i)
    {
        swapped = false;
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (numbers[j] > numbers[j + 1])
            {
                std::swap(numbers[j], numbers[j + 1]);
                swapped = true;
            }
        }
        // If no two elements were swapped in the inner loop, the array is already sorted
        if (!swapped)
            break;
    }
}

void selectionSort(std::vector<int> &numbers)
{
    int n = numbers.size();
    for (int i = 0; i < n - 1; ++i)
    {
        // Find the minimum element in unsorted array
        int min_index = i;
        for (int j = i + 1; j < n; ++j)
        {
            if (numbers[j] < numbers[min_index])
                min_index = j;
        }
        // Swap the found minimum element with the first element
        std::swap(numbers[min_index], numbers[i]);
    }
}

void insertionSort(std::vector<int> &numbers)
{
    int n = numbers.size();
    for (int i = 1; i < n; ++i)
    {
        int key = numbers[i];
        int j = i - 1;

        while (j >= 0 && numbers[j] > key)
        {
            numbers[j + 1] = numbers[j];
            j = j - 1;
        }
        numbers[j + 1] = key;
    }
}

// Partition function for Quick Sort
int partition(std::vector<int> &arr, int low, int high)
{
    int pivot = arr[high]; // Choose the last element as the pivot
    int i = (low - 1);     // Index of smaller element

    for (int j = low; j < high; ++j)
    {
        // If the current element is smaller than or equal to the pivot
        if (arr[j] <= pivot)
        {
            ++i;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// Quick Sort function
void quickSort(std::vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        // Partition the array and get the pivot index
        int pivotIndex = partition(arr, low, high);

        // Recursively sort the subarrays
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

void quickSort(std::vector<int> &numbers)
{
    int size = numbers.size();
    quickSort(numbers, 0, size - 1);
}
void merge(std::vector<int> &numbers, int left, int middle, int right)
{
    int n1 = middle - left + 1;
    int n2 = right - middle;

    std::vector<int> leftPart(n1);
    std::vector<int> rightPart(n2);

    for (int i = 0; i < n1; ++i)
        leftPart[i] = numbers[left + i];
    for (int j = 0; j < n2; ++j)
        rightPart[j] = numbers[middle + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        if (leftPart[i] <= rightPart[j])
        {
            numbers[k] = leftPart[i];
            i++;
        }
        else
        {
            numbers[k] = rightPart[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        numbers[k] = leftPart[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        numbers[k] = rightPart[j];
        j++;
        k++;
    }
}

void mergeSortHelper(std::vector<int> &numbers, int left, int right)
{
    if (left >= right)
        return;

    int middle = left + (right - left) / 2;
    mergeSortHelper(numbers, left, middle);
    mergeSortHelper(numbers, middle + 1, right);

    merge(numbers, left, middle, right);
}

void mergeSort(std::vector<int> &numbers)
{
    mergeSortHelper(numbers, 0, numbers.size() - 1);
}

bool isSorted(const std::vector<int> &numbers)
{
    for (size_t i = 0; i < numbers.size() - 1; ++i)
        if (numbers.at(i) > numbers.at(i + 1))
            return false;
    return true;
}
int main()
{
    std::vector<int> v1 = generate(100);
    bubbleSort(v1);
    if (isSorted(v1))
        std::cout << "sorted\n";
    /**
    std::vector<int> v2 = generate(100);
    selectionSort(v2);
    std::vector<int> v3 = generate(100);
    insertionSort(v3);
    std::vector<int> v4 = generate(100);
    quickSort(v4);
    std::vector<int> v5 = generate(100);
    mergeSort(v5);
    **/
}