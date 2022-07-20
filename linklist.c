#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"

//创建
linkList* list_create()
{
	linkList* L = (linkList*)malloc(sizeof(linkList));
	if(NULL==L)
	{
		printf("创建失败！\n");
		return NULL;
	}

	//初始化
	L->len=0;
	L->next=NULL;
	printf("创建成功！\n");
	return L;
}

//判空
int list_empty(linkList* L)
{
	//1表示空 0表示非空
	return NULL==L->next?1:0;
}
//头插
int list_insert_head(linkList* L,datatype e)
{
	//判断条件
	if(NULL == L)
	{
		printf("所给链表不合法!\n");
		return -1;
	}
	//申请节点
	linkList* p = (linkList*)malloc(sizeof(linkList));
	if(NULL == p)
	{
		printf("节点申请失败\n");
		return -1;
	}
	//将要插入的数据放入节点
	p->data = e;
	p->next = NULL;
	//完成头插
	p->next = L->next;
	L->next = p;
	//表的变化
	L->len++;

	printf("头插成功!\n");
}
//遍历
void list_show(linkList* L)
{
	//判断逻辑
	if(NULL==L || list_empty(L))
	{
		printf("遍历失败\n");
		return;
	}
	//遍历逻辑
	printf("链表元素分别是:");
	linkList* q=L->next;
	while(q!=NULL)
	{
		printf("%c\t",q->data);
		q = q->next;
	}
	printf("\n");
}

//定义申请节点函数
linkList* node_buy(datatype e)
{
	//申请节点
	linkList* p = (linkList*)malloc(sizeof(linkList));
	if(NULL == p)
	{
		printf("节点申请失败\n");
		return NULL;
	}
	//将数据存到节点中
	p->data = e;
	p->next = NULL;

	return p;
}
//尾插函数
int list_insert_tail(linkList* L,datatype e)
{
	//判断逻辑
	if(NULL==L)
	{
		printf("所给链表不合法\n");
		return -1;
	}
	//申请节点
	linkList* q = node_buy(e);
	//遍历指针指向最后一个节点
	linkList* p = L;
	while(p->next != NULL)
	{
		p=p->next;
	}
	//尾插逻辑
	p->next = q;
	//表的变化
	L->len++;
	printf("尾插成功!\n");
	return 0;
}
//任意插
int list_insert_pos(linkList* L,int pos,datatype e)
{
	//判断逻辑
	if(NULL==L || pos<1 || pos>L->len+1)
	{
		printf("任意插失败!\n");
		return -1;
	}
	//申请新新节点
	linkList* q = node_buy(e);
	//查找要插入位置的前驱节点
	linkList* s = node_find(L,pos-1);
	//插入逻辑
	q->next = s->next;
	s->next = q;
	//表的变化
	L->len++;
	printf("任意插入成功！\n");
	return 0;
}
//按位置查找返回查找到的节点
linkList* node_find(linkList* L,int pos)
{
	//判断逻辑
	if(NULL==L || pos<0 || pos>L->len)
	{
		printf("查找失败！\n");
		return NULL;
	}

	//查找节点
	linkList* q = L;
	for(int i=1;i<=pos;i++)
	{
		q = q->next;
	}
	return q; 		//将找到的节点返回
}
//头删
int list_delete_head(linkList* L)
{
	if(NULL==L || list_empty(L))
	{
		printf("删除失败\n");
		return -1;
	}
	//头删
	linkList* p = L->next; 		//标记
	L->next = p->next; 			//孤立
	free(p); 					//踢开
	p=NULL;
	//表的变化
	L->len--;
	printf("头删成功\n");

	return 0;
}
//尾删
int list_delete_tail(linkList* L)
{
	//逻辑判断
	if(NULL==L||list_empty(L))
	{
		printf("尾删失败!\n");
		return -1;
	}
	//遍历到最后一个节点
	linkList* p = L;
	while(p->next->next!=NULL)
	{
		p=p->next;
	}
	//删除逻辑
	free(p->next);
	p->next=NULL;
	//表的变化
	L->len--;
	printf("尾删除成功!\n");
	return 0;
}
//任意删
int list_delete_pos(linkList* L,int pos)
{
	if(NULL==L || pos<1 || pos>L->len)
	{
		printf("任意删失败!\n");
		return -1;
	}
	//找到要删除的位置的前驱
	linkList* p = node_find(L,pos-1);
	//删除逻辑
	linkList* q = p->next;
	p->next = q->next; 		//孤立
	free(q);
	q=NULL;
	L->len--;
	printf("任意删除成功!\n");
	return 0;
}
//按值查找,返回第一个查找成功的位置
int list_search_value(linkList* L,datatype e)
{
	//判断逻辑
	if(NULL==L || list_empty(L))
	{
		//printf("查找失败!\n");
		return -1;
	}
	//查找逻辑
	linkList* p = L->next;
	
	for(int i=1;i<=L->len;i++)
	{
		if(p->data == e)
		{
			return i;
		}
		p=p->next;
	}

	return 0;
}
//销毁链表
void list_free(linkList* L)
{
	if(NULL==L)
	{
		return;
	}
	//不断调用头删，将节点进行删除
	while(L->next != NULL)
	{
		list_delete_head(L);
	}
	//将头节点释放
	free(L);
	L = NULL;
	printf("释放表成功\n");
	return ;
}
//按位置修改
int list_update_pos(linkList* L,int pos,datatype e)
{
	//判断逻辑
	if(NULL==L || pos<1 || pos>L->len)
	{
		printf("按位置修改失败!\n");
		return -1;
	}
	//直接修改	
	linkList* p = node_find(L,pos);
	p->data=e;
	printf("按位置修改成功!\n");
	return 0;
}
//按值修改
int list_update_value(linkList* L,datatype old_e,datatype new_e)
{
	//判断逻辑
	if(NULL == L||list_empty(L))
	{
		printf("按值修改失败!\n");
		return -1;
	}
	//修改
	int index = list_search_value(L,old_e);
	linkList* p = node_find(L,index);
	p->data = new_e;
	printf("按值修改成功!\n");
	return 0;
}
//链表反转函数
void list_reverse(linkList* L)
{
	//逻辑判断
	if(NULL == L||list_empty(L))
	{
		printf("反转失败!\n");
	}
	//三杯水交换原则
	for(int i=L->len;i>L->len/2;i--)
	{
		linkList* p = node_find(L,i);
		datatype temp;
		linkList* q = node_find(L,L->len+1-i);
		temp = p->data;
		p->data=q->data;
		q->data=temp;
	}
	printf("反转成功!\n");
}
