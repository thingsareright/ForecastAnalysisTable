#include "head.h"
#include "apart_from.h"
#include "first.h"
/*
#include "follow.h"
#include "table.h"
#include "judge.h"*/

int main(int argc, char const *argv[])
{
	int i = 0;
	while((scanf("%s", form[i].formula),form[i].formula[0]!='#')){
		i ++;
	}
	sum = i;
	apart();
	for (i=0; i<sizeOfString(ter_symbol);++i)
	{
		printf("%c ", ter_symbol[i]);
	}
	for (i=0; i<sizeOfString(non_ter);++i)
	{
		printf("%c ", non_ter[i]);
	}

	First();
	int j;
	for(i = 0; i<sizeOfString(ter_symbol); i++){
		for(j=1;j<sizeOfString(first_set[i]);j++){
			printf("%c ", first_set[i][j]);
		}
		printf("\n");
	}
/*	Follow();
	printf("非终结符；\n");
	printf("%s\n", ter_symbol);
	printf("终结符：\n");
	printf("%s\n",non_ter);

	getTable();
	printf("输入串（以'#'号键结束):\n");
	scanf("%s", inter_symbol);
	while(inter_symbol[strlen(inter_symbol)-1]!='#'){
		std::cout << "输入串没有以'#'结束，请重新输入：\n" << std::endl;
		std::cin >> inter_symbol;
	}
	Judge();*/
	return 0;
}