//
//  main.cpp
//  oj3_2
//
//  Created by bb on 2021/4/27.
//  Copyright © 2021 mac. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
struct Node{
    int var;
    Node* left=NULL;
    Node* right=NULL;
    Node(int n ){
           var = n;
           left = NULL;
           right = NULL;
       }
};
int max_d=0;
Node* CreateTree(vector<int> pre,vector<int> in)
{
    if(pre.size()==0||in.size()==0||pre.size()!=in.size())
        return NULL;

    Node* root = new Node(pre[0]);//创建根节点
    int index = 0;
    vector<int> left_pre,right_pre,left_in,right_in;//递归需要的参数

    for(int i = 0;i<in.size();i++)//在中序遍历里面找到根节点
        if(root->var==in[i])
            index = i;

    for(int i = 0;i<index;i++)
    {
        left_pre.push_back(pre[i+1]);//根节点左子树前序遍历序列
        left_in.push_back(in[i]);//根节点右左子树中序遍历序列
    }

    for(int j = index+1;j<pre.size();j++)
    {
        right_pre.push_back(pre[j]);//节点右子树前序遍历序列
        right_in.push_back(in[j]);//根节点右子树中序遍历序列
    }

    root->left = CreateTree(left_pre,left_in);//递归构建左子树
    root->right = CreateTree(right_pre,right_in);//递归构建右子树
    return root;

}
int Tree_Height(Node*tree){
    
    if(!tree)
        return -1;
    else{
        int num_left=Tree_Height(tree->left);
        int num_right=Tree_Height(tree->right);
        if(num_left+num_right+2>max_d)
            max_d=num_left+num_right+2;
        if(num_right>num_left)
            return num_right+1;
        else
            return num_left+1;
    }
}
int main(){
    int n;
    cin>>n;
    int num;
    vector<int>pre,in;
    for(int i=0;i<n;i++){
        cin>>num;
        pre.push_back(num);
    }
    for(int i=0;i<n;i++){
        cin>>num;
        in.push_back(num);
    }
    Node*root=CreateTree(pre, in);
    cout<<Tree_Height(root)<<endl;
    cout<<max_d;
}
