#include<fcntl.h>
#include<stdio.h>

int main(int argc, char *argv[])
{
	int counter;
	char *buf;
	int fid, copyfid;
	
	counter = 0;
	if (argc < 2) {
                printf("Usage: dictate <filename>\n");
                return 0;  }
	
	//Open file to copy from
	fid = open(argv[1], O_RDONLY, 0664);
	//Open file to copy to
	copyfid = open(argv[2], O_WRONLY|O_CREAT, 0644);

	while((read(fid, &buf, 1)) != '\0')
	{
		if((buf == ' ') | (buf == '/n')){
			write(copyfid, &buf, 1);
			counter = 0;
			}

		if(counter == 0){
			if(buf >= 'a'){
				buf = buf-32;
				write(copyfid, &buf, 1);
				counter = counter + 1;
				}
			else{
				write(copyfid, &buf, 1);
			}
				}
		else{
			write(copyfid, &buf, 1);
		}
		
	}
	
	close(fid);
	close(copyfid);
	return 0;
}

