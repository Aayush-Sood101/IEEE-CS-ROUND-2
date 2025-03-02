// SPACE COMPLEXITY : O(n+n+n) == O(n)
// For any operation : O(1)


#include<bits/stdc++.h>
using namespace std;

class Stack{
public:
    stack<int> st;
    stack<int> min_stack;
    stack<int> max_stack;

    void push(int x){
        if(st.size() == 0){
            st.push(x);
            min_stack.push(x);
            max_stack.push(x);
            return ;
        }

        st.push(x);

        if(min_stack.top() <= x)
        min_stack.push(min_stack.top());
        else
        min_stack.push(x);
        
        if(max_stack.top() >= x)
        max_stack.push(max_stack.top());
        else
        max_stack.push(x);
        
    }

    void pop(){
        if(st.size() == 0)
        return ;

        st.pop();
        min_stack.pop();
        max_stack.pop();
    }

    int top(){
        if(st.size() == 0) return -1;

        return st.top();
    }

    int getMin(){
        if(min_stack.size() == 0) return -1;

        return min_stack.top();
    }

    int getMax(){
        if(max_stack.size() == 0) return -1;

        return max_stack.top();
    }
};

int main(){
    Stack st;
    cout<<"Enter 1 to push"<<endl;
    cout<<"Enter 2 to pop"<<endl;
    cout<<"Enter 3 to top"<<endl;
    cout<<"Enter 4 to get minimum"<<endl;
    cout<<"Enter 5 to get maximum"<<endl;
    cout<<"Enter -1 to terminate loop"<<endl;
    while(true){
        cout<<"Enter your choice:";
        int ch;
        cin>>ch;
        switch(ch){
            case 1:
            int x;
            cin>>x;
            st.push(x);
            break;
            case 2:
            st.pop();
            break;
            case 3:
            cout<<st.top()<<endl;
            break;
            case 4:
            cout<<st.getMin()<<endl;
            break;
            case 5:
            cout<<st.getMax()<<endl;
            break;
            default:
            return 0;
        }
    }
}