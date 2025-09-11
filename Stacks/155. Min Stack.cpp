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

// Optimal Approach
class MinStack {
public:
    stack<long long> st;
    long long min;
    MinStack() {
        min = LLONG_MAX;  
    }
    
    void push(int val) {
        long long x = (long long)val;
        if(st.empty()){
            st.push(x);
            min = x;
        }
        else if(x >= min) st.push(x);
        else{
            st.push(2*x - min);
            min = x;
        }
    }
    
    void pop() {
        if(st.top() < min){ // Fake value present
            // before popping make sure to retrieve the oldMin
            long long oldMin = 2*min - st.top();
            min = oldMin;
        }
        st.pop();
    }
    
    int top() {
        if(st.top() < min) return (int)min;
        else return (int)st.top();
    }
    
    int getMin() {
        return (int)min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */