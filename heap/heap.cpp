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

int main(){
    Heap hp;

    hp.insert(55);
    hp.insert(56);
    hp.insert(48);
    hp.insert(35);
    hp.insert(25);
    hp.insert(46);
    hp.print();
    hp.deleteRoot();
    hp.print(); // Time Complexity: O(logN)

    vector<int> arr = {-1, 43, 56, 54, 34, 87};
    int n = arr.size();

    for(int i=n/2; i>0; i--){
        heapify(arr, n, i);
    }

    cout << "Printing now" << endl;
    for(int i=1; i<n; i++) cout << arr[i] << " ";
    cout<<endl;

    return 0;
}

/* Output : 
56 55 48 35 25 46 
55 46 48 35 25 
Printing now
87 56 54 34 43
*/

/*
What is HEAP?

It is a CBT (Complete Binary Tree) that satisfies the heap property:
- for every node, the value of its children is greater than or equal to its own value(depending upon max heap or min heap)
- where the smallest (or largest) element is always at the root of the tree.

Insertion and deletion in heap takes O(logN) time.
*/