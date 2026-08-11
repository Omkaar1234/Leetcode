class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int>freqMag(26,0);
        for(char ch : magazine){
            freqMag[ch-'a']++;
        }

        vector<int>freqRan(26,0);
        for(char ch : ransomNote){
            freqRan[ch-'a']++;
        }

        for(int i=0; i<26; i++){
            if(freqRan[i] > freqMag[i]) return false;
        }

        return true;
    }
};