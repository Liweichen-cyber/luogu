/*
 * 洛谷 P1024 [NOIP 2001 提高组] 一元三次方程求解
 * 难度：入门
 * 来源：【算法1-6】二分查找与二分答案
 * 链接：https://www.luogu.com.cn/problem/P1024
 */

#include <stdio.h>
double f(double x, double a, double b, double c, double d)  //注意abcd是实数，用double
{
    return a * x * x * x + b * x * x + c * x + d;
}

int main(void) {
    double a ,b , c , d ;
    int i ;
    scanf("%lf %lf %lf %lf", &a, &b, &c, &d);

    for (i = -100 ; i < 100 ; i ++) {
        // i 本身就是根，直接处理
        if (f(i, a, b, c, d) == 0) {
            printf("%.2f ", (double)i);

        }
        // 根在 i 和 i+1 之间，需要二分
        else if (f(i, a, b, c, d) * f(i+ 1, a, b, c, d) < 0) {
            double left = i ;
            double right = i + 1 ;
            double mid ;

            while (right - left > 0.0001) {   //最后mid保留两位小数，精度需要高于0.01
                mid = (left + right) / 2 ;

                if (f(right , a , b , c , d)* f(mid , a , b , c , d) < 0) {
                    left = mid ;    //区间在中点和右端点之间，因此mid变成左端点left
                }

                else  {
                    right = mid ;   //同上
                }
            }
            printf("%.2lf " , mid);  //一个printf即可，输出一次重新进入for 循环
        }
    }
    if (f(100, a, b, c, d) == 0) {
        printf("%.2f ", 100.0);
    }

    return 0;
}
/*for + if：寻找根所在的长度为 1 的区间（或发现整数根）
while：不断把这个区间二分缩小，逼近根。*/
