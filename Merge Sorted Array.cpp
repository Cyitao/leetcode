/*/**
 * Author: 常奕涛
 * Date: 2016/07
 * Github: https://github.com/Cyitao
 * Declaration: All Rights Reserved !!!
 **/

class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
	{
		if(nums1.size()<m+n||nums2.size()<n)
			return;
		int j1,j2,i;
		for(i=m+n-1,j1=m-1,j2=n-1;j1>=0&&j2>=0;i--)
		{
			if(nums1[j1]>=nums2[j2])
				nums1[i]=nums1[j1--];
			else
				nums1[i]=nums2[j2--];
		}
		if(j2>=0)
			while(j2>=0)
				nums1[i--]=nums2[j2--];
		return;
	}
};