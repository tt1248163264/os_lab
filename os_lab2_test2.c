#include<stdio.h>

int main(){
    char buf[200] = "usr\n var\n bin\n etc\n proc\n boot\n root\n";
    
    FILE *fw = popen("grep bin","w");
    fputs(buf,fw);
    pclose(fw);
}
