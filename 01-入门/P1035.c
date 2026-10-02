/*
 * 洛谷 P1035 [NOIP 2002 普及组] 级数求和
 * 难度：入门
 * 来源：【入门3】循环结构
 * 链接：https://www.luogu.com.cn/problem/P1035
 */
#include <stdio.h>
int main (void) {
    int k , n = 1 ;
    double sum = 0 ;

    scanf("%d" , &k) ;
    while (1)  {
        sum = sum + 1.0 / n ;
        n ++ ;

        if (sum > k) {
            printf("%d" , n - 1) ;   // n 已提前自增，因此输出 n - 1
            break;
        }
    }
    return 0 ;
}