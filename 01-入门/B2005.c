/*
 * 洛谷 B2005 字符三角形
 * 难度：入门
 * 来源：【入门1】顺序结构
 * 链接：https://www.luogu.com.cn/problem/B2005
 */

#include <stdio.h>
int main(void) {
    char ch ;
    //printf("Please input an charactor :") ;
    scanf("%c" , &ch) ;

    printf("  %c  \n" , ch);
    printf(" %c%c%c \n",ch , ch , ch ) ;
    printf("%c%c%c%c%c\n" , ch , ch , ch , ch , ch );

    return 0;

}
