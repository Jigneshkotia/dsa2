#include<iostream>
using namespace std;

/*
we are given an array of length 2m+1 where m 
numbers are 2 times in the array 
and one number is 1 time in the array.
*/

int findunique(int array[],int size){
    int ans = 0;
    for(int i = 0; i<size ; i++){
        ans = ans ^ array[i];
    }
    return ans;
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
    //call function here
    return 0;
}