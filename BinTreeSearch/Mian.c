#include "Search.h"


void TestBSTree()
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
	BSTreeInOrder(&tree);
	printf("\n");
}

int main()
{
	TestBSTree();
	return 0;
}