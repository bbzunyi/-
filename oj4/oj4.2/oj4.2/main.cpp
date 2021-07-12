//
//  main.cpp
//  oj4.2
//
//  Created by bb on 2021/5/15.
//  Copyright © 2021 mac. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>


using namespace std;
bool lessSort(string a,string b){
    return a<b;
}
int main(){
    int num;
    int k;
    cin>>num>>k;
    vector<string> str;
    string s;
    for(int i=0;i<num;i++){
        cin>>s;
        str.push_back(s);
    }
    sort(str.begin(), str.end(),lessSort);
    int mid=(num-1)>>1;
    for(int i=mid-k;i<=mid+k;i++)
        if(i!=mid+k)
            cout<<str[i]<<" ";
        else{
            cout<<str[i];
        }
}
