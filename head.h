#include <stdio.h>

#define  MAX  100	
typedef struct {
	char formula[MAX] ;	//表达式
} grammerElement;	//产生式

grammerElement form[MAX] ;	//原始文法的产生式集合

int sum = 0;
char ter_symbol[MAX] = {0};	//非终结符号
char non_ter[MAX] = {0};	//终结符号
char inter_symbol[MAX] = {0};	//输入符号
char first_set[MAX][MAX] = {0};	//各产生式右部的FIRST集
char follow_set[MAX][MAX] = {0};	//各产生式左部的FOLLOW集
int M[MAX][MAX] = {0};	//分析表

//判断有效字符的个数
int sizeOfString(char * p) {
	int i = 0;
	for (i = 0; p[i] != '\0'; ++i);
	return i;
}

/**
* 判断一个字符是否是非终结符，其实是通过遍历的形式寻找的
* 如果找到的话返回其数组下标，否则返回-1
*/
int get_ter(char a) {
	for (int i = 0; i < sizeOfString(ter_symbol); ++i)
	{
		if (ter_symbol[i] == a)
		{
			return i;
		}
	}
	return -1;
}
/**
* 判断一个字符是否是终结符，其实是通过遍历的形式寻找的
* 如果找到的话返回其数组下标，否则返回-1
*/
int get_non(char a) {
	for (int i = 0; i < sizeOfString(non_ter); ++i)
	{
		if (non_ter[i] == a)
		{
			return i;
		}
	}
	return -1;
}


/**
* 判断将要加入的first集的终结符是否已经存在
* 如果已经存在，那么返回0
* 如果没有存在，那么返回1
*/
int is_sameFir(int col, int stop, char a) {
	for (int i = 0; i < stop; ++i)
	{
		if (first_set[col][i] == a)
		{
			return 0;
		}
	}
	return 1;
}

/**
* 判断将要加入的follow集的终结符是否已经存在
* 如果已经存在，那么返回0
* 如果没有存在，那么返回1
*/
int is_sameFol(int col, int stop, char a) {
	for (int i = 0; i < stop; ++i)
	{
		if (follow_set[col][i] == a)
		{
			return 0;
		}
	}
	return 1;
}

//打印预测分析表
void printTable(){
	for (int i = 0; i < sizeOfString(ter_symbol); ++i)
	{
		for (int j = 0; j < sizeOfString(non_ter); ++j)
		{
			printf("%c ", M[i][j]);
		}
	}
}