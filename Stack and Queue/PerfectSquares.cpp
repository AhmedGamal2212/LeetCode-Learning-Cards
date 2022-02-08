class Solution {
public:
    vector<int> memo, p;
    
    int dp(int curr){
        if(curr < 4) 
            return curr;
        
        if(~memo[curr])
            return memo[curr];
        
        int ret = 10000;
        for(auto& i : p){
            if(curr >= i){
                ret = min(ret, 1 + dp(curr - i));
            }
        }
        
        return memo[curr] = ret;
    }
    
    int numSquares(int n) {
        memo.assign(n + 1, -1);
        
        for(int i = 1; i * i <= 10000; i++){
            p.emplace_back(i * i);
        }
        
        return dp(n);
        
    }
};