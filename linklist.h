#ifndef ___LINKLIST_H___
#define ___LINKLIST_H___

typedef char datatype;

typedef struct Node
{
	union
	{
		int len; 		//头结点的数据域，记录个数
		datatype data; 	//普通节点的数据域
	};
	struct Node* next;
}linkList;

//创建
linkList* list_create();
//判空
int lisi_empty(linkList* L);
//头插
int list_insert_head(linkList* L,datatype e);
//遍历
void list_show(linkList* L);
//尾插
int list_insert_tail(linkList* L,datatype e);
//任意插
int list_insert_pos(linkList* L,int pos,datatype e);
//按位置查找返回查找到的节点
linkList* node_find(linkList* L,int pos);
//头删
int list_delete_head(linkList* L);
//尾删
int list_delete_tail(linkList* L);
//任意删
int list_delete_pos(linkList* L,int pos);
//按值查找,返回第一个查找成功的位置
int list_search_value(linkList* L,datatype e);
//按位置修改
int list_update_pos(linkList* L,int pos,datatype e);
//按值修改
int list_update_value(linkList* L,datatype old_e,datatype new_e);
//链表反转函数
void list_reverse(linkList* L);
//销毁链表
void list_free(linkList* L);



#endif




