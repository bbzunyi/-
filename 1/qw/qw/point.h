//
//  point.h
//  qw
//
//  Created by bb on 2021/6/28.
//  Copyright © 2021 mac. All rights reserved.
//

#ifndef point_h
#define point_h
#include<iostream>
using namespace std;
//头文件可以不写这两句*/
class point
{
public:
    friend void point_count(point *p);//声明为友员函数，便于引用类的私有数据
    friend void build_line(point *p);
    void set_value()                  //作用：输入点的坐标
    {
        cout<<"请输入点的坐标"<<endl;
        cin>>x>>y;
    }
    void show()                       //作用：输出点的坐标
    {
        cout<<"点的坐标是:("<<x<<","<<y<<")"<<endl;
    }
private:
    float x,y;
};


void point_count(point *p)            //作用：计算两点间的距离
{
    cout<<"两点间的距离为:"<<endl;
    cout<<sqrt(((*p).x-(*(p+1)).x)*((*p).x-(*(p+1)).x)+((*p).y-(*(p+1)).y)*((*p).y-(*(p+1)).y))<<endl;
}

void build_line(point *p)             //作用：用两点构造直线
{
    cout<<"两个点的坐标为:("<<(*p).x<<","<<(*p).y<<"),("<<(*(p+1)).x<<","<<(*(p+1)).y<<")"<<endl;
    cout<<"参数:a="<<(*p).y-(*(p+1)).y<<",b="<<(*(p+1)).x-(*p).x<<",c="<<(*(p+1)).y*(*p).x-(*p).y*(*(p+1)).x<<endl;
    cout<<"直线方程是:"<<(*p).y-(*(p+1)).y<<"x+"<<(*(p+1)).x-(*p).x<<"y+"<<(*(p+1)).y*(*p).x-(*p).y*(*(p+1)).x<<"=0"<<endl;
}


#endif /* point_h */
