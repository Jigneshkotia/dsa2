class circularQueue {
    int * arr;
    int start;
    int end;
    int k;

public:
    circularQueue(int k) {
        this->k = k;
        arr = new int[k];
        start = end = -1;
    }
    
    bool enQueue(int value) {
        if(isFull()){
            return false;
        }
        if(start == -1){
            start = end = 0;
            arr[start]=value;
        }else{
            end = (end+1)%k;
            arr[end]=value;
        }
        return true;
    }
    
    bool deQueue() {
       if(isEmpty()){
        return false;
       }
       if(start == end){
        arr[start]=-1;
        start = end = -1;
       }else{
        arr[start]= -1;
        start = (start+1)%k;
       }
       return true;
    }
    
    int Front() {
        if(start == -1){
            return -1;
        }else{
            return arr[start];
        }
    }
    
    int Rear() {
        if(start == -1){
            return -1;
        }else{
            return arr[end];
        }
    }
    
    bool isEmpty() {
        return start == -1;
    }
    
    bool isFull() {
        return (end+1)%k == start;
    }
};
