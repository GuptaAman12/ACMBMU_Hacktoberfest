#include <iostream>
using namespace std;

const int MAX_SIZE = 100;
int arr[MAX_SIZE];
int currentSize = 0;

void traverse() {
    for (int i = 0; i < currentSize; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertBeginning(int value) {
    if (currentSize < MAX_SIZE) {
        for (int i = currentSize; i > 0; --i) {
            arr[i] = arr[i - 1];
        }
        arr[0] = value;
        ++currentSize;
    } else {
        cout << "Array is full. Cannot insert." << endl;
    }
}

void insertEnd(int value) {
    if (currentSize < MAX_SIZE) {
        arr[currentSize] = value;
        ++currentSize;
    } else {
        cout << "Array is full. Cannot insert." << endl;
    }
}

void insertRandom(int key, int value){
    int i = 0;
    while (arr[i] != key){
        i++;
    }
    int x = i+1; 
    while (i < currentSize){
        i++;
    }
    while (i != x){
        arr[i] = arr[i-1];
        i--;
    }
    currentSize ++;
    arr[x] = value;

}
