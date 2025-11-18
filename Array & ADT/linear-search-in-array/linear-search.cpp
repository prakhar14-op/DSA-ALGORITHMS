#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr) / sizeof(arr[0]);

    int num, index = -1; 
    cout << "Enter the element to be searched: ";
    cin >> num;
    for (int i = 0; i < size; i++) {
        if (arr[i] == num) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        cout << "Element found at index: " << index << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}