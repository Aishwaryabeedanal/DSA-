#include<stdio.h>
int main()
{
    FILE* fp1;
    FILE* fp2;
    int n;
    int factorial=1;
    fp1=fopen("factorial_input.txt","r");
    fp2=fopen("factorial_output.txt","w");
    fscanf(fp1,"%d",&n);
    for(int i=n;i>0;i--)
    {
        factorial=factorial*i;
    }
    fprintf(fp2,"%d",factorial);
    printf("output has been generated in factorial_output.txt");
    fclose(fp1);
    fclose(fp2);

}
