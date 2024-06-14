#include<iostream>
#include<stack>

using namespace std;


void insertAtBottom(stack<int> s, int element){
    //base case
    if(s.empty()){
        s.push(element);
        return;
    }

    int temp = s.top();
    s.pop();

    insertAtBottom(s, element);

    s.push(temp);
}

void reverseStack(stack<int> &mystack){
    //base case 
    if(mystack.empty()){
        return;
    }

    int temp = mystack.top();
    mystack.pop();

    reverseStack(mystack);

    insertAtBottom(mystack,temp);
}

int main(){
    //run the functions here.
    return 0;
}