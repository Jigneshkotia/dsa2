#include<iostream>
using namespace std;

bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    if (num <= 3) {
        return true;
    }
    
    if (num % 2 == 0 || num % 3 == 0) {
        return false;
    }
    
    for (int i = 5; i * i <= num; i = i + 6) {
        if (num % i == 0 || num % (i + 2) == 0) {
            return false;
        }
    }
    
    return true;
}

int no_of_primefactor(int num){
    if(isPrime(num) && num > 1) {
        return 1;
    }
    int count = 0;
    int i = 2;
    while(num != 1 && i<=num){
        if(isPrime(i) && num%i == 0){
            num = num / i;
            count ++;
        }else{
            i++;
        }
    }
    return count;
}

int score(int l , int r){
    int ans = 0;
    for(int i = l; i<=r;i++){
        if(no_of_primefactor(i)>ans){
            ans = no_of_primefactor(i);
        }
    }
    return ans;
}

int main(){
    int no_inputs;
    cin>> no_inputs ;
    int arr[no_inputs][2];
    for(int i =0;i<no_inputs; i++){
        cin>> arr[i][0];
        cin>> arr[i][1];
    }

    for(int i =0; i<no_inputs;i++){
        cout<< score(arr[i][0],arr[i][1])<<endl;
    }

    return 0;
}