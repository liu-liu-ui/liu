#include<iostream>
using namespace std;
#define maxsize 100
typedef struct
{
	int key;
	char otherinfo;
}redtype;
typedef struct
{
	redtype r[maxsize+1];
	int length;
}sqlist;
void insertsort(sqlist l);//直接插入排序
void bubblesort(sqlist l);//起泡排序
void quicksort(sqlist l);//快速排序
void qsort(sqlist &l,int low,int high,int &x3,int &y3);
int partition(sqlist &l,int low,int high,int &x3,int &y3);
void selectsort(sqlist l);//简单选择排序
void shellsort(sqlist l,int dt[],int t);//希尔排序
void shellinsert(sqlist &l,int dk,int &x5,int &y5);
void heapsort(sqlist l);//堆排序
void creatheap(sqlist &l,int &x6,int &y6);
void heapadjust(sqlist &l,int s,int m,int &x6,int &y6);
int main()
{
	int i,k2=0;
	sqlist s;
	int dk[5]={50,25,10,5,1};//希尔排序的增量
	int maxt=5;
	for(i=1;i<=maxsize;i++)
	{
		s.r[i].key=rand();
	}
	cout<<"产生的"<<maxsize<<"个随机数为："<<endl;
	for(i=1;i<=maxsize;i++)
	{
		k2=k2++;
		cout<<s.r[i].key<<" ";
		if(k2%10==0)
		{
			cout<<endl;
		}
	}
	s.length=maxsize;
	cout<<"请选择排序算法："<<endl;
	cout<<"1、直接插入排序"<<endl;
	cout<<"2、起泡排序"<<endl;
	cout<<"3、快速排序"<<endl;
	cout<<"4、简单选择排序"<<endl;
	cout<<"5、希尔排序"<<endl;
	cout<<"6、堆排序"<<endl;
	int a;
	while(1){
	cin>>a;
	switch(a)
	{
		case 1:insertsort(s);break;
		case 2:bubblesort(s);break;
		case 3:quicksort(s);break;
		case 4:selectsort(s);break;
		case 5:shellsort(s,dk,maxt);break;
		case 6:heapsort(s);break;
		default:cout<<"输入错误";break;
	}
	}
	return 0;
}
void insertsort(sqlist l)//直接插入排序
{
	int i,j;
	int x1=0,y1=0;
	for(i=2;i<=l.length;i++)
	{
		x1=x1++;
		if(l.r[i].key<l.r[i-1].key)	
		{
			
			l.r[0]=l.r[i];
			l.r[i]=l.r[i-1];
			y1=y1++;
			for(j=i-2;l.r[j].key>l.r[0].key;j--)
			{
				x1=x1++;
				l.r[j+1]=l.r[j];
				y1=y1++;
			}
			x1=x1++;
			l.r[j+1]=l.r[0];
			
		}
	}
	int k1=0;
	cout<<"直接插入排序后的结果为："<<endl;
	for(i=1;i<=l.length;i++)
	{
		k1=k1++;
		cout<<l.r[i].key<<" ";
		if(k1%10==0)
		{
			cout<<endl;
		}
	}
	cout<<"比较次数为："<<x1<<"次"<<endl;
	cout<<"移动次数为："<<y1<<"次"<<endl;
}
void bubblesort(sqlist l)//起泡排序
{
	int flag=1;
	int m=l.length-1,i;
	redtype t;
	int x2=0,y2=0;
	while((m>0)&&(flag==1))
	{
		flag=0;//如果本趟没有发生交换，就不往下执行
		for(i=1;i<=m;i++)//每趟交换几次
		{
			x2=x2++;
			if(l.r[i].key>l.r[i+1].key)
			{
				flag=1;//进行了交换
				t=l.r[i+1];
				l.r[i+1]=l.r[i];
				l.r[i]=t;
				y2=y2+3;
			}
		}
		m=m--;
	}
	int k1=0;
	cout<<"起泡排序后的结果为："<<endl;
	for(i=1;i<=l.length;i++)
	{
		k1=k1++;
		cout<<l.r[i].key<<" ";
		if(k1%10==0)
		{
			cout<<endl;
		}
	}
	cout<<"比较次数为："<<x2<<"次"<<endl;
	cout<<"移动次数为："<<y2<<"次"<<endl;
}
void quicksort(sqlist l)//快速排序
{
	int x3=0,y3=0;
	qsort(l,1,l.length,x3,y3);
	int k1=0,i;
	cout<<"快速排序后的结果为："<<endl;
	for(i=1;i<=l.length;i++)
	{
		k1=k1++;
		cout<<l.r[i].key<<" ";
		if(k1%10==0)
		{
			cout<<endl;
		}
	}
	cout<<"比较次数为："<<x3<<"次"<<endl;
	cout<<"移动次数为："<<y3<<"次"<<endl;

}
void qsort(sqlist &l,int low,int high,int &x3,int &y3)
{
	int pivotloc;
	if(low<high)
	{
		pivotloc=partition(l,low,high,x3,y3);//找出枢纽位置
		qsort(l,low,pivotloc-1,x3,y3);//对左子表进行递归排序
		qsort(l,pivotloc+1,high,x3,y3);//对右子表进行递归排序
	}
}
int partition(sqlist &l,int low,int high,int &x3,int &y3)
{
	int pivokey;
	l.r[0]=l.r[low];//字表第一个记录做枢纽记录
	pivokey=l.r[0].key;
	while(low<high)
	{
		while(low<high&&l.r[high].key>=pivokey)
		{
			x3=x3++;
			high=high--;
		}
		l.r[low]=l.r[high];
		x3=x3++;
		y3=y3++;
		while(low<high&&l.r[low].key<=pivokey)
		{
			low=low++;
			x3=x3++;
		}
		l.r[high]=l.r[low];
		x3=x3++;
		y3=y3++;
	}
	l.r[low]=l.r[0];
	return low;
}

