class MyCircularQueue {
public:
    int f;
    int b;
    int s;
    int c;
    vector<int> arr;
    MyCircularQueue(int k) {
        f = 0;
        b = 0;
        s = 0;
        c = k;
        vector<int> vec(k);
        arr = vec;
    }
    
    bool enQueue(int val) {
        if(s == c) return false;
        arr[b] = val;
        b++;
        if(b == c) b = 0; // imp
        s++;
        return true;
    }
    
    bool deQueue() {
        if(s == 0) return false;
        f++;
        if(f == c) f = 0; // imp
        s--;
        return true;
    }
    
    int Front() {
        if(s == 0) return -1;
        return arr[f];
    }
    
    int Rear() {
        if(s == 0) return -1;
        if(b == 0) return arr[c-1]; // imp
        return arr[b-1];
    }
    
    bool isEmpty() {
        if(s == 0) return true;
        else return false;
    }
    
    bool isFull() {
        if(s == c) return true;
        else return false;
    }
};