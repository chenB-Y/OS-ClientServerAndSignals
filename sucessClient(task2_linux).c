//חן חזיזה 319027892
//שחר נעים 318685807
#include <stdio.h>
# include <sys/fcntl.h>
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
    if (atoi(argv[3]) == 4 && atoi(argv[4]) == 0)
    {
        printf("ERROR-cannot devide by ZERO.\n");
        exit(0);
    }
    signal(1, handler);
    int fd, x, i, op, pid, pidserver, f;
    for (i = 0; i < 10; i++)
    {
        fd = open("toServer.txt", O_RDWR | O_CREAT, 0644);
        if (fd < 0)
        {
            x = rand() % 5;
            sleep(x);
        }
        else
        {
            break;
        }
    }
    if (i == 10)
    {
        printf("connot do the operation\n");
        exit(0);
    }
    pid = getpid();
    f = fork();
    if (f < 0)
        printf("error of clients");
    if (f == 0)
    {
        close(1);
        dup(fd);
        close(fd);
        printf("%d\n%s\n%s\n%s", pid, argv[2], argv[3], argv[4]);
        exit(0);
    }
    else
    {
        wait(NULL);
    }
    pidserver = atoi(argv[1]);
    kill(pidserver, 1);
    pause();
    exit(1);
    return 0;
}
void handler(int sign) {
    signal(1, handler);
    int fdo, fdr;
    char buf[100] = "toClient";
    char buf2[10];
    char result[100];
    int pidnew = getpid();
    sprintf(buf2, "%d", pidnew);
    strcat(buf, buf2);
    strcat(buf, ".txt");
    fdo = open(buf, O_CREAT | O_RDWR);
    if (fdo < 0)
    {
        printf("error");
        exit(0);
    }
    read(fdo, result, 100);
    printf("%s\n", result);
}
