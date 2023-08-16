#include <iostream>

using namespace std;

/**
* Helper function for bubble sort
*/
void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}
/**
* In bubble sort we start comparing from first two elements
* and then swap if left param is greater. if not then we
* move next step. Keep doing this and one complete iteration
* will set biggest item at end of the list. Now last item is
* sorted so we will not touch it and work on rest of the array.
* Keep doing this and you will get sorted array. Complexity is
* O(squareof n)
*
* Not the best , but easiest sorting mechanism
*/
void bubbleSort(int arr[], int size) {
    for (int i = size - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

/**
 * Steps for Merge Sort:
 * 1. Merge Sort works on divide and conquer.
 * 2. We use two functions main function and a helper function.
 * 3. Helper function merge two sorted arrays. It needs array, leftIndex, midIndex, rightIndex as arguments.
 * 4. arguments needed by helper function are passed by mergeSort function.
 * 5. mergeSort function need array, left and right index as 3 arguments.
 * 6. when doing merge on two sorted arrays: midIndex is counted in left array and rightarray starts from midIndex+1.
*/

/**
*   Helper function for Merge Sort :
*   this function can sort two array that are already sorted.
*   Both arrays are subarrays in a big array. so big array's
*   left, mid and right index are passed to this function.
*
*   left and right arrays are passed into two new arrays and
*   then we compare their items and put them back in array
*   which becomes sorted.
*
*/
void merge(int array[], int leftIndex, int midIndex, int rightIndex) {

    // to create two arrays we take leftArraySize and rightArraySize
    int leftArraySize = midIndex - leftIndex + 1;
    int rightArraySize = rightIndex - midIndex;

    // create two dynamic arrays - left and right   
    // unique_ptr<int[]> replaced by auto
    auto leftArray = make_unique<int[]>(leftArraySize);
    auto rightArray = make_unique<int[]>(rightArraySize);

    // load left dynamic array
    for (int i = 0; i < leftArraySize; i++) {
        leftArray[i] = array[leftIndex + i];
    }

    // load right dynamic array
    for (int i = 0; i < rightArraySize; i++) {
        rightArray[i] = array[midIndex + 1 + i];
    }

    int index = leftIndex;  // first item in sub array and used to put back in main array
    int i = 0;
    int j = 0;

    while (i < leftArraySize && j < rightArraySize) {
        if (leftArray[i] <= rightArray[j]) {
            array[index] = leftArray[i];
            index++;
            i++;
        }
        else {
            array[index] = rightArray[j];
            j++;
            index++;
        }
    }

    while (i < leftArraySize) {
        array[index] = leftArray[i];
        index++;
        i++;
    }

    while (j < rightArraySize) {
        array[index] = rightArray[j];
        index++;
        j++;
    }
}


/**
* One of the most efficient way to sort an array. It is
* O(log n) as complexity. It works on the basis of divide
* and conquer with help of recursion. You split array of
* size n into n arrays of single element. Now you sort them.
* Now create sorted arrays of 2 with 2 adjacent items for
* each. Now create new arrays by again mixing 2 arrays of
* size 2 each. Keep going and you will get sorted array
* in O(log n).
*
* Here in algorithm we keep calling mergeSort recursively
* first to reach smallest sub array on the left and then
* small sub array on the right. and on the smallest sub arrays
* we call merge() to merge them. Then we keep moving upword
* to bigger sub arrays and keep calling merge function.
*/
void mergeSort(int arr[], int leftIndex, int rightIndex) {
    if (leftIndex >= rightIndex) return;

    // here leftIndex is added only because what if leftIndex is not zero then calculations wont be correct.
    int midIndex = leftIndex + (rightIndex - leftIndex) / 2;

    mergeSort(arr, leftIndex, midIndex);
    mergeSort(arr, midIndex + 1, rightIndex);

    merge(arr, leftIndex, midIndex, rightIndex);
}

int main()
{
    int arr[] = { 6,4,2,5,1,3 };
    int size = sizeof(arr) / sizeof(int);
    cout << "size of array is " << size << endl;
    cout << "array before bubble sort is ";
    for (auto i : arr) {
        cout << i << " ";
    }
    cout << endl;

    bubbleSort(arr, size);
    cout << "array after bubble sort is ";
    for (auto i : arr) {
        cout << i << " ";
    }
    cout << endl;

    int arr1[] = { 5, 1, 7, 99, 2, 8 };
    size = sizeof(arr1) / sizeof(int);
    int rightIndex = size - 1;
    int leftIndex = 0;
    
    cout << "array before merge sort is ";
    for (auto i : arr1) {
        cout << i << " ";
    }
    cout << endl;

    mergeSort(arr1, leftIndex, rightIndex);
    cout << "array after merge sort is ";
    for (auto i : arr1) {
        cout << i << " ";
    }
    cout << endl;
}
