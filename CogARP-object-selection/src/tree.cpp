#include<iostream>
#include <stdlib.h>
#include "C:\ma\include\building.h"
#include "C:\ma\include\method.h"
#include "C:\ma\include\tree.h"
#include "C:\ma\include\poltree.h"
// #include "C:\ma\include\method_slidew.h"
#include<vector>
#include<fstream>
#include <string>
#include <iomanip>
#include <sstream>
#include<algorithm>
#include<iterator>
#include <math.h>
#include <windows.h>

using namespace std;


extern vector<building> Ptree;
extern vector<building> pt; 
// extern vector<vector<building>> pol_tree;
int cnt_pol=0;

building pollist[2100000];//tree
int head[1048576];//head
DWORD time_start, time_end;


/* 按照坐标从小到大排序 */
bool cmp3(building x,building y)
{
    return x.getLocation() < y.getLocation();
}

bool cmp9(building x,building y)
{
    return x.getOrd() < y.getOrd();
}

// tree createTree(int n,vector<building> p,double s){
//     // std::cout << "b.getID" << p[0].getOrd() << std::endl;
//     // tree tree;//头结点和索引树部分
//     // vector<vector<poltree>> pol_tree;//索引树部分
//     // vector<building> list;//头结点
//     tree tree;//头结点和索引树部分
//     vector<vector<poltree>> pol_tree;//索引树部分
//     vector<building> list;//头结点
//     int k=0;//层数初始为0
//     int tmp = s/pow(2,k);int d=0;int j=0;
//     vector<poltree> pollist;//先都push进去然后再设置idx
//     vector<poltree> head;
//     vector<building> ptm;
//     vector<poltree>().swap(head);
//     while(k<n){
//         /* 找出所有头结点存入head */
//         tmp = s/pow(2,k),d=0;
//     building b;
//     // vector<building>().swap(list);
//     for(int i=0;i<pow(2,k);i++){
//         int min = 100000;
//         b = building();
//         int flag=0;
//         for(building b1:p){

//             if(b1.getLocation()>d&&b1.getLocation()<=d+tmp){
//                 if(min>b1.getOrd()){
//                 b = b1;
//                 min = b1.getOrd();
//                 // std::cout << "b111.getID" << b.getId() << std::endl;
//                 flag=1;
//                 }
//             }
//             }
//             if(flag==1){
//                 list.push_back(b);
//                 // std::cout << "b.getID" << b.getOrd() << std::endl;
            
//             }
//             else{
//                 building b;
//                 b.setId(-1);
//                 list.push_back(b);
//             }
        
//             d+=tmp;
//         }
//         /*  先存头节点 */
//         for(int i=0;i<list.size();i++){
//             if(list[i].getId()!=-1){
//                 head.push_back(poltree(list[i].getOrd(),list[i],true));
//                 // cout<<list[i].getId()<< endl;
//             }
//             else{
//                 head.push_back(poltree(-1,list[i],true));
//                 // cout<<list[i].getId()<< endl;
//             }
//         }
//         k++;
//     }
    
//     tree.seth(head);

//     /* 建立树 */
//     k=0;
//     while(k<n){
//         vector<poltree>().swap(pollist);
//         /* 找出所有头结点存入pollist */
//         tmp = s/pow(2,k),d=0;
//         building b;
//         /* 无索引存入子列表 */
//         sort(p.begin(),p.end(),cmp9);//子列表按照次序排序,次序从1开始
//         for(j=0;j<p.size();j++){
//             pollist.push_back(poltree(0,p[j]));
            
//         }
//         /* 每层索引写入 */
//         tmp = s/pow(2,k),d=0;
//         for(int i=0;i<pow(2,k);i++){
//             vector<building>().swap(ptm);
//             /* 找到所有子列表对象 */
//             for(building b:p){
//                 // std::cout << "bbbbb.getID     " << b.getId() << std::endl;
//                 if(b.getLocation()>d&&b.getLocation()<=d+tmp){
//                     ptm.push_back(b);//子列表获取
//                     // std::cout << "b.getID     " << b.getId() << std::endl;
//                 }
//             }
//             d+=tmp;
//             // sort(p.begin(),p.end(),cmp9);//子列表按照次序排序,次序从1开始
//             // cout<< ptm.size() <<endl;
//             if(ptm.size()!=0){
//                 for(j=0;j<ptm.size()-1;j++){
//                     pollist[ptm[j].getOrd()].setPolidx(ptm[j+1].getOrd());
//                     // std::cout << "ptm[j+1].getID     " << ptm[j].getId() << std::endl;
//                 }
            
