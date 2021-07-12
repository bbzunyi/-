//
//  main.cpp
//  oj2_1
//
//  Created by bb on 2021/4/16.
//  Copyright © 2021 mac. All rights reserved.
//

#include <iostream>
#include <string.h>
using namespace std;
void Sort(int left, int right,char**arr){
    if(left >= right)
        return;
    int i, j;
    char*temp=new char[11];
    i = left;
    j = right;
    char*pivot=new char[11];
    strcpy(pivot,arr[left]);  //取最左边的数为基准数
    while (i < j)
    {
        while (strcmp(arr[j],pivot)>=0 && i < j)
            j--;
        while (strcmp(arr[i],pivot)<=0 && i < j)
            i++;
        if(i < j)
        {
            strcpy(temp,arr[i]);
            strcpy(arr[i],arr[j]);
            strcpy(arr[j],temp);
        }
    }
    //基准数归位
    strcpy(arr[left],arr[i]);
    strcpy(arr[i],pivot);
    Sort(left, i - 1,arr);//递归左边
    Sort(i + 1, right,arr);//递归右边

}
long long int reverse_number(char**arr,int left,int right){
    long long num=0;
    if(right==left)
        return num;
    int mid=left+(right-left)/2;
    num+=reverse_number(arr, left, mid);
    num+=reverse_number(arr, mid+1, right);
    Sort(left, mid, arr);
    Sort(mid+1, right, arr);
    int i=left;
    int j=mid+1;
    while(i<=mid){
        if(strcmp(arr[i],arr[j])>0){
            num+=mid-i+1;
            j++;
            if(j>right)
                break;
        }
        else
            i++;
    }
    return num;
}
int main() {
    int n;
    cin>>n;
    char**str=new char*[n];
    int i;
    for(i=0;i<n;i++){
        str[i]=new char[11];
        cin>>str[i];
    }
    cout<<"wo yi yue du guan yu chao xi de shuo ming"<<endl;
    cout<<reverse_number(str, 0, n-1)<<endl;
}
