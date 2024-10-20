// TC->O(N)
// SC->O(N)
class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;

        for(auto it: expression){

            if(it != ')' && it != ','){
                st.push(it);
            }
            else if(it == ')'){
                vector<int> vc;
                
                while(!st.empty() && st.top() !='('){
                    char c = st.top();
                    st.pop();
                    if(c == 't') vc.push_back(1);
                    else vc.push_back(0);
                }
                st.pop();

                //operator
                
                if(!st.empty()){
                    int res = vc[0];
                    char cc = st.top();
                    st.pop();
                    if(cc == '&'){
                        for(int i=0;i<vc.size();i++){
                            res &= vc[i];
                        }
                    }
                    else if(cc == '|'){
                        for(int i=0;i<vc.size();i++){
                            res |= vc[i];
                        }
                    }
                    else {
                        res = !res;
                    }
                    if(res) st.push('t');
                    else st.push('f');
                }
                
            }
        }
        if(st.top() == 't') return true;
        return false;
    }
};