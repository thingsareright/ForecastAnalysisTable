/**
用于展示FIRST集，FOLLOW集和预测分析表
*/

/**
展示FIRST集
*/
void showFirst()
{
	int length = sizeOfString(ter_symbol);	//非终结符的长度
	int i = 0;
	for(i=0; i<length; i++){
		int j = 0;
		printf("%c的FIRST集是：", ter_symbol[i]);
		for(j=1; j<sizeOfString(first_set[i]); j++){
			printf("%c ", first_set[i][j]);
		}
		printf("\n");
	}
}


/**
展示FOLLOW集
*/
void showFollow()
{
	int length = sizeOfString(non_ter);
	int i = 0;
	for(i=0; i<length; i++){
		int j = 0;
		printf("%c的FOLLOW集是：", non_ter[i]);
		for(j=1; j<sizeOfString(follow_set[i]); j++){
			printf("%c ", follow_set[i][j]);
		}
		printf("\n");
	}
}

/**
展示预测分析表
*/
void showForecast()
{
	int i,j;
	//输出表头
	printf("        ");
	for(i=0; i<sizeOfString(non_ter)+1;i++)	//注意还有一个'#'
	{
		if(sizeOfString(non_ter) == i){
			printf("%-8c",'#');
		}
		printf("%-8c", non_ter[i]);
	}
	printf("\n");
	//输出每个终结符对应的预测分析表
	for(i=0; i<sizeOfString(ter_symbol); i++){
		printf("%-8c", ter_symbol[i]);
		for(j=0; j<sizeOfString(non_ter);j++)
		{
			if(-1 == M[i][j])
				printf("        ");
			else if(j <= sizeOfString(non_ter))
			{
				printf("%-8s", form[M[i][j]].formula);
			}
		}
		printf("\n");
	}
}