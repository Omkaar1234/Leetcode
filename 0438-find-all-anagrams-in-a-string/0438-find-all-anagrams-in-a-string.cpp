class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(p.size() > s.size()) return {};
        vector<int>freqS(26,0);
        vector<int>freqP(26,0);

        for(int i=0; i<p.size(); i++){
            char ch = p[i];
            freqP[ch-'a']++;
        }

        for(int i=0; i<p.size(); i++){
            freqS[s[i]-'a']++;
        }

        vector<int>ans;
        if(freqS == freqP) ans.push_back(0);
        int l = 0;

        for(int i=p.size(); i<s.size(); i++){
            freqS[s[l++]-'a']--;
            freqS[s[i]-'a']++;

            if(freqS == freqP) ans.push_back(l);
        }

        return ans;
    }
};