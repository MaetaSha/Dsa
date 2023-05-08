#include <iostream>
using namespace std;

void merge(int arr[], int left[], int leftSize, int right[], int rightSize) {
    int i = 0, j = 0, k = 0;

    while(i < leftSize && j < rightSize) {
        if(left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        }
        else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while(i < leftSize) {
        arr[k] = left[i];
        i++;
        k++;
    }

    while(j < rightSize) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int size) {
    if(size < 2) {
        return;
    }

    int mid = size / 2;
    int left[mid], right[size-mid];

    for(int i = 0; i < mid; i++) {
        left[i] = arr[i];
    }

    for(int i = mid; i < size; i++) {
        right[i-mid] = arr[i];
    }

    mergeSort(left, mid);
    mergeSort(right, size-mid);
    merge(arr, left, mid, right, size-mid);
}

int main() {
    int arr[50], n;
    cout<<"Enter the Size for Array: ";
    cin>>n;
    cout<<"Enter "<<n<<" Array Elements: ";
    for(int i=0; i<n; i++)
        cin>>arr[i];
    mergeSort(arr, n);

    // print the sorted array
    cout << "Sorted array: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
/*Algorithm 9.7: MERGE SORT(A, N) This algorithm sorts the N-clement array A using an auxili ...:r ray I. Set L . =. 1. [Initializes the number of elements in the suharrays. I2.Repeit Steps 3 to 6 while L. <N: 3.Call MERGEI'ASS(A, N, L, B). 4.Call MERGE-N. 2 * L. A). Set L:=4*I.. lEnd of Step 2 loop.] hixit.
