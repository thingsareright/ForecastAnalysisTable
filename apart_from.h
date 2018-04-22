#ifndef __HEAD_H__
#define __HEAD_H__
#endif


void apart(){
	int i = 0, len = 0, k = 0, j = 0, l = 0, p = 0;
	for (i = 0; i < sum; ++i)
	{
		for (j = 0; j < k; ++j)
		{
			if (ter_symbol[j] == form[i].formula[0])	//先检查是否已被加入非终结符序列
			{
				break;
			}
		}
		if (j == k)
			{
				ter_symbol[k++] = form[i].formula[0];
			}
	}
	ter_symbol[k] = '\0';

	k = 0;
	for (i = 0; i < sum; ++i)
	{
		len = sizeOfString(form[i].formula);
		for(j = 3; j < len; j++){
			if (form[i].formula[j] == '$')	//检查是否已经到了输入的结尾
			{
				break;
			}
			for(l =0; l < sizeOfString(ter_symbol); l++){		//检查是否已经加入了非终结符
				if (form[i].formula[j] == ter_symbol[l])
				{
					break;
				}
			}
			for(p = 0; p<k; p++){				//在没有加入非终结符的情况下判断是否是终结符才是有意义的
				if (form[i].formula[j] == non_ter[p])
				{
					break;
				}
			}
			if (l == sizeOfString(ter_symbol) && p == k)
			{
				non_ter[k++] = form[i].formula[j];
			}
		}
		non_ter[k] = '\0';
	}
}

/**

这个函数主要是分离出终结符和非终结符，我假设一个文法产生式是类似如下形式的：
A->a$
我们可以发现，这条输入串的下标为0的字符是一个终结符，下标为3以及以后的字符是非终结符或者终结符，文法以'$'结尾
*/