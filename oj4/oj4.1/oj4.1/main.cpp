//
//  main.cpp
//  oj4.1
//
//  Created by bb on 2021/5/14.
//  Copyright © 2021 mac. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){
    int num,sum;
    cin>>num>>sum;
    priority_queue <int,vector<int>,greater<int> > arr;
    int n;
    for(int i=0;i<num;i++){
        cin>>n;
        arr.push(n);
    }
    int count=0;
    int size=(int)arr.size();
    int*data=new int[size+2];
    for(int i=0;i<size;i++){
        data[i]=arr.top();
        arr.pop();
    }
    int sum1;
    for(int i=0;i<size;i++)
        for(int j=i+1;j<size;j++)
            for(int left=j+1,right=size-1;left<=right;){
                sum1=data[i]+data[j];
                int mid=(left+right)>>1;
                if(sum1+data[mid]>sum){
                    right=mid-1;
                }
                else if(sum1+data[mid]<sum)
                    left=mid+1;
                else{
                    count++;
                    break;
                }
                
            }
    cout<<count<<endl;
}
