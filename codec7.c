#include<stdio.h>
void main()
{
    int t,flag=0,fl;
    long long n,i,sum,min,pos;
    scanf("%d",&t);
    while(t--)
    {sum=0;
    flag=0;
    fl=0;
        scanf("%lld",&n);
        long long a[n];
        for(i=0;i<n;++i)
            scanf("%lld",&a[i]);
        for(i=0;i<n;++i)
        {
        if(a[i]==2)
            flag=1;
         if(a[i]==1)
            fl=1;
        }
        if(fl)
            printf("-1\n");
        else if(n==1)
            printf("2\n");
        else if(flag)
        {
             for(i=0;i<n;++i)
            sum=sum+a[i];
            printf("%lld\n",sum);
        }
        else
        {min=a[0];
            for(i=0;i<n;++i)
            {
                if(a[i]<=min)
                  {min=a[i];
                    pos=i;
                  }
            }
            for(i=0;i<n;++i)
            {
                if(i!=pos)
                    sum=sum+a[i];
            }
            sum=sum+2;
            printf("%lld\n",sum);
        }


    }
}
