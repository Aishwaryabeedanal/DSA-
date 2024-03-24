#include<stdio.h>
void fiboncii(int);
void readfromfile(char*,int*);
void writetofile(char*,int);
int main()
{
    int n;
    readfromfile("input.txt",&n);
    fiboncii(n);
    return 0;
}
void fiboncii(int n)
{
    int i,a=0,b=1,next_term;
    FILE *file=fopen("output.txt","w");
    if(file==NULL)
    {
        printf("Error opening input file");
        return;
    }
    for(i=0;i<n;i++)
    {
        fprintf(file,"%d ",a);
        next_term=a+b;
        a=b;
        b=next_term;
    }
    fclose(file);
    printf("Fibonacci series for is written to output.txt\n");
}
void readfromfile(char*filename,int *n)
{
    FILE *file=fopen(filename,"r");
    if(file==NULL)
    {
        printf("Error opening input file");
        return;
    }

    fscanf(file,"%d",n);
    fclose(file);
}

void writetofile(char*filename,int result)
{
    FILE *file=fopen(filename,"w");
    if(file==NULL)
    {
        printf("error opening input file %s",filename);
        return;
    }
    fprintf(file,"d\n",result);
    fclose(file);
     printf("\n results are in written to %s\n",filename);

}
