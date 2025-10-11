#include <bits/stdc++.h>
using namespace std;
class Node{
public:
    int val;
    Node* left;
    Node* right;
    Node(int data){
        this->val = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void leftBoundary(Node* root){
    if(!root) return;
    if(!root->left && !root->right) return;
    cout << root->val << " ";
    leftBoundary(root->left);
    if(!root->left) leftBoundary(root->right);
}

void leaves(Node* root){
    if(!root) return;
    if(!root->left && !root->right){
        cout << root->val << " ";
        return;
    }
    leaves(root->left);
    leaves(root->right);
}

void rightBoundary(Node* root){
    if(!root) return;
    if(!root->left && !root->right) return;
    rightBoundary(root->right);
    if(!root->right) rightBoundary(root->left);
    cout << root->val << " ";
}

Node* construct(int arr[], int n){
    queue<Node*> q;
    Node* root = new Node(arr[0]);
    q.push(root);
    int i = 1;
    int j = 2;
    while(!q.empty() && i < n){
        Node* temp = q.front();
        q.pop();
        Node* l;
        Node* r;
        if(arr[i] != INT_MIN) l = new Node(arr[i]);
        else l = NULL;
        if(j!= n && arr[j] != INT_MIN) r = new Node(arr[j]);
        else r = NULL;

        temp->left = l;
        temp->right = r;
        if(l != NULL) q.push(l);
        if(r != NULL) q.push(r);

        i += 2;
        j += 2;
    }
    return root;
}
int main(){ 
    int arr[] = {1,2,3,4,5,6,7,8,9,INT_MIN,INT_MIN,10,11,INT_MIN,INT_MIN};
    int n = sizeof(arr)/sizeof(arr[0]);
    Node* root = construct(arr, n);
    leftBoundary(root);
    leaves(root);
    rightBoundary(root->right);
    return 0;
}