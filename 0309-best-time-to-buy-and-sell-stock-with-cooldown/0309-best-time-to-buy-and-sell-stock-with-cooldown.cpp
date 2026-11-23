class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int>front(2,0);
        vector<int>after(2 , 0);
        vector<int>curr(2,0);
        for(int ind = n-1 ; ind>=0 ; ind--){
            
                
                  
                  curr[1]= max(-prices[ind] +after[0] ,0 + after[1]);

    
        curr[0]= max(prices[ind]+front[1] ,  after[0]);
     
                
            
        front = after;
        after = curr;
    }
        return curr[1];

        
    }
};