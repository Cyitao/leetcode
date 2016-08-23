#pragma once
#include "base.h"
#include "FileComparess.h"
#include "HaffmanTree.h"
using namespace std;
class HaffmanTree;


class Heap
{
protected:
	vector <Node *> _a;
	void _AdjustDown(int parent);
	void _AdjustUp(int child);
public:
	Heap(){}
	void push(Node* x);
	void pop();
	Node *GetTop();
	bool Empty();
};

bool Heap::Empty()
{
	return _a.empty();
}

Node *Heap::GetTop()
{
	return _a[0];
}

void Heap::pop()
{
	assert(!_a.empty());
	swap(_a[0],_a[_a.size()-1]);
	_a.pop_back();
	if(!_a.empty())
		_AdjustDown(0);
}

void Heap::push(Node *x)
{
	_a.push_back(x);
	_AdjustUp(_a.size()-1);
}

void Heap::_AdjustDown(int parent)
{
	Node *key=_a[parent];
	int i;
	for(i=2*parent+1;i<_a.size();i=2*i+1)
	{
		if(i<_a.size()-1&&((*_a[i+1])._wight<(*_a[i])._wight))
			i++;
		if((*key)._wight<(*_a[i])._wight)
			break;
		swap(_a[(i-1)/2],_a[i]);
	}
	return;
}

void Heap::_AdjustUp(int child)
{
	int parent=(child-1)/2;
	while(child>0)
	{
		if((*_a[child])._wight<((*_a[parent])._wight))
			swap(_a[child],_a[parent]);
		else
			break;
		child=parent;
		parent=(child-1)/2;
	}
	return;
}