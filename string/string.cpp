#include <iostream>
#include <string>
#include<climits>
#include <string.h>
#include <cstdlib>
#include <memory>

using namespace std;

//leetcode 58
int lengthOfLastWord(string s)
{
	int len = s.size();
	int i;
	bool isFindChar = false;
	
	int res = 0;
	for (i = len; i >= 0;i--)
	{
		
		if (isalpha(s[i]))
		{
			isFindChar = true;
		}

		if (isFindChar)
		{
			if (isalpha(s[i]))
			{
				res++;
			}
			if (!isalpha(s[i]))
			{
				break;
			}
		}
		
	}
	return res;
}

void insertSort(int array[], int len)
{
	int i, j;
	for (i = 1; i < len; i++)
	{
		if (array[i] < array[i - 1])
		{
			int tmp = array[i];
			for (j = i - 1; j >= 0 && array[j] > tmp; j--)
			{
				array[j + 1] = array[j];
			}
			array[j + 1] = tmp;
		}
	}
}

void SWAP(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void merge(int* nums1, int m, int* nums2, int n)
{
	int * buff = (int *)malloc((m + n)*sizeof(int));
	for (int i = 0; i < m;i++)
	{
		buff[i] = nums1[i];
	}
	for (int i = m,j=0; i < n+m,j<n; i++,j++)
	{
		buff[i] = nums2[j];
	}

	insertSort(buff, m + n);

}
int main()
{
	char str[100] = { 0x00 };
	strcpy(str, "Hello World");
	lengthOfLastWord(str);

	int array[] = { 1, 1, 1, 2 };
	return 0;
}