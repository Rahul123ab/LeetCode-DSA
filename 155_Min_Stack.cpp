class MinStack {
public:
    stack<pair<int, int>> st;//TC=O(1), SC=O(2*n)

    MinStack() {
        
    }
    
    void push(int val) {

        if(st.empty()) {
            st.push({val,val});
        } else {
            int minVal = min(val, st.top().second);
            st.push({val,minVal});
        }
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */