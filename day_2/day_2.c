#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define RED   0
#define GREEN 1
#define BLUE  2

int color_size[3] = {
  12,
  13,
  14
};

bool is_valid = true;

const char *beg = "Game \n";

int main(){
  FILE *inp = fopen("input","r");

  char *lineptr;

  size_t size = 0;
  ssize_t chars = 1;
  int sum = 0;
  while((chars = getline(&lineptr, &size, inp)) >= 0){
      int i;
      for( i=0; lineptr[i] == beg[i];i++);
      int count=0;
      int id = 0;
      char id_ch[4];
      int exp = 1;
      while(lineptr[i] != ':'){
        id_ch[count++] = lineptr[i++];
        exp *= 10;
      }
      exp /= 10;
      for(int j=0; exp != 0; j++){
          id += (id_ch[j] - '0')*exp;
          exp /= 10;
      }
      count = 0;
      exp = 1;
      printf("%s", lineptr);
      for(int i=0; i<3; i++){
          color_size[i] = 0;
      }
      while(lineptr[i] != '\n'){
          if(lineptr[i] <= '9' && lineptr[i] >= '0'){
              id_ch[count++] = lineptr[i++];
              exp *= 10;
              continue;
          }
          count = 0;
          if(lineptr[i] == 'r' && lineptr[i+1] == 'e' && lineptr[i+2] == 'd'){
              exp /= 10;
              int val = 0;
              for(int j=0; exp != 0; j++){
                  val += (exp * (id_ch[j] - '0'));
                  exp /=10;
              }
              exp = 1;
              if(val > color_size[RED]){
                      color_size[RED] = val;
              }
          }
          if(lineptr[i] == 'g' && lineptr[i+1] == 'r' && lineptr[i+2] == 'e' && lineptr[i+3] == 'e' && lineptr[i+4] == 'n'){
              exp /= 10;
              int val = 0;
              for(int j=0; exp != 0; j++){
                  val += (exp * (id_ch[j] - '0'));
                  exp /=10;
              }
              exp = 1;
              if(val > color_size[GREEN]){
                      color_size[GREEN] = val;
              }
          }
          if(lineptr[i] == 'b' && lineptr[i+1] == 'l' && lineptr[i+2] == 'u' && lineptr[i+3] == 'e' ){
              exp /= 10;
              int val = 0;
              for(int j=0; exp != 0; j++){
                  val += (exp * (id_ch[j] - '0'));
                  exp /=10;
              }
              exp = 1;
              if(val > color_size[BLUE]){
                      color_size[BLUE] = val;
              }
          }

          i++;
      }
      sum += color_size[BLUE]*color_size[GREEN]*color_size[RED];
  }
  printf("sum is %d", sum);
  fflush(stdout);
  free(lineptr);
  fclose(inp);
  return 0;
}
