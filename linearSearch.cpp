# include<iostream>
using namespace std;
int linearSearch(int *arr, int n, int target){
    for(int i = 0; i < n; i++){
        if(arr[i] == target){
            return i;
        }
    }
    return -1;
}

int main(){
    int size = 10;
    int arr[size] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int key = 100;
    int index = linearSearch(arr, size, key);
    cout << "Result " << index;
    return 0;
}