//                 pollist[ptm[ptm.size()-1].getOrd()].setPolidx(-1);
//             }
//         }
//         pol_tree.push_back(pollist);
//         k++;
//     }
//     tree.setPoltree(pol_tree);
//     return tree;
// }


/* 建立树索引 */


void createTree(int n,vector<building> p,double s){

    vector<building> list;
    int k=0;//层数初始为0
    int tmp = s/pow(2,k);int d=0;int j=0;
    vector<building> ptm;
    // vector<poltree>().swap(head);
    while(k<n){
        /* 找出所有头结点存入head */
        tmp = s/pow(2,k),d=0;
    building b;
    // vector<building>().swap(list);
    for(int i=0;i<pow(2,k);i++){
        int min = 100000;
        b = building();
        int flag=0;
        for(building b1:p){

            if(b1.getLocation()>d&&b1.getLocation()<=d+tmp){
                if(min>b1.getOrd()){
                b = b1;
                min = b1.getOrd();
                // std::cout << "b111.getID" << b.getId() << std::endl;
                flag=1;
                }
            }
            }
            if(flag==1){
                list.push_back(b);
                // std::cout << "b.getID" << b.getOrd() << std::endl;
            
            }
            else{
                building b;
                b.setId(-1);
                list.push_back(b);
            }
        
            d+=tmp;
        }
        k++;
    }
    /*  先存头节点 */
    for(int i=0;i<list.size();i++){
        if(list[i].getId()!=-1){
            head[i] = list[i].getOrd();
            // head.push_back(poltree(list[i].getOrd(),list[i],true));
            // cout<<list[i].getId()<< endl;
        }
        else{
            head[i] = -1;
            // head.push_back(poltree(-1,list[i],true));
            // cout<<list[i].getId()<< endl;
        }
    }
    
    // tree.seth(head);

    /* 建立树 */
    k=0;
    while(k<n){
        // vector<poltree>().swap(pollist);
        tmp = s/pow(2,k),d=0;
        building b;
        /* 无索引存入子列表 */
        sort(p.begin(),p.end(),cmp9);//子列表按照次序排序,次序从1开始
        for(j=j;j<p.size();j++){
            pollist[j] = p[j];
            
        }

        /* 每层索引写入 */
        tmp = s/pow(2,k),d=0;
        for(int i=0;i<pow(2,k);i++){
            vector<building>().swap(ptm);
            /* 找到所有子列表对象 */
            for(building b:p){
                // std::cout << "bbbbb.getID     " << b.getId() << std::endl;
                if(b.getLocation()>d&&b.getLocation()<=d+tmp){
                    ptm.push_back(b);//子列表获取
                    // std::cout << "b.getID     " << b.getId() << std::endl;
                }
            }
            d+=tmp;
            // sort(p.begin(),p.end(),cmp9);//子列表按照次序排序,次序从1开始
            // cout<< ptm.size() <<endl;
            if(ptm.size()!=0){
                for(int k=0;k<ptm.size()-1;k++){
                    pollist[ptm[k].getOrd()].setPolidx(ptm[k+1].getOrd());
                    // std::cout << "ptm[j+1].getID     " << ptm[j].getId() << std::endl;
                }
            
                pollist[ptm[ptm.size()-1].getOrd()].setPolidx(-1);
            }

        }
        // pol_tree.push_back(pollist);
        k++;
    }

    for(int i=0;i< sizeof(head)/sizeof(head[0]);i++){
        cout << head[i] ;
    }
    cout << endl;
    for(int i=0;i< sizeof(pollist)/sizeof(pollist[0]);i++){
        cout <<"pollist[i].getID()"<< pollist[i].getId() << " ";
        cout <<"pollist[i].getOrd()"<< pollist[i].getPolidx() << ;
    }

}


