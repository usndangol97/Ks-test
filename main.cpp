#include<stdio.h>
#include<stdlib.h>

float maxx(float x[],int k)
{
	int i;
	float t;
	t=x[0];
	for(i=1;i<k;i++)
        {
		if(x[i]>t)
			t=x[i];
	}
	return t;
}

float maximum(float a,float b)
{
    if(a>b)
        return a;
    else
        return b;
}

int sort_arr(float number[],int n)
{
    int i,j;
    float z;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (number[i] > number[j])
            {
                z =  number[i];
                number[i] = number[j];
                number[j] = z;
            }
        }
    }
}

int main()
{
    int n,i;
    float ar[20],ary1[20],ary2[20];
    float d_tab,d_cal,d_min,d_max,a,b;
    printf("Enter number of random numbers you want: ");
    scanf("%d",&n);
    printf("Enter random numbers: ");
    for(i=0;i<n;i++)
    {
        scanf("%f",&ar[i]);
    }
    printf("Enter tabulated value of d: ");
    scanf("%f",&d_tab);
    sort_arr(ar,n);
    printf("i\t(i/n)\t(i-1/n)\tRi\ta-Ri\tRi-b\n");
    for(i=1;i<=n;i++)
    {
        a=(float)i/n;
        b=(float)(i-1)/n;
        ary1[i-1]=a-ar[i-1];
        ary2[i-1]=ar[i-1]-b;
        printf("%d\t%0.4f\t%0.4f\t%0.4f\t%0.4f\t%0.4f\n",i,a,b,ar[i-1],ary1[i-1],ary2[i-1]);
    }
    d_min=maxx(ary1,n);
    d_max=maxx(ary2,n);
    d_cal=maximum(d_min,d_max);
    if(d_tab>d_cal)
    {
        printf("\nWe accept the null hypothesis H0.");
    }
    else
    {
        printf("\nWe reject the null hypothesis H0.");
    }
}
