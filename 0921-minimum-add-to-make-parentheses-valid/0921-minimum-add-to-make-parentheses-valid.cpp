class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>st;
        int move = 0;

        for(int i=0; i<s.size(); i++){
            char ch = s[i];

            if(ch == '(' || ch == '{' || ch == '['){
                st.push(ch);
            }else{
                if(st.empty()){
                    move++;
                    continue;
                }
                if((ch == ']' && st.top() == '[') || (ch == '}' && st.top() == '{') || (ch == ')' && st.top() == '(')) st.pop();
                else move++;
            }
        }

        while(!st.empty()){
            move++;
            st.pop();
        }
        
        return move;
    }
};