vector<building> merge(int k,tree& tree,vector<int> a,int c,double ws,double we){
    vector<building> pk;
    vector<poltree> ptree = tree.getPoltree().at(c);
    vector<int> aa;
    
    while(k--){
        // time_start = GetTickCount(); //从操作系统启动经过的毫秒数
        for(int i=0;i<a.size();i++){
                while((a[i]!=-1)&&(!(ptree.at(a[i]).getProject().getLocation()<=we&&ptree.at(a[i]).getProject().getLocation()>ws))){
                    /* if(ptree.at(a[i]).getPolidx()==-1){
                        a[i]=-1;
                        break;
                    } */
                    // cout << "a[i]" << ptree.at(a[i]).getProject().getId() << endl;
                    a[i] = ptree.at(a[i]).getPolidx();
                
                }
            // cnt_pol++;
        }
        // time_end = GetTickCount();
        // cout << "Time1 = " << (time_end - time_start) << "ms\n ";

        vector<int>().swap(aa);
        // time_start = GetTickCount(); //从操作系统启动经过的毫秒数
        for(int i=0;i<a.size();i++){
            if(a[i]!=-1){
                // a.erase(a.begin()+i);
                aa.push_back(a[i]);
            }
            // cnt_pol++;
        }
        a.swap(aa);
        // time_end = GetTickCount();
        // cout << "Time2 = " << (time_end - time_start) << "ms\n ";
        int f=0,n=0,m=0,mi=1000000,idx=0;
        
        // time_start = GetTickCount(); //从操作系统启动经过的毫秒数
        switch (a.size())
        {
        case 0:
            f=1;
            break;
        case 1:
            pk.push_back(ptree.at(a[0]).getProject());
            a[0] = tree.getPoltree().at(c).at(a[0]).getPolidx();
            // cnt_pol++;
            break;

        case 2:
            if(a[0]>=a[1]){//比较的地方有问题头结点特殊
                pk.push_back(ptree.at(a[1]).getProject()); 
                a[1] =ptree.at(a[1]).getPolidx();
                
            }
            else{
                pk.push_back(ptree.at(a[0]).getProject()); 
                a[0] = ptree.at(a[0]).getPolidx();
            }
            // cnt_pol++;
            break;

        case 3:
            // m = min(min(a[0],a[1]),min(a[1],a[2]));
            mi=a[0],idx=0;
            for(int j=1;j<a.size();j++){
                if(mi>a[j]){
                   mi=a[j];
                   idx=j;
                }
                // cnt_pol++;
            }
            pk.push_back(ptree.at(mi).getProject()); 
            a[idx] = ptree.at(a[idx]).getPolidx();  
            break;

        case 4:
            // m = min(min(min(a[0],a[1]),min(a[1],a[2])),min(a[2],a[3]));
            mi=a[0],idx=0;
            for(int j=1;j<a.size();j++){
                if(mi>a[j]){
                   mi=a[j];
                   idx=j;
                }
                // cnt_pol++;
            }
            pk.push_back(ptree.at(mi).getProject()); 
            a[idx] = ptree.at(a[idx]).getPolidx();  
            break;

        case 5:
            // m = min(min(min(a[0],a[1]),min(a[1],a[2])),min(a[2],a[3]));
            mi=a[0],idx=0;
            for(int j=1;j<a.size();j++){
                if(mi>a[j]){
                   mi=a[j];
                   idx=j;
                }
                // cnt_pol++;
            }
            pk.push_back(ptree.at(mi).getProject()); 
            a[idx] = ptree.at(a[idx]).getPolidx();  
            break;

        default:
            if(a.size()>5){
                mi=a[0],idx=0;
                for(int j=1;j<a.size();j++){
                    if(mi>a[j]){
                    mi=a[j];
                    idx=j;
                    }
                    // cnt_pol++;
                }
                pk.push_back(ptree.at(mi).getProject()); 
                a[idx] = ptree.at(a[idx]).getPolidx();  
            }
            break;
        }
        // time_end = GetTickCount();
        // cout << "Time3 = " << (time_end - time_start) << "ms\n ";
        if(f==1)break;
        /* if(a.size()==1){
            if(a[0]!=-1){
                pk.push_back(tree.getPoltree().at(c).at(a[0]).getProject());
                a[0] = tree.getPoltree().at(c).at(a[0]).getPolidx();
                continue;
            }
            break;
            
        }
        if(a.size()==2){
            if(a[0]==-1&&a[1]==-1){
                break;
            }
            if(a[0]==-1&&a[1]!=-1){
                pk.push_back(tree.getPoltree().at(c).at(a[1]).getProject());
                a[1] = tree.getPoltree().at(c).at(a[1]).getPolidx();
                continue;
                
            }
            if (a[0]!=-1&&a[1]==-1)
            {
                pk.push_back(tree.getPoltree().at(c).at(a[0]).getProject());
                a[0] = tree.getPoltree().at(c).at(a[0]).getPolidx();
                continue;
                
            }
            if(a[0]!=-1&&a[1]!=-1){
               int n = min(a[0],a[1]);
               pk.push_back(tree.getPoltree().at(c).at(n).getProject()); 
                if(a[0]>=a[1]){//比较的地方有问题头结点特殊
                    a[1] = tree.getPoltree().at(c).at(a[1]).getPolidx();
                    continue;
                }
                else{
                    a[0] = tree.getPoltree().at(c).at(a[0]).getPolidx();
                    continue;
                }
                
            }
            
        }
        else
        if(a.size()==3){
            if(a[0]==-1&&a[1]==-1&&a[2]==-1){
                break;
            }
            if(a[0]==-1&&a[1]!=-1&&a[2]!=-1){
                int m = min(a[1],a[2]);
                pk.push_back(tree.getPoltree().at(c).at(m).getProject()); 
                if(a[1]>=a[2]){//比较的地方有问题头结点特殊
                    a[2] = tree.getPoltree().at(c).at(a[2]).getPolidx();
                    continue;
                }
                else{
                    a[1] = tree.getPoltree().at(c).at(a[1]).getPolidx();
                    continue;
                }
                
            }

            if(a[0]!=-1&&a[1]==-1&&a[2]!=-1){
                int m = min(a[0],a[2]);pk.push_back(tree.getPoltree().at(c).at(m).getProject()); 
                if(a[0]>=a[2]){//比较的地方有问题头结点特殊
                    a[2] = tree.getPoltree().at(c).at(a[2]).getPolidx();
                    continue;
                }
                else{
                    a[0] = tree.getPoltree().at(c).at(a[0]).getPolidx();
                    continue;
                }
                
                
            }

            if(a[0]!=-1&&a[1]!=-1&&a[2]==-1){
                int m = min(a[0],a[1]);
                pk.push_back(tree.getPoltree().at(c).at(m).getProject()); 
                if(a[0]>=a[1]){//比较的地方有问题头结点特殊
                    a[1] = tree.getPoltree().at(c).at(a[1]).getPolidx();
                    continue;
                }
                else{
                    a[0] = tree.getPoltree().at(c).at(a[0]).getPolidx();
                    continue;
                }

            }
            if(a[0]!=-1&&a[1]!=-1&&a[2]!=-1){
                int m = min(min(a[0],a[1]),min(a[1],a[2]));
                int min=100000,idx=0;
                pk.push_back(tree.getPoltree().at(c).at(m).getProject());
                for(int j=0;j<a.size();j++){
                    if(min>a[j]){
                        min=a[j];
                        idx=j;
                    }
                }
                a[idx] = tree.getPoltree().at(c).at(a[idx]).getPolidx();  
                continue;
            }
            if(a[0]!=-1&&a[1]==-1&&a[2]==-1){
                pk.push_back(tree.getPoltree().at(c).at(0).getProject());
                a[0] = tree.getPoltree().at(c).at(a[0]).getPolidx();
                continue;
            }
            if(a[0]==-1&&a[1]!=-1&&a[2]==-1){
                pk.push_back(tree.getPoltree().at(c).at(1).getProject());
                a[1] = tree.getPoltree().at(c).at(a[1]).getPolidx();
                continue;
            }
            if(a[0]==-1&&a[1]==-1&&a[2]!=-1){
                pk.push_back(tree.getPoltree().at(c).at(2).getProject());
                a[2] = tree.getPoltree().at(c).at(a[2]).getPolidx();
                continue;
            }
            
        }
    } */
    
    }
    // cout << "cnt_pol:  " << cnt_pol <<endl; 
    return pk;
}

