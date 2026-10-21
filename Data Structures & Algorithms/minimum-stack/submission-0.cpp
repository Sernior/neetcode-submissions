class MinStack {
public:

    MinStack() {
        
    }
    
    void push(int val) {
        if (stack_.empty()){
            stack_.push_back(val);
            currentMins_.push_back(val);
        }
        else{
            stack_.push_back(val);
            currentMins_.push_back(val < currentMins_.back() ? val : currentMins_.back());
        }
    }
    
    void pop() {
        //int back = stack_.back();
        stack_.pop_back();
        currentMins_.pop_back();
    }
    
    int top() {
        return stack_.back();
    }
    
    int getMin() {
        return currentMins_.back();
    }

    private:
    std::vector<int> stack_;
    std::vector<int> currentMins_;
};
