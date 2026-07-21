class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>m;

        for(int &x : nums){
            m[x]++;
        }

        priority_queue<pair<int,int>>pq;

        for(auto &p : m){
            int freq = p.second;
            int num = p.first;

            pq.push({freq,num});
        }

        vector<int>ans;
        while(k > 0){
            auto [freq,num] = pq.top();
            pq.pop();

            ans.push_back(num);
            k--;
        }

        return ans;
    }
};