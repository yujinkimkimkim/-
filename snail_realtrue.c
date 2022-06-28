#include <stdio.h>

int main()
{
	int input, l = 0, k = 1, num = 1;
	int arr[10][10];
	int sum = 0, arr1 = 0;
	scanf_s("%d", &input);

	for (int i = 0; i < input; i++)
	{
		for (int j = i; j < input - k + 1; j++)
		{
			arr[i][j] = num;
			num++;
		}
		for (int j = k; j <= input - k; j++)
		{
			arr[j][input - 1 - i] = num;
			num++;
		}
		for (int j = input - k - 1; j >= i; j--)
		{
			arr[input - 1 - i][j] = num;
			num++;
		}
		for (int j = input - k - 1; j >= k; j--)
		{
			arr[j][i] = num;
			num++;
		}
		k++;
	}




	for (int i = 0; i < input; i++)
	{
		for (int j = 0; j < input; j++)
		{
			printf("%d\t", arr[i][j]);

			if (int j == input - 1)
			{
				printf("\n\n");
			}
		}
	}


	for (int i = 0; i < input; i++)
	{
		l = input - i - 1;
		arr1 = arr[l][0];

		for (int j = 1; j <= input - i - 1; j++)
		{
			arr1 *= arr[--l][j];
		}
		sum += arr1;
	}
	int arr2, o;
	for (int i = 0; i < input - 1; i++)
	{
		o = input - 1;
		arr2 = arr[o][i + 1];
		for (int j = i + 1; j < input - 1; j++)
		{
			arr2 *= arr[--o][j + 1];
		}
		sum += arr2;
	}

	printf("대각선 곱 합: %d", sum);

	return 0;
}

