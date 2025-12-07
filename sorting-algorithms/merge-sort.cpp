#include<bits/stdc++.h>
using namespace std;

void merge(int st, int mid, int end, vector<int> &arr) {

    int n1 = mid - st + 1;
    int n2 = end - mid; 

    vector<int> L(n1), R(n2);
    
    for(int i=0; i<n1; i++) L[i] = arr[st + i];
    for(int i=0; i<n2; i++) R[i] = arr[mid+1 + i];
    
    int i=0, j=0, k = st;
    while(i < n1 && j < n2) {
        if(L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while(i < n1) arr[k++] = L[i++];
    while(j < n2) arr[k++] = R[j++];
}

void mergeSort(int i, int j, vector<int> &arr){
    if(i >= j) return;

    int mid = i + (j-i)/2;

    mergeSort(i, mid, arr);
    mergeSort(mid+1, j, arr);

    merge(i, mid, j, arr);
}

int main() {
    vector<int> arr = {3, 34, 5, 1, 84, 24};
    cout << "Before sort: ";
    for(int x : arr) cout << x << " ";
    cout << endl;

    int n = arr.size();

    mergeSort(0, n-1, arr);
    cout << "After sort: ";
    for(int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}

// Time Complexity : O(N*logN)
// Space complexity: O(N) (L and R) + O(logN) (recursion)