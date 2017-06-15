/* 
 * HDU:1050
 * 
 * URL: http://acm.hdu.edu.cn/showproblem.php?pid=1050
 * 
 * This is one kind of my solution,signing each section.
 * It is so easy.
 * But it's not solve by greedy algorithm.
 * So I will solve this problen by greedy algorithm latter.
 * In the other file named HDU1050_G,you could see it.
 * GOOD LUCK!
 * 
 */

#include<stdio.h>
#include<string.h>
#define swap(a, b, key) key = a, a = b, b = key;

int main(void)
{
    int count[210];//It is used to be record how many time every section have been used.
    int swapKey,count_i,count_j;
    int testNum,eachTestNum;
    int roomStart,roomEnd;
    int ans;
    
    scanf("%d",&testNum);//Input the test case number.
    
    while(testNum--)
    {
        memset(count,0,sizeof(count));//Initialize the array
        scanf("%d",&eachTestNum);
        
        for( count_i = 0; count_i < eachTestNum; count_i++)
        {
            scanf("%d %d", &roomStart, &roomEnd);
            
            //Just make the section more simple.
            roomEnd = (roomEnd + 1) / 2;
            roomStart = (roomStart + 1) / 2;
            
            //Pay attention to it!!
            //Maybe the start room number will bigger then the room end number.
            if(roomStart > roomEnd )
                swap(roomStart, roomEnd, swapKey);
            
            //Sign the section
            for( count_j = roomStart; count_j <= roomEnd; count_j++)
                count[count_j]++;
        }
        
        ans = -1;
        
        //Find the biggest signed times in the signed sections
        for( count_i = 0; count_i < 205; count_i++)
            if(ans < count[count_i])
                ans = count[count_i];
        
        printf("%d\n",ans*10);
    }
    return 0;
}
