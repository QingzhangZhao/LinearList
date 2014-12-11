#include<stdio.h>
int c=0;//C是用来计算数组中数的个数的，当下面插入时就c++;删除时就c--
void print(int a[100])//打印整个数组的函数
{
 int b;
 for(b=0;b<c;b++)
  printf("%d  ",a[b]);
 printf("\n");
}
void cr(int a[])//插入函数
{
 int i,j,m;
 printf("请输入要插入的位置:");
 scanf("%d",&i);
 //*************************************************************
 //这些是用来判断，所输入的位置是否存在，
 //如果不存在,则重新再输入一次，当然这些可以不要，那在运行的时候
 //就需要保证输入的位置都是对的！
 while(i<1||i>c+1)
 {
  printf("没有这个位置，请重新输入要插入的位置:");
  scanf("%d",&i);
 }
 //**************************************************************
 printf("请输入要插入的数:");
 scanf("%d",&j);
 (c)++;
 //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 //用来把要插入位置以后的数，都往后移动一会，这样腾出位置
 for(m=c-1;m>=i;m--)
 {
  a[m]=a[m-1];
 }
 //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 a[i-1]=j;//把要插入的数放入前面腾出的位置
 print(a);
}

void del(int a[])//删除函数
{
 int i,m;
 printf("请输入要删除数的位置:");
 scanf("%d",&i);
 (c)--;
 for(m=i-1;m<c;m++)
  a[m]=a[m+1];
 print(a);
}

void find(int a[])//查找函数
{
 int i,m;
 char x;
 printf("请输入要查找的数:");
 scanf("%d",&i);
 for(m=0;m<c;m++)
 {

  if(a[m]==i)break;
 }
 if(m!=c)
 {
  printf("找到该数下标是%d.\n",m);

}
 else
  printf("查无此数.\n");
}
void hb(int a[])
{
 int b[100]={0};
 int d,i;
 printf("请输入要并入的数组数据数量(不能大于%d)：",100-c);
 scanf("%d",&d);
 for(i=0;i<d;i++)
 {
  printf("请输入第%d个数:",i+1);
  scanf("%d",&b[i]);
 }
 printf("\n并入\n");
 print(a);
 printf("\n得到:\n");
 for(i=0;i<d;i++)
 {
  a[c]=b[i];
  c++;

 }
 print(a);
}
void main()
{
 int a[100]={0};
 int i,j,m,n;
 printf("请输入数据数量：");
 scanf("%d",&c);
 for(i=0;i<c;i++)
 {
  printf("请输入第%d个数:",i+1);
  scanf("%d",&a[i]);
 }
 print(a);
 //__________________________________________________________
 //次处采用选择结构，既根据输入m的值来判断执行下面哪个语句
 printf("插入请输入1，删除请输入2,查找请输入3,合并新数据4\n任意数结束:");
 scanf("%d",&m);
 switch (m)
 {
 case 1 :cr(a);break;
 case 2 :del(a);break;
 case 3 :find(a);break;
 case 4 :hb(a);break;
 default : break;
 };
 //______________________________________________________________
 //如果不要两横线内的东西，则屏蔽掉后使用下面三句
 //cr(a);
 //del(a);
 //find(a)
}
