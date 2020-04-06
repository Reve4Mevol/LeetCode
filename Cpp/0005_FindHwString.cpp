#include <iostream>
#include <string>
using namespace std;

/**
 * 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
 *
 * 回文子串在我的理解就是相对于一个中间点对称
 * 例如abcddcbfff这个字符串满足s[1]==s[6],s[2]==s[5],s[3]==s[4];其中1+6=2+5=3+4,sumIndex = 7;
 * 再例如abcdcbfff,bcdcb是回文子串，满足s[1]==s[5],s[2]==s[4],s[3]单独不用管，1+5=2+4,sumIndex = 6;
 * 当string的长度大于0，sumIndex[0~ 2*size-2]     [0,1,2....size-2,size-1]
 * 找出sumIndex对应的最大回文子串长度O(n)
 * 遍历每个可能的sumIndex O(n)
 * 整体时间复杂度O(n^2)
 */
class Solution {
public:
    string longestPalindrome(string s) {
        string rtStr = "";
        int maxLen = 0,tmpMaxLen = 0;
        int sumIndex = 0;
        if(s.empty())
            return rtStr;
        else
        {
            for (int i = 0; i <= 2*s.length()-2; ++i) {
                tmpMaxLen = findMaxlenAtSumIndex(s,i);
                if(tmpMaxLen>=maxLen)
                {
                    maxLen = tmpMaxLen;
                    sumIndex = i;
                }
            }
        }
        /*再根据对应的sumIndex和len，打印出对于的字符串*/
        char tmp[maxLen+1];
        for (int j = 0; j < maxLen; ++j) {
            tmp[j] = s[j+(sumIndex+1-maxLen)/2];
        }
        tmp[maxLen]='\0';
        rtStr=tmp;
        return rtStr;
    }

public:
    int findMaxlenAtSumIndex(string s,int sumIndex)
    {
        int len = s.length();
        /* maxLen表示sumIndex对应的最长回文串长度 */
        int maxLen = 0;
        /*sumIndex-i<=len-1*/
        for (int i = max(0,sumIndex+1-len); i <= (sumIndex/2); ++i) {
            if(s[i]==s[sumIndex-i]&&i==sumIndex-i)
                maxLen++;
            else if(s[i]==s[sumIndex-i]&&i!=sumIndex-i)
                maxLen+=2;
            else
                maxLen = 0;
        }
        return maxLen;
    }
};

int main() {
    Solution t;
    string s = "abccbff";
    printf("result:%s",t.longestPalindrome(s).c_str());
    return 0;
}