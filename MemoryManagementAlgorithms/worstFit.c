#include<stdio.h>
#define max 7
void main()
{
    int frag[max],b[max],f[max],i,j,blockNumber,files,temp,highest=0;
    static int bf[max],ff[max];
    printf("\nEnter the number of blocks:");
    scanf("%d",&blockNumber);
    printf("Enter the number of files:");
    scanf("%d",&files);
    printf("\nEnter the size of the blocks:-\n");
    for(i=1;i<=blockNumber;i++)
    {
        printf("Block %d:",i);
        scanf("%d",&b[i]);
    }

    printf("Enter the size of the files :-\n");
    for(i=1;i<=files;i++)
    {
        printf("File %d:",i);
        scanf("%d",&f[i]);
    }

    for(i=1;i<=files;i++)
    {
        for(j=1;j<=blockNumber;j++)
        {
            if(bf[j]!=1) //if bf[j] is not allocated
            {
                temp=b[j]-f[i];
                if(temp>=0)
                if(highest<temp)
                {
                    ff[i]=j;
                    highest=temp;
                }
            }
            frag[i]=highest;
            bf[ff[i]]=1;
            highest=0;
        }

        ff[i]=j;
        highest=temp;
    }
    
    printf("\nThe files are allocated in the following blocks:-\n");
    printf("\nFile_no:\tFile_size:\tBlock_no:\tBlock_size:\tFragement");
    for(i=1;i<=files;i++)
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d",i,f[i],ff[i],b[ff[i]],frag[i]);
}