/* 寻找指定层数 符合条件的上一层 */
vector<building> selectList_pre(tree tree,int k,double ws,double we,double s){
    cnt_pol=0;
    int i=-1,c=0;//树的层次 头结点初始下标
    do
    {
        i++;
        c+=pow(2,i);
        cnt_pol++;
    }while((we-ws)<s/pow(2,i));
    // cout<< "层数: " << i <<endl;
    c-=pow(2,i);
    c-=pow(2,i-1);
    // cout<<"c:"<< c <<endl; 
    int j=0;
    double d =0.0;
    vector<int> a;
    while(d<s){
        if((ws>d&&ws<=d+s/pow(2,i-1))||(we>d&&we<=d+s/pow(2,i-1))){
            if((tree.geth().at(c).getPolidx())!=-1){//如果头结点为空则不加入 
              a.push_back(tree.geth().at(c).getPolidx());       
            //   cout<< c <<endl; 
            //   cout << "id:" << tree.geth().at(c).getPolidx() << endl;
            //   cout << "id:" << tree.geth().at(c).getProject().getId() << endl;
            }
        }
        c++;
        d+=s/pow(2,i-1);
        cnt_pol++;
    }

    return merge(k,tree,a,i-1,ws,we); //i为层数，实验修改i

}  


/* 寻找指定层数 符合条件的下一层 */
vector<building> selectList_next(tree tree,int k,double ws,double we,double s){
    cnt_pol=0;
    int i=-1,c=0;//树的层次 头结点初始下标
    do
    {
        i++;
        c+=pow(2,i);
        cnt_pol++;
    }while((we-ws)<s/pow(2,i));
    // cout<< "层数: " << i <<endl;
    // c+=pow(2,i);
    // cout<<"c:"<< c <<endl; 
    int j=0;
    double d =0.0;
    vector<int> a;
    while(d<s){
        if((d<=we&&d>ws)||((d+s/pow(2,i+1))<=we&&(d+s/pow(2,i+1))>ws)){
            if((tree.geth().at(c).getPolidx())!=-1){//如果头结点为空则不加入 
              a.push_back(tree.geth().at(c).getPolidx());       
            //   cout<< c <<endl; 
            //   cout << "id:" << tree.geth().at(c).getPolidx() << endl;
            //   cout << "id:" << tree.geth().at(c).getProject().getId() << endl;
            }
           
        }
        c++;
        d+=s/pow(2,i+1);
        cnt_pol++;
    }

    return merge(k,tree,a,i+1,ws,we); //i为层数，实验修改i

}  

