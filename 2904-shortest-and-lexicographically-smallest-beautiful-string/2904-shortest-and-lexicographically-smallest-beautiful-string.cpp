class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string ans = "";
        int n = s.size();

        for(int i=0; i<n; i++){
            int count = 0;
            string curr = "";
            for(int j=i; j<n; j++){
                if(s[j] == '1') count++;
                curr += s[j];

                if(count == k){
                    if(ans.empty() || ans.size() > curr.size() || (ans.size() == curr.size() && ans > curr)){
                        cout<<curr<<"   ";
                        ans = curr;
                        cout<<ans<<endl;
                    }
                    break;
                }
            }
        }

        return ans;
    }
};