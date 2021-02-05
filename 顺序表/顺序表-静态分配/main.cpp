#include"method.h" 
int main(){	
	Sqlist L;
	printf("演示初始化：\n");
	initSqlist(L);
	
	putchar(10);
	printf("创建线性表L:\n");
	createSqlist(L);
	printSqlist(L);
	
	putchar(10);
	printf("销毁线性表\n");
	destroySqlist(L); 
	printSqlist(L);
	
	putchar(10);
	Sqlist A;
	printf("清空线性表：\n");
	initSqlist(A);
	createSqlist(A);
	printSqlist(A);
	clearSqlist(A);
	
	putchar(10);
	printf("线性表长度：\n");
	createSqlist(A);
	printSqlist(A);
	getLength(A);
	
	putchar(10);
	printf("判断线性表是否为空：\n");
	isEmpty(A);
	isEmpty(L);
	
	putchar(10);
	printf("获取位置i的元素\n");
	int a;
	getElem(A,3,a);
	
	putchar(10);
	printf("查找元素e的位置\n");
	int e = A.elem[3];
	locationElem(A,e); 
	
	
	putchar(10);
	printf("插入元素\n");
	ElemType instert = 100;
	int i = 5;
	insertSqlist(A,i,instert);
	printSqlist(A);
	
	putchar(10);
	printf("删除元素\n");
	deleteElem(A,4);
	printSqlist(A);
	return 0;
}
