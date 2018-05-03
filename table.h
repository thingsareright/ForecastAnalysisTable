//这个算法，用于生成预测分析表
//ter_symbol 非终结符号
//non_ter  终结符号
void getTable() 
{
	int i,j,k,col,row,flag=0;
	//初始化M这个预测分析表
	for(i=0; i<sizeOfString(ter_symbol);i++){
		for(j=0;j<sizeOfString(non_ter)+1;j++){	//这里面这个加1，是为了给'#'预留空间
			M[i][j] = -1;
		}
	}

	for(i=0;i<sum;i++)
	{
		flag = 0;
		//产生式（对应课本上的候选式）的右部首字符为终结符
		if(0 <= (row = get_non(form[i].formula[3])))
		{
			col = get_ter(form[i].formula[0]);
			M[col][row]=i;
		}
		else if((row=get_non(form[i].formula[3])) == -1) {
			//候选时右部为非终结符和空时
			col = get_ter(form[i].formula[0]);
			k = get_ter(form[i].formula[3]);
			if(0 <= k){
				//如果右部首符为非终结符而不是空
				for(j=1; j<sizeOfString(first_set[k]); j++){
					if(first_set[k][j] == '$'){
						flag = 1;
						continue;
					}
					row = get_non(first_set[k][j]);
					M[col][row] = i;
				}
			}
			if(1 == flag)
			{
				//如果只是因为第一个非终结符的FIRST集含空，那么可能会有两种情况:
				//1. 这个候选式的FIRST集含空；
				//2. 不含。
				int j = 0;
				for(j=4; i<sizeOfString(form[i].formula);i++){
						if(get_non(form[i].formula[j]) > 0){
							M[col][get_non(form[i].formula[j])] = i;
							break;
						}
						if (get_ter(form[i].formula[j]))
						{
							//如果右部首符为非终结符而不是空
							for(j=1; j<sizeOfString(first_set[get_ter(form[i].formula[j])]); j++){
								if(first_set[get_ter(form[i].formula[j])][j] == '$'){
									flag = 1;
									continue;
								}
								row = get_non(first_set[get_ter(form[i].formula[j])][j]);
								M[col][row] = i;
							}
						}
					}
				}
				
			}
			if('$' == form[i].formula[3])
				flag = 1;

			if(1 == flag) {
				for(j=1; j<sizeOfString(follow_set[col]); j++){
					for(j=1;j<sizeOfString(follow_set[col]);j++){  
      					if(follow_set[col][j]=='#')  //我把'#'这个东西的下标定义为终结符的长度，这也是上面为什么rol ++ (初始化的时候)
      						row=sizeOfString(non_ter);  
      					else row=get_non(follow_set[col][j]);  
      						M[col][row]=i;  
				}
			}
		}
	}
}