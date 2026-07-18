class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        unordered_map<string,vector<string>>m;

        for(int i=0; i<n; i++){
            string curr = wordList[i];
            int match = 0;
            for(int j=0; j<curr.size(); j++){
                if(curr[j] == beginWord[j]) match++;
            }
            if(match == curr.size()-1) m[beginWord].push_back(curr);
        }

        for(int i=0; i<n; i++){
            string curr = wordList[i];
            for(int j=0; j<n; j++){
                if(i == j) continue;
                string check = wordList[j];
                int match = 0;

                for(int k=0; k<curr.size(); k++){
                    if(curr[k] == check[k]) match++;
                }

                if(match == curr.size()-1) m[curr].push_back(check);
            }
        }

        for(auto &p : m){
            cout<<"KEY :"<<p.first<<" ";
            cout<<"V :";
            for(string s : p.second){
                cout<<s<<" ";
            }
            cout<<endl;
        }

        queue<string>q;
        set<string>s;
        s.insert(beginWord);
        q.push(beginWord);
        q.push("");

        int shortestPath = 1;

        while(!q.empty()){
            string curr = q.front();
            q.pop();

            cout<<curr<<"->";

            if(curr == ""){
                shortestPath++;
                if(!q.empty()){
                    q.push("");
                    continue;
                }else{
                    break;
                }
            }

            if(curr == endWord) return shortestPath;

            for(string v : m[curr]){
                if(s.find(v) == s.end()){
                    s.insert(v);
                    q.push(v);
                }
            }
        }

        return 0;
    }
};