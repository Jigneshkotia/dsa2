#include<iostream>
#include<stack>

using namespace std;

void sortedInsert(stack<int> s, int num){
    //base case
    if(s.empty() || s.top() < num){
        s.push(num);
        return;
    }

    int temp = s.top();
    s.pop();

    sortedInsert(s, num);

    s.push(temp);
}

void sortStack(stack<int> &myStack){
    //base case
    if(myStack.empty()){
        return;
    }

    int temp = myStack.top();
    myStack.pop();

    sortStack(myStack);

    sortedInsert(myStack, temp);

}

int main(){
    //call your functions here.
    return 0;
}