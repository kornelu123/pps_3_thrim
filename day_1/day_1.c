#include <stdio.h>
#include <stdlib.h>
#include <error.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#define LETTER_COUNT 9
#define LETTER_OFFSET 1

char *letters[] = {
	"one",
	"two", 
	"three",
	"four",
	"five",
	"six",
	"seven",
	"eight",
	"nine"
};

int letter_count[9];
int max_count[9];

void clear_letter_count(){
	for(int i=0; i<LETTER_COUNT;i++){
		letter_count[i] = 0;
	}
}

void count_init(){
	for(int i=0; i<LETTER_COUNT; i++){
		max_count[i] = strlen(letters[i]);
	}
	clear_letter_count();
}

char handle_letter(char ch){
	for(int i=0; i<LETTER_COUNT;i++){
		if(ch == letters[i][letter_count[i]]){
			letter_count[i]++;
		}else{
			letter_count[i] = 0;
		}
		if(letter_count[i] == max_count[i]){
			return '0' + i + LETTER_OFFSET;
			letter_count[i] = 0;
		}
	}
	return 0;
}

int main(){
	count_init();
	FILE *inp;
	
	inp = fopen("input", "r");
	if(inp == NULL){
		exit(1);
	}
	
	char *lineptr = NULL;
	
	size_t size = 0;
	ssize_t chars;
	int sum = 0;
	int count = 0;
	while((chars = getline(&lineptr, &size, inp)) >=0){

		int i=0;
		int last = 0, first = 0;
		bool is_first = true;
		do{
			char num;
			if((num = handle_letter(lineptr[i])) != 0){
				lineptr[i] = num;
			}
			if(lineptr[i] <= '9' && lineptr[i] >= '1'){
				if(is_first){
					first = -'0' + lineptr[i] ;
					is_first = false;
				}
				last = -'0' + lineptr[i];
			}
			i++;
		}while(lineptr[i] != '\n');
		sum += first*10 + last;
		clear_letter_count();
		printf("%d. %s \n %d%d\n\n", count++, lineptr, first, last);  
	}
	printf("sum is %d", sum);
	fflush(stdout);
	free(lineptr);
	fclose(inp);
	return 0;
}
