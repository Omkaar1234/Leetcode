class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int r = 0;
        int maxLen = INT_MIN;
        int n = s.size();
        vector<int>freq(26,0);

        while(r < n){
            freq[s[r]-'A']++;

            int maxFreqIdx = -1;
            int maxFreq = -1;
            for(int i=0; i<26; i++){
                if(maxFreq < freq[i]){
                    maxFreq = freq[i];
                    maxFreqIdx = i;
                }
            }

            if(abs((r-l+1) - maxFreq) > k){
                while(abs((r-l+1) - maxFreq) > k){
                    int currMax = INT_MIN;
                    int currMaxIdx = INT_MIN;

                    freq[s[l]-'A']--;
                    l++;
                    
                    for(int i=0; i<26; i++){
                        if(freq[i] > currMax){
                            currMax = freq[i];
                            currMaxIdx = i;
                        }
                    }

                    maxFreq = currMax;
                    maxFreqIdx = currMaxIdx;
                }
            }

            maxLen = max(maxLen , (r-l+1));
            r++;
        }

        return maxLen;
    }
};