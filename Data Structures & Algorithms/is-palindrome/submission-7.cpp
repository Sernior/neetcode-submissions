class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j =s.size()-1;
        while (i < j){
            while(!isalnum(static_cast<unsigned char>(s[i])) && i < j)++i;
            while(!isalnum(static_cast<unsigned char>(s[j])) && i < j)--j;
            if(tolower(static_cast<unsigned char>(s[i])) != tolower(static_cast<unsigned char>(s[j])))return false;
            ++i;
            --j;
        }
        return true;
    }
};
