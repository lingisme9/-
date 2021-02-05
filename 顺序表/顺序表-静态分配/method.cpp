#include"method.h"
//��ʼ��˳��� 
Status initSqlist(Sqlist &L){
	//1.����ռ�
	//Ϊʲô��new��ͷ�ļ��д�����elem������Ϊʲô��Ҫnew����malloc�� ,ָ����մ��������������ǲ��Ǿ�̬�� 
	L.elem = new ElemType[MAXSIZE];
	//���Կռ��Ƿ����ɹ� 
	for(int i = 0; i < MAXSIZE; i++){
		L.elem[i] = 0;
		printf("%d ",0);
	} 
	putchar(10);
	//2.�ж��Ƿ����ɹ�
	if(!L.elem){
		exit(OVERFLOW);
	}
	//3.length =0
	L.length = 0;
	//4.����״̬
	return OK; 
}

//�������Ա�
void createSqlist(Sqlist &L,int n){
	printf("������Ҫ���������Ա���Ĭ��Ϊ10");
	putchar(10);
	for(int i = 0; i < n; i++){
		L.elem[i] = randomElem() + i;
	} 
	L.length = L.length + n;
	printf("��ʱ���Ա���Ϊ��%d",L.length);
	putchar(10);
} 
 
//��ӡ˳���
void printSqlist(Sqlist &L){
	if(L.elem){
		for(int i = 0; i < L.length - 1; i++ ){
			printf("%d ",L.elem[i]);
		}
	}
	else
		printf("���Ա�����\n"); 
	putchar(10);
} 

//����˳���
void destroySqlist(Sqlist &L){
	//1.���ڲ����٣�Ϊʲô��delete��free��ô�� 
	if(L.elem) L.elem = NULL; //�ͷſռ� 
	else
		printf("˳�������\n");
}


//������Ա�

void clearSqlist(Sqlist &L){
	L.length = 0;
	printf("length = %d\n",L.length); 
} 

//��ȡ���Ա��� 
Status getLength(Sqlist &L){
	printf("���Ա�ĳ���Ϊ��%d\n",L.length);
	return L.length;
}

//�ж����Ա��Ƿ�Ϊ��
Status isEmpty(Sqlist &L){
	if(L.length == 0){
		printf("���Ա�Ϊ��\n");	
		return OK;
	}
	else if(L.elem == NULL){
		printf("���Ա�����\n");
		return ERROR;
	}
	else{
		printf("���Ա�Ϊ��\n"); 
	 	return ERROR;		
	}
} 

//��ȡ���Ա���Ԫ�ص�λ��
Status getElem(Sqlist &L, int i, ElemType &e){
	//1.�жϲ���λ���Ƿ�Ϸ�
	//Ϊ�˷������Ա���չʾ�����ӣ�����Ҫ 
	if(i < 1 || i > L.length)return ERROR;
	e = L.elem[i - 1];
	printf("��%dλ���ϵ�Ԫ����:%d\n",i,e);
	return e;
} 

//����Ԫ��e 
Status locationElem(Sqlist &L,ElemType &e){
	//1.˳�����
	for(int i = 0; i < L.length; i++){
		if(L.elem[i] == e){
			printf("Ԫ��%d��λ���ǣ�%d",e,i + 1);
			return i + 1;
		}

	}
	return 0; 
} 

//����Ԫ��e
Status insertSqlist(Sqlist &L,int i,ElemType &e){
	//1.�ж�λ���Ƿ����
	if(i < 1 || i > L.length + 1){
		printf("λ�ô���\n");
		return ERROR;
	}
	//2.�жϿռ��Ƿ�����
	if(L.length == MAXSIZE){
		printf("�ڴ�����\n"); 
		return ERROR;
	}
	//3.�ƶ�Ԫ�� 
	for(int j = L.length - 1; j >= i - 1; j--){
		L.elem[j+1] = L.elem[j]; 
		printf("Ԫ��:%d\n",L.elem[j]);
	} 
	//4.����Ԫ�� 
	L.elem[i - 1] = e;
	//5.��+1 
	L.length ++;
	return OK;
}

//ɾ����i��Ԫ��
Status deleteElem(Sqlist &L,int i){
	//1.�ж�ֵ�Ƿ�Ϸ�
	if(i < 1 || i > L.length)return ERROR;
	printf("Ҫɾ����Ԫ���ǣ�%d\n",L.elem[i-1]);
	//2.ǰ��Ԫ��
	for(int j = i; j < L.length - 1; j++){
		L.elem[j - 1] = L.elem[j];
		printf("Ԫ�أ�%d\n",L.elem[j]);
	} 
	//3.��-1
	L.length --;
	return OK; 
} 

//��������� 
Status randomElem(){
    int a;
    srand((unsigned)time(NULL));
    a = rand() % 51 + 13;
    return a;
}


