// TC->O(2*N)
// SC->O(N)
class Solution {
public:
    string reverseParentheses(string s) {
        string x=s;
        stack<int> st;
        for(int i=0;i<x.length();i++){
            if(x[i]=='('){
                st.push(i);
            }
            if(!st.empty() && x[i]==')'){
                int start=st.top();
                reverse(x.begin()+start+1,x.begin()+i);
                st.pop();
            }
        }
        string res="";
        for(int i=0;i<x.length();i++){
            if(x[i] =='(' || x[i]==')'){
                continue;
            }
            res+=x[i];
        }
        return res;
    }
};