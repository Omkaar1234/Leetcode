class Solution {
public:
    bool isPresent(int num, vector<int>&digits){
        unordered_map<int, int>m;

        while(num > 0){
            int lastDig = num % 10;
            num /= 10;
            m[lastDig]++;
        }

        for(int i=0; i<digits.size(); i++){
            if(m.count(digits[i]) && m[digits[i]] > 0) m[digits[i]]--;
        }

        for(auto &p : m){
            if(p.second != 0){
                return false;
            }
        }

        return true;
    }
    int totalNumbers(vector<int>& digits) {
        int count = 0;

        for(int i=100; i<=998; i=i+2){
            if(isPresent(i,digits)){
                count++;
            }
        }

        return count;
    }
};