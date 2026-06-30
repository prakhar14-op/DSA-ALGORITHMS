#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();
        int n=image[0].size();

        //org coloer ko nikal ke rakh lo ham neigh ke pass jake unka color dekh liya karenge if stat me
        int original_color = image[sr][sc];
        //ending statment to skip infinite loop
        if (original_color == color) return image;
        //using bfs approach
        queue<pair<int,int>> q; //{row,col}
        q.push({sr,sc});
        image[sr][sc]=color;

        //step2
        while(!q.empty()){
            //jisko just hamnne value image ki chnage kari uski row and col 
            int r=q.front().first;
            int c=q.front().second;
            //for going to neighbour
            int derow[]={-1,0,1,0};
            int decol[]={0,1,0,-1};

            //step 3
            q.pop();
            for(int i=0;i<4;i++){
                
                int nrow=r+derow[i];
                int ncol=c+decol[i];
                //chechinh anf updateing the image value of neighboour
                if(nrow>=0 && ncol>=0 && nrow<m && ncol<n && image[nrow][ncol]==original_color){
                    q.push({nrow,ncol});
                    image[nrow][ncol]=color;
                }
            }
        }
        return image;
    }
};