/* 寻找指定层数 符合条件的下2层 */
vector<building> selectList_next1(tree tree,int k,double ws,double we,double s){
    cnt_pol=0;
    int i=-1,c=0;//树的层次 头结点初始下标
    do
    {
        i++;
        c+=pow(2,i);
        cnt_pol++;
    }while((we-ws)<s/pow(2,i));
    // cout<< "层数: " << i <<endl;
    c+=pow(2,i+1);
    // cout<<"c:"<< c <<endl; 
    int j=0;
    double d =0.0;
    vector<int> a;
    while(d<s){
        if((d<=we&&d>ws)||((d+s/pow(2,i+2))<=we&&(d+s/pow(2,i+2))>ws)){
            if((tree.geth().at(c).getPolidx())!=-1){//如果头结点为空则不加入 
              a.push_back(tree.geth().at(c).getPolidx());       
            //   cout<< c <<endl; 
            //   cout << "id:" << tree.geth().at(c).getPolidx() << endl;
            //   cout << "id:" << tree.geth().at(c).getProject().getId() << endl;
            }
           
        }
        c++;
        d+=s/pow(2,i+2);
        cnt_pol++;
    }

    return merge(k,tree,a,i+2,ws,we); //i为层数，实验修改i

} 


vector<building> selectList_next2(tree tree,int k,double ws,double we,double s){
    cnt_pol=0;
    int i=-1,c=0;//树的层次 头结点初始下标
    do
    {
        i++;
        c+=pow(2,i);
        cnt_pol++;
    }while((we-ws)<s/pow(2,i));
    // cout<< "层数: " << i <<endl;
    c+=pow(2,i+1);
    c+=pow(2,i+2);
    // cout<<"c:"<< c <<endl; 
    int j=0;
    double d =0.0;
    vector<int> a;
    while(d<s){
        if((d<=we&&d>ws)||((d+s/pow(2,i+3))<=we&&(d+s/pow(2,i+3))>ws)){
            if((tree.geth().at(c).getPolidx())!=-1){//如果头结点为空则不加入 
              a.push_back(tree.geth().at(c).getPolidx());       
            //   cout<< c <<endl; 
            //   cout << "id:" << tree.geth().at(c).getPolidx() << endl;
            //   cout << "id:" << tree.geth().at(c).getProject().getId() << endl;
            }
           
        }
        c++;
        d+=s/pow(2,i+3);
        cnt_pol++;
    }

    return merge(k,tree,a,i+3,ws,we); //i为层数，实验修改i

} 

