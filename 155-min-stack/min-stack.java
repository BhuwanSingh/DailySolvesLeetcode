class MinStack {
    private Stack current_stack;
    private Stack min_stack;

    public MinStack() {
        current_stack = new Stack<>();
        min_stack = new Stack<>();
    }
    
    public void push(int val) {
        if (min_stack.isEmpty()) min_stack.push(val);
        else min_stack.push(Math.min(val, (int)min_stack.peek()));
        current_stack.push(val);
    }
    
    public void pop() {
        current_stack.pop();
        min_stack.pop();
    }
    
    public int top() {
        return (int)current_stack.peek();
    }
    
    public int getMin() {
        return (int)min_stack.peek();
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(val);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */