
/*
* a表示要求follow集的字符，col指的是其在非终结符序列里的位置
*/
int getFollow(char a, int col) 
{
	int i,j,len,k=1,p,l,flag;
	if(col == 0)
		k = 2;	//这是因为开始符的FOLLOW集里已经预先压进去了个'#'
	//遍历每一个候选式
	for(i=0; i<sum; i++) 
	{
		len = sizeOfString(form[i].formula);
		flag = 0;	//用来标志此字符后面是否出现了一个FIRST集含有一步斯诺的非终结符

		for(j=3;j<len-1;j++)	//注意去掉最后的'$'
		{
			//下面开始遍历每一个候选式的右部字符
			
			if(form[i].formula[j] == a)
			{
				if(j<len-2){
					//当前字符不是最后一个字符时，向后遍历
					for(p=0; p<sizeOfString(ter_symbol);p++)
					{
						if(form[i].formula[j+1] == ter_symbol[p] )
							break;
					}
					if(p == sizeOfString(ter_symbol) )
					{
						if(is_sameFol(col,k,form[i].formula[j+1]) && form[i].formula[j+1] != '$')
							follow_set[col][k++] = form[i].formula[j+1];
						continue;
					}
					else
					{
						for(l=1;l<sizeOfString(first_set[p]); l++)
							if('$' == first_set[p][l])
								flag = 1;
							else if(is_sameFol(col,k,first_set[p][l]))
									follow_set[col][k++] = first_set[p][l];
						//这时候说明这个字符后面跟的是个非终结符
						int now = j + 1;
						while(++now < len-1 && 1 == flag){

							flag = 0;
							for(p=0; p<sizeOfString(ter_symbol);p++)
							{
								if(form[i].formula[now] == ter_symbol[p])
								break;
							}
							//当前字符是终结符时退出
							if(p == sizeOfString(ter_symbol)){
								if(is_sameFol(col,k,form[i].formula[now]) && form[i].formula[now] != '$'){
									follow_set[col][k++] = form[i].formula[now];
								}
								break;
							}
							if(ter_symbol[p] == a)
								break;
							for(l=1;l<sizeOfString(first_set[p]); l++)
								if(first_set[p][l] == '$')
									flag = 1;
								else if(is_sameFol(col,k,first_set[p][l]) )
									follow_set[col][k++] = first_set[p][l];
						}
							
						
					}

				}
				else if(j==len-2 || ((j==len-3)&&(flag)))
				{
					p = get_ter(form[i].formula[0]);
					if(a ==  form[i].formula[0])
						break;
					if(follow_set[p][0] == '0'){
						getFollow(ter_symbol[p],p);
					}
					for(l=1; l<sizeOfString(follow_set[p]); l++){
						if(is_sameFol(col,k,follow_set[p][l]))
							follow_set[col][k++] = follow_set[p][l];
					}
				}


			}	
		}
	}	
	if(sizeOfString(follow_set[col]) > 1){
		follow_set[col][0] = '1';
	}
	follow_set[col][k] = '\0';
	return 0;
}

void Follow(){
	int i;
	for(i=0;i<sizeOfString(ter_symbol);i++){
		follow_set[i][0] = '0';
	}
	//follow_set[0][0] = 1;
	follow_set[0][1] = '#';
	for(i=0; i<sizeOfString(ter_symbol); i++){
		if(follow_set[i][0] == '0')
			getFollow(ter_symbol[i],i);
	}
}