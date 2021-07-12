//
//  main.cpp
//  oj_3_1
//
//  Created by bb on 2021/4/27.
//  Copyright © 2021 mac. All rights reserved.
//

#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <stdio.h>
#include <queue>
using namespace std;
bool cmp(const int &a,const int &b)
{
  return a>b;
}
int main(){
    int num;
    priority_queue<int, vector<int>, less<int>> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    while(cin>>num){
         if(max_heap.empty()){
                    max_heap.push(num);
                    cout<<max_heap.top()<<" ";
                }
                else{
                if(num<max_heap.top()){
                    max_heap.push(num);
                }
                else{
                    min_heap.push(num);
                }
                if((int)max_heap.size()>(int)min_heap.size()+1){
                    int top=max_heap.top();
                    max_heap.pop();
                    min_heap.push(top);
                }
                else if((int)min_heap.size()>(int)max_heap.size()+1){
                    int bottom=min_heap.top();
                    min_heap.pop();
                    max_heap.push(bottom);
                }
        
                if((int)max_heap.size()>=(int)min_heap.size()){
                    cout<<max_heap.top()<<" ";
                }
                else{
                    cout<<min_heap.top()<<" ";
                }
        
                }
    }
//    int num;
//    vector<int> max_heap,min_heap;
//    while(cin>>num){
//        if(max_heap.empty()){
//            max_heap.push_back(num);
//            cout<<max_heap[0]<<" ";
//        }
//        else{
//        if(num<max_heap[0]){
//            max_heap.push_back(num);
//            make_heap(max_heap.begin(), max_heap.end());
//        }
//        else{
//            min_heap.push_back(num);
//            make_heap(min_heap.begin(), min_heap.end(), cmp);
//        }
//        if((int)max_heap.size()>(int)min_heap.size()+1){
//            int top=max_heap[0];
//            max_heap.erase(max_heap.begin());
//            make_heap(max_heap.begin(), min_heap.begin());
//            min_heap.push_back(top);
//            make_heap(min_heap.begin(), min_heap.end(),cmp);
//        }
//        else if((int)min_heap.size()>(int)max_heap.size()+1){
//            int bottom=min_heap[0];
//            min_heap.erase(min_heap.begin());
//            make_heap(min_heap.begin(), min_heap.end(),cmp);
//            max_heap.push_back(bottom);
//            make_heap(max_heap.begin(), max_heap.end());
//        }
//
//        if(max_heap.size()>=min_heap.size()){
//            cout<<max_heap[0]<<" ";
//        }
//        else{
//            cout<<min_heap[0]<<" ";
//        }
//
//        }
//    }
//    return 0;
}
