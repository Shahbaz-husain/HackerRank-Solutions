#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <unordered_set>
using namespace std;

long MM = 1000000007;

class Node;

class Edge{
public:
    Node* next;
    char c;
    Edge(Node* next, char c){
        this->next = next;
        this->c = c;
    }
};

class Node{
public:
    vector<Edge*> edges;
};

class DNode{
public:
    int id;
    string str;
    set<int> nodes;
    bool end;
    DNode* a;
    DNode* b;
    DNode(int id, string str, set<int> nodes, bool end = false){
        this->id = id;
        this->str = str;
        this->nodes = nodes;
        this->end = end;
        a = 0; b = 0;
    }
};

class TreeNode{
public:
    int type; // 0-a, 1-b, 2-concat, 3-union, 4-*
    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;
    TreeNode(TreeNode* parent, int type = 2){
        this->parent = parent;
        this->type = type;
        this->left = 0;
        this->right = 0;
    }
};

TreeNode* makeTree(string s){
    TreeNode* root = new TreeNode(0);
    TreeNode* curr = root;
    bool haveLeft = false;
    for (int i = 0; i < s.size(); i++){
        switch(s[i]){
            case 'a':
            case 'b':{
                if (curr->left) curr->right = new TreeNode(curr, s[i]-'a');
                else curr->left = new TreeNode(curr, s[i]-'a');
                break;
            }
            case '(':{
                TreeNode* tn = new TreeNode(curr);
                if (curr->left) curr->right = tn;
                else curr->left = tn;
                curr = tn;
                break;
            }
            case ')':{
                curr = curr->parent;
                break;
            }
            case '|':{
                curr->type = 3;
                break;
            }
            case '*':{
                curr->type = 4;
                break;
            }
        }
    }
    return root->left;
}

vector<Node*> makeNFA(TreeNode* root){
    vector<Node*> out;
    switch (root->type){
        case 0:
        case 1:{
            out.push_back(new Node());
            out.push_back(new Node());
            out[0]->edges.push_back(new Edge(out[1], 'a' + root->type));
            break;
        }
        case 2:{ // concat
            vector<Node*> p1 = makeNFA(root->left);
            vector<Node*> p2 = makeNFA(root->right);
            bool rec = false;
            for (int i = 1; i < p2.size(); i++){
                if (p2[0] == p2[i]){
                    rec = true;
                    break;
                }
            }
            out = p2;
            out[0] = p1[0];
            for (int i = 1; i < p1.size(); i++){
                p1[i]->edges.insert(p1[i]->edges.end(), p2[0]->edges.begin(), p2[0]->edges.end());
                if (rec) out.push_back(p1[i]);
            }
            break;
        }
        case 3:{ // union
            vector<Node*> p1 = makeNFA(root->left);
            vector<Node*> p2 = makeNFA(root->right);
            out = p1;
            out[0]->edges.insert(out[0]->edges.end(), p2[0]->edges.begin(), p2[0]->edges.end());
            for (int i = 1; i < p2.size(); i++){
                if (p2[i] == p2[0]){
                    p2[i] = p1[0];
                } else {
                    for (int j = 0; j < p2[i]->edges.size(); j++){
                        if (p2[i]->edges[j]->next == p2[0]) p2[i]->edges[j]->next = p1[0];
                    }
                }
            }
            out.insert(out.end(), p2.begin() + 1, p2.end());
            break;
        }
        case 4:{ // *
            out = makeNFA(root->left);
            bool rec = false;
            for (int i = 1; i < out.size(); i++){
                if (out[0] == out[i]) rec = true;
                unordered_set<Edge*> s;
                for (Edge* x : out[i]->edges) s.insert(x);
                for (Edge* x : out[0]->edges) s.insert(x);
                out[i]->edges.assign(s.begin(), s.end());
            }
            if (!rec) out.push_back(out[0]);
            break;
        }
    }
    
    return out;
}

int countNodes(Node* root){
    map<Node*, int> seen;
    queue<Node*> Q;
    Q.push(root);
    int out = 0;
    while (!Q.empty()){
        Node* n = Q.front();
        Q.pop();
        seen[n] = 1;
        out += 1;
        for (vector<Edge*>::iterator it = n->edges.begin(); it != n->edges.end(); it++){
            Edge* e = *it;
            if (seen.find(e->next) == seen.end()) Q.push(e->next);
        }
    }
    return out;
}

string setString(set<int> &s){
    stringstream ss;
    bool first = true;
    for (set<int>::iterator it = s.begin(); it != s.end(); it++){
        if (!first) ss << " ";
        first = false;
        ss << *it;
    }
    return ss.str();
}

