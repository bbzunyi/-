//
//  circle.h
//  qw
//
//  Created by bb on 2021/6/28.
//  Copyright © 2021 mac. All rights reserved.
//

#ifndef circle_h
#define circle_h
#include<iostream>
using namespace std;
class circle
{
public:
    void set_value()      //作用：输入圆心坐标和半径
    {
        cout<<"请输入圆的坐标和半径"<<endl;
        cin>>x>>y>>r;
    }
    void show()           //作用：输出圆的圆心坐标、半径和方程(构造圆)
    {
        cout<<"圆心坐标:("<<x<<","<<y<<"),半径:"<<r<<endl;
        if(x==0&&y==0)cout<<"圆的方程:xx+yy="<<r*r<<endl;
        else if(x==0&&y!=0)cout<<"圆的方程:xx+(y-"<<y<<")(y-"<<y<<")="<<r*r<<endl;
        else if(y==0&&x!=0)cout<<"圆的方程:"<<"(x-"<<x<<")(x-"<<x<<")+yy="<<r*r<<endl;
        else cout<<"圆的方程:(x-"<<x<<")(x-"<<x<<")+(y-"<<y<<")(y-"<<y<<")="<<r*r<<endl;
    }
private:
    float x,y,r;
};


#endif /* circle_h */
