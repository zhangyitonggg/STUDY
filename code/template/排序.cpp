#include<bits/stdc++.h>
using namespace std;
int a[2000010],bucket[2000010],temp[2000010];
void Selection_sort(int n)//选择排序
{
//每次选择最小的放到最未排序部分最前面
	int i,j;
	for(i=0;i<n;i++)//枚举放的位置
	{
		for(j=i+1;j<n;j++)//枚举后面
		{
			if(a[j]<a[i])
			{
				swap(a[i],a[j]);//交换，放置到当前最前面
			}
		}
	}
}
void bubble_sort(int n)//冒泡排序
{
//每次比较相邻两个，如果不符合就交换，那么每一轮排序后最后面会多一个最大的
	int i,j;
	for(i=0;i<n;i++)//枚举第几轮
	{
		for(j=0;j<n-i;j++)//枚当前未排序区间
		{
			if(a[j+1]<a[j])
			{
				swap(a[j],a[j+1]);//冒泡操作
			}
		}
	}
}
void bucket_sort(int n)//桶排序
{
//将元素放入桶中，最后遍历桶
	int i,big=0,k=0;
	memset(bucket,0,99999);
	for(i=0;i<n;i++)
	{
		bucket[a[i]]++;//放入桶中
		if(a[i]>big)
		{
			big=a[i];//记录最大值，枚举桶时会用到
		}
	}
	for(i=0;i<big+1;i++)//枚举桶
	{
		if(bucket[i]>=0)
		{
			for(int j=0;j<bucket[i];j++)
			{
				a[k++]=i;//输出桶到序列中
			}
		}
	}
}
void insertion_Sort(int n)//插入排序
{
//每次将当前数向前枚举并插入合适的位置
	int i,j,temp;
	for(i=0;i<n;i++)//插入第i个数
	{
		temp=a[i];
		for(j=i-1;j>=0&&temp<a[j];j--)//插入过程
		{
			a[j+1]=a[j];//整体后移
		}
		a[j+1]=temp;
	}
}
void merge_Sort(int l,int r)//归并排序
{
//每次将区间二分，直到单独的数，由于一个数有序，返回合并区间。
	if(l>=r)return ;//单独的数
		int mid=(l+r)/2,i,j,c=0;
		merge_Sort(l,mid);//排序左区间
		merge_Sort(mid+1,r);//排序右区间
		i=l;
		j=mid+1;
		while(i<=mid&&j<=r)//在temp中进行合并操作
		{
			if(a[i]<a[j])temp[++c]=a[i++];
			else temp[++c]=a[j++];
		}
		while(i<=mid)temp[++c]=a[i++];
		while(j<=r)temp[++c]=a[j++];
		for(i=1;i<=c;i++)//复制到原数组
		{
			a[l++]=temp[i];
		} 
}
void quick_sort(int l, int r)//快速排序
{
//每次选一个数，以它为界划分左右区间并像归并一样返回
    if (l< r)//边界
    {     
        int i = l, j = r, x = a[l];
        while (i < j)//以x为界划分
        {
            while(i < j && a[j]>= x)
                j--; 
            if(i < j)
                a[i++] =a[j];
            while(i < j && a[i]< x)
                i++; 
            if(i < j)
                a[j--] = a[i];
        }
        a[i] = x;
        quick_sort( l, i - 1); //递归左区间
        quick_sort( i + 1, r);//递归右区间
    }
}
	

int main () {
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        scanf("%d",a+i);
    merge_Sort(1,n);//我个人喜欢归并，因为快排有可能退化O(n^2)
    for(int i=1;i<=n;++i)
        printf("%d ",a[i]);
    return 0;
}