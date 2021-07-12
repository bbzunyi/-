//
//  line.h
//  qw
//
//  Created by bb on 2021/6/28.
//  Copyright © 2021 mac. All rights reserved.
//

#ifndef line_h
#define line_h
#include<iostream>
using namespace std;
class line
{
public:
    friend void line_count(line *p);//声明为友员函数
    void set_value()                //作用：输入直线的三个参数
    {
        cout<<"请输入直线的三个参数"<<endl;
        cin>>a>>b>>c;
    }
    void show()                     //作用：输出直线的方程
    {
        if(a==1&&b!=1)cout<<"直线的方程为:x+"<<b<<"y+"<<c<<"=0"<<endl;
        else if(a!=1&&b==1)cout<<"直线的方程为:"<<a<<"x+y+"<<c<<"=0"<<endl;
        else if(a==1&&b==1)cout<<"直线的方程为:x+y+"<<c<<"=0"<<endl;
        else cout<<"直线的方程为:"<<a<<"x+"<<b<<"y+"<<c<<"=0"<<endl;
    }
private:
    float a,b,c;
};

void line_count(line *p)            //作用:计算两直线的交点
{
    if((*p).a/(*(p+1)).a==(*p).b/(*(p+1)).b)cout<<"两直线平行，没有交点"<<endl;
    else {
        cout<<"两直线的交点是:"<<endl;
        cout<<"("<<((*p).b*(*(p+1)).c-(*p).c*(*(p+1)).b)/((*p).b*(*(p+1)).a-(*p).a*(*(p+1)).b)<<","
        <<((*p).a*(*(p+1)).c-(*p).c*(*(p+1)).a)/((*p).a*(*(p+1)).b-(*p).b*(*(p+1)).a)<<")"<<endl;
    }
}


#endif /* line_h */
