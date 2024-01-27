#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include "Binary_tree.hxx"

using namespace std;

void preOrder_traversal_recursion(Node<int>* root){
    if( root == nullptr)
        return;
    cout << root->data << endl;
    preOrder_traversal_recursion(root->left);
    preOrder_traversal_recursion(root->right);  
}

void preOrder_traversal_iteration(Node<int> *root) {
    if (root == nullptr) return;
    stack<Node<int>*> s;
    s.push(root);
    while(!s.empty()){
        Node<int>* curr = s.top();
        cout << curr->data << " ";
        s.pop();
        if(curr->right != nullptr) s.push(curr->right);
        if(curr->left != nullptr) s.push(curr->left);
    }
}


void inOrder_traversal_recursion(Node<int>* root){
    if( root == nullptr)
        return;
    inOrder_traversal_recursion(root->left);
    cout << root->data << endl;
    inOrder_traversal_recursion(root->right);  
}

void inOrder_traversal_iteration(Node<int> *root) {
    if (root == nullptr) return;
    stack<Node<int>*> s;
    Node<int>* curr = root;
    while(true){
        if(curr != nullptr){
            s.push(curr);
            curr= curr->left;
        }
        else{
            if(s.empty()) break;
            curr = s.top();
            s.pop();
            cout << curr->data << " ";
            curr = curr->right;
        }
    }
}

void postOrder_traversal_recursion(Node<int>* root){
    if( root == nullptr)
        return;
    postOrder_traversal_recursion(root->left);
    postOrder_traversal_recursion(root->right);  
    cout << root->data << endl;
}

void postOrder_traversal_iteration(Node<int> *root) {
    if ( root == nullptr) return;
    stack<Node<int>*> s;
    Node<int>* curr = root;
    while(curr != nullptr or !s.empty()){
        if( curr != nullptr){
            s.push(curr);
            curr = curr->left;
        }
        else{
            Node<int>* temp = s.top() -> right;
            if (temp == nullptr){
                temp = s.top();
                cout << temp->data << " ";
                s.pop();
                while(!s.empty() and temp == s.top()->right){
                    temp = s.top();
                    s.pop();
                    cout << temp->data << " ";
                }
            }
            else 
                curr = temp;
        }
    }
}

void levelOrder_traverse(Node<int>* root) {
    if (root == nullptr)
        return;
    queue<Node<int>*> q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        for(int i = 0; i < size; ++i){
            Node<int>* curr = q.front();
            cout << curr->data << " ";
            q.pop();
            if(curr->left != nullptr) q.push(curr->left);
            if(curr->right != nullptr) q.push(curr->right); 
        }
    }

}

void traverse_2d_array(vector<vector<int>> v){
    for(int i = 0; i < v.size(); ++i){
        for(int j = 0; j < v[i].size(); ++j){
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

vector<vector<int>> levelOrder_traversal(Node<int>* root){
    vector<vector<int>> ans;
    if(root == nullptr) return ans; 
    queue<Node<int>*> q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        vector<int> level;
        for(int i = 0; i < size; ++i){
            Node<int>* curr = q.front();
            q.pop();
            if(curr->left != nullptr) q.push(curr->left);
            if(curr->right != nullptr) q.push(curr->right);
            level.push_back(curr->data);
        }
        ans.push_back(level);
    }
    return ans;
}

int height_of_tree(Node<int>* root){
    if(root == nullptr)
        return 0;
    
    int lh = height_of_tree(root->left);
    int rh = height_of_tree(root->right);

    return max(lh, rh) + 1;
}


int max_edges_in_height_of_tree(Node<int>* root){
    if(root == nullptr)
        return -1;
    
    int lh = max_edges_in_height_of_tree(root->left);
    int rh = max_edges_in_height_of_tree(root->right);

    return 1 + max(lh, rh);
}

int dfsHeight(Node<int>* root){
    if(root == nullptr)
        return 0;
    
    int lh = dfsHeight(root->left);
    if (lh == -1)  return -1;

    int rh = dfsHeight(root->right);
    if (rh == -1)  return -1;

    if(abs(lh - rh) > 1) return -1;
    return max(lh, rh) + 1;
}

bool check_balance(Node<int>* root){
    return dfsHeight(root) != -1;
}