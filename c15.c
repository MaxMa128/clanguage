#include<stdio.h>

int main(int argc,char** argv)
{
	int k=0,i=0,j=0;
	char c;
	FILE *f1,*f2;
	if(argc!=3)
		return 1;
	f2=fopen(argv[2],"w");
	f1=fopen(argv[1],"r");
	if(f1==NULL)
		return 1;
 	c=fgetc(f1);
	while(!feof(f1))
	{
		while(c==' '&&!feof(f1))
		{
            j++;
	   		c=fgetc(f1);
	  	}
	  	if(!feof(f1)&&c!='\n')
	  	{
			while(c!=' '&&c!='\n'&&!feof(f1))
		  	{
		   		j++;
		   		c=fgetc(f1);
		  	}
		  	k++;
	  	}
            if(feof(f1)||c=='\n')
			{
				if(!feof(f1))
				{
					j++;
					c=fgetc(f1);
				}
				i++;
			}               
	}
	fclose(f1);
	fprintf(f2,"%d %d %d",i,k,j);
	fclose(f2);
	return 0;
}
