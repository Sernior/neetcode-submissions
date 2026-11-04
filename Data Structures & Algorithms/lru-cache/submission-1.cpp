#include <stdexcept>

class LRUCache {
public:
    LRUCache(int capacity) : capacity_{capacity} {
        if (capacity == 0 || capacity > 3000)
            throw std::invalid_argument("wrong capacity");
        m_.reserve(capacity);
    }
    
    int get(int key) {
        if (!m_.contains(key))return -1;
        auto it = m_[key];
        l_.splice(l_.begin(), l_, it);
        return l_.front().second;
    }
    
    void put(int key, int value){
        if (!m_.contains(key)){
            if (l_.size() >= capacity_){
                auto toRem = l_.back();
                m_.erase(toRem.first);
                l_.pop_back();
                l_.push_front({key, value});
                m_[key] = l_.begin();
            }
            else{
                l_.push_front({key, value});
                m_[key] = l_.begin();
            }
            return;
        }

        // element existing
        auto it = m_[key];
        it->second = value;
        l_.splice(l_.begin(), l_, it);

    }

    private:
    std::unordered_map<int, std::list<pair<int, int>>::iterator> m_;
    std::list<pair<int, int>> l_; // front good back to del
    int capacity_;
};
