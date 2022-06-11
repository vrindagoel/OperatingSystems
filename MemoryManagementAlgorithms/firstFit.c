#include<stdio.h>
#define max 7
void main()
{
    int frag[max],b[max],f[max],i,j,blockNumber,files,temp;
    static int bf[max],ff[max];
    printf("\n\tMemory Management Scheme - First Fit");
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
            if(bf[j]!=1)
            {
                temp=b[j]-f[i];
                if(temp>=0)
                {
                    ff[i]=j;
                    break;
                }
            }
        }
        frag[i]=temp; bf[ff[i]]=1;
    }

    printf("\nFile_no:\tFile_size :\tBlock_no:\tBlock_size:\tFragement");
    for(i=1;i<=files;i++)
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d",i,f[i],ff[i],b[ff[i]],frag[i]);

}