/*
 * HDU 1003
 * 
 * URL http://acm.hdu.edu.cn/showproblem.php?pid=1003
 * 
 * Given a sequence a[1],a[2],a[3]......a[n], your job is to calculate the max sum of a sub-sequence.
 * For example, given (6,-1,5,4,-7), the max sum in this sequence is 6 + (-1) + 5 + 4 = 14.
 */

#include <stdio.h>

int main()
{
    int array[100010];
    int testCaseNum;
    int eachTestNum;
    int count_i;
    int cas = 1;
    int start,end,temp;
    int sum,max;
    
    scanf("%d", &testCaseNum);
    
    while(testCaseNum--)
    {
        start = end = temp = 1;                                 //Initialize
        sum = 0;
        max = -1001;                                            //Because all the integers are between -1000 and 1000.
        
        scanf("%d",&eachTestNum);
        
        for(count_i = 1; count_i <= eachTestNum; count_i++)     //Find maxinum subarray.
        {
            scanf("%d",&array[count_i]);
            
            sum = sum + array[count_i];
            
            if(sum > max)
            {
                max = sum;
                start = temp;
                end = count_i;
            }
            
            if(sum < 0)
            {
                sum = 0;
                temp = count_i + 1;
            }
        }
        
        printf("Case %d:\n",cas++);
        printf("%d %d %d\n",max,start,end);
        
        if(testCaseNum > 0)
            printf("\n");
    }
    return 0;
}