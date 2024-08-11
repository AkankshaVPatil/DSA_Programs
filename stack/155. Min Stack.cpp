//https://leetcode.com/problems/min-stack/description/
//155. Min Stack.cpp

class MinStack {
public:
    stack<int>st, minst;
    MinStack() {
        
    }
    
    void push(int val) {
        if(minst.empty() || (!minst.empty() && val <= minst.top()))
            minst.push(val); //0
        st.push(val);//0 1
    }
    
    void pop() {
        int poped = st.top();
        st.pop();

        if(poped == minst.top())
            minst.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minst.top();
    }
};
