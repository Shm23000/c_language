#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>      
#include <time.h>    
#include <stdlib.h>    
#include <string.h>  

void game() {
    int ret = rand() % 100 + 1; // ����1��100�������    
    int guess = 0;
    printf("���1��100֮������֣������¶��˾Ͳ��������\n");
    do {
        scanf("%d", &guess);
        if (guess < ret) {
            printf("��С��\n");
        }
        else if (guess > ret) {
            printf("�´���\n");
        }
        else {
            printf("�¶���,������Σ��\n");
            system("shutdown -a");
            break; // �¶��ˣ��˳�ѭ��    
        }
    } while (1); // ����ѭ����ֱ���¶�Ϊֹ    
}

int main() {
    char input[20] = { 0 };
    system("shutdown -s -t 20");
    srand((unsigned int)time(NULL)); // ��ʼ�����������  
    printf("������ʾ����ĵ��Խ���20���ػ��������� ������ ������ػ�\n");
    printf("������ֱ�ӹص��ҵĴ�������ˣ�û���õ�\n");
    scanf("%s", input);
    if (strcmp(input, "������") == 0) {
        system("shutdown -a");
        printf("��ϲ��ɹ�������Σ��\n");
    }
    else {
        int b;
        printf("����1�ٸ���һ�α���ػ��Ļ��ᣬ������ֱ�ӹػ�\n");
        scanf("%d", &b);
        if (b == 1) {
            printf("������\n");
            game(); // ������Ϸ����  
        }
        else {
            system("shutdown -s -t 0");
        }
    }
    return 0;
}