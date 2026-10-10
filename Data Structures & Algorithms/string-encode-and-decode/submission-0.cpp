class Solution {
public:

    string encode(vector<string>& strs) {
        int numOfStrs = strs.size();
        vector<int> sizes;
        string ret = "";
        sizes.reserve(numOfStrs);
        for (int i = 0; i < numOfStrs; ++i){
            sizes.push_back(strs[i].size());
            ret = ret + strs[i];
        }
        std::reverse(sizes.begin(), sizes.end());
        for (auto s : sizes){
            ret = ret + '-' + std::to_string(s);
        }
        ret = ret + '-';
        ret = ret + std::to_string(numOfStrs);
        std::cout << ret;
        return ret;
    }

    vector<string> decode(string s) {
        auto const pos = s.find_last_of('-');
        int numOfStrs = std::stoi(s.substr(pos + 1));
        s.erase(pos);
        //cout << '\n' << s;
        vector<int> sizes;
        sizes.reserve(numOfStrs);
        //cout << '\n' << numOfStrs;
        for (int i = 0; i < numOfStrs; ++i){
            auto const pos = s.find_last_of('-');
            sizes.push_back(std::stoi(s.substr(pos + 1)));
            s.erase(pos);
        }
        vector<string> ret;
        ret.reserve(numOfStrs);
        for (auto size : sizes){
            ret.push_back(s.substr(0, size));
            s.erase(0, size);
        }
        return ret;
    }
};
