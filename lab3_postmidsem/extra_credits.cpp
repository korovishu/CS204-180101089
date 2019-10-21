#include <bits/stdc++.h> 
using namespace std; 
  
int visited[10000][10000]; 
int input[10000][10000];
int COUNT; 


  
bool is_valid(int x, int y, int key, int n, int m) 
{ 
    if (x < n && y < m && x >= 0 && y >= 0) { 
        if (visited[x][y] == false && input[x][y] == key) 
            return true; 
        else
            return false; 
    } 
    else
        return false; 
} 
  
void BFS(int x, int y, int i, int j, int n, int m) 
{ 
    if (x != y) 
        return; 
  
    visited[i][j] = 1; 
    COUNT++; 
  
    int x_move[] = { 0, 0, 1, -1 }; 
    int y_move[] = { 1, -1, 0, 0 }; 
   
    for (int u = 0; u < 4; u++) 
        if (is_valid(i + y_move[u], j + x_move[u], x,n,m)) 
            BFS(x, y, i + y_move[u], j + x_move[u], n, m); 
} 
  
void reset_visited(int n, int m) 
{ 
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) 
            visited[i][j] = 0; 
} 
   
void hulala(int n, int m) 
{ 
    int current_max = INT_MIN; 
    int color;
  
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < m; j++) { 
            reset_visited(n,m); 
            COUNT = 0; 
            
            if (j + 1 < m) 
                BFS(input[i][j], input[i][j + 1], i, j,n,m); 
            
            if (COUNT >= current_max) { 
                current_max = COUNT; 
                color=input[i][j];
            } 
            reset_visited(n,m); 
            COUNT = 0; 
            
            if (i + 1 < n) 
                BFS(input[i][j], input[i + 1][j], i, j, n,m); 
            
            if (COUNT >= current_max) { 
                current_max = COUNT; 
                color=input[i][j];
            } 
        } 
    } 
    if(current_max==0) current_max++;
    cout<<current_max<<" "<<color<<endl; 
} 

int main() 
{ 
    int n,m,c;cin>>n>>m>>c;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>input[i][j];
        }
    } 
  
    
    hulala(n,m); 
    return 0; 
} 
