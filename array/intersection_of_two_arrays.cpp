#include<iostream>
using namespace std;


//we have to return vector with all unique intersections.
vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans ;
        int n1 = nums1.size();
        int n2 = nums2.size();
        int state = 0;
        for(int i = 0 ; i< n1;i++){
            int element = nums1[i];
            state = 0;
            for(int j = 0; j<n2; j++){
                
                if(element == nums2[j]){
                    state = 1;
                    nums2[j]=-1;
                }
            }
            if(state == 1){
                ans.push_back(element);
            }
        }
        return ans;
}

int main(){
    //we can use functions here.
    return 0;
}