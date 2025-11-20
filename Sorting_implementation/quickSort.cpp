#include<iostream>
#include<vector>
using namespace std;
int partition(vector<int>& arr, int low, int high){
    int pivot = arr[high];
    int idx = low - 1;

    for(int i = low; i < high; i++){
        if(arr[i] < pivot){
           idx++;
           int temp = arr[i];
           arr[i] = arr[idx];
           arr[idx] = temp;
        }        
    }

    idx++;
    arr[high] = arr[idx];
    arr[idx] = pivot;

    return idx;
}

void qs(vector<int>& arr, int low, int high){
    if(low >= high){
        return;
    }

    int pivotIndex = partition(arr, low, high);
    partition(arr, low, pivotIndex - 1);
    partition(arr, pivotIndex + 1, high);
}

int main(){
    vector<int> arr = {3,2,4,2,56,4};
    qs(arr, 0, arr.size() - 1);
    for(int n : arr) cout<< n <<" ";
}