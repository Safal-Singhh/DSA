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


// Method - 2
// class MinStack {
// public:
//     stack<int> st;
//     stack<int> second;
//     MinStack() {
        
//     }
    
//     void push(int val) {
//         st.push(val);
//         if(second.empty() || val < second.top()){
//             second.push(val);
//         } else{
//             second.push(second.top());
//         }
//     }
    
//     void pop() {
//         st.pop();
//         second.pop();
//     }
    
//     int top() {
//         return st.top();
//     }
    
//     int getMin() {
//         return second.top();
//     }
// };