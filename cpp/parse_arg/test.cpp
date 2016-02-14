#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>

using namespace std;

const char short_opt[] = {'w', 'h', 'u', '\0'};
const char *long_opt[] = {"--width", "--height", "--usage", ""};

void usage(char *argv)
{
  printf("Usage:\n");
  printf("\t%s opt opt_val\n\n", argv);
  printf(" -w    (--width)         image_width\n");
  printf(" -h    (--height)        image_height\n");
}

int moreopt(char *argv)
{
  int i=0;
  while(short_opt[i]!='\0'){
	if(strcmp(argv, long_opt[i])==0){
	  argv[1]=short_opt[i];
	  argv[2]='\0';
	  return 0;
	}
	i++;
  }
  return 1;
}

int read_opt(int argc, char **argv, int id, void *data, const char *datatype) 
{
  if(strcmp(datatype, "int")==0) {
	if(id+1 >= argc) {
	  fprintf(stderr, "incomplete input");
	  usage(argv[0]);
	  exit(EXIT_FAILURE);
	}
	*((int*)data)=atoi(argv[id+1]);
  }

  return id+1;
}

struct PARAM{
  int width;
  int height;
};

int main(int argc, char *argv[])
{
  PARAM param;

  if(argc<=1){
	usage(argv[0]);
	exit(EXIT_FAILURE);
  }

  int i;
  while(i < argc)
  {
	if(argv[i][0]=='-') 
	{
	  if(argv[i][1]=='-'){
		// read long options
		if(moreopt(argv[i]))
		  fprintf(stderr,"unknown verbose option : %s\n", argv[i]);
	  }	

	  // read short options
	  switch(argv[i][1])
	  {
		case 'u':
		  usage(argv[0]);
		  exit(EXIT_FAILURE);
	  
		case 'w':
		   i=read_opt(argc, argv, i, &param.width, "int");
		  break;

		case 'h':
		  i=read_opt(argc, argv, i, &param.height, "int");
		  break;
	  }
	}
	i++;
  }

  printf("width %d\n", param.width);
  printf("height %d\n", param.height);

  return (0);
}

