#include "head.h"
#include "apart_from.h"
#include "first.h"

#include "follow.h"

#include "table.h"

#include "judge.h"


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
	printf("C的终结符：\n");
	int k = get_ter('C');
	printf("C的FIRST集\n");
	for(i=0; i<sizeOfString(first_set[k]); i++)
		printf("%c ", first_set[k][i]);
	k = get_ter('C');
	printf("\n");
	printf("C的FOLLOW集\n");
	for(i=0; i<sizeOfString(follow_set[k]); i++)
		printf("%c ", follow_set[k][i]);
	printf("\n");
	getTable();
	for (i = 0; i < sizeOfString(ter_symbol); ++i)
	{
		for (j = 0; j < sizeOfString(non_ter) + 1; ++j)
		{
			printf("%d ", M[i][j]);
		}
		printf("\n");
	}
	scanf("%s", inter_symbol);
	Judge();
	return 0;
}