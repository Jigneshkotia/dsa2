#include<iostream>
#include<stack>

using namespace std;

void solve(stack<int> st, int x){
    //base case
    if(st.empty()){
        st.push(x);
    }

    int num = st.top();
    st.pop();

    solve(st, x);

    st.push(num);
}

stack<int> pushAtBottom(stack<int> &mystack, int x){
    solve(mystack , x);
    return mystack;
}

int main(){
    //you can check the code here.
    return 0;
}