class KthLargest {
public:
    KthLargest(size_t k, vector<int>& nums) : k_{k}, heap_(nums.begin(), nums.end()) {
        while (heap_.size() > k_) heap_.pop();
    }
    
    int add(int val) {
        heap_.push(val);
        while (heap_.size() > k_) heap_.pop();
        return heap_.top();
    }

private:
    size_t k_;
    std::priority_queue<int, std::vector<int>, std::greater<>> heap_;
};
