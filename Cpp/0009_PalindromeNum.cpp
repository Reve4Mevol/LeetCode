/**
 * Created by Reve4mevol on 2020/10/17.
 * Copyright (c) 2020 JM. All rights reserved.
 * Version:     1.0.0
 * Brief:       LeetCode #9
 * Details:     判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
 * Note:        注意回文后是否越界
 * History:     <Version> <Date> <Description> <Author>
 *              1.0.0   2020/10/17     判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
 *                                          --by Reve4Mevol<jazmin_1998@foxmail.com>
 *
 *
 * !!! 优化解法：while条件框iCopy != 0改成iCopy > palindromeNum,这样就不要特意考虑palindromeNum越界，因为一半的时候就能得到结果
 * return iCopy == palindromeNum || iCopy == palindromeNum / 10;
 * 如果为基数 12321，那么满足条件时12<123,偶数满足条件时候1221,12=12.
 */

#include <iostream>

class Solution {
public:
    bool isPalindrome(int x) {
        if(0 > x)
        {
            return false;
        }
        if(0 <= x && 10 > x)
        {
            return true;
        }
        int iCopy = x;
        long long palindromeNum = 0;
        while(iCopy != 0)
        {
            palindromeNum = palindromeNum*10 + iCopy%10;
            iCopy/=10;
        }
        return palindromeNum==x;
    }
};


int main() {
    Solution t;
    if(t.isPalindrome(121))
    {
        printf("true!\n");
    }
    else
    {
        printf("false!\n");
    }
    return 0;
}