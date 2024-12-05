// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>

using namespace std;

bool exists(int n, int k) {
    return k<n;
}

void heapify(vector<int>& arr, int index) {
    if(index < 0 || index >= arr.size())
        return;
    int n = arr.size();
    int left = index*2 +1;
    int right = index*2 +2;
    if(exists(n, left) && exists(n, right)) {
        if(arr[left] >= arr[right] && arr[left] > arr[index]) {
            swap(arr[left], arr[index]);
            heapify(arr, left);
        } else if(arr[right] >= arr[left] && arr[right] > arr[index]) {
            swap(arr[right], arr[index]);
            heapify(arr, right);
        } else {
            // nothing
        }
    } else if(exists(n, left) && !exists(n, right)) {
        if(arr[left] > arr[index]) {
            swap(arr[left], arr[index]);
            heapify(arr, left);
        }
    } else {
        // do nothing
    }
}

void updateTree(vector<int>& arr, int index) {
    if(index == 0)
        return;
    if((index-1)%2 == 0) {
        int parent = (index-1)/2;
        if(arr[parent] < arr[index]) {
            swap(arr[parent], arr[index]);
            updateTree(arr, parent);
        }
    } else {
        int parent = (index-2)/2;
        if(arr[parent] < arr[index]) {
            swap(arr[parent], arr[index]);
            updateTree(arr, parent);
        }
    }
}

void insert(vector<int>& arr, int val) {
    arr.push_back(val);
    updateTree(arr, arr.size()-1);
}

int main() {
    vector<int> arr = {1,2,3,4,5,6,7,8,9,10};
    for(int i=arr.size() /2 -1;i>=0;i--)
        heapify(arr, i);
    for(auto& val : arr)
        cout << val << " ";
    cout << "\n";
    insert(arr, 500);
    for(auto& val : arr)
        cout << val << " ";
    cout << "\n";
    return 0;
}
