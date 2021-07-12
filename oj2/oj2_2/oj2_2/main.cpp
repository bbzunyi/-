//
//  main.cpp
//  oj2_2
//
//  Created by bb on 2021/4/16.
//  Copyright © 2021 mac. All rights reserved.
//

#include <iostream>
#include <map>
#include <string.h>
#include<algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
bool cmp(const string &x,const string &y)
{
        return x<y;
}
void Ectopic_word(vector<string>& strs) {
        vector<vector<string>> ans;
        int count=0;
        unordered_map<string,vector<string>>mp;
        for(const auto& str:strs){
            auto key=str;
            sort(key.begin(),key.end());
            mp[key].push_back(str);
        }
        for(const auto&m:mp){
            ans.push_back(m.second);
        }
    for(int i=0;i<ans.size();i++){
        if(ans[i].size()>1)
            count++;
    }
    cout<<count<<endl;
    vector<string> res;
    for(int i=0;i<ans.size();i++){
        if(ans[i].size()>1){
            string min=ans[i][0];
            for(int j=1;j<ans[i].size();j++){
                if(ans[i][j]<min)
                    min=ans[i][j];
            }
            res.push_back(min);
        }
    }
    sort(res.begin(),res.end());
    for(int i=0;i<res.size();i++)
        cout<<res[i]<<endl;
}

int main(){
    int n;
    cin>>n;
    vector<string> str;
    int i=0;
    for(;i<n;i++){
        string s;
        cin>>s;
        str.push_back(s);
    }
    cout<<"wo yi yue du guan yu chao xi de shuo ming"<<endl;
    Ectopic_word(str);
}
