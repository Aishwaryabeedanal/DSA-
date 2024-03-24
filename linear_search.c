#include<stdio.h>
int linearsearch(int n,int nu[]);
int readfromfile(char*,int[]);
void writetofile(char*,int);
void readarray(int[],int n,FILE*);
void printarray(int[],int n,FILE*);


int main()
{
    int n,search;
    n=readfromfile("input.txt",NULL);
    if(n==0)
    {
        printf("Unable to read data from file\n");
        return 1;
    }
    int nu[n];
    if(readfromfile("input.txt",nu)!=n)
    {
        printf("Unable to read data from file\n");
        return 1;
    }
    search=linearsearch(n,nu);
    writetofile("output.txt",search);
    return 0;
}
void readarray(int nu[],int n,FILE *file)
{
    int i;
    printf("enter the array value:");
    for(i=0;i<n;i++)
    {
        fscanf(file,"%d",&nu[i]);
    }
}
void printarray(int nu[],int n,FILE *file)
{
    int i;
    printf("\narray value are:");
    for(i=0;i<n;i++)
    {
        fprintf(file,"\n%d",nu[i]);
    }
}

int linearsearch(int n,int nu[])
{
    int i,key;
    printf("\nenter the element to be search");
    scanf("%d",&key);
    for(i=0;i<n;i++)
    {
        if(nu[i]==key)
        {
           return i;
        }
    }
    return -1;

}
void writetofile(char*filename,int search)
{
    FILE *file=fopen(filename,"w");
    if(file==NULL)
    {
        fprintf(file,"key element is found");
        return;
    }
    if(search!=-1)
    {
        fprintf(file,"key element is found");
    }
    else
    {
        fprintf(file,"key element not found");
    }

    fclose(file);
    printf("\nsearch result is written to %s\n",filename);
}
int readfromfile(char*filename,int nu[])
{
    FILE *file=fopen(filename,"r");
    if(file==NULL)
    {
        printf("Error opening input file");
        return 0;
    }
    int n;
    fscanf(file,"%d",&n);
    if(nu==NULL)
    {
        fclose(file);
        return n;
    }
    int i=0;
    while(fscanf(file,"%d",&nu[i])!=EOF)
    {
        i++;
    }
    fclose(file);
    return i;
}
