//#include "Search.h"
#include "KeyValue.h"

/*
void TestBSTree1()
{
	int i = 0;
	int arr[] = { 5,3,4,1,7,8,2,6,0,9 };
	BSTreeNode* tree=NULL;
	for (; i < sizeof(arr) / sizeof(arr[0]); ++i)
	{
		BSTreeInsert(&tree, arr[i]);
	}
	BSTreeInOrder(&tree);
	printf("\n");

	BSTreeInsert(&tree, 10);
	BSTreeInOrder(&tree);
	printf("\n");

	BSTreeRemove(&tree, 9);
	BSTreeRemove(&tree, 4);
	BSTreeRemove(&tree, 5);
	BSTreeRemove(&tree, 2);
	BSTreeRemove(&tree, 1);
	BSTreeRemove(&tree, 0);
	BSTreeInOrder(&tree);
	printf("\n");
}

void TestBSTree2()
{
	int i = 0;
	int arr[] = { 5,3,4,1,7,8,2,6,0,9 };
	BSTreeNode* tree = NULL;
	for (; i < sizeof(arr) / sizeof(arr[0]); ++i)
	{
		BSTreeInsert(&tree, arr[i]);
	}
	BSTreeInOrder(&tree);
	printf("\n");

	BSTreeRemoveR(&tree, 6);
	BSTreeInOrder(&tree);
	printf("\n");
}

void TestBSTree3()
{
	BSTreeNode* tree = NULL;
	BSTreeInsertK(&tree, "hello");
	BSTreeInsertK(&tree, "sort");
	BSTreeInsertK(&tree, "insert");
	BSTreeInsertK(&tree, "find");
	BSTreeInsertK(&tree, "destory");

	char buf[10];
	while (1)
	{
		gets(buf);
		if (BSTreeFindK(&tree, buf))
		{
			printf("µ¥´ÊÆ´Ð´ÕýÈ·¡£\n");
		}
		else
		{
			printf("µ¥´ÊÆ´Ð´´íÎó¡£\n");
		}
		//setbuf(stdin, NULL);
	}
}
*/

void TestBSTree4()
{
	char str[10] = { '0' };
	BSTreeNode* pTree = NULL;
	int i = 5;
	while (i--)
	{
		BSTreeNode* node;
		scanf_s("%s", str,10);
		if (strcmp(str, "exit") == 0)
		{
			break;
		}

		node = BSTreeFindKV(&pTree, str);
		if (node)
		{
			node->_value++;
		}
		else
		{
			BSTreeInsertKV(&pTree, str, 1);
		}
	}

	BSTreeInOrderKV(&pTree);
}
int main()
{
	//TestBSTree1();
	//TestBSTree2();
	//TestBSTree3();
	TestBSTree4();
	return 0;
}