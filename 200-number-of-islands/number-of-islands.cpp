class Solution {
public:

    int row[4]={-1,1,0,0};
    int col[4]={0,0,-1,1};

    bool valid(int n,int m,int i,int j){

        if(i<0 || i>=n || j<0 || j>=m) return 0;

        return 1;
    }

    void bfs(vector<vector<char>>& grid,int n,int m,int i,int j,vector<vector<bool>>&visited){
              
         visited[i][j]=1;

         for(int k=0;k<4;k++){

            int r=i+row[k];
            int c=j+col[k];
            
            if(valid(n,m,r,c) && grid[r][c]=='1' && visited[r][c]==0){
                bfs(grid,n,m,r,c,visited);
            }
         }
    }

    int numIslands(vector<vector<char>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        int res=0;
        vector<vector<bool>>visited(n,vector<bool>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(grid[i][j]=='1'&& visited[i][j]==0 ){
                    bfs(grid,n,m,i,j,visited);
                    res++;
                }          
            }
        }

        return res;
    }
};