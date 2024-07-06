#include<iostream>
#include<queue>
using namespace std;

void heapify(int arr[], int n, int i){
    int largest = i;
    int left = i*2;
    int right = i*2 + 1;

    if(left <= n && arr[largest]<arr[left]){
        largest = left;
    }
    if(right <= n && arr[largest]< arr[right]){
        largest = right;
    }

    if(largest != i){
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }

}

void heapSort(int arr[], int n){
    int size = n;
    while(size> 1){
        swap(arr[size], arr[1]);
        size--;

        heapify(arr, size, 1);
    }
}


int main(){

    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    for( int i = n/2; i>0 ; i--){
        heapify(arr, n, i);
    }

    heapSort(arr, n);

    //printing the array now
    for( int i = 1; i<=n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;


    //maxheap using stl
    priority_queue<int> pq;

    pq.push(54);
    pq.push(23);
    pq.push(43);
    pq.push(52);

    cout<<"element at top : "<<pq.top()<<endl;
    pq.pop();
    cout<<"element at top : "<<pq.top()<<endl;
    cout<<"size : "<<pq.size()<<endl;
    cout<<"empty : "<<pq.empty()<<endl;

    //minhead using stl
    priority_queue<int, vector<int> ,greater<int> > minheap;

    minheap.push(54);
    minheap.push(23);
    minheap.push(43);
    minheap.push(52);

    cout<<"element at top : "<<minheap.top()<<endl;
    minheap.pop();
    cout<<"element at top : "<<minheap.top()<<endl;
    cout<<"size : "<<minheap.size()<<endl;
    cout<<"empty : "<<minheap.empty()<<endl;



    return 0;
}