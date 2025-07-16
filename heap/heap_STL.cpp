#include<iostream>
#include<queue>
using namespace std;

int main(){
    // Max Heap (default)
    priority_queue<int> pq;
    cout << "----Max Heap----" << endl;
    pq.push(45);
    pq.push(42);
    pq.push(56);
    pq.push(53);
    pq.push(26);
    cout << "Element at Top: " << pq.top() << endl;
    pq.pop();
    cout << "Element at Top: " << pq.top() << endl;

    pq.empty() ? cout << "Priority queue is Empty!" << endl : cout << "Not Empty." << endl;
    cout << "Size is: " << pq.size() << endl;

    // Min Heap
    priority_queue<int, vector<int>, greater<int>> min_heap;
    cout << "----Min Heap----" << endl;
    min_heap.push(45);
    min_heap.push(42);
    min_heap.push(56);
    min_heap.push(53);
    cout << "Element at Top: " << min_heap.top() << endl;
    min_heap.pop(); min_heap.pop();
    cout << "Element at Top: " << min_heap.top() << endl;

    min_heap.empty() ? cout << "Min Heap is Empty!" << endl : cout << "Not Empty." << endl;
    cout << "Size is: " << min_heap.size() << endl;

    return 0;
}