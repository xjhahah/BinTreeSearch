#pragma once
#pragma once
#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include <string.h>

typedef char* BSTKeyType;
typedef int BSTValueType;

typedef struct BSTreeNode
{
	struct BSTreeNode* _left;
	struct BSTreeNode* _right;
	BSTKeyType _key;
	BSTValueType _value;
}BSTreeNode;

int BSTreeInsertK(BSTreeNode** tree, BSTKeyType key);
BSTreeNode* BSTreeFindK(BSTreeNode** tree, BSTKeyType key);

int BSTreeInsertKV(BSTreeNode** tree, BSTKeyType key,BSTValueType val);
BSTreeNode* BSTreeFindKV(BSTreeNode** tree, BSTKeyType key);

void BSTreeInOrderKV(BSTreeNode** tree);