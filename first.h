//求一个非终结符的FIRST集
int getFirst(char a, int col) {
	int i,j,k=1,l,p;
	for (i = 0; i < sum; ++i)
	{
		if(form[i].formula[0] == a){
			for(j=0; j<sizeOfString(non_ter);j++){
				if(form[i].formula[3] == non_ter[j]){
					break;
				}
			}
			//判断是否是终结符，是的话加入FIRST集
			if(j<sizeOfString(non_ter)){
				if(is_sameFir(col,k,form[i].formula[3])){
					first_set[col][k++]=form[i].formula[3];
				}
				continue;
			} else if(form[i].formula[3] == '$') {
				if(is_sameFir(col,k,'$'))
					first_set[col][k++] = '$';
				continue;
			}
			else if(form[i].formula[3] == a){
				continue;
			}
			else {
				for(l=3; l<sizeOfString(form[i].formula); l++){
					for(j=0; j<sizeOfString(ter_symbol);j++){
						if(form[i].formula[l] == ter_symbol[j])
							break;
					}
					if(j == sizeOfString(ter_symbol)){
						if(is_sameFir(col,k,form[i].formula[l]))
							first_set[col][k++] = form[i].formula[l];
						break;
					}

					if(first_set[j][0] == '0'){
						getFirst(form[i].formula[l],j);
					}

					int flag = 0;	//为0表示这个接下去的first集里无$,否则有
					for(p=1; p<sizeOfString(first_set[j]);p++){
						if (first_set[j][p] == '$')
						{
							flag = 1;
						}
						if(is_sameFir(col,k,first_set[j][p])){
							first_set[col][k++] = first_set[j][p];
						}
					}
					if(flag == 0){
						break;	//如果上面的那个FIRST集无空，则跳出
					}
				}

			}
		}
	}
	first_set[col][k] = '\0';	//标志FIRST集结束
	first_set[col][0] = 1;	//标志已经球队的FIRST集
	return 0;
}

void First(){
	int i, len_ter = sizeOfString(ter_symbol);
	for(i = 0; i<len_ter; i++)
		first_set[i][0] = '0';
	for(i=0; i<len_ter; i++){
		if(first_set[i][0] == '0')
			getFirst(ter_symbol[i],i);
	}
}