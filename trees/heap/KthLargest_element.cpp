#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int> , greater<int> > pq;
        for( int i = 0; i< k; i++){
            pq.push(nums[i]);
        }

        int n = nums.size();
        for( int i = k; i<n; i++){
            if(pq.top() < nums[i]){
                pq.pop();
                pq.push(nums[i]);
            }
        }
        return pq.top();
    }

// for kth smallest we use max heap instead of min heap

int main(){
    return 0;
}