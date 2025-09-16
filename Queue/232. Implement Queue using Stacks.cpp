// Push efficient approach
class MyQueue {
public:
    stack<int> st1;
    stack<int> st2;
    MyQueue() {
        
    } 
    
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }
        int x = st2.top();
        st2.pop();
        while(!st2.empty()){
            st1.push(st2.top());
            st2.pop();
        }
        return x;
    }
    
    int peek() {
        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }
        int x = st2.top();
        while(!st2.empty()){
            st1.push(st2.top());
            st2.pop();
        }
        return x;
    }
    
    bool empty() {
        if(st1.empty()) return true;
        else return false;
    }
};


// Pop efficient approach
class MyQueue {
public:
    stack<int> st1;
    stack<int> st2;
    MyQueue() {
        
    } 
    
    void push(int x) {
        if(st1.size() == 0){
            st1.push(x);
            return;
        }
        else{
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
            st1.push(x);
            while(!st2.empty()){
                st1.push(st2.top());
                st2.pop();
            }
        }
    }
    
    int pop() {
        int x = st1.top();
        st1.pop();
        return x;
    }
    
    int peek() {
        return st1.top();
    }
    
    bool empty() {
        if(st1.empty()) return true;
        else return false;
    }
};