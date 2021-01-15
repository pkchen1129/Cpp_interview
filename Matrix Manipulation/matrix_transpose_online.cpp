/************************************************* ************************ 
    > File Name: matrix_transpose.cpp 
    > Author: SongLee 
    > E-mail: lisong.shine@qq.com 
    > Created Time : 2014年06月06日星期五14時26分15秒
    > Personal Blog: http://songlee24.github.io 
*********************** *************************************************/ 
# include <iostream> 
using  namespace  std ;

/*後繼*/ 
int  getNext ( int i, int m, int n)
{ return (i%n)*m + i/n; }
    


/*前驅*/ 
int  getPre ( int i, int m, int n)
{ return (i%m)*n + i/m; }
    


/*處理以下標i為起點的環*/ 
void  movedata ( int *mtx, int i, int m, int n)
{   
    int temp = mtx[i];   //暫存
    int cur = i;        //當前下標
    int pre = getPre(cur, m, n); 
    while (pre != i) {         
        mtx[cur] = mtx[ pre];         
        cur = pre;         
        pre = getPre(cur, m, n);    
    }
    mtx[cur] = temp; 
}


/*轉置，即循環處理所有環*/ 
void  transpose ( int *mtx, int m, int n)
{ 
    for ( int i= 0 ; i<m*n; ++i)     
    { 
        int next = getNext(i, m, n); 
        while (next > i) //若存在後繼小於i說明重複            
            next = getNext( next, m, n); 
        if (next == i)    //處理當前環            
            movedata(mtx, i, m, n);
    } 
}