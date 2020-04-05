class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //represent longest string's first index and last index
        int first=0;
        int last=1;
        int currentLength=1;
        int maxLength=0;
        int size=s.size();
        int i,j,flag;
        if(size==0||size==1)
            maxLength=size;
        for(i=first;i<last;i++)
        {
            flag=0;
            if(last>(size-1))
            {
                break;
            }
            for(j=first;j<last;j++)
            {
                if(s[j]==s[last])
                {
                    currentLength=currentLength-(j-first);
                    first=j+1;
                    flag=1;
                    break;
                }
            }
            
            if(flag==0)
                currentLength++;
            
            last++;
            if(currentLength>maxLength)
                maxLength=currentLength;
        }
        return maxLength;
    }
};