#include <iostream>

using namespace std;

int main() {

    int n = 5; // size of array

    int arr[n] = {5, 2, 4, 6, 1}; // array to be sorted

    // bubble sort algorithm

    for(int i = 0; i < n-1; i++) {

        for(int j = 0; j < n-i-1; j++) {

            if(arr[j] > arr[j+1]) {

                // swap arr[j] and arr[j+1]

                int temp = arr[j];

                arr[j] = arr[j+1];

                arr[j+1] = temp;

            }

        }

    }

    // print the sorted array

    cout << "Sorted array: ";

    for(int i = 0; i < n; i++) {

        cout << arr[i] << " ";

    }

    cout << endl;

    return 0;

}
