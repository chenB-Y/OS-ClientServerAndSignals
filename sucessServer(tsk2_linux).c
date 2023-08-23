//חן חזיזה 319027892
//שחר נעים 318685807
#include <stdio.h>
#include <sys/fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <wait.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
int placeOfMark = 0;
int checkLine(char* file);
void handler(int sign); 
int main(int argc, char* argv[]) {
    signal(1, handler);
    while (1)
    {
        pause();
        placeOfMark = 0;
    }
}
void handler(int sign) {
    signal(1, handler);
    int numOfLet, dfr1, dfs1, fdo, fdr, result, fdf, numpid, size;
    char ClientID[6];
    char* args[] = { "rm","toServer.txt",NULL };
    char txt[5] = ".txt";
    char clientName[50] = "toClient";
    char buff[100];
    fdo = open("toServer.txt", O_RDWR);
    if (fdo < 0)
    {
        exit(0);
    }
    dfs1 = lseek(fdo, placeOfMark, SEEK_SET);
    numOfLet = checkLine("toServer.txt");
    char* clientPID = (char*)malloc((numOfLet + 1) * sizeof(char));
    dfr1 = read(fdo, clientPID, numOfLet);
    dfs1 = lseek(fdo, placeOfMark, SEEK_SET);
    numOfLet = checkLine("toServer.txt");
    char* num1 = (char*)malloc((numOfLet + 1) * sizeof(char));
    dfr1 = read(fdo, num1, numOfLet);
    dfs1 = lseek(fdo, placeOfMark, SEEK_SET);
    numOfLet = checkLine("toServer.txt");
    char singleOperator[2];
    dfr1 = read(fdo, &singleOperator, numOfLet);
    dfs1 = lseek(fdo, placeOfMark, SEEK_SET);
    numOfLet = checkLine("toServer.txt");
    char* num2 = (char*)malloc((numOfLet + 1) * sizeof(char));
    dfr1 = read(fdo, num2, numOfLet);
    close(fdo);
    strcat(clientName, clientPID);
    strcat(clientName, txt);
    fdf = fork();
    if (fdf < 0)
        exit(0);
    if (fdf == 0)
    {
        execvp("rm", args);//delete "toServer.txt"
        return;
    }
    else
        wait(NULL);
    switch (*singleOperator)
    {
    case'1':
    {
        result = atoi(num1) + atoi(num2);
        break;
    }
    case'2':
    {
        result = atoi(num1) - atoi(num2);
        break;
    }
    case'3':
    {
        result = atoi(num1) * atoi(num2);
        break;
    }
    case'4':
    {
        result = atoi(num1) / atoi(num2);
        break;
    }
    default:
        printf("EROOR! incorrect operator\n");
        break;
    }
    fdo = open(clientName, O_CREAT | O_RDWR, 0644);//create toclient123456.txt
    if (fdo < 0) {
        exit(0);
    }
    sprintf(buff, "%d", result);
    size = strlen(buff);
    write(fdo, buff, size);
    close(fdo);
    kill(atoi(clientPID), 1);
}
int checkLine(char* file) {
    int dfo, dfr, dfls, counter = 0;
    char ch;
    dfo = open(file, O_RDONLY);
    if (dfo < 0)
        exit(0);
    dfls = lseek(dfo, placeOfMark, SEEK_SET);
    if (dfls < 0)
        return 0;
    while (1)
    {
        dfr = read(dfo, &ch, 1);
        counter++;
        if (ch == '\n' || dfr == 0)
            break;
    }
    placeOfMark += counter;
    close(dfo);
    return (counter - 1);
}
