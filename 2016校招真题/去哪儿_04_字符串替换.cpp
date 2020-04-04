/*
请你实现一个简单的字符串替换函数。原串中需要替换的占位符为"%s",请按照参数列表的顺序一一替换占位符。若参数列表的字符数大于占位符个数。则将剩下的参数字符添加到字符串的结尾。

给定一个字符串A，同时给定它的长度n及参数字符数组arg，请返回替换后的字符串。保证参数个数大于等于占位符个数。保证原串由大小写英文字母组成，同时长度小于等于500。

测试样例：
"A%sC%sE",7,['B','D','F']
返回："ABCDEF"
*/

//超级简单
class StringFormat {
public:
    string formatString(string A, int n, vector<char> arg, int m) {
        // write code here
        string res = "";
        int repIdx = 0;
        for(int i=0;i<n;){
            if(A[i]=='%' && i < n-1 && A[i+1]=='s'){
                res += arg[repIdx];
                ++repIdx;
                i+=2;
            }else{
                res += A[i];
                ++i;
            }
        }
        
        if(repIdx < m){
            for(int i=repIdx;i<m;++i){
                res += arg[i];
            }
        }
        
        return res;
    }
};