void selectsort(sqlist l)//简单选择排序
{
	int i,k,j;
	redtype t;
	int x4=0,y4=0;
	for(i=1;i<l.length;i++)
	{
		k=i;
		for(j=i+1;j<=l.length;j++)
		{
			x4=x4++;
			if(l.r[j].key<l.r[k].key)
				k=j;
			if(k!=i)
			{
				t=l.r[i];
				l.r[i]=l.r[k];
				l.r[k]=t;
				y4=y4++;
			}
		}
	}
	int k1=0;
	cout<<"简单选择排序后的结果为："<<endl;
	for(i=1;i<=l.length;i++)
	{
		k1=k1++;
		cout<<l.r[i].key<<" ";
		if(k1%10==0)
		{
			cout<<endl;
		}
	}
	cout<<"比较次数为："<<x4<<"次"<<endl;
	cout<<"移动次数为："<<y4<<"次"<<endl;
}
void shellsort(sqlist l,int dt[],int t)//希尔排序
{
	int k,i;
	int x5=0,y5=0;
	for(k=0;k<t;k++)
	{
		shellinsert(l,dt[k],x5,y5);
	}
	int k1=0;
	cout<<"希尔排序后的结果为："<<endl;
	for(i=1;i<=l.length;i++)
	{
		k1=k1++;
		cout<<l.r[i].key<<" ";
		if(k1%10==0)
		{
			cout<<endl;
		}
	}
	cout<<"比较次数为："<<x5<<"次"<<endl;
	cout<<"移动次数为："<<y5<<"次"<<endl;
}
void shellinsert(sqlist &l,int dk,int &x5,int &y5)
{
	int i,j;
	
	for(i=dk+1;i<=l.length;i++)
	{
		x5=x5++;
		if(l.r[i].key<l.r[i-dk].key)
		{
			l.r[0]=l.r[i];
			for(j=i-dk;j>0&&l.r[0].key<l.r[j].key;j=j-dk)
			{
				l.r[j+dk]=l.r[j];
				y5=y5++;
				x5=x5++;
			}
			x5=x5++;
			l.r[j+dk]=l.r[0];
		}
	}

}
void heapsort(sqlist l)//堆排序
{
	int x6=0,y6=0;
	creatheap(l,x6,y6);
	int i;
	redtype t;
	for(i=l.length;i>1;--i)
	{
		t=l.r[1];
		l.r[1]=l.r[i];
		l.r[i]=t;
		y6=y6+3;
		heapadjust(l,1,i-1,x6,y6);
	}
	int k1=0;
	cout<<"堆排序后的结果为："<<endl;
	for(i=1;i<=l.length;i++)
	{
		k1=k1++;
		cout<<l.r[i].key<<" ";
		if(k1%10==0)
		{
			cout<<endl;
		}
	}
	cout<<"比较次数为："<<x6<<"次"<<endl;
	cout<<"移动次数为："<<y6<<"次"<<endl;
}
void creatheap(sqlist &l,int &x6,int &y6)
{
	int n,i;
	n=l.length;
	for(i=n/2;i>0;--i)
		heapadjust(l,i,n,x6,y6);
}
void heapadjust(sqlist &l,int s,int m,int &x6,int &y6)
{
	redtype t1;
	t1=l.r[s];
	int j;
	for(j=2*s;j<=m;j*=2)
	{
		
		if(j<m&&l.r[j].key<l.r[j+1].key)
			++j;
		x6=x6++;
		if(t1.key>=l.r[j].key)
			break;
		x6=x6++;
		l.r[s]=l.r[j];
		y6=y6+3;
		s=j;
	}
	l.r[s]=t1;
}