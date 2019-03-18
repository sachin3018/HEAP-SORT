#include<stdio.h>
void Aheapfy(int a[],int n,int i)
{
    int largest=i,l=2*i+1,r=2*i+2;
    if(l<=n && a[l]>a[largest])
        largest=l;
    if(r<=n && a[r]>a[largest])
        largest=r;
    if(largest==i)
        return ;
    else
    {
        int temp=a[i];
        a[i]=a[largest];
        a[largest]=temp;

        Aheapfy(a,n,largest);
    }

}
void Aheapsort(int a[],int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
     Aheapfy(a, n, i);
    for(int i=n-1;i>=0;i--)
    {   int j=i;
        int temp=a[0];
        a[0]=a[i];
        a[j]=temp;
        Aheapfy(a,--j,0);
    }
}
void Dheapfy(int a[],int n,int i)
{
    int smallest=i,l=2*i+1,r=2*i+2;
    if(l<=n && a[l]<a[smallest])
        smallest=l;
    if(r<=n && a[r]<a[smallest])
        smallest=r;
    if(smallest==i)
        return ;
    else
    {
        int temp=a[i];
        a[i]=a[smallest];
        a[smallest]=temp;

        Dheapfy(a,n,smallest);
    }

}
void Dheapsort(int a[],int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
     Dheapfy(a, n, i);
    for(int i=n-1;i>=0;i--)
    {   int j=i;
        int temp=a[0];
        a[0]=a[i];
        a[j]=temp;
        Dheapfy(a,--j,0);
    }
}
void dispalay(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d   ",a[i]);
    }
}
int main()
{
    int n,choice;
    printf("enter the no of element :\t");
    scanf("%d",&n);
    int a[n];
    printf("enter the tree element :\t");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    do
    {
        printf("enter the choice:\n");
        printf("0 to exite\n");
        printf("1 to asscending order\n");
        printf("2 for desending order\n");
        scanf("%d",&choice);
        switch (choice)
        {
            case 0 :printf("exiting the programe\n");break;
            case 1: Aheapsort(a,n);
                    dispalay(a,n);break;
            case 2: Dheapsort(a,n);
                    dispalay(a,n);break;
            default: printf("enter valid choice\n");break;
        }
    } while (choice!=0);
}
