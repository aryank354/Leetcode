class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.length();
        unordered_set<int>set;
        int ans = 0;
        
        for(int i = 0 ; i<n ; i++){
            set.insert(s[i]);
        }

        for(char chars : set){
            int leftmost = -1;
            int rightmost = -1;
            unordered_set<int>st;

            for(int i = 0 ; i<n ; i++){
                if(s[i] == chars){
                    if(leftmost == -1){
                        leftmost = i;
                    }
                rightmost = i;

                }

            }

            for(int i = leftmost+1 ; i<=rightmost-1 ; i++){
                st.insert(s[i]);
                
            }

            ans += st.size();
            
        }

        return ans;
        
       
    }
};
