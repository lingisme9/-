// 静态分配的线性表实现 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXSIZE 100

#define TURE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int Status;
typedef int ElemType; 

typedef struct{
	 ElemType *elem;
	 int length;
} Sqlist;
