#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() 
{
	int input, i, j, m ,cheak=0, l = 0, k = 1, num=1;
	int arr[10][10];
	int sum = 0, arr1 = 0;
	scanf("%d", &input);

	for (i = 0; i < input; i++)
	{
		for (j = k-1; j < input-k+1; j++)
		{	
			arr[i][j] = num;
			num++;

			if (num > input * input)
			{
				goto re;
			}

		}
		for (j = k; j <= input - k; j++)
		{
			arr[j][input - 1-i] = num; 
			num++;
			
			if (num > input * input)
			{
				goto re;
			}
		}
		for (j = input - k-1; j >= i; j--)
		{
			arr[input-1-i][j] = num;
			num++;
			
			if (num > input * input)
			{
				goto re;
			}
		}
		for (j = input -k-1; j >= k; j--) 
		{		
			arr[j][i] = num;
			num++;
			
			if (num > input * input)
			{
				goto re;
			}
		}	
		k++;
	}


re:

	for (i = 0; i < input; i++)
	{
		for (j = 0; j < input; j++)
		{
			printf("%d\t", arr[i][j]);

			if (j ==input-1)
			{
				printf("\n\n");
			}
		}
	}
	
	
	for (i = 0; i < input; i++)
	{
		l = input - i -1; 
		arr1 = arr[l][0]; 
		if (cheak <= 1)
		{
			for (j = 1; j <= input - i - 1; j++)
			{
				arr1 *= arr[--l][j];
			}
			sum += arr1;
			cheak++;
		}
		else
		{
			break;
		}
	}
	 
	printf("대각선 곱 합(n-1케이스까지): %d", sum);

	return 0;
}

