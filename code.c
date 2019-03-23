#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int check_keyword(char arr[]);
int main(){
	char character, arr[15], operators[] = "+-*/%=<>&|:?";
	FILE *fp; //fp is the file pointer
	int i,k=0;
	fp = fopen("ppg.txt","r"); //opening the file in read mode
	if(fp == NULL){
		printf("Cannot open the file.\n");
		exit(0);
	}
	while((character = fgetc(fp)) != EOF){
   		for(i = 0; i < sizeof(operators); i++){
   			if(character == operators[i])
   				printf("%c : operator\n", character);
   		}
   		if(isalnum(character)){
   			arr[k++] = character;
   		}
   		//When a character is passed as an argument, corresponding ASCII value (integer) of the character is passed instead of that character itself.
   		else if((character == ' ' || character == '\n' || character == '('|| character == ')' || character == ',') && (k != 0)){
   				arr[k] = '\0'; // '\0' is null terminator
   				k = 0;

   				if(check_keyword(arr) == 1)
   					printf("%s : keyword\n", arr);
   				else
   					printf("%s : identifier\n", arr);
   		}
	}
	fclose(fp);
	return 0;
}
int check_keyword(char arr[]){
	char keywords[32][10] = {"auto","break","case","char","const","continue","default",
							"do","double","else","enum","extern","float","for","goto",
							"if","int","long","register","return","short","signed",
							"sizeof","static","struct","switch","typedef","union",
							"unsigned","void","volatile","while"};
	int i, check = 0;
	for(i = 0; i < sizeof(keywords[0]); ++i){
		if(strcmp(keywords[i], arr) == 0){
			check = 1;
			break;
		}
	}
	return check;
}
