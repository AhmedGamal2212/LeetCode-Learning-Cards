class Solution {
public:
    
    int numSquares(int n) {
        queue<int> q;
        
        int shortest = 0;
        q.push(n);
        
        while(not q.empty()){
            int size =  (int)q.size();
            
            while(size--){
                int curr = q.front();
                q.pop();
                
                for(int i = 1; i * i <= curr; i++){
                    if(not(curr - i * i)){
                        return shortest + 1;
                    }
                    q.push(curr - i * i);
                }
            }
            shortest++;
        }
        return 0;
    }
};