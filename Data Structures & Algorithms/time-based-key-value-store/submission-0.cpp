class TimeMap {
public:

    struct Comp{
        using is_transparent = void;
        bool operator()(pair<string, int> const& lhs,pair<string, int> const& rhs) const {
            return lhs.second < rhs.second;
        }

        bool operator()(pair<string, int> const& lhs, int const x) const {
            return lhs.second < x;
        }

        bool operator()(int const x, pair<string, int> const& rhs) const {
            return x < rhs.second;
        }
    };

    unordered_map<string, set<pair<string, int>, Comp>> m_;

    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        pair<string, int> v = {value, timestamp};
        if (m_.contains(key))m_[key].insert(v);
        else m_[key].insert(v);
    }
    
    string get(string key, int timestamp) {
        if (!m_.contains(key))return "";
        else {
            auto it = m_[key].upper_bound(timestamp);
            if (it ==  m_[key].begin())return "";
            return std::prev(it)->first;
        }
    }
};
