#include<iostream>
#include<vector>
using namespace std;

class Heap{
public:
    int arr[100];
    int size;

    Heap(){
        arr[0] = -1;
        size = 0;
    }

    // Insertion in Heap
    void insert(int val){
        size++;
        int idx=size;
        arr[idx] = val;

        while(idx > 1){
            int parent = idx/2;

            if(arr[parent] < arr[idx]) {
                swap(arr[parent], arr[idx]);
                idx = parent;
            } else return;
        }
    }

    // Deletion in Heap
    void deleteRoot(){
        if(size == 0) {
            cout << "nothing to delete" << endl;
            return;
        }
        
        // 1. put last node as root node 
        arr[1] = arr[size];
        // 2. Remove last node
        size--;

        // 3. Place the last (currently root node) to its correct place
        int i=1;
        while(i < size){
            int lIdx = 2*i; // left child index in array
            int rIdx = 2*i +1; // right child index in array

            if(lIdx < size && arr[lIdx] > arr[i]){
                swap(arr[lIdx], arr[i]);
                i = lIdx;
            }
            else if(rIdx < size && arr[rIdx] > arr[i]){
                swap(arr[rIdx], arr[i]);
                i = rIdx;
            } else return;
        }        
    }

    void print(){
        for(int i=1; i<=size; i++) cout << arr[i] << " ";

        cout<<endl; 
    }
};

// Making the root node heapified (preferred heap order)
void heapify(vector<int> &arr, int n, int i){
    int largest = i;
    int left = 2*i, right = 2*i + 1;

    if(left < n && arr[left] > arr[largest]) {
        largest = left;
    }
    if(right < n && arr[right] > arr[largest]){
        largest = right;
    }

    if(largest != i) {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
    return;        
}

void HeapSort(vector<int> &arr, int n){
    int t = n-1;

    while(t > 1){
        //1. swap first and current last element 
        swap(arr[t], arr[1]);
        t--;

        //2. heapify at the swapped node(index)
        heapify(arr, t, 1);
    }
}

int main(){
    Heap hp;

    hp.insert(55);
    hp.insert(56);
    hp.insert(48);
    hp.insert(35);
    hp.insert(25);
    hp.insert(46); cout << "Insertion: ";
    hp.print();
    hp.deleteRoot(); cout << "Deletion: ";
    hp.print(); // Time Complexity: O(logN)

    vector<int> arr = {-1, 43, 56, 54, 34, 87}; // 1-based indexing
    int n = arr.size();

    cout << "Printing Before Heapify" << endl;
    for(int i=1; i<n; i++) cout << arr[i] << " ";
    cout<<endl;

    for(int i=n/2; i>0; i--){
        heapify(arr, n, i);
    }

    cout << "Printing After Heapify(Max Heap)" << endl;
    for(int i=1; i<n; i++) cout << arr[i] << " ";
    cout<<endl;

    HeapSort(arr, n);

    cout << "After Heap Sort" << endl;
    for(int i=1; i<n; i++) cout << arr[i] << " ";
    cout<<endl;

    return 0;
}

/* Output : 
Insertion: 56 55 48 35 25 46 
Deletion: 55 46 48 35 25 
Printing Before Heapify
43 56 54 34 87 
Printing After Heapify(Max Heap)
87 56 54 34 43 
After Heap Sort
34 54 43 56 87 
*/

/*
What is HEAP?

It is a CBT (Complete Binary Tree) that satisfies the heap property:
- for every node, the value of its children is greater than or equal to its own value(depending upon max heap or min heap)
- where the smallest (or largest) element is always at the root of the tree.

Insertion and deletion in heap takes O(logN) time.

Insert(x)           ->  Add at end & heapify up	                            ->  O(log n)
Delete Root         ->  Swap root with last, remove last, heapify down      ->  O(log n)
Heapify (At Index)  -> 	Builds maxHeap or minHeap at a particular node/idx  ->  O(log n)

*/