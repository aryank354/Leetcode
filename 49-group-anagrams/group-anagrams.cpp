class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& arr) {
        int n = arr.size();
        unordered_map<string ,  vector<string>> mp;
        vector<vector<string>>ans;

        for(int i = 0 ; i<n ; i++){
            string str = arr[i];
            sort(str.begin() , str.end());
            mp[str].push_back(arr[i]);
        }

        for(auto it : mp){
            ans.push_back(it.second);

        }

        return ans;
    }
};