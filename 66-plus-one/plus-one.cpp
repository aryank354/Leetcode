class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i = digits.size() - 1;

        while(i>=0){
            int value = digits[i];
            if(value == 9){
                digits[i] = 0;
                i--;
            }else {
                digits[i] += 1;
                return digits;
            }
        }


        digits.insert(digits.begin() , 1);
        return digits;
  
    }
};