// Smallest Number in Infinite Set
// SmallestInfiniteSet() - Initializes object to contain all positive integers[1,2,3,4,5,...].
// int popSmallest() - Removes and returns the smallest integer contained in the infinite set.
// void addBack(int num) - Adds a `num` back into the infinite set, if it is not already in the infinite set.

// Appraoch 1
class SmallestInfiniteSet {
    int i;
    vector<bool> num;
public:
    SmallestInfiniteSet() {
        num = vector<bool>(1001, true);
        i = 1;
    }
    
    int popSmallest() {   
        int ans = i;
        num[i] = false;

        // direct i+=1 is not appropriate
        for(int j=i+1; j<1001; j++){
            if(num[j] == true){
                i = j;
                break;
            }
        }
        return ans;
    }
    
    void addBack(int n) { // O(1)
        num[n] = true;
        i = min(i, n);
    }
};
// Time Complexity: O(N) (popSmallest), Space Complexity: O(N) (O(1001))

// Approach 2
class SmallestInfiniteSet {
    int currSmallest;
    priority_queue<int, vector<int>, greater<int>> pq;
    unordered_set<int> st;
public:
    SmallestInfiniteSet() {
        currSmallest = 1;
    }

    int popSmallest() {  
        int ans = currSmallest;

        if(pq.empty()) currSmallest += 1;
        else{
            ans = pq.top();
            pq.pop();
            st.erase(ans);
        } 

        return ans;    
    }

    void addBack(int num){ // O(logK)
        if(num >= currSmallest || st.count(num)) return;

        st.insert(num);
        pq.push(num);
    }
};
// Time Complexity: O(logK) (heap insertion and pop), Space Complexity: O(K) (K - elements stored in pq and set)

// Approach 3
class SmallestInfiniteSet {
    int currSmallest;
    set<int> st;
public:
    SmallestInfiniteSet() {
        currSmallest = 1;
    }

    int popSmallest() {  
        int ans = currSmallest;

        if(st.empty()) currSmallest += 1;
        else{
            ans = *st.begin();
            st.erase(ans);
        }
        return ans;    
    }

    void addBack(int num){ // O(logK)
        if(num >= currSmallest || st.count(num)) return;

        st.insert(num);
    }
};
// Time Complexity: O(logK) (ordered set insertion and erase), Space Complexity: O(K) (K - elements stored in pq and set)

/*
Approach 1
- take a variable-`i` that increaments everytime when it is popped, starting from 1.
- When addBack() is called, is the element to be added is smaller than current i.
Then we need to go back and pop that element first.
- Next time all the elements b/w the new popped and previous i, has to skipped as they are popped already.
- To check whether the element has to be popped or not, take a vector of size 1001 with boolean value (element available or not)

Appraoch 2
We needed array in the previous approach because, when addBack() adds smaller number, 
After popping back current i, to get back to where we previously were, we iterated directly to true value for that matter.
- But popping back can be done by 'i' only.
- for addBack, let's say 2 elements are added - 6 & 3
Now the first element that will be popped should be 3. How to get that?
Min heap, it gives smallest element everytime.

So, if heap is empty, simply pop by increament current 'i' (currSmallest)
- Otherwise, heap is smaller, pop it.

Note: Important Edge cases
*The number to be added can be dublicate and heap has no property that can check for unique
-> So, before adding to heap, add them to unordered_set and check for uniqueness.

- if the element to be added is greater than currSmallest, no need to add it, it will already be considered later. 
- if it is already present in set, then also skip.

Approach 3
Min heap was used in 2nd approach, to find minimum element in fastest time & set in order to get ensure unique elements.
Both of this can be achieved by ordered set.
It stores only unique elements and in ascending order.
- Here, front popping from set is done by pointer.

And, that's it!
*/
