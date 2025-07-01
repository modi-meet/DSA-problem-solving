#include<iostream>
#include<vector>
using namespace std;

void bubble_sort(vector<int>& arr){
    int n = arr.size();

    for(int r=n-1; r>=0; r--){
        bool swapped = false;  // slight optimization
        for(int l=0; l<=r-1; l++){
            if(arr[l] > arr[l+1]){
                int temp = arr[l+1];
                arr[l+1] = arr[l];
                arr[l] = temp;
                //swap(arr[j], arr[j-1]);
                swapped = true;
            }
        }
        if(swapped == false) break; // early break
    }
}

int main(){
    vector<int> arr = {-2, -112, -1, 34, 5, 22, 6};

    for(auto x : arr){
        cout << x << " ";
    } cout << endl;
    bubble_sort(arr);
    for(auto x : arr){
        cout << x << " ";
    }
    
    return 0;
}
// OUTPUT - 
// -2 -112 -1 34 5 22 6 
// -112 -2 -1 5 6 22 34 

/* How Bubble Sort works?
- place largest element to the end of the array in each iteration
- for current window(l to r) set the largest element to the end
- each iteration ensures that array after r pointer is at least sorted; as largest element till r is pushed to the end.

TIME COMPLEXITY : O(N^2) (Worst case)/(Average complexity)
                  O(N) (Best case - array is sorted already)
*/
