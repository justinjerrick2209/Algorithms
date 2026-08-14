# include<iostream>
using namespace std;
int binarySearch(int *arr, int n, int key){
    int low = 0;
    int high = n - 1;
    
    while(low <= high){
        int mid = (low + high)/2;
        if(arr[mid] == key){
            return mid;
        }else if(arr[mid] > key){
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    
    return -1;
}

int main(){
    int size = 10;
    int arr[size] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int key = 70;
    int index = binarySearch(arr, size, key);
    cout << "Result " << index;
    return 0;
}