#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <zconf.h>
#include <limits.h>

#define true 1
char args[100];
char** argv;
char* pathVar;
char* username;
char* hostname;
size_t len = 64;
char cwd[PATH_MAX];
char getDirectory(){
    if (getcwd(cwd, sizeof(cwd)) != NULL) {

    }else{
        perror("getcwd() error");
    }
}
void execute(){
    int status;
    pid_t pid = fork();
    if(pid==0){
        if(execvp(*argv,argv)<0)
        {
            //wyjebalo sie;
            //error
            //exit 1
        }else{
            //wykonalo sie;
        }
    }else if(pid==-1){
        //fork sie wyjebal
        //exit 1
    }
    int w8 = waitpid(pid,&status,0);
}
void prompt(){
    getDirectory();
    pathVar=cwd;
    printf("[{%s}@{%s}{%s}]:? ",username,hostname,pathVar);
}
void helper(){
    int i=0;
    while(argv[i]!=NULL)
    {
        printf("%d:%s\n",i,argv[i]);
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
void clear(){

}

int main() {
    username=getenv("USER");
    hostname=getenv("HOST");
    while(true) {
        argv = (char **)malloc(sizeof(char *) * 100);
        prompt();
        getInput(argv, args);
        helper();
        if(strcmp(argv[0],"exit")==0)
        {
            if(argv[1]!=NULL){
                exit(argv[1]);
            }else{
                exit(0);
            }
        } else if(strcmp(argv[0],"cd")==0){
            chdir(argv[1]);
        } else {
            execute();
        }

    }
    return 0;
}
