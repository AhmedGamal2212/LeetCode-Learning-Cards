class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        queue<int> q;
        
        bitset<10000> vis;
        int shortest = 0;
        
        int t = stoi(target);
        
        for(auto& i : deadends){
            vis[stoi(i)] = true;
        }
        if(0 == t)
            return 0;
        if(vis[0])
            return -1;
        
        q.push(0), vis[0] = true;
        
        while(not q.empty()){
            int size = (int)q.size();
            while(size--){
                int curr = q.front();
                int tmp = curr;
                q.pop();
                
                for(int i = 1; i <= 1000; i *= 10){
                    int forward = curr + i * (tmp % 10 == 9 ? -9 : 1);
                    if(not vis[forward]){
                        if(forward == t)
                            return shortest + 1;
                        q.push(forward);
                        vis[forward] = true;
                    }
                    
                    int back = curr - i * (tmp % 10 ? 1 : -9);
                    if(not vis[back]){
                        if(back == t)
                            return shortest + 1;
                        q.push(back);
                        vis[back] = true;
                    }
                    tmp /= 10;
                }
            }
             shortest++;
        }
        return -1;
    }
};