#include<windows.h>
#include<stdio.h>
#include<string.h>
#define max 2000
#define sleep(x) Sleep(10*x)
char per[max][50];                //a 2D array to store permutations
int k=0;                        //indices for the permutation array
int permute(char[],int,int);    //permute function
void lexisort();                //alphabetical order sort function
void frequency();         //swapping function

int main()
{
    FILE *fp;                   //file pointer for file operations
    char c,str[100],fname[20];    //fname for file name
    int i=0,len=0,tot=0;              //i is index for string str
    printf("Enter filename");   //entering a file name
    gets(fname);
    fp=fopen(fname,"r");        //opening file in read mode
    while((c=getc(fp))!=EOF)    //read till . is not encountered
    {
        if(c!=' ')
        {
            str[i]=c;       //put the character in str index
                i++;            //incrementing indexes

        }
        else                    //as soon as enter is encountered
        {   str[i]='\0';        //put null at the index of enter
            //len=strlen(str);    //find the string length
            strcpy(per[k],str);
            //printf("%s ",per[k]);
            tot++;
            k++;
            i=0;

        }
    }
    str[i]='\0';        //put null at the index of enter
            //len=strlen(str);    //find the string length
            strcpy(per[k],str);
            tot++;
            //printf("%s ",per[k]);
    printf("\nThe total words = %d \n",k);
    fclose(fp);

    lexisort();
    for(i=0;i<=k;i++)
    printf("%s ",per[i]);

    frequency();
}

/* Lexical sort function that uses bubble sort to sort different strings as per alphabetical order */
void lexisort()
{
    int i=0,j=0;                //variables for loops
    char t[50];                  //a temporary string
    for(i=1;i<=k;i++)            //starting loop for total passes
        for(j=1;j<=k;j++)        //loop for comparing
        {


            if(strcmp(per[j-1],per[j])>0)
            {
                strcpy(t,per[j-1]);
                strcpy(per[j-1],per[j]);
                strcpy(per[j],t);
            }

        }
}


void frequency()
{
FILE *fp;
fp=fopen("output.txt","w+a");
int pos=0,i=0,c=1,j=0;
for(i=pos;i<=k;)
{
    for(j=i+1;j<=k;j++)
    {   //printf("\n%s %s",per[i],per[j]);
        if(strcmpi(per[i],per[j])==0)
        {
               c=c+1;
               //np=np+1;
        }
    }
    if(c>1)
    {       sleep(10);
            printf("\n%s ----- %d ",per[i],c);
    i=i+c;
    c=1;

    }
    else
    {   sleep(10);
        printf("\n%s ----- 1",per[i]);
    i=i+1;
    c=1;
    }


}
fclose(fp);

}

