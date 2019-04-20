#include<stdio.h>
#include<unistd.h>
#include<string.h>
int main(){
    char str_num[256];
    int ret;
    printf("Give me a string:");
    scanf("%s",str_num);
    syscall(328,str_num,strlen(str_num),&ret);
    printf("int sys_print_val:%d\n",ret);
}
