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
void insertsort(sqlist l);//ֱ�Ӳ�������
void bubblesort(sqlist l);//��������
void quicksort(sqlist l);//��������
void qsort(sqlist &l,int low,int high,int &x3,int &y3);
int partition(sqlist &l,int low,int high,int &x3,int &y3);
void selectsort(sqlist l);//��ѡ������
void shellsort(sqlist l,int dt[],int t);//ϣ������
void shellinsert(sqlist &l,int dk,int &x5,int &y5);
void heapsort(sqlist l);//������
void creatheap(sqlist &l,int &x6,int &y6);
void heapadjust(sqlist &l,int s,int m,int &x6,int &y6);
int main()
{
	int i,k2=0;
	sqlist s;
	int dk[5]={50,25,10,5,1};//ϣ�����������
	int maxt=5;
	for(i=1;i<=maxsize;i++)
	{
		s.r[i].key=rand();
	}
	cout<<"������"<<maxsize<<"�������Ϊ��"<<endl;
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
	cout<<"��ѡ�������㷨��"<<endl;
	cout<<"1��ֱ�Ӳ�������"<<endl;
	cout<<"2����������"<<endl;
	cout<<"3����������"<<endl;
	cout<<"4����ѡ������"<<endl;
	cout<<"5��ϣ������"<<endl;
	cout<<"6��������"<<endl;
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
		default:cout<<"�������";break;
	}
	}
	return 0;
}
void insertsort(sqlist l)//ֱ�Ӳ�������
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
	cout<<"ֱ�Ӳ��������Ľ��Ϊ��"<<endl;
	for(i=1;i<=l.length;i++)
	{
		k1=k1++;
		cout<<l.r[i].key<<" ";
		if(k1%10==0)
		{
			cout<<endl;
		}
	}
	cout<<"�Ƚϴ���Ϊ��"<<x1<<"��"<<endl;
	cout<<"�ƶ�����Ϊ��"<<y1<<"��"<<endl;
}
void bubblesort(sqlist l)//��������
{
	int flag=1;
	int m=l.length-1,i;
	redtype t;
	int x2=0,y2=0;
	while((m>0)&&(flag==1))
	{
		flag=0;//�������û�з����������Ͳ�����ִ��
		for(i=1;i<=m;i++)//ÿ�˽�������
		{
			x2=x2++;
			if(l.r[i].key>l.r[i+1].key)
			{
				flag=1;//�����˽���
				t=l.r[i+1];
				l.r[i+1]=l.r[i];
				l.r[i]=t;
				y2=y2+3;
			}
		}
		m=m--;
	}
	int k1=0;
	cout<<"���������Ľ��Ϊ��"<<endl;
	for(i=1;i<=l.length;i++)
	{
		k1=k1++;
		cout<<l.r[i].key<<" ";
		if(k1%10==0)
		{
			cout<<endl;
		}
	}
	cout<<"�Ƚϴ���Ϊ��"<<x2<<"��"<<endl;
	cout<<"�ƶ�����Ϊ��"<<y2<<"��"<<endl;
}
void quicksort(sqlist l)//��������
{
	int x3=0,y3=0;
	qsort(l,1,l.length,x3,y3);
	int k1=0,i;
	cout<<"���������Ľ��Ϊ��"<<endl;
	for(i=1;i<=l.length;i++)
	{
		k1=k1++;
		cout<<l.r[i].key<<" ";
		if(k1%10==0)
		{
			cout<<endl;
		}
	}
	cout<<"�Ƚϴ���Ϊ��"<<x3<<"��"<<endl;
	cout<<"�ƶ�����Ϊ��"<<y3<<"��"<<endl;

}
void qsort(sqlist &l,int low,int high,int &x3,int &y3)
{
	int pivotloc;
	if(low<high)
	{
		pivotloc=partition(l,low,high,x3,y3);//�ҳ���Ŧλ��
		qsort(l,low,pivotloc-1,x3,y3);//�����ӱ���еݹ�����
		qsort(l,pivotloc+1,high,x3,y3);//�����ӱ���еݹ�����
	}
}
int partition(sqlist &l,int low,int high,int &x3,int &y3)
{
	int pivokey;
	l.r[0]=l.r[low];//�ֱ��һ����¼����Ŧ��¼
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

void selectsort(sqlist l)//��ѡ������
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
	cout<<"��ѡ�������Ľ��Ϊ��"<<endl;
	for(i=1;i<=l.length;i++)
	{
		k1=k1++;
		cout<<l.r[i].key<<" ";
		if(k1%10==0)
		{
			cout<<endl;
		}
	}
	cout<<"�Ƚϴ���Ϊ��"<<x4<<"��"<<endl;
	cout<<"�ƶ�����Ϊ��"<<y4<<"��"<<endl;
}
void shellsort(sqlist l,int dt[],int t)//ϣ������
{
	int k,i;
	int x5=0,y5=0;
	for(k=0;k<t;k++)
	{
		shellinsert(l,dt[k],x5,y5);
	}
	int k1=0;
	cout<<"ϣ�������Ľ��Ϊ��"<<endl;
	for(i=1;i<=l.length;i++)
	{
		k1=k1++;
		cout<<l.r[i].key<<" ";
		if(k1%10==0)
		{
			cout<<endl;
		}
	}
	cout<<"�Ƚϴ���Ϊ��"<<x5<<"��"<<endl;
	cout<<"�ƶ�����Ϊ��"<<y5<<"��"<<endl;
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
void heapsort(sqlist l)//������
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
	cout<<"�������Ľ��Ϊ��"<<endl;
	for(i=1;i<=l.length;i++)
	{
		k1=k1++;
		cout<<l.r[i].key<<" ";
		if(k1%10==0)
		{
			cout<<endl;
		}
	}
	cout<<"�Ƚϴ���Ϊ��"<<x6<<"��"<<endl;
	cout<<"�ƶ�����Ϊ��"<<y6<<"��"<<endl;
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