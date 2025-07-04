class Solution {
public:
    void solve(vector<string>&ans , int o , int c , string op){
        if(c == 0  && o == 0){
            ans.push_back(op);
            return;
        }

        string op1;
        string op2;

        if(o>0){
            op1 = op;
            op1.push_back('(');
            solve(ans , o-1 , c , op1);
        }
        if(c>o){
            op2 = op;
            op2.push_back(')');
            solve(ans , o , c-1 , op2);  
        }


    }
    vector<string> generateParenthesis(int n) {
        int o = n, c = n;
        vector<string>ans;
        string op = "";
        solve(ans , c , o , op);
        return ans;
    }
};