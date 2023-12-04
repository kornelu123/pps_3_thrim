#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define LINE_SIZE 141

char **lineptr;
char pseudo_line[LINE_SIZE];

void init_lines(){
  lineptr = (char **)malloc(sizeof(char *)*3);
  for(int i=0; i<LINE_SIZE; i++){
     pseudo_line[i] = '.';
  }
  pseudo_line[LINE_SIZE - 2] = '\n';
  pseudo_line[LINE_SIZE - 1] = '\0';
  for(int i=0; i<3; i++){
    lineptr[i] = (char *)malloc(LINE_SIZE*(sizeof(char)));
    memcpy(lineptr[i], &pseudo_line, LINE_SIZE);
  }
}

void move_one_up(){
    memcpy(lineptr[0], lineptr[1], LINE_SIZE);
    memcpy(lineptr[1], lineptr[2], LINE_SIZE);
}

int check_validity(int index, int size, char *num_ch){
    int exp = 1;
    int num = 0;
    for(int i=1; i<size; i++){
      exp *= 10;
    }

    for(int i=0; i<size; i++){
      num += (num_ch[i] - '0')*exp;
      exp /= 10;
    }

    if(index != 0) index--;
    if(index + size + 2 >= LINE_SIZE) size--;
    for(int i=0; i<3; i++){
      for(int j=0; j<size+2; j++){
        if(lineptr[i][index + j] == '.' || (lineptr[i][index + j] <= '9' && lineptr[i][index + j] >= '0') || lineptr[i][index+j] == '\n'){
            continue;
        }
        return num;
      }
    }

    return 0;
}

int parse_line(){
    char num_ch[5];
    int count = 0;
    bool is_num_started = false;
    int i=0;
    int num = 0;
    do{
      if(lineptr[1][i] <= '9' && lineptr[1][i] >= '0'){
        is_num_started = true;
        num_ch[count++] = lineptr[1][i];
      }
      if(is_num_started && (lineptr[1][i] < '0' || lineptr[1][i] > '9')){
        num += check_validity(i - count , count, num_ch);
        is_num_started = false;
        count = 0;
      }
      
      i++;
    }while(lineptr[1][i] != '\n');

    return num;
}

int main(){

  FILE *inp = fopen("../input","r");
  
  ssize_t chars = 0;
  size_t size = 0;
  int sum = 0;
  init_lines();
  char *tmp;
  int count = 0;
  while((chars = getline(&tmp, &size, inp)) >= 0){  
      printf("%s", tmp);
      move_one_up();
      memcpy(lineptr[2], tmp, LINE_SIZE);
      sum += parse_line();
      count++;
  }
  move_one_up();
  memcpy(lineptr[2], pseudo_line, LINE_SIZE);
  sum += parse_line();


  printf("%d\n", sum);
  fflush(stdout);

  

  free(lineptr[0]);
  free(lineptr);
  fclose(inp);
  return 0;
}
