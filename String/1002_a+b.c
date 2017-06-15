/*
 * HDU 1003
 * 
 * URL http://acm.hdu.edu.cn/showproblem.php?pid=1002
 * 
 * Calculate the Sum of A + B by string.
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Max(a,b) ((a)>(b)?(a):(b))
#define MAX_Num 1005

int main(void)
{
    char a[MAX_Num],b[MAX_Num];                     //a and b are the number we want to add.
    int c[MAX_Num];                                 //c is the reault.
    int testCaseNum;
    int counter = 0;                                //used to record how many cases we have done.
    int len_a, len_b, len;                          //string len; len is the longest string length between a and b.
    int count_i;
    int transposition;                              //used to transposition
    int status;                                     //used to check the special case: 0 + 0 = 0
    
    scanf("%d", &testCaseNum);
    
    while(testCaseNum--)
    {
        counter++;
        status = 0;
        
        memset(a,0,sizeof(a));                      //Initialize
        memset(b,0,sizeof(b));
        memset(c,0,sizeof(c));
        
        scanf("%s", a);                             //Get number a and b. The kind of data is char.
        scanf("%s", b);
        
        len_a = strlen(a);                          //Get the length of string a and b.
        len_b = strlen(b);
        
        len = len_a > len_b ? len_a : len_b;
        
        for(count_i = len ; count_i > 0 ; count_i--)//Calculate a + b. Begin in the end of string a and b.
        {
            len_a--;
            len_b--;
            
            if(len_a >= 0 && len_b >= 0)            //Add a and b by adding their each position.
            {
                c[count_i] = c[count_i] + ( a[len_a] - '0') + ( b[len_b] - '0');//Become char to int.
            }
            else if(len_a < 0 && len_b >= 0)
            {
                c[count_i] = c[count_i] + b[len_b] - '0'; 
            }
            else if(len_b < 0 && len_a >= 0)
            {
                c[count_i] = c[count_i] + a[len_a] - '0';
            }
            
            if(c[count_i] > 9)                      //If ome position is bigger then 9,it should be carried.
            {
                transposition = c[count_i] / 10;
                c[count_i] = c[count_i] % 10;
                c[count_i - 1] = c[count_i - 1] + transposition;
            }
        }
        
        printf("Case %d:\n", counter);
        printf("%s + %s = ", a, b);
        
        for(count_i = 0; c[count_i] == 0; count_i++);//Skip the no sense position.
        for( ; count_i <= len; count_i++)
        {
            printf("%d", c[count_i]);
            status = 1;
        }
        if(status == 0)
            printf("0");
            
        if(testCaseNum > 0)                         //Notice it!
            printf("\n\n");
        else
            printf("\n");
    }
    return 0;
}

