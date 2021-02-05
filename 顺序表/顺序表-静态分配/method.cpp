#include"method.h"
//初始化顺序表 
Status initSqlist(Sqlist &L){
	//1.分配空间
	//为什么用new，头文件中创建了elem，这里为什么还要new，用malloc呢 ,指针接收创建的数组这种是不是静态？ 
	L.elem = new ElemType[MAXSIZE];
	//测试空间是否分配成功 
	for(int i = 0; i < MAXSIZE; i++){
		L.elem[i] = 0;
		printf("%d ",0);
	} 
	putchar(10);
	//2.判断是否分配成功
	if(!L.elem){
		exit(OVERFLOW);
	}
	//3.length =0
	L.length = 0;
	//4.返回状态
	return OK; 
}

//创建线性表
void createSqlist(Sqlist &L,int n){
	printf("输入需要创建的线性表长度默认为10");
	putchar(10);
	for(int i = 0; i < n; i++){
		L.elem[i] = randomElem() + i;
	} 
	L.length = L.length + n;
	printf("此时线性表长度为：%d",L.length);
	putchar(10);
} 
 
//打印顺序表
void printSqlist(Sqlist &L){
	if(L.elem){
		for(int i = 0; i < L.length - 1; i++ ){
			printf("%d ",L.elem[i]);
		}
	}
	else
		printf("线性表不存在\n"); 
	putchar(10);
} 

//销毁顺序表
void destroySqlist(Sqlist &L){
	//1.存在才销毁，为什么用delete，free怎么样 
	if(L.elem) L.elem = NULL; //释放空间 
	else
		printf("顺序表不存在\n");
}


//清空线性表

void clearSqlist(Sqlist &L){
	L.length = 0;
	printf("length = %d\n",L.length); 
} 

//获取线性表长度 
Status getLength(Sqlist &L){
	printf("线性表的长度为：%d\n",L.length);
	return L.length;
}

//判断线性表是否为空
Status isEmpty(Sqlist &L){
	if(L.length == 0){
		printf("线性表为空\n");	
		return OK;
	}
	else if(L.elem == NULL){
		printf("线性表不存在\n");
		return ERROR;
	}
	else{
		printf("线性表不为空\n"); 
	 	return ERROR;		
	}
} 

//获取线性表中元素的位置
Status getElem(Sqlist &L, int i, ElemType &e){
	//1.判断查找位置是否合法
	//为了符合线性表所展示的样子，代码要 
	if(i < 1 || i > L.length)return ERROR;
	e = L.elem[i - 1];
	printf("第%d位置上的元素是:%d\n",i,e);
	return e;
} 

//查找元素e 
Status locationElem(Sqlist &L,ElemType &e){
	//1.顺序查找
	for(int i = 0; i < L.length; i++){
		if(L.elem[i] == e){
			printf("元素%d的位置是：%d",e,i + 1);
			return i + 1;
		}

	}
	return 0; 
} 

//插入元素e
Status insertSqlist(Sqlist &L,int i,ElemType &e){
	//1.判断位置是否合理
	if(i < 1 || i > L.length + 1){
		printf("位置错误\n");
		return ERROR;
	}
	//2.判断空间是否已满
	if(L.length == MAXSIZE){
		printf("内存已满\n"); 
		return ERROR;
	}
	//3.移动元素 
	for(int j = L.length - 1; j >= i - 1; j--){
		L.elem[j+1] = L.elem[j]; 
		printf("元素:%d\n",L.elem[j]);
	} 
	//4.插入元素 
	L.elem[i - 1] = e;
	//5.表长+1 
	L.length ++;
	return OK;
}

//删除第i个元素
Status deleteElem(Sqlist &L,int i){
	//1.判断值是否合法
	if(i < 1 || i > L.length)return ERROR;
	printf("要删除的元素是：%d\n",L.elem[i-1]);
	//2.前移元素
	for(int j = i; j < L.length - 1; j++){
		L.elem[j - 1] = L.elem[j];
		printf("元素：%d\n",L.elem[j]);
	} 
	//3.表长-1
	L.length --;
	return OK; 
} 

//生成随机数 
Status randomElem(){
    int a;
    srand((unsigned)time(NULL));
    a = rand() % 51 + 13;
    return a;
}


