#include <stdio.h>
#include <fcntl.h>

int main(int argc, char *argv[]){
        if (argc < 2) {
                printf("Usage: dictate <filename>\n");
                return 0;  }

        int maxSize;
        int fid = open(argv[1], O_RDONLY, 0644);

        char buff[128];

        int fcopyid = open(argv[2], O_WRONLY|O_CREAT, 0644);

        if(fid > 0){
                maxSize = read(fid, buff, sizeof(buff));
                write(fcopyid, buff, maxSize);
                }

        close(fid);
        close(fcopyid);

        return 0;
}
