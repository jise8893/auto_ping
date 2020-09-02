#include <stdio.h>
int main(){
  int i;
  char cmd[40];
  for(i=0;i<=255;i++){
    sprintf(cmd,"ping -c 1 192.168.1.%d | grep from",i);
    system(cmd);
    }
    return 0;
}
