#include <iostream>
using namespace std;

class heap
{
public:
    int arr[100];
    int size;

    heap()
    {
        arr[0] = -1;
        size = 0;
    }

    void insert(int num)
    {
        size = size + 1;
        int idx = size;
        arr[size] = num;

        while (idx > 1)
        {
            int parent = idx / 2;

            if (arr[parent] < arr[idx])
            {
                swap(arr[parent], arr[idx]);
                idx = parent;
            }
            else
            {
                return;
            }
        }
    }

    void deletefromHeap()
    {
        if (size == 0)
        {
            cout << "nothing to delete ";
            return;
        }

        arr[1] = arr[size];
        size--;

        int i = 1;
        while (i < size)
        {
            int leftidx = 2 * i;
            int rightidx = (2 * i) + 1;

            if (leftidx <= size && arr[i] < arr[leftidx])
            {
                swap(arr[i], arr[leftidx]);
                i = leftidx;
            }
            else if (rightidx <= size && arr[i] < arr[rightidx])
            {
                swap(arr[i], arr[rightidx]);
                i = rightidx;
            }
            else
            {
                return;
            }
        }
    }

    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};


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


int main()
{
    heap h;
    h.insert(55);
    h.insert(54);
    h.insert(5);
    h.insert(100);
    h.insert(35);

    h.print();

    h.deletefromHeap();

    h.print();

    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    for( int i = n/2; i>0 ; i--){
        heapify(arr, n, i);
    }

    //printing the array now
    for( int i = 1; i<=n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    return 0;
}