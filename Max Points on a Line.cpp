/*/**
 * Author: 常奕涛
 * Date: 2016/07
 * Github: https://github.com/Cyitao
 * Declaration: All Rights Reserved !!!
 **/


/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) 
    {
        if(points.size()<=2||allSame(points))
             return points.size();
        int res=0;
        for(int i=0;i<points.size();i++)
           for(int j=i+1;j<points.size();j++)
           {
               if(points[i].x==points[j].x&&points[i].y==points[j].y)
                    continue;
               int cur=2;
               for(int k=0;k<points.size();k++)
                    if(k!=i&&k!=j&&(points[k].y-points[i].y)*(points[i].x-points[j].x)==(points[i].y-points[j].y)*(points[k].x-points[i].x))
                          cur++;
               res=max(res,cur);
           }
        return res;
    }
    bool allSame(vector<Point>& points)
    {
        for(int i=0;i<points.size()-1;i++)
          if(points[i].x!=points[i+1].x||points[i].y!=points[i+1].y)
              return false;
        return true;
    }
};