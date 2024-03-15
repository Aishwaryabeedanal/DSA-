#include<stdio.h>
#include<math.h>
#define pi 3.14
int main()
{
    FILE* fp1;
    FILE* fp2;
    char shape[20];
    int area[10];
    int area_count=0;
    fp1=fopen("area_of_shape_input.txt","r");
    fp2=fopen("area_of_shape_output.txt","w");
     while (fscanf(fp1, "%s", shape) != EOF)
    {
    if(strcmp(shape,"Rectangle")==0)
    {
        int l,b;
        printf("Enter length and breadth");
        scanf("%d%d",&l,&b);
        area[area_count++]=l*b;
    }
    if(strcmp(shape,"Circle")==0)
    {
        int r;
        printf("Enter radius");
        scanf("%d",&r);
        area[area_count++]=pi*r*r;
    }
    if(strcmp(shape,"Triangle")==0)
    {
        int b1,h;
        printf("Enter breadth and height");
        scanf("%d%d%d",&b1,&h);
        area[area_count++]=(1.0/2)*b1*h;
    }
    }

    for(int i=0;i<area_count;i++){
    fprintf(fp2,"%d\n",area[i]);
    }
    printf("output has been generated in area_of_shape_output.txt");
    fclose(fp1);
    fclose(fp2);

}
