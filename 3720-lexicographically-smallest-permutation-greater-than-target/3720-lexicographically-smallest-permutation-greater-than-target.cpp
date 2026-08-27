class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        vector<int>freq(26,0);

        for(int i=0; i<s.size(); i++){
            char ch = s[i];
            freq[ch-'a']++;
        }

        string res = "";

        for(int i=0; i<target.size(); i++){
            char ch = target[i];
            int idx = ch-'a';

            if(freq[idx] > 0){
                res += ch;
                freq[idx]--;
                continue;
            }

            bool found = false;

            for(int j=idx+1; j<26; j++){
                if(freq[j] > 0){
                    res += 'a' + j;
                    freq[j]--;
                    
                    for(int k=0; k<26; k++){
                        while(freq[k] > 0){
                            res += 'a' + k;
                            freq[k]--;
                        }
                    }

                    return res;
                }
            }

            break;
        }

        for (int i = res.size() - 1; i >= 0; i--) {
            // Put the current character back into freq
            freq[res[i] - 'a']++;

            int idx = target[i] - 'a';

            // Try to make this position greater
            for (int j = idx + 1; j < 26; j++) {
                if (freq[j] > 0) {
                    string ans = res.substr(0, i);

                    ans += char('a' + j);
                    freq[j]--;

                    // Add remaining characters
                    for (int k = 0; k < 26; k++) {
                        while (freq[k] > 0) {
                            ans += char('a' + k);
                            freq[k]--;
                        }
                    }

                    return ans;
                }
            }
        }

        return "";
    }
};