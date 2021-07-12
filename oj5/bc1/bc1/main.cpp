//
//  main.cpp
//  bc1
//
//  Created by bb on 2021/6/3.
//  Copyright © 2021 mac. All rights reserved.
//

#include <stdio.h>
#define NUM 100
#define BNUM 100
#define MAXLEN 100
#define DIRNUM 100
struct filesys {
        unsigned int s_size;        //总大小
        unsigned int s_itsize;        //inode表大小
        unsigned int s_freeinodesize;    //空闲i节点的数量
        unsigned int s_nextfreeinode;    //下一个空闲i节点
        unsigned int s_freeinode[NUM];     //空闲i节点数组
        unsigned int s_freeblocksize;    //空闲块的数量
        unsigned int s_nextfreeblock;    //下一个空闲块
        unsigned int s_freeblock[NUM];    //空闲块数组
        unsigned int s_pad[];        //填充到512字节
};
//磁盘inode结构
struct finode {
        int fi_mode;            //类型：文件/目录
        int fi_nlink;            //链接数，当链接数为0，意味着被删除
        long int fi_size;        //文件大小
        long int fi_addr[BNUM];        //文件块一级指针，并未实现多级指针
};
//内存inode结构
struct inode {
        struct finode   i_finode;
        struct inode    *i_parent;    //所属的目录i节点
        int     i_ino;            //i节点号
        int     i_users;        //引用计数
};
//目录项结构(非Linux内核的目录项)
struct direct
{
        char d_name[MAXLEN];        //文件或者目录的名字
        unsigned short d_ino;        //文件或者目录的i节点号
};
//目录结构
struct dir
{
        struct direct direct[DIRNUM];    //包含的目录项数组
        unsigned short size;        //包含的目录项大小
};
//抽象的文件结构
struct file {
        struct inode *f_inode;        //文件的i节点
        int f_curpos;            //文件的当前读写指针
};
int main(){
    
}
