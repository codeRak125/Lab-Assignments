#include <stdio.h>
#include <math.h>
#include <stdlib.h>
struct stack
{
    int top1, top2;
    int *ar;
};
struct stack xy;

void pushst1(int qwe)
{
    xy.ar[xy.top1] = qwe;
    xy.top1++;
}

void pushst2(int qwe)
{
    xy.ar[xy.top2] = qwe;
    xy.top2--;
}

void pop1()
{
    xy.top1--;
    xy.ar[xy.top1] = 0;
}

void pop2()
{
    xy.top2++;
    xy.ar[xy.top2] = 0;
}

float mean(int *arr, int M)
{
    int i, sum = 0, count = 0;
    for (i = 0; i < M; ++i)
        if (arr[i] != 0)
        {
            sum += arr[i];
            count++;
        }
    return (float)sum / count;
}

float median(int *arr , int M)
{
    float median=0;
    
    
    if(M%2 == 0)
        median = (arr[(M-1)/2] + arr[M/2])/2.0;

    else
        median = arr[M/2];
    
    return median;
}
float mode(int *arr , int M) 
{
   float maxValue = 0, maxCount = 0;
   int i, j;

   for (i = 0; i < M; ++i) 
   {
      int count = 0;
      
      for (j = 0; j < M; ++j) 
	  {
         if (arr[j] == arr[i])
         ++count;
      }
      
      if (count > maxCount) 
	  {
         maxCount = count;
         maxValue = arr[i];
         
      }
   }

   return maxValue;
}
float standard_Deviation(int *arr, int M)
{
    float mean=0.0, sum_deviation=0.0;
    int i;
    for(i=0; i<M;++i)
    {
        mean+=arr[i];
    }
    mean=mean/M;
    for(i=0; i<M;++i)
    sum_deviation+=(arr[i]-mean)*(arr[i]-mean);
    return sqrt(sum_deviation/M);           
}

int main()
{
    int N, M;
	int a, b, qwe, i;
    scanf("%d %d", &N, &M);
    int *arr;
    arr = (int *)malloc(M * sizeof(int));
    xy.top1 = 0;
    xy.top2 = N - 1;
    xy.ar = (int *)malloc(N * sizeof(int));
    
	
	for (i = 0; i < N; ++i)
    {
        xy.ar[i] = 0;
    }
    
	
	for (i = 0; i < M; ++i)
    {
        arr[i] = 0;
    }
    
	
	for (i = 0; i < M; ++i)
    {
        scanf("%d %d %d", &a, &b, &qwe);
        if(qwe!=-1)
        	arr[i] = qwe;
        if (a == 1 && b == 1)
            pushst1(qwe);
        else if (a == 1 && b == 2)
            pushst2(qwe);
        else if (a == 2 && b == 1)
            pop1();
        else if (a == 2 && b == 2)
            pop2();
    }
    printf("%.1f %.2f %.1f %.2f\n", mean(arr, M), median(arr, M), mode(arr, M), standard_Deviation(arr, M));
    
   
   
    for(i=xy.top1-1;i>=0;--i)
    {
    	if (xy.ar[i]==0)
    		break;
    	printf("%d ", xy.ar[i]);
    	pop1();
	}
	printf("\n");


	for(i=xy.top2+1;i<=N-1;++i)
	{
		if(xy.ar[i]==0)
			break;
		printf("%d ", xy.ar[i]);
		pop2();
	}
    return 0;
}
