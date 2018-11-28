#define  _CRT_SECURE_NO_WARNINGS

#include "KeyValue.h"


BSTreeNode* BuyBSTreeKNode(BSTKeyType key)
{
	BSTreeNode* pNewNode = (BSTreeNode*)malloc(sizeof(BSTreeNode));
	if (pNewNode == NULL)
	{
		assert(0);
		printf("节点创建失败！\n");
		return NULL;
	}
	pNewNode->_key = key;
	pNewNode->_left = NULL;
	pNewNode->_right = NULL;
	return pNewNode;
}
//插入
int BSTreeInsertK(BSTreeNode** tree, BSTKeyType key)
{
	BSTreeNode* pCur = NULL;
	BSTreeNode* pParent = NULL;
	if (NULL == *tree)
	{
		*tree = BuyBSTreeKNode(key);
		return 1;
	}
	pCur = *tree;
	while (pCur)
	{
		if (strcmp(pCur->_key,key)>0)
		{
			pParent = pCur;
			pCur = pCur->_left;
		}
		else if(strcmp(pCur->_key, key) < 0)
		{
			pParent = pCur;
			pCur = pCur->_right;
		}
		else
		{
			return 0;
		}
	}
	if (strcmp(pParent->_key, key) < 0)
	{
		pParent->_right = BuyBSTreeKNode(key);
	}
	else
	{
		pParent->_left = BuyBSTreeKNode(key);
	}
	return 1;
}
//查找
BSTreeNode* BSTreeFindK(BSTreeNode** tree, BSTKeyType key)
{
	BSTreeNode* pCur = *tree;
	while (pCur)
	{
		if (strcmp(pCur->_key,key) < 0)
		{
			pCur = pCur->_right;
		}
		else if (strcmp(pCur->_key, key) > 0)
		{
			pCur = pCur->_left;
		}
		else
		{
			return pCur;
		}
	}
	return NULL;
}


BSTreeNode* BuyBSTreeKVNode(BSTKeyType key, BSTValueType val)
{
	BSTreeNode* pNewNode = (BSTreeNode*)malloc(sizeof(BSTreeNode));
	if (pNewNode == NULL)
	{
		assert(0);
		printf("节点创建失败！\n");
		return NULL;
	}

	pNewNode->_left = NULL;
	pNewNode->_right = NULL;
	pNewNode->_key = (char *)malloc(strlen(key)+1);
	strcpy(pNewNode->_key, key);
	pNewNode->_value = val;
	return pNewNode;
}

int BSTreeInsertKV(BSTreeNode** tree, BSTKeyType key, BSTValueType val)
{
	BSTreeNode* pCur = NULL;
	BSTreeNode* pParent = NULL;
	if (NULL == *tree)
	{
		*tree = BuyBSTreeKVNode(key,val);
		return 1;
	}
	pCur = *tree;
	while (pCur)
	{
		if (strcmp(pCur->_key, key) > 0)
		{
			pParent = pCur;
			pCur = pCur->_left;
		}
		else if (strcmp(pCur->_key, key) < 0)
		{
			pParent = pCur;
			pCur = pCur->_right;
		}
		else
		{
			return 0;
		}
	}
	if (strcmp(pParent->_key, key) < 0)
	{
		pParent->_right = BuyBSTreeKVNode(key,val);
	}
	else
	{
		pParent->_left = BuyBSTreeKVNode(key,val);
	}
	return 1;
}
BSTreeNode* BSTreeFindKV(BSTreeNode** tree, BSTKeyType key)
{
	BSTreeNode* pCur = *tree;
	while (pCur)
	{
		if (strcmp(pCur->_key, key) < 0)
		{
			pCur = pCur->_right;
		}
		else if (strcmp(pCur->_key, key) > 0)
		{
			pCur = pCur->_left;
		}
		else
		{
			return pCur;
		}
	}
	return NULL;
}

void BSTreeInOrderKV(BSTreeNode** tree)
{
	if (NULL == *tree)
	{
		return;
	}
	BSTreeInOrderKV(&((*tree)->_left));
	printf("\n%s:%d\n", (*tree)->_key,(*tree)->_value);
	BSTreeInOrderKV(&((*tree)->_right));
}