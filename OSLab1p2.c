#include <stdio.h>
#include <fcntl.h>

int main(int argc, char *argv[]){
        int i;
	int fid, copyfid;
        char buf;
	char *newLine;

	newLine = "/n";
	
        if (argc < 2) {
                printf("Usage: dictate <filename>\n");
                return 0;  }

	//Open file to copy from
	fid = open(argv[1], O_RDONLY, 0644);
	//Open file to copy to
	copyfid = open(argv[2], O_WRONLY|O_CREAT, 0644);

	while((read(fid, &buf, 1)) != '\0')
	{
		write(2, &buf, 1);
		if(buf == 'n'){
			write(copyfid, &newLine, 1);
			write(copyfid, &newLine, 1);
				}
		write(copyfid, &buf, 1);
		
	}
        close(fid);
        close(copyfid);

        return 0;
}

