#include<stdio.h>

int main(){
    char buf[200] = "usr var bin etc proc boot root";
    
    FILE *fw = popen("grep bin","w");
    fputs(buf,fw);
    pclose(fw);
}
