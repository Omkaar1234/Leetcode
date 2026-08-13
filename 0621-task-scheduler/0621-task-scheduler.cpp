class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>freq(26,0);
        map<char,int>m;

        for(char &ch : tasks){
            freq[ch-'A']++;
            m[ch] = 0;
        }

        int op = 0;
    
        while(true){
            bool allDone = true;
            for(int i=0; i<26; i++){
                if(freq[i] > 0){
                    allDone = false;
                    break;
                }
            }

            if(allDone) break;
            int maxFreq = INT_MIN;
            char bestTask = '\0';

            bool taskPerform = false;
            for(auto &p : m){
                if(p.second == 0 && freq[p.first-'A'] > maxFreq){
                    maxFreq = freq[p.first-'A'];
                    bestTask = p.first;
                }
            }

            if(bestTask != '\0'){
                m[bestTask] = n+1;
                freq[bestTask-'A']--;
                op++;
                taskPerform = true;
                cout<<bestTask<<" ";
            }
            

            for(auto &p : m){
                if(p.second > 0) p.second--;
            }

            if(!taskPerform){
                cout<<"IDLE"<<" ";
                op++;
            }
        }

        return op;
    }
};