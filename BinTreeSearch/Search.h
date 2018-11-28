#pragma once
#include <stdio.h>
#include <assert.h>
#include <malloc.h>

typedef int BSTDataType;

typedef struct BSTreeNode
{
	struct BSTreeNode* _left;
	struct BSTreeNode* _right;
	BSTDataType _data;
}BSTreeNode;

//�ǵݹ�
int BSTreeInsert(BSTreeNode** tree, BSTDataType data);
int BSTreeRemove(BSTreeNode** tree, BSTDataType data);
BSTreeNode* BSTreeFind(BSTreeNode** tree, BSTDataType data);
void BStreeDestroy(BSTreeNode** tree);

//�ݹ�ʵ��
int BSTreeInsertR(BSTreeNode** tree, BSTDataType data);
int BSTreeRemoveR(BSTreeNode** tree, BSTDataType data);
BSTreeNode* BSTreeFindR(BSTreeNode** tree, BSTDataType data);

void BSTreeInOrder(BSTreeNode** tree);