/* 寻找指定层数 符合条件的li-2 */
vector<building> selectList_i_2(tree tree,int k,double ws,double we,double s){
    cnt_pol=0;
    int i=-1,c=0;//树的层次 头结点初始下标
    do
    {
        i++;
        c+=pow(2,i);
        cnt_pol++;
    }while((we-ws)<s/pow(2,i));
    // cout<< "层数: " << i <<endl;
    c-=pow(2,i);
    c-=pow(2,i-1);
    c-=pow(2,i-2);
    // cout<<"c:"<< c <<endl; 
    int j=0;
    double d =0.0;
    vector<int> a;
    while(d<s){
        if((ws>d&&ws<=d+s/pow(2,i-2))||(we>d&&we<=d+s/pow(2,i-2))){
            if((tree.geth().at(c).getPolidx())!=-1){//如果头结点为空则不加入 
              a.push_back(tree.geth().at(c).getPolidx());       
            //   cout<< c <<endl; 
            //   cout << "id:" << tree.geth().at(c).getPolidx() << endl;
            //   cout << "id:" << tree.geth().at(c).getProject().getId() << endl;
            }
        }
        c++;
        d+=s/pow(2,i-2);
        cnt_pol++;
    }

    return merge(k,tree,a,i-2,ws,we); //i为层数，实验修改i

}


/* 寻找指定层数 符合条件的li-3 */
vector<building> selectList_i_3(tree tree,int k,double ws,double we,double s){
    cnt_pol=0;
    int i=-1,c=0;//树的层次 头结点初始下标
    do
    {
        i++;
        c+=pow(2,i);
        cnt_pol++;
    }while((we-ws)<s/pow(2,i));
    // cout<< "层数: " << i <<endl;
    c-=pow(2,i);
    c-=pow(2,i-1);
    c-=pow(2,i-2);
    c-=pow(2,i-3);
    // cout<<"c:"<< c <<endl; 
    int j=0;
    double d =0.0;
    vector<int> a;
    while(d<s){
        if((ws>d&&ws<=d+s/pow(2,i-3))||(we>d&&we<=d+s/pow(2,i-3))){
            if((tree.geth().at(c).getPolidx())!=-1){//如果头结点为空则不加入 
              a.push_back(tree.geth().at(c).getPolidx());       
            //   cout<< c <<endl; 
            //   cout << "id:" << tree.geth().at(c).getPolidx() << endl;
            //   cout << "id:" << tree.geth().at(c).getProject().getId() << endl;
            }
        }
        c++;
        d+=s/pow(2,i-3);
        cnt_pol++;
    }

    return merge(k,tree,a,i-3,ws,we); //i为层数，实验修改i

}


/* 寻找指定层数 符合条件的 */
vector<building> selectList(tree tree,int k,double ws,double we,double s){
    cnt_pol=0;
    int i=-1,c=0;//树的层次 头结点初始下标
    do
    {
        i++;
        c+=pow(2,i);
        cnt_pol++;
    }while((we-ws)<s/pow(2,i));
    // cout<< "层数: " << i <<endl;
    c-=pow(2,i);
    // cout<<"c:"<< c <<endl; 
    int j=0;
    double d =0.0;
    vector<int> a;
    while(d<s){
        if((d<=we&&d>ws)||((d+s/pow(2,i))<=we&&(d+s/pow(2,i))>ws)){
            if((tree.geth().at(c).getPolidx())!=-1){//如果头结点为空则不加入 
              a.push_back(tree.geth().at(c).getPolidx()); 
            //   cout<< c <<endl; 
            //   cout << "id:" << tree.geth().at(c).getPolidx() << endl;
            //   cout << "id:" << tree.geth().at(c).getProject().getId() << endl;
            }
           
        }
        c++;
        d+=s/pow(2,i);
        cnt_pol++;
    }

    return merge(k,tree,a,i,ws,we); //i为层数，实验修改i

}  


