#pragma once
#include<iostream>
#include<string>
#include <vector>
#include <assert.h>
#include <sstream>
using namespace std;
typedef long LongType;
struct CharInfo
{
	unsigned char _ch;
	LongType _count;
	string _code;
	CharInfo(LongType count=0):_count(count){};
	CharInfo(unsigned char ch):_ch(ch){};
	CharInfo operator+(const CharInfo &cc) const
	{
		return CharInfo(_count+cc._count);
	}
	bool operator!=(const CharInfo &cc) const
	{
		return (_count!=cc._count);
	}
	bool operator<(const CharInfo &cc) const
	{
		return (_count<cc._count);
	}
};

typedef struct HaffmanNode
{
	HaffmanNode *_left;
	HaffmanNode *_right;
	CharInfo _wight;
	HaffmanNode(){}
	HaffmanNode(const CharInfo &t)
	{
		_wight=t;
		_left=NULL;
		_right=NULL;
	}
}Node;