#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int row=grid.size();
        //columns
        int col=grid[0].size();

        //jo us cell ki value vahi distance mange 
        //distance matrix 
        vector<vector<int>> dist(row,vector<int>(col,1e9));
        dist[0][0]=grid[0][0]; //ham uski cell value ko distance maan rahe h

        //making the set and since now our node is not only one int it is  {row,col}
        set<pair<int,pair<int,int>>> st;
        st.insert({dist[0][0],{0,0}});

        //now while loop and for going to neighbour we will use drow , dcol instred of adj list
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        while(!st.empty()){
            auto top=*(st.begin());//top fetch kar liya
            int currdist=top.first;
            int curr_row=top.second.first;
            int curr_col=top.second.second;
            st.erase(st.begin());
            //now its time to go to the neighbours 
            //base case 
            if(curr_row==row-1 && curr_col==col-1){
                return currdist;
            }
            for(int i=0;i<4;i++){
                int nrow=curr_row+drow[i];
                int ncol=curr_col+dcol[i];
                if(nrow>=0 && nrow<row && ncol>=0 && ncol<col){


                    //new max dist
                    int newdist=max(currdist,grid[nrow][ncol]);//yeh new distance hoga
                    
                    //now updation work
                    if(newdist<dist[nrow][ncol]){
                        //finding iski koi purani entry in set 
                        if(dist[nrow][ncol]!=1e9){
                            st.erase({dist[nrow][ncol],{nrow,ncol}});
                        }
                        //updating 
                        dist[nrow][ncol]=newdist;
                        st.insert({newdist,{nrow,ncol}});
                    }

                }
            }

        }
        return -1;
    }
};