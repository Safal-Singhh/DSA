class Solution {
  public:
    void rearrangeQueue(queue<int> &q) {
        // code here
        int n = q.size()/2;
        queue<int> dummy;
        for(int i = 0; i < n; i++){
            dummy.push(q.front());
            q.pop();
        }
        while(!dummy.empty()){
            q.push(dummy.front());
            dummy.pop();
            q.push(q.front());
            q.pop();
        }
    }
};