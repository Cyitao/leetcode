/*/**
 * Author: 常奕涛
 * Date: 2016/07
 * Github: https://github.com/Cyitao
 * Declaration: All Rights Reserved !!!
 **/
class Solution {
public:
    int mySqrt(int x) 
    {
        if(x==0)
            return 0;
        if(x<0)
            return -1;
        double lastx=0,curx=1;
        while(abs(lastx-curx)>=0.000001)
        //牛顿迭代
        {
            lastx=curx;
            curx=(lastx*lastx+x)/(2*lastx);
        }
        return (int)curx;
        /*int low=1,high=x/2+1,mid;
        while(low<=high)
        {
            mid=low+(high-low)/2;
            if(mid<=(x/mid)&&(mid+1)>x/(mid+1))
                  return mid;
            else if(mid>(x/mid))
                  high=mid-1;
            else
                  low=mid+1;
        }
        return high;*/
    }
};