#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <zconf.h>
#include <limits.h>

#define true 1
char args[100];
char hstring[128];
char** argv;
char* pathVar;
char* username;
char hostname[1024];
size_t len = 64;
char cwd[PATH_MAX];
char getDirectory(){
    if (getcwd(cwd, sizeof(cwd)) != NULL) {

    }else{
        perror("getcwd() error\n");
    }
}
void execute(){
    int status;
    pid_t pid = fork();
    if(pid==0){
        if(execvp(*argv,argv)<0)
        {
            printf("Error: Failed to execute command\n");
            exit(1);
        }else{
            //wykonalo sie;
        }
    }else if(pid==-1){
        printf("Failed to fork\n");
        exit(1);
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
    hostname[1023] = '\0';
    gethostname(hostname, 1023);
    while(true) {
        argv = (char **)malloc(sizeof(char *) * 100);
        prompt();
        getInput(argv, args);
        helper();
        strcpy(hstring,argv[0]);
        if(strcmp(&hstring[0], "./") == 0){
            system(hstring);
        }else if(strcmp(argv[0],"exit")==0)
        {
            if(argv[1]!=NULL){
                exit(argv[1]);
            }else{
                exit(0);
            }
        } else if(strcmp(argv[0],"cd")==0){
            chdir(argv[1]);
        } else if(strcmp(argv[0],"echo")==0){
            if(argv[1]!=NULL) {
                printf((char *) argv[1]);
                printf("\n");
            }else{
                printf("\n");
            }

        } else if(strcmp(argv[0],"help")==0){
            printf("This program simulates shell\n");
            printf("Example commands:\n");
            printf("cd - changes directory\n");
            printf("ls - shows files in current dir\n");
            printf("date - shows date");

        }
//        else if (strcmp(argv[0])){
//
//        }
        else{
            execute();
        }

    }
    return 0;
}
