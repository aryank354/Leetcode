class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        set<int>st;
        for(int i = 0 ; i<n ; i++){
            st.insert(nums[i]);
        }
        int longest = 0;
        int current = 0;
        int length = 0;
        for(auto it : st){
            if(st.find(it - 1) == st.end()){
                current = it;
                length = 1;

                while(st.find(current + 1) != st.end()){
                    current++;
                    length++;
                }

                longest = max(longest , length);

            }
        }

        return longest;    

    }
};