//
//  main.cpp
//  oj_5.1
//
//  Created by bb on 2021/5/28.
//  Copyright © 2021 mac. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
enum Color {white,black,grey};
struct Point{
    int id=0;
    int discovertime=0;
    int back=0;
    int parent=0;
    vector<int> neighbor;
    Color color=white;
};
struct edge{
    int x;
    int y;
};
vector<int> articulation_point;
vector<edge> bridge;
vector<Point> all_point;
int my_time=0;
void find_articulation_point(int v){
    all_point[v].color=grey;
    my_time++;
    all_point[v].discovertime=my_time;
    all_point[v].back=all_point[v].discovertime;
    for(int w=0;w<all_point[v].neighbor.size();w++){
        int neighbor=all_point[v].neighbor[w];
        if(all_point[neighbor].color == white){
            find_articulation_point(neighbor);
            if(all_point[neighbor].back>=all_point[v].discovertime){
                bool flag=true;
                for(int i=0;i<articulation_point.size();i++){
                   if(v==articulation_point[i])
                       flag=false;
                }
                if(flag)
                    articulation_point.push_back(v);
            }
            all_point[v].back=min(all_point[neighbor].back,all_point[v].back);
        }
        else if(all_point[neighbor].color == grey){
            all_point[v].back=min(all_point[neighbor].discovertime,all_point[v].back);
        }
    }
    all_point[v].color=black;
}
bool my_flag;
void is_articulation_point(int v){
    all_point[v].color=grey;
    my_time++;
    all_point[v].discovertime=my_time;
    all_point[v].back=all_point[v].discovertime;
    for(int w=0;w<all_point[v].neighbor.size();w++){
        int neighbor=all_point[v].neighbor[w];
        if(all_point[neighbor].color == white){
            is_articulation_point(neighbor);
            if(all_point[neighbor].back>=all_point[v].discovertime){
                if(v==0)
                    my_flag=true;
            }
            all_point[v].back=min(all_point[neighbor].back,all_point[v].back);
        }
        else if(all_point[neighbor].color == grey){
            all_point[v].back=min(all_point[neighbor].discovertime,all_point[v].back);
        }
    }
    all_point[v].color=black;
}
void find_bridge(int v){
    all_point[v].color=grey;
    my_time++;
    all_point[v].discovertime=my_time;
    all_point[v].back=all_point[v].discovertime;
    for(int w=0;w<all_point[v].neighbor.size();w++){
        int neighbor=all_point[v].neighbor[w];
        if(all_point[neighbor].color == white){
            all_point[neighbor].parent=v;
            find_bridge(neighbor);
            all_point[v].back=min(all_point[neighbor].back,all_point[v].back);
            if(all_point[neighbor].back>all_point[v].discovertime){
                bool flag=true;
                for(int i=0;i<bridge.size();i++){
                   if((v==bridge[i].x&&neighbor==bridge[i].y)||(neighbor==bridge[i].x&&v==bridge[i].y))
                       flag=false;
                }
                if(flag){
                    edge x;
                    if(v<neighbor){
                        x.x=v;
                        x.y=neighbor;
                    }
                    else{
                        x.x=neighbor;
                        x.y=v;
                    }
                    bridge.push_back(x);
                }
            }
        }
        else if(all_point[neighbor].color == grey&&all_point[v].parent!=neighbor){
            all_point[v].back=min(all_point[neighbor].discovertime,all_point[v].back);
        }
    }
    all_point[v].color=black;
}
bool cmp(edge a,edge b){
    if(a.x==b.x){
        return a.y<=b.y;
    }
    else
        return a.x<b.x;
}
int main(){
    int num;
    cin>>num;
    for(int i=0;i<num;i++){
        Point a_point;
        a_point.id=i;
        all_point.push_back(a_point);
    }
    int x,y;
    while(cin>>x>>y){
        all_point[x].neighbor.push_back(y);
        all_point[y].neighbor.push_back(x);
    }
    find_articulation_point(0);
    sort(articulation_point.begin(),articulation_point.end(),less<int>());
    if(!my_flag)
        articulation_point.erase(articulation_point.begin());
    for(int i=0;i<articulation_point.size();i++)
        cout<<articulation_point[i]<<endl;
    my_time=0;
    for(int i=0;i<all_point.size();i++)
        all_point[i].color=white;
    find_bridge(0);
    sort(bridge.begin(),bridge.end(),cmp);
    for(int i=0;i<bridge.size();i++)
        cout<<bridge[i].x<<" "<<bridge[i].y<<endl;
    
}
