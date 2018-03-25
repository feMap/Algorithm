/*通过计算返回子串T的next数组*/
void get_next(String T, int* next)
{
    int i, j;
    i = 1; 
    j = 0;
    next[1] = 0;
    while(i < T[0]) /*此处T[0]表示串T的长度*/
    {
        if(j == 0 || T[i] == T[j]) /*T[i]表示后缀的单个字符*/
        {                          /*T[j]表示前缀的单个字符*/
            i++;
            j++;
            next[i] = j;
        }
        else
        {
            j = next[j]; /*若字符不相同则回溯*/
        }
    }
}


/* 返回子串T在主串S中的第pos个字符之后的位置。若不存在，则函数返回值为0 */
/* T非空，1<= pos <=StrLength(s) */

