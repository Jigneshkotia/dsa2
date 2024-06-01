#include<iostream>
using namespace std;

void swap_alternate(int arr[],int n){
    for(int i = 0; i<n-1; i= i+2){
        swap(arr[i],arr[i+1]);
    }
}

void printarray(int arr[],int n){
    cout<<endl;
    cout<< "printing the array "<<endl;
    for(int i =0; i< n ; i++){
        cout << arr[i]<< " ";
    }
    cout<< endl;
}



int main(){
    int arr[5];
    for(int i =0; i<5;i++){
        cin>>arr[i];
    }
    swap_alternate(arr,5);
    printarray(arr, 5);
    return 0;
}