class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0; 
        int ten = 0 ; 
        int tty = 0;  

        for(auto & amt: bills){
            if(amt == 5){
                five++;
            }

            if(amt == 10){
                ten++;

                if(five > 0)
                five--;
                else return false;
            }

            if(amt == 20){
                tty++;

                if(five > 0 && ten>0){
                five--;
                ten--;
                }
                else if(five >=3){
                    five--;
                    five--;
                    five--;
                }
                else return false;


            }

            
        }

 

        return true;


    }
};