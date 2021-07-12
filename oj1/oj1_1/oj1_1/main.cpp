//
//  main.cpp
//  oj1_1
//
//  Created by bb on 2021/3/30.
//  Copyright © 2021 mac. All rights reserved.
//

#include <iostream>
using namespace std;
void quickSort(int left, int right,int*arr){
    if(left >= right)
        return;
    int i, j;
    int temp;
    i = left;
    j = right;
    int pivot = arr[left];  //取最左边的数为基准数
    while (i < j)
    {
        while (arr[j] >= pivot && i < j)
            j--;
        while (arr[i] <= pivot && i < j)
            i++;
        if(i < j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    //基准数归位
    arr[left] = arr[i];
    arr[i] = pivot;
    quickSort(left, i - 1,arr);//递归左边
    quickSort(i + 1, right,arr);//递归右边

}
int main(){
    int k,n;
    int i;
    scanf("%d %d",&k,&n);
    int*A=new int [100];
    for(i=0;i<n;i++)
        scanf("%d",&A[i]);
    quickSort(0, n-1,A);
    int mid=(n-1)/2;
    for(i=0;i<2*k+1;i++)
        printf("%d ",A[mid-k+i]);
}
