#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>      
#include <time.h>    
#include <stdlib.h>    
#include <string.h>  

void game() {
    int ret = rand() % 100 + 1; // 生成1到100的随机数    
    int guess = 0;
    printf("请猜1到100之间的数字，你若猜对了就不关你电脑\n");
    do {
        scanf("%d", &guess);
        if (guess < ret) {
            printf("猜小了\n");
        }
        else if (guess > ret) {
            printf("猜大了\n");
        }
        else {
            printf("猜对了,解除这次危机\n");
            system("shutdown -a");
            break; // 猜对了，退出循环    
        }
    } while (1); // 无限循环，直到猜对为止    
}

int main() {
    char input[20] = { 0 };
    system("shutdown -s -t 20");
    srand((unsigned int)time(NULL)); // 初始化随机数种子  
    printf("友情提示，你的电脑将在20秒后关机，请输入 我是猪 来解除关机\n");
    printf("别想着直接关掉我的代码就行了，没有用的\n");
    scanf("%s", input);
    if (strcmp(input, "我是猪") == 0) {
        system("shutdown -a");
        printf("恭喜你成功解除这次危机\n");
    }
    else {
        int b;
        printf("输入1再给你一次避免关机的机会，输入别的直接关机\n");
        scanf("%d", &b);
        if (b == 1) {
            printf("猜数字\n");
            game(); // 调用游戏函数  
        }
        else {
            system("shutdown -s -t 0");
        }
    }
    return 0;
}