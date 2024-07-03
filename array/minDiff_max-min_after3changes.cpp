#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

//leetcode 1509
int minDifference(vector<int> &nums){
    if(nums.size()<= 4){
            return 0;
        }
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int min1 = min(nums[n-1]-nums[3],nums[n-2]-nums[2]);
        int min2 = min(nums[n-3]-nums[1], nums[n-4]-nums[0]);

        return min(min1, min2);
}


int main(){
    int n;
    cout<< "entre the size of vector"<<endl;
    cin>>n;
    cout<<"entre the values"<<endl;
    vector<int> arr;
    int nums;
    for( int i = 0 ; i<n;i++){
        cin>>nums;
        arr.push_back(nums);
    }
    cout<<"the min difference is :"<<endl;
    cout<< minDifference(arr)<<endl;
    return 0;
}