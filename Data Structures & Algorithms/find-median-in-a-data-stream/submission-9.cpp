class MedianFinder {
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (!nums_.size()) {
            nums_.insert(num);
            mid_ = nums_.begin();
            return;
        }
        bool wasOdd = nums_.size() % 2 == 1;
        nums_.insert(num);
        if (*mid_ <= num && !wasOdd) { // even and greater
            ++mid_;
        }
        else if (*mid_ > num && wasOdd) { // odd and lower equal
            --mid_;
        }
    }
    
    double findMedian() {
        if (nums_.size() % 2 == 1)
            return static_cast<double>(*mid_);
        auto h = std::next(mid_, 1);
        return (*mid_ + *h) / 2.0;
    }

private:
    std::multiset<int> nums_;
    std::multiset<int>::iterator mid_;
};
