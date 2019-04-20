#include<stdio.h>
#include<unistd.h>
int main(){
    //char cmd[10][10] = {"ls","-a","/","|","grep","bin"};
    char cmd[10][10] = {"","-a","/","|","grep","bin"};
    char *argv1[4] = {cmd[0],cmd[1],cmd[2],NULL};
    char *argv2[4] = {cmd[4],cmd[5],NULL};
    pid_t child_pid = fork();
    if(child_pid == 0){
        char buf[200];
        //char cmd_left[10][10] = {"ls","-a","/"};
        FILE *fr = popen("ls -a /","r");
        fread(buf,sizeof(char),sizeof(buf),fr);
        FILE *fw = popen("grep bin","w");
        fputs(buf,fw);
        pclose(fw);
        //execvp(argv1[0],argv1);
        /*pid_t cchild_pid = fork();
        
        if(cchild_pid == 0){
            //cchild
            //printf("%s",buf);
            FILE *fw = popen("grep bin","w");
            fputs(buf, fw);
            fclose(fw);
            exit(1);
        }else{
            int c_status;
            c_status = waitpid(cchild_pid,&c_status,0);
            //child
        }*/
        pclose(fr);
        exit(1);
    }else{
        int status;
        status = waitpid(child_pid,&status,0);
    }
    
    getchar();
}
/*
pid_t child_pid = fork(); 
if (child_pid == 0) {    
    // 子进程，准备 exec 
} else {
    // 父进程，等待子进程结束    
    int status;    
    status = waitpid(child_pid, &status, 0);
    // status 的用法详见 [man 2 wait] 
}
*/
