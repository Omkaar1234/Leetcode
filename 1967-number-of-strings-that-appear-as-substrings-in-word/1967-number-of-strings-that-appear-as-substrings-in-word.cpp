class Solution {
public:
    bool checkStrings(string &s1 , string &s2){
        for(int i=0; i<s2.size(); i++){
            if(s2[i] == s1[0]){
                int j = i;
                int k = 0;
                while(k < s1.size() && j < s2.size()){
                    if(s2[j] != s1[k]) break;
                    k++;
                    j++;
                }   

                if(k == s1.size()) return true;
            }
        }

        return false;
    }

    int numOfStrings(vector<string>& patterns, string word) {
        int count = 0;

        for(string &s : patterns){
            if(checkStrings(s,word)) count++;
        }   

        return count;
    }
};