class Solution {
public:
	void replaceSpace(char *str,int length) {
        int orig_len = strlen(str);
        int space_cnt = 0;
        char *str_cp = str;
        while(*str_cp!='\0')
        {
            if(*str_cp == ' ')
                ++space_cnt;
            ++str_cp;
        }
        int replace_len = orig_len + space_cnt*2;
        if(length < replace_len)
            return;
        str[replace_len] = '\0';
        int orig_cur = orig_len - 1;
        int rep_cur = replace_len - 1;
        while(orig_cur >= 0)
        {
            if(str[orig_cur]==' ')
            {
                str[rep_cur] = '0';
                str[rep_cur - 1] = '2';
                str[rep_cur - 2] = '%';
                rep_cur -= 3;
                orig_cur-=1;
            }else
            {
                str[rep_cur--] = str[orig_cur--];
            }
        }
	}
};