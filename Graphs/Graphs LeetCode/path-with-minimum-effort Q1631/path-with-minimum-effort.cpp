#include<bits/stdc++.h>
using namespace std;
class Solution { 

        //har ek entry weight hai 
        //target is the bottom right
        //4 way moving allowed 
        //effort=max abs diff of height
        //we have to return the min effort

        //dijkstra
        //let each cell a node ad the edge with the weight= the abs diff of weight betwee the cell of that matrix
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        //number of rows
        int row=heights.size();
        //columns
        int col=heights[0].size();
        //distance matrix 
        vector<vector<int>> dist(row,vector<int>(col,1e9));
        dist[0][0]=0;
        //making the set and since now our node is not only one int it is  {row,col}
        set<pair<int,pair<int,int>>> st;
        st.insert({0,{0,0}});

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

                    //calcultaing the new dist 
                    int jump=abs(heights[curr_row][curr_col]-heights[nrow][ncol]);

                    //new max dist
                    int newdist=max(currdist,jump);
                    
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
        return 0;

    }
};
