//232. Implement Queue using Stacks
//https://leetcode.com/problems/implement-queue-using-stacks/description/

class MyQueue {
public:
    stack<int>st1;
    stack<int>st2;
    MyQueue() {
        
    }
    
    void push(int x) {
        if(!st1.empty())
        {
            while(!st1.empty())
            {
                st2.push(st1.top());
                st1.pop();
            }
            st1.push(x);
            while(!st2.empty())
            {
                st1.push(st2.top());
                st2.pop();
            }
        }
        else
            st1.push(x);
    }
    
    int pop() {
        int ret = st1.top();
        st1.pop();
        return ret;
    }
    
    int peek() {
        return st1.top();
    }
    
    bool empty() {
        return st1.empty();
    }
};
