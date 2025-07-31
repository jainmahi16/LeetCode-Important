class Solution {
public:
    string shortestPalindrome(string s) {
        auto temp = s;
        ranges::reverse(temp);
        auto pi = prefix(s+"#"+temp);
        auto rem = s.substr(pi.back());
        ranges::reverse(rem);
        return rem + s;
    }
    vector<int> prefix(string s){
        vector<int> pi(s.size(),0);
        for(int i = 1; i < s.size() ; i++){
            int j = pi[i-1];
            while(j > 0 and s[i] != s[j]) j = pi[j-1];
            if(s[i] == s[j]) j++;
            pi[i] = j;
        }
        return pi;
    }
};

// aacecaaa#aaacecaa