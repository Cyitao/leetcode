#pragma once
#include "FileComparess.h"
#include "Heap.h"
#include "base.h"
class HaffmanTree
{
public:
	HaffmanTree(const CharInfo *a,int size,CharInfo &Invalid)
	{
		_root=_CreatHaffmanTree(a,size,Invalid);
	}
	Node *GetRoot()
	{
		return _root;
	}
protected:
	Node * _CreatHaffmanTree(const CharInfo *a,int size,CharInfo &Invalid)
	{
		Heap MinHeap;
		for(int i=0;i<size;i++)
			if(a[i]!=Invalid)
			{
				Node *tmp=new Node(a[i]);
				MinHeap.push(tmp);
			}
		while(!MinHeap.Empty())
		{
			Node *left=MinHeap.GetTop();
			MinHeap.pop();
			Node *right=NULL;
			if(!MinHeap.Empty())
			{
				right=MinHeap.GetTop();
				MinHeap.pop();
			}
			Node *parent=NULL;
			if(right)
				parent=new Node((*left)._wight+(*right)._wight);
			else
				parent=new Node((*left)._wight);
			(*parent)._left=left;
			(*parent)._right=right;
			if(MinHeap.Empty())
				return parent;
			MinHeap.push(parent);
		}
		return NULL;
	}
	Node *_root;
};