class Solution {
public:
    
    int row[4]={-1,1,0,0};
    int col[4]={0,0,-1,1};

    bool valid(int n,int m,int i,int j){

        if(i<0 || i>=n || j<0 || j>=m) return 0;

        return 1;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        
        queue<pair<int,int>>q;
        int n=grid.size();
        int m=grid[0].size();
        int fresh=0;
        int time=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                    grid[i][j]=-1;
                }

                else if(grid[i][j]==1) fresh++;
            }
        }

        while(!q.empty() && fresh>0){
             
             time++;
             int s=q.size();

             while(s--){

                int i=q.front().first;
                int j=q.front().second;
                q.pop();

                for(int k=0;k<4;k++){

                    int r=i+row[k];
                    int c=j+col[k];

                    if(valid(n,m,r,c) && grid[r][c]==1){
                        q.push({r,c});
                        grid[r][c]=-1;
                        fresh--;
                    }
                }
             }
        }

        if(!fresh) return time;
        return -1;

    }
};