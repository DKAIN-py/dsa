#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
#include<limits>

using namespace std;

vector<int> indegree(vector<vector<int>> adjMat, int vertices){
    vector<int> indegrees(vertices, 0);

    for(int i =0; i<vertices; i++){
        for(int j =0; j<vertices; j++){
            if( adjMat[j][i] == 1 ){
                indegrees[i]++;
            }
        }
    }

    return indegrees;
}

void topologicalSort(vector<vector<int>> adjMat, int vertices){
    vector<int> indegrees = indegree(adjMat,vertices);
    vector<int> order;
   
   
    for(int count = 0; count<vertices; count++){
        
        int cur_ver = distance(indegrees.begin(), min_element(indegrees.begin(),indegrees.end())); 
        if(indegrees[cur_ver]!=0){
            cout<<"Graph contains a cycle!!"<<endl;
            return;
        }
        order.push_back(cur_ver);
        indegrees[cur_ver] = numeric_limits<int>::max();
        
    
        for(int i = 0; i<vertices; i++){
            if(adjMat[cur_ver][i]==1 && indegrees[i]!=numeric_limits<int>::max() ){
                indegrees[i]--;
            }
        }    

    }
    
    cout<<"Topological ordering: ";
    for(int v : order) cout<<v<<" ";

}

int main(){
    int vertices = 5;
    vector<vector<int>> adjMat = {
        {0, 1, 0, 1, 0}, // edges from vertex 0 → 1, 3
        {0, 0, 1, 1, 0}, // edges from vertex 1 → 2
        {0, 0, 0, 0, 1}, // edges from vertex 2 → 4
        {0, 0, 0, 0, 0}, // edges from vertex 3 → 1
        {0, 0, 0, 1, 0}  // edges from vertex 4 → 3
    };

    topologicalSort(adjMat,vertices);
    return 0;
}