#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"
int main(int argc, const char *argv[])
{
	//创建头节点
	linkList* L=list_create();
	if(NULL == L)
	{
		return -1;
	}
	//调用头插函数
	list_insert_head(L,'H');
	list_insert_head(L,'E');
	list_insert_head(L,'L');
	list_insert_head(L,'L');
	list_insert_head(L,'C');
	list_insert_head(L,'Q');
	printf("L->len=%d\n",L->len);
	list_show(L);
	//调用尾插函数
	list_insert_tail(L,'M');
	list_show(L);
	printf("L->len=%d\n",L->len);
	//调用任意插函数
	list_insert_pos(L,7,'K');
	list_show(L);
	//头删
	list_delete_head(L);
	list_show(L);
	//调用任意删
	list_delete_pos(L,3);
	list_show(L);
	//调用尾删函数
	list_delete_tail(L);
	list_show(L);
	//调用按值查找函数
	int res = list_search_value(L,'K');
	if(res<0)
	{
		printf("按值查找失败!\n");
	}else if(res==0)
	{
		printf("没找到!\n");
	}else
		printf("按值查找成功!在第%d个\n",res);
	//调用按位置修改函数
	list_update_pos(L,2,'X');
	list_show(L);
	//调用按值修改函数
	list_update_value(L,'X','O');
	list_show(L);
	//调用函数反转
	list_reverse(L);
	list_show(L);
	//调用释放函数
	list_free(L);
	L = NULL;

	return 0;

}
