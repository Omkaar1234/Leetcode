class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int>s;
        int n = temperatures.size();
        int i = n-1;
        vector<int>ans(n);

        while(i >= 0){
            while(!s.empty() && temperatures[s.top()] <= temperatures[i]){
                s.pop();
            }

            if(s.empty()){
                ans[i] = 0;
            }else{
                ans[i] = s.top() - i;
            }
            s.push(i--);
        }

        return ans;
    }
};