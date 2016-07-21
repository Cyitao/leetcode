/*/**
 * Author: 常奕涛
 * Date: 2016/07
 * Github: https://github.com/Cyitao
 * Declaration: All Rights Reserved !!!
 **/
//方法一：
struct Node
{
	int data;
	int pos;
	Node(){
		data=0;
		pos=0;
	}
};
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) 
	{
		vector<int> res;
		if(nums.empty())
			return res;
		int len=nums.size();
		Node *num=new Node[len];
		for(int i=0;i<len;i++)
		{
			num[i].data=nums[i];
			num[i].pos=i;
		}
		sort(num,num+len,Solution::cmp);
		int low=0,high=len-1;
		while(low<high)
		{
			if(num[low].data+num[high].data==target)
			{
				res.push_back(num[low].pos);
				res.push_back(num[high].pos);
				return res;
			}
			if(num[low].data+num[high].data>target)
				high--;
			else if(num[low].data+num[high].data<target)
				low++;
		}
		delete []num;
		num=NULL;
		return res;
	}
	static bool cmp(Node &a,Node &b)
	{
		return a.data<b.data;
	}
};
//方法二：
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) 
	{
		vector<int> res;
		if(nums.size()<2)
			return res;
		map<int,int> data;
		for(int i=0;i<nums.size();i++)
		{
			if(data.find(target-nums[i])!=data.end())
			{
				res.push_back((*data.find(target-nums[i])).second);
				res.push_back(i);
				return res;
			}
			data.insert(make_pair(nums[i],i));
		}
		return res;
	}
};