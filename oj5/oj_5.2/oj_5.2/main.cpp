//
//  main.cpp
//  oj_5.2
//
//  Created by bb on 2021/5/30.
//  Copyright © 2021 mac. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
enum Color {white,black,grey};
struct point{
    int id;
    int time;
    vector<int> neighbors;
    int indegree=0;
    int outdegree=0;
    int est=0;
    int eft=0;
    Color color=white;
};
vector<point> points;
void critical_path(int v){
    points[v].est=0;
    points[v].color=grey;
    for(int i=0;i<points[v].neighbors.size();i++){
        int w=points[v].neighbors[i];
        if(points[w].color==white){
            critical_path(w);
            if(points[w].eft>=points[v].est)
                points[v].est=points[w].eft;
        }
        else{
            if(points[w].eft>=points[v].est)
                points[v].est=points[w].eft;
        }
    }
    points[v].eft=points[v].est+points[v].time;
    points[v].color=black;
}
int main(){
    int num;
    cin>>num;
    int i=0;
    int time;
    point a_point;
    int a;
    while(i<num){
        cin>>a;
        cin>>time;
        a_point.id=i;
        a_point.time=time;
        i++;
        points.push_back(a_point);
    }
    int x,y;
    while(cin>>x>>y){
        x--;
        y--;
        points[x].outdegree++;
        points[x].neighbors.push_back(y);
        points[y].indegree++;
    }
    for(i=0;i<points.size();i++){
        if(points[i].indegree==0)
            critical_path(points[i].id);
    }
    int max=0;
    for(i=0;i<points.size();i++){
        if(points[i].eft>max)
            max=points[i].eft;
    }
    cout<<max<<endl;
}
