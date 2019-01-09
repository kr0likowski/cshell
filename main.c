#include <stdio.h>
#include <string.h>
#define true 1
char args[100];
char** argv;
void helper(){
    int i=0;
    while(argv[i]!=NULL)
    {
        printf("1:%s\n",argv[i]);
        i++;
    }
}
void getInput(char** argv, char* args)
{
    int i=0,j=0;
    char c;
    char* wrd;
    while((c = getchar())!='\n'){
        args[i]=c;
        i++;
    }
   wrd=strtok(args," ,.");
    while(wrd!=NULL)
    {

        argv[j]=wrd;
        wrd=strtok(NULL," ,.");
        j++;
    }
    argv[j]=NULL;
}

int main() {
    while(true) {
        argv = (char **)malloc(sizeof(char *) * 100);
        getInput(argv, args);
        helper();
    }
    return 0;
}
