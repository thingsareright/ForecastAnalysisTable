int top = 0;
char stack[200];
int x;
void Judge() 
{
	stack[0] = '#';	//把'#'压栈
	stack[1] = form[0].formula[0];	//把开始符入栈
	int flag = 1, step = 0;
	int i,j,l;
	char print[100];
	top = 1;
	x = 0;
	for(l=0; l<=top; l++)
		printf("%c", stack[l]);
	printf("\n");				

	//这里其实是在一行里以比较整齐的形式输出了栈里和输入串尚未被匹配的值
	while(flag)
	{


		if(get_non(stack[top]) >= 0)
		{
			//如果分析栈栈顶是终结符，那么进行比对
			if(stack[top] == inter_symbol[x])
			{
				x ++;	//终结符匹配上了
				top --;
				int step = 0;	//输出格式用
				for(l=0;l<=top;l++){
					printf("%c", stack[l]);
					step ++;
				}
				for(step;step<=12;step++)
					printf(" ");

				step = 0;
				for(l=x;l<=sizeOfString(inter_symbol);l++){
					printf("%c", inter_symbol[l]);
					step ++;
				}
				for(step;step<=12;step++)
					printf(" ");
				printf("\n");
			} else {
				break;	//其实吧，就是错了，终结符没对上
			}
		}
		else if(stack[top] == '#') 
		{
			if(stack[top] == inter_symbol[x])
				flag = 0;
			else 
				break;
		}	
		else 
		{

			int col = get_ter(stack[top]);
			int row = get_non(inter_symbol[x]);
			if(inter_symbol[x] == '#')
				row = sizeOfString(non_ter);
			if(M[col][row] >= 0){
				if(form[M[col][row]].formula[3] == '$'){
					top --;
				}
				else 
				{
					//显示要代替的字符串
					printf("%s\n", form[M[col][row]].formula);
					//将要代替的字符串逆序入栈
					for(i = sizeOfString(form[M[col][row]].formula)-2; i>=3;i--)
					{
						stack[top++] = form[M[col][row]].formula[i];
					}
					top --;
				}
				
				
			}else {
				break;
			}
		}
	}
	if(flag){
		printf("匹配失败！");
	}
	else {
		printf("匹配成功！\n");
	}
}