int findLevel(tree tree,double w,double s,int& c){
    int i=-1;//树的层次 头结点初始下标
    do
    {
        i++;
        c+=pow(2,i);
    }while(w<s/pow(2,i));
    return i;
}

/* sliding查询 */
vector<building> precomIndex_sliding(tree tree,int k,double s,double w){
    vector<building> pk_idx;
    vector<building> g;
    int i=0,c=0,jj=0;//树的层次 头结点初始下标
    i=findLevel(tree,w,s,c);    // cout<< "层数: " << i <<endl;
    c-=pow(2,i);//头节点起始位置
    int j=0,cnt=0;vector<int> a;double ws=0.0,we=ws+w;
    
    //用一个公式完成寻找合并桶
    jj = c+ws/(s/pow(2,i));
    c += we/(s/pow(2,i)); 
    for(jj=jj;jj<=c;jj++){
        if((tree.geth().at(jj).getPolidx())!=-1){//如果头结点为空则不加入 
            a.push_back(tree.geth().at(jj).getPolidx()); 
        }
    }
    g=merge(k,tree,a,i,ws,we);
    sort(g.begin(),g.end(),cmp3);
    pk_idx.insert(pk_idx.end(),g.begin(),g.end());
    double ww=0;
    for(int j=1;j<g.size();j++){
        ww+=g.at(j).getLocation()-g.at(j-1).getLocation();
    }
    ww=ww/(g.size()-1);
    c=0;
    i=findLevel(tree,ww,s,c);
    c-=pow(2,i);//头节点起始位置
    int cc=c;
    ws=we,we=pk_idx.at(0).getLocation()+w;
    cnt=1;
    int ndx = pk_idx.size();
    int odx = 0;

    while(we<s){
        vector<int>().swap(a);
        time_start = GetTickCount(); //从操作系统启动经过的毫秒数
        jj = c+ws/(s/pow(2,i));
        c += we/(s/pow(2,i)); 
        for(jj=jj;jj<=c;jj++){
            if((tree.geth().at(jj).getPolidx())!=-1){//如果头结点为空则不加入 
                a.push_back(tree.geth().at(jj).getPolidx()); 
            }
        }
        g=merge(k-(pk_idx.size()-cnt),tree,a,i,ws,we);
        time_end = GetTickCount();
        cout << "Time1 = " << (time_end - time_start) << "ms\n ";

        time_start = GetTickCount(); //从操作系统启动经过的毫秒数
        g=merge(k-(pk_idx.size()-cnt),tree,a,i,ws,we);
        time_end = GetTickCount();
        cout << "Time2 = " << (time_end - time_start) << "ms\n ";
        
        time_start = GetTickCount(); //从操作系统启动经过的毫秒数
        pk_idx.insert(pk_idx.end(),g.begin(),g.end());

        //更新
        c=cc;//回到起始位置
        sort(pk_idx.begin(),pk_idx.end(),cmp3);
        if(cnt<pk_idx.size()){
            ws=we;
            we=pk_idx.at(cnt).getLocation()+w;
            cnt++;
        }
        else{
            ws=we;
            we=ws+w;
        }

        time_end = GetTickCount();
        cout << "Time3 = " << (time_end - time_start) << "ms\n ";
    }
    cout << we << endl;
    return pk_idx;
}


/* 计算认知收益 */
vector<building> dn_pol;
double calpol(vector<building> res){
    vector<building>().swap(dn_pol);
    double pl=0.0;
    for(int i=0;i<res.size();i++){
        update(res[i],dn_pol);
    }
    for(building pp:dn_pol){
        pl+=pp.getRange();
    }
    return pl;
}





tree::tree(/* args */)
{
}


void tree::setPoltree(vector<vector<poltree>> pol_tree){
    this->pol_tree = pol_tree;
}

void tree::seth(vector<poltree> head){
    this->h = head;
}

void tree::setch(bool bb,int n,int c){
    this->pol_tree.at(c).at(n).getProject().setChoose(bb);
}

bool tree::getch(int n,int c){
    return this->pol_tree.at(c).at(n).getProject().getChoose();
}

vector<vector<poltree>> tree::getPoltree(){
    return this->pol_tree;
}

vector<poltree> tree::geth(){
    return this->h;
}
tree::~tree()
{
}