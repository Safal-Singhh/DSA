// Brute Force Approach

// class MinStack {
// public:
//     stack<int> st;
//     MinStack() { 
//     }
    
//     void push(int val) {
//         st.push(val);
//     }
    
//     void pop() {
//         st.pop();
//     }
    
//     int top() {
//         return st.top();
//     }
    
//     int getMin() {
//         stack<int> second;
//         int mn = INT_MAX;
//         while(!st.empty()){
//             mn = min(mn, st.top());
//             second.push(st.top());
//             st.pop();
//         }
//         while(!second.empty()){
//             st.push(second.top());
//             second.pop();
//         }
//         return mn;
//     }
// };
