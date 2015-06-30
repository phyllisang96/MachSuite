#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <assert.h>

#include "stencil.h"

int main(int argc, char **argv)
{
  struct bench_args_t data;
  int i, fd;

  // Fill data structure
  srand(1);
  for(i=0; i<row_size*col_size; i++)
    data.orig[i] = rand()%(MAX-MIN) + MIN;
  for(i=0; i<f_size; i++)
    data.filter[i] = rand()%(MAX-MIN) + MIN;

  // Open and write
  fd = open("input.data", O_WRONLY|O_CREAT|O_TRUNC, S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH);
  assert( fd>0 && "Couldn't open input data file" );
  data_to_input(fd, (void *)(&data));

  return 0;
}
