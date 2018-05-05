#include "head.h"
#include "apart_from.h"
#include "first.h"
#include "follow.h"
#include "table.h"
#include "judge.h"
#include "show.h"

int main(int argc, char const *argv[])
{
	int i = 0,j;
	while((scanf("%s", form[i].formula),form[i].formula[0]!='#')){
		i ++;
	}
	sum = i;
	apart();
	
	First();
	
	Follow();
	printf("非终结符；\n");
	printf("%s\n", ter_symbol);
	printf("终结符：\n");
	printf("%s\n",non_ter);
	
	printf("\n");
	
	printf("\n");
	getTable();
	
	scanf("%s", inter_symbol);
	printf("\n");
	showFirst();
	printf("\n");
	showFollow();
	printf("\n");
	showForecast();
	printf("\n");
	Judge();
	return 0;
}
