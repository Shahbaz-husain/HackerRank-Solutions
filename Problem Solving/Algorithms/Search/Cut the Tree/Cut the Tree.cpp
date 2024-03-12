#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// depth first search algorithm
int dfs(int* cumulative, bool* visited, vector<int>* edges, const vector<int>& data , const size_t& n, const int& current_node){
    cumulative[current_node]+=data[current_node];
    visited[current_node]=true;
    for(auto& c : edges[current_node]){
        if(!visited[c]){
            visited[c]=true;
            cumulative[current_node]+=dfs(cumulative,visited,edges,data,n,c);
        }
    }
    return cumulative[current_node];
}

int cutTheTree(vector<int> data, vector<vector<int>> edges) {
    vector<int> candidates;
    vector<int>* adjancylist = new vector<int>[data.size()];
    int* cumulative=new int[data.size()]{};
    bool* visited=new bool[data.size()]{};

    // step 1: construct a bi-direction graph
    for(auto& c : edges){
        adjancylist[c[0]-1].push_back(c[1]-1);
        adjancylist[c[1]-1].push_back(c[0]-1);
    }

    // step 2: dfs to calculate the total value of each node
    dfs(cumulative,visited,adjancylist,data,data.size(),0);
    const int v = cumulative[0]/2;
    for(int i=0;i<data.size();i++) 
        visited[i]=false;

    // step 3: bfs using a queue for calculating difference of each edge
    queue<int> search;
    search.push(0);
    visited[0]=true;
    while(!search.empty()){
        int cur_node=search.front();
        search.pop();
        for(auto& next: adjancylist[cur_node]){
            if(!visited[next]){
                visited[next]=true;
                candidates.push_back(cumulative[0]-cumulative[next]);
                if(cumulative[0]-cumulative[next]<v)
                    search.push(next);
            }
        }
    }
    
    for (int& e : candidates) {
        e = abs(cumulative[0] - 2 * e);
    }
    delete[] adjancylist;
    delete[] visited;
    delete[] cumulative;

    // step 4: find the minimal difference
    return *min_element(candidates.begin(),candidates.end());
}

int main()
{
    int n;
    cin >> n;
    vector<int> data(n);
    vector<vector<int>> edges(n - 1, vector<int>(2));

    for (int i = 0; i < n; i++) 
        cin >> data[i];

    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < 2; j++)
            cin >> edges[i][j];

    cout << cutTheTree(data, edges);
}