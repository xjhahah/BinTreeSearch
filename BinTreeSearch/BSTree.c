#include "Search.h"

BSTreeNode* BuyBSTreeNode(BSTDataType data)
{
	BSTreeNode* pNewNode = (BSTreeNode*)malloc(sizeof(BSTreeNode));
	if (pNewNode == NULL)
	{
		assert(0);
		printf("节点创建失败！\n");
		return NULL;
	}
	pNewNode->_data = data;
	pNewNode->_left = NULL;
	pNewNode->_right = NULL;
	return pNewNode;
}
//插入
int BSTreeInsert(BSTreeNode** tree, BSTDataType data)
{
	BSTreeNode* pCur = NULL;
	BSTreeNode* pParent = NULL;
	if (NULL == *tree)
	{
		*tree = BuyBSTreeNode(data);
		return 1;
	}
	pCur = *tree;
	while (pCur)
	{
		if (pCur->_data > data)
		{
			pParent = pCur;
			pCur = pCur->_left;
		}
		else if (pCur->_data < data)
		{
			pParent = pCur;
			pCur = pCur->_right;
		}
		else
		{
			return 0;
		}
	}
	if (pParent->_data < data)
	{
		pParent->_right = BuyBSTreeNode(data);
	}
	else
	{
		pParent->_left = BuyBSTreeNode(data);
	}
	return 1;
}
//删除
int BSTreeRemove(BSTreeNode** tree, BSTDataType data)
{
	BSTreeNode* pCur = NULL;
	BSTreeNode* pParent = NULL;
	pCur = *tree;
	while (pCur)
	{
		if (pCur->_data > data)
		{
			pParent = pCur;
			pCur = pCur->_left;
		}
		else if (pCur->_data < data)
		{
			pParent = pCur;
			pCur = pCur->_right;
		}
		else
		{
			//找到了开始删除
			//1.左/右为空
			if (pCur->_left == NULL)
			{
				if (pParent->_left == pCur)
				{
					pParent->_left = pCur->_right;
				}
				else if (pParent->_right == pCur)
				{
					pParent->_right = pCur->_right;
				}
			}
			else if (pCur->_right == NULL)
			{
				if (pParent->_left == pCur)
				{
					pParent->_left = pCur->_left;
				}
				else if (pParent->_right == pCur)
				{
					pParent->_right = pCur->_left;
				}
			}
			//2.左右都不空
			else
			{
				BSTreeNode* replace = pCur->_right;
				while (replace->_left)
				{
					replace = replace->_left;
				}
				pCur->_data = replace->_data;
				return BSTreeRemove(&pCur, replace->_data);
			}
			return 1;
		}
	}
	return 0;
}
//查找
BSTreeNode* BSTreeFind(BSTreeNode** tree, BSTDataType data)
{
	BSTreeNode* pCur = *tree;
	while (pCur)
	{
		if (pCur->_data > data)
		{
			pCur = pCur->_left;
		}
		else if (pCur->_data < data)
		{
			pCur = pCur->_right;
		}
		else
		{
			return pCur;
		}
	}
	return NULL;
}
void BSTreeInOrder(BSTreeNode** tree)
{
	if (NULL == *tree)
	{
		return;
	}
	BSTreeInOrder(&((*tree)->_left));
	printf("%d ", (*tree)->_data);
	BSTreeInOrder(&((*tree)->_right));
}