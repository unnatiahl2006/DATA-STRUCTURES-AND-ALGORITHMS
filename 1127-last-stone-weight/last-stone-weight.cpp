class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int result;
        priority_queue<int>pq(stones.begin(),stones.end());
        while(pq.size()>1){
            int firststone=pq.top();
            pq.pop();
            int secondstone=pq.top();
            pq.pop();
            if(firststone!=secondstone){
                result=firststone-secondstone;
                pq.push(result);
            }
            
        }
        if(pq.empty()) return 0;

        return pq.top();
    }
};