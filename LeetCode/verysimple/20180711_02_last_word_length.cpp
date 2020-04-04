/*
Given a string s consists of upper/lower-case alphabets and empty space characters' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example, 
Given s ="Hello World",
return5.

//这道题，尾部空格不管，比如"a  " 返回1

*/

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        if(s==nullptr)
            return 0;
        std::string str(s);
        if(s == "")
            return 0;
        //去掉尾部空格
        while(str.back()==' '){
            str.pop_back();
        }
        
        int lastSpacePos = -1;
        for(int i=str.length()-1;i>=0;--i){
            if(str[i]==' '){
                lastSpacePos = i;
                break;
            }
        }
        if(lastSpacePos == -1)
            return str.length();
        return str.length()-lastSpacePos-1;
    }
};