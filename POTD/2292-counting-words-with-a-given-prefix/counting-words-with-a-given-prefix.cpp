class Solution {
public:
    bool func(string str1 , string str2){
        return str2.find(str1) == 0;
    }
    int prefixCount(vector<string>& words, string pref) {
        int n = words.size();
        int count = 0;

        for(int i = 0 ; i<n ; i++){
                if(func(pref , words[i])) count ++;
                
        
        }

        return count;
        
    }
};