pair<DNode*, int> makeDFA(vector<Node*> &v){
    map<Node*, int> endNodes;
    map<int, Node*> idToNode;
    map<Node*, int> nodeToId;
    queue<Node*> Q1;
    Q1.push(v[0]);
    idToNode[0] = v[0];
    nodeToId[v[0]] = 0;
    int nextID = 1;
    while (!Q1.empty()){
        Node* n = Q1.front(); Q1.pop();
        for (vector<Edge*>::iterator it = n->edges.begin(); it != n->edges.end(); it++){
            Edge* e = *it;
            if (nodeToId.find(e->next) == nodeToId.end()){
                idToNode[nextID] = e->next;
                nodeToId[e->next] = nextID++;
                Q1.push(e->next);
            }
        }
    }
    for (int i = 1; i < v.size(); i++){
        endNodes[v[i]] = 1;
    }
    
    map<string, DNode*> DNMap;
    
    set<int> si;
    si.insert(0);
    
    bool rootEnd = (endNodes.find(idToNode[0]) != endNodes.end());
    DNode* firstDNode = new DNode(0, "0", si, rootEnd);
    DNMap["0"] = firstDNode;
    queue<DNode*> Q;
    Q.push(firstDNode);
    nextID = 1;
    while (!Q.empty()){
        DNode* newv = Q.front(); Q.pop();
        
        set<int> aset;
        set<int> bset;
        for (set<int>::iterator it = newv->nodes.begin(); it != newv->nodes.end(); it++){
            vector<Edge*> &vv = idToNode[*it]->edges;
            for (int j = 0; j < vv.size(); j++){
                if (vv[j]->c == 'a') {
                    aset.insert(nodeToId[vv[j]->next]);
                } else {
                    bset.insert(nodeToId[vv[j]->next]);
                }
            }
        }
        
        if (aset.size() > 0){
            string aStr = setString(aset);
            if (DNMap.find(aStr) != DNMap.end()){
                newv->a = DNMap[aStr];
            } else {
                bool isEndNode = false;
                for (set<int>::iterator it = aset.begin(); it != aset.end(); it++){
                    if (endNodes.find(idToNode[*it]) != endNodes.end()){
                        isEndNode = true;
                        break;
                    }
                }
                DNode* aNode = new DNode(nextID++, aStr, aset, isEndNode);
                newv->a = aNode;
                DNMap[aStr] = aNode;
                Q.push(aNode);
            }
        }
        if (bset.size() > 0){
            string bStr = setString(bset);
            if (DNMap.find(bStr) != DNMap.end()){
                newv->b = DNMap[bStr];
            } else {
                bool isEndNode = false;
                for (set<int>::iterator it = bset.begin(); it != bset.end(); it++){
                    if (endNodes.find(idToNode[*it]) != endNodes.end()){
                        isEndNode = true;
                        break;
                    }
                }
                DNode* bNode = new DNode(nextID++, bStr, bset, isEndNode);
                newv->b = bNode;
                DNMap[bStr] = bNode;
                Q.push(bNode);
            }
        }
    }
    
    return {firstDNode, nextID};
}

long calcOut(DNode* d, int n, long k){
    vector<int> endNodes;
    
    long M[n][n];
    long X[n][n];
    long Y[n][n];
    long temp[n];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            M[i][j] = 0;
            if (i == j) X[i][j] = 1;
            else X[i][j] = 0;
        }
    }
    
    map<DNode*, int> seen;
    seen[d] = 1;
    queue<DNode*> Q;
    Q.push(d);
    while (!Q.empty()){
        DNode* d2 = Q.front(); Q.pop();
        if (d2->end) endNodes.push_back(d2->id);
        if (d2->a){
            M[d2->id][d2->a->id]++;
            if (seen.find(d2->a) == seen.end()){
                Q.push(d2->a);
                seen[d2->a] = 1;
            }
        }
        if (d2->b){
            M[d2->id][d2->b->id]++;
            if (seen.find(d2->b) == seen.end()){
                Q.push(d2->b);
                seen[d2->b] = 1;
            }
        }
    }
    
    long p2 = 1;
    while (2*p2 <= k) p2 *= 2;
    
    while (p2 > 0){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                Y[i][j] = X[i][j];
            }
        }
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                X[i][j] = 0;
                for (int l = 0; l < n; l++){
                    X[i][j] += Y[i][l] * Y[l][j];
                    X[i][j] %= MM;
                }
            }
        }
        if (k >= p2){
            k -= p2;
            for (int i = 0; i < n; i++){
                for (int j = 0; j < n; j++){
                    temp[j] = X[i][j];
                }
                for (int j = 0; j < n; j++){
                    X[i][j] = 0;
                    for (int l = 0; l < n; l++){
                        X[i][j] += temp[l] * M[l][j];
                        X[i][j] %= MM;
                    }
                }
            }
        }
        p2 /= 2;
    }
    
    long out = 0;
    for (vector<int>::iterator it = endNodes.begin(); it != endNodes.end(); it++){
        out += X[0][*it];
        out %= MM;
    }
    return out;
}

int main() {
    long t, l; 
    cin >> t;
    while (t--){
        string s;
        cin >> s >> l;
        //cout << s << endl;
        TreeNode* root = makeTree(s);
        //printTree(root); cout << endl;
        vector<Node*> v = makeNFA(root);
        //printNFA(v);
        pair<DNode*, int> p = makeDFA(v);
        //printDFA(p.first);
        cout << calcOut(p.first, p.second, l) << endl;
    }
}