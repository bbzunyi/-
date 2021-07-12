//
//  main.cpp
//  qw
//
//  Created by bb on 2021/6/28.
//  Copyright © 2021 mac. All rights reserved.
//

#include<iostream>
#include<cmath>
#include<string>
using namespace std;
#include"point.h"
#include"line.h"
#include"circle.h"

int main()
{
    point poi[2];
    line lin[2];
    circle cir;
    int i;
    string choose;                    //choose 选择是否继续输入
    string typ;                       //typ：图形的形状


    //  while(1)无限循环，让用户自己选择
    for(;;)
    {
        cout<<"请输入图形类型"<<endl;
        cin>>typ;  //出现过：'cin' : ambiguous(不明确的，多定义的) symbol
        cout<<"图形为："<<typ<<endl;

//处理点的问题
        if(typ=="point")
        {
            for(i=0;;i++)             //注意要让程序跳出
            {
                poi[i].set_value();
                cout<<"是否继续输入点的坐标?"<<endl;
                cin>>choose;
                if(choose=="no")break;
            }
            if(i==0)poi[0].show();
            else if(i==1)
            {
                for(i=0;i<2;i++)
                {
                    poi[i].show();
                }
                point_count(poi);
                build_line(poi);
            }
            else break;
        }

//处理直线的问题
        else if(typ=="line")
        {
            for(i=0;;i++)
            {
                lin[i].set_value();
                cout<<"是否继续输入直线的参数?"<<endl;
                cin>>choose;
                if(choose=="no")break;//只有选择了不输入时，才能跳出
            }
            if(i==0)lin[0].show();
            else if(i==1)
            {
                for(i=0;i<2;i++)
                {
                    lin[i].show();
                }
                line_count(lin);
            }

        }

//处理圆的问题
        else if(typ=="circle")
        {
            cir.set_value();
            cir.show();
        }

//处理其他图形的问题
        else cout<<"图形不在指定的范围内"<<endl;
        cout<<"是否继续输入图形的类型?"<<endl;
        cin>>choose;
        if(choose=="no")break;        //同样只有选择了不输入时，才能跳出
    }


    return 0;
}
