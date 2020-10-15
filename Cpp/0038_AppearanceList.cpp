/**
 * Created by Reve4mevol on 2020/10/15.
 * Copyright (c) 2020 JM. All rights reserved.
 * Version:     1.0.0
 * Brief:       LeetCode #38
 * Details:
//给定一个正整数 n（1 ≤ n ≤ 30），输出外观数列的第 n 项。
//
//注意：整数序列中的每一项将表示为一个字符串。
//
//「外观数列」是一个整数序列，从数字 1 开始，序列中的每一项都是对前一项的描述。前五项如下：
//
//1.     1
//2.     11
//3.     21
//4.     1211
//5.     111221
//第一项是数字 1
//
//描述前一项，这个数是 1 即 “一个 1 ”，记作 11
//
//描述前一项，这个数是 11 即 “两个 1 ” ，记作 21
//
//描述前一项，这个数是 21 即 “一个 2 一个 1 ” ，记作 1211
//
//描述前一项，这个数是 1211 即 “一个 1 一个 2 两个 1 ” ，记作 111221
 * Note:        xxx
 * History:     <Version> <Date> <Description> <Author>
 *              1.0.0   2020/10/15     LeetCode #38
 *                                          --by Reve4Mevol<jazmin_1998@foxmail.com>
 */

#include <iostream>
using namespace std;

/**
 * 采用递归，以上一个结果作为输入得到当前结果很简单
 * 需要注意一些情况，比如我刚开始只考虑了当前字符发生变化时，合一下得到字符串，没考虑到字符串结束也没发生变化
 */
class Solution {
public:
    string countAndSay(int n) {
        if (1 == n)
        {
            return "1";
        }
        else
        {
            return stateLastList(countAndSay(n-1));
        }
    }

    string stateLastList(string lastList)
    {
        char curNum = lastList[0];            // 当前字符
        int curCount = 0;       // 当前这个字符已经有几个相同
        string ret = "";
        for (int i = 0; i < lastList.length(); ++i) {
            if (lastList[i] == curNum)
            {
                curCount++;
            }
            else
            {
                ret = ret + to_string(curCount) + curNum;
                curCount = 1;
                curNum = lastList[i];
            }
            // 不要忽略快结束时候，需要合一下
            if ( (lastList.length()-1) == i)
            {
                ret = ret + to_string(curCount) + curNum;
            }
        }
        return ret;
    }
};

int main() {
    Solution t;
    cout<<t.countAndSay(4)<<endl;
    return 0;
}