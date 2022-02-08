class MinStack {
public:
    vector<int> Stack, mini;
    int size;
    
    MinStack() {
        size = 0;
        mini = {INT_MAX};
    }
    
    void push(int val) {
        Stack.emplace_back(val);
        mini.emplace_back(min(mini.back(), val));
        size++;
    }
    
    void pop() {
        if(size){
            Stack.pop_back();
            mini.pop_back();
            size--;
        }
    }
    
    int top() {
        return Stack.back();
    }
    
    int getMin() {
        return mini.back();
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