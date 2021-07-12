//
//  main.cpp
//  oj1_2
//
//  Created by bb on 2021/3/30.
//  Copyright © 2021 mac. All rights reserved.
//

#include <iostream>
using namespace std;
void search_sum(int*arr,int sum,int n){
    int s_index=0;
    int l_index=n-1;
    while(s_index<l_index){
        if(arr[s_index]+arr[l_index]==sum){
            printf("%d %d\n",arr[s_index],arr[l_index]);
            s_index++;
            l_index--;
        }
        else if(arr[s_index]+arr[l_index]>sum)
            l_index--;
        else
            s_index++;
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int*arr=new int[n];
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    int sum;
    scanf("%d",&sum);
    search_sum(arr,sum,n);
    return 0;
}
