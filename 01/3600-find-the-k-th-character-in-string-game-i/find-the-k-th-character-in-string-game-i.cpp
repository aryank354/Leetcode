// class Solution {
// public:
    
//     char func(int k , string op){
//         if(op.length() ==  k){
//             return ' ';
//         }

//         string op1 = op;
//         int s = op.length();
//         for(int i = 0 ; i<s ; i++){
//             if(op[i] == 'z'){
//                 op.push_back('a');
//                 continue;
//             }
//             op.push_back(op[i]+1);
//         }

//         func(k , op1);

//         return op[k-1];
//     }
//     char kthCharacter(int k) {
//         string op = "";

//         return func(k , op);
//     }
// };

class Solution {
public:

    char func(int k , string op) {
        if(op.length() >= k) {
            return op[k - 1];
        }

        string op1 = op;
        int s = op1.length();
        for(int i = 0 ; i < s ; i++) {
            if(op1[i] == 'z') {
                op1.push_back('a');
            } else {
                op1.push_back(op1[i] + 1);
            }
        }

        return func(k , op1);
    }

    char kthCharacter(int k) {
        string op = "a";
        return func(k , op);
    }
};
