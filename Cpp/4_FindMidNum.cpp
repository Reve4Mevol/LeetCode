#include <iostream>
#include <stdio.h>
#include<vector>
using namespace std;
/**
 *  归并排序，判断时需要注意先判断迭代器是否到end
 */
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> tmp;
        vector<int>::iterator p1;
        vector<int>::iterator p2;
        p1 = nums1.begin();
        p2 = nums2.begin();

        while(p1!=nums1.end()||p2!=nums2.end())
        {
            if(p1!=nums1.end()&&p2!=nums2.end())
            {
                if(*p1>*p2){
                    tmp.push_back(*p2);
                    p2++;
                }
                else
                {
                    tmp.push_back(*p1);
                    p1++;
                }
            }
            else if (p2==nums2.end()&&p1!=nums1.end())
            {
                tmp.push_back(*p1);
                p1++;
            }
            else if (p1==nums1.end()&&p2!=nums2.end())
            {
                tmp.push_back(*p2);
                p2++;
            } else
                break;
        }
        int i = nums1.size()+nums2.size();
        if(i%2==0)
        {
            i = i/2;
            return (double)(tmp[i]+tmp[i-1])/2.0;
        }
        else {
            i = (i - 1) / 2;
            return (double)tmp[i];
        }
    }
};

int main() {
    Solution s1;
    vector<int> t1;
    vector<int> t2;
    t1.push_back(1);
    t1.push_back(3);
    t2.push_back(2);
//    t2.push_back(6);
    double i;
    i = s1.findMedianSortedArrays(t1,t2);
    cout<<i;
    return 0;
}