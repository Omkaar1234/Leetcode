class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string>ans;

        string curr = "";
        for(int j=0; j<n; j++){
            curr += ".";
        }

        ans.push_back(curr);

        for(int i=0; i<m-1; i++){
            string curr = "";
            for(int j=0; j<n-1; j++){
                curr += "#";
            }
            curr += ".";
            ans.push_back(curr);
        }

        return ans;
    }
};