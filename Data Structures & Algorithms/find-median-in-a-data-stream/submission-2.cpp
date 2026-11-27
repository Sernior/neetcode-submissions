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
        if (*mid_ <= num && nums_.size() % 2) { // odd and greater
            nums_.insert(num);
        }
        else if (*mid_ <= num && !(nums_.size() % 2)) { // even and greater
            nums_.insert(num);
            ++mid_;
        }
        else if (*mid_ > num && nums_.size() % 2) { // odd and lower equal
            nums_.insert(num);
            --mid_;
        }
        else if (*mid_ > num && !(nums_.size() % 2)) { // even and lower equal
            nums_.insert(num);
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
