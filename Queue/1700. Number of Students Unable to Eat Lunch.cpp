class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n = students.size();
        queue<int> q;
        for(int s : students) q.push(s);
        int i = 0;
        int count = 0;
        while(!q.empty() && count != q.size()){
            if(q.front() == sandwiches[i]){
                q.pop();
                i++;
                count = 0;
            }
            else{
                q.push(q.front());
                q.pop();
                count++;
            }
        }
        return count;
    }
};