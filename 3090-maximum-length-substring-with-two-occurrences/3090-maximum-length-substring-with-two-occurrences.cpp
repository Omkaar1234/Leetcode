class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char,int>m;

        int maxLen = INT_MIN;
        int l = 0;

        for(int r=0; r<s.size(); r++){
            char ch = s[r];
            m[ch]++;

            while(m[ch] > 2){
                m[s[l]]--;
                l++;
            }

            int len = r-l+1;
            maxLen = max(maxLen,len);
        }

        return maxLen;
    }
};