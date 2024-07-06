#include<iostream>
#include <queue>
#include <climits>
using namespace std;

class MedianFinder {
    int signum(int a , int b){
        if(a == b){
            return 0;
        }else if(a > b){
            return 1;
        }else{
            return -1;
        }
    }
public:
    priority_queue<int> maxheap; // Max-heap for the lower half
    priority_queue<int, vector<int>, greater<int>> minheap; // Min-heap for the upper half
    double median;

    MedianFinder() {
        median = 0.0;
    }
    
    void addNum(int num) {
        switch (signum(maxheap.size(), minheap.size())) {
            case 0:
                if (num > median) {
                    minheap.push(num);
                    median = minheap.top();
                } else {
                    maxheap.push(num);
                    median = maxheap.top();
                }
                break;
            case 1:
                if (num > median) {
                    minheap.push(num);
                    median = (minheap.top() + maxheap.top()) / 2.0;
                } else {
                    minheap.push(maxheap.top());
                    maxheap.pop();
                    maxheap.push(num);
                    median = (minheap.top() + maxheap.top()) / 2.0;
                }
                break;
            case -1:
                if (num > median) {
                    maxheap.push(minheap.top());
                    minheap.pop();
                    minheap.push(num);
                    median = (maxheap.top() + minheap.top()) / 2.0;
                } else {
                    maxheap.push(num);
                    median = (maxheap.top() + minheap.top()) / 2.0;
                }
                break;
        }
    }
    
    double findMedian() {
        return median;
    }
};