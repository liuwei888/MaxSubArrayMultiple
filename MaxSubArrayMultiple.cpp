/*************************************************************************
    > File Name: test.cpp
    > Author: liuwei
    > Mail: 271551048@qq.com 
    > Created Time: 2015年09月08日 星期二 22时47分45秒
 ************************************************************************/

#include<iostream>
using namespace std;

double Max(double a, double b, double c)
{ 
	double max = (a > b) ? a : b;
	return (max > c) ? max : c;
}

double Max2(double a, double b)
{ 
	return (a > b) ? a : b;
}

double Min(double a, double b, double c)

{ 
	double min = (a < b) ? a : b;
	return (min < c) ? min : c;
}

double MaxSubArrayMultiple(double *arr, int length)
{
	if(NULL == arr || length < 0)
		return -1;
	double max = arr[0];
	double min = arr[0];
	double result = arr[0];
	for(int i = 1; i < length; i++)
	{
		max = Max(max * arr[i], min * arr[i], arr[i]);
		min = Min(max * arr[i], min * arr[i], arr[i]);
		result = Max2(result, max);
	}
	return result;
}

int main()
{
	double arr[] = {-2.5, 4, 0, 3, 0.5, 8, -1};
	int result = MaxSubArrayMultiple(arr, 7);
	cout << result << endl;
}
