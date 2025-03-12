#include<cstdio>
double a,b,c,d;
double fc(double x)
{
    return a*x*x*x+b*x*x+c*x+d;
}
int main()
{
    double l,r,m,x1,x2;
    int s=0,i;
    scanf("%lf%lf%lf%lf",&a,&b,&c,&d);  //输入
    for (i=-100;i<100;i++)
    {
        l=i; 
        r=i+1;
        x1=fc(l); 
        x2=fc(r);
        if(!x1) 
        {
            printf("%.2lf ",l); 
            s++;
        }      //判断左端点，是零点直接输出。
                        
                        //不能判断右端点，会重复。
        if(x1*x2<0)                             //区间内有根。
        {
            while(r-l>=0.001)                     //二分控制精度。
            {
                m=(l+r)/2;  //middle
                if(fc(m)*fc(r)<=0) 
                   l=m; 
                else 
                   r=m;   //计算中点处函数值缩小区间。
            }
            printf("%.2lf ",r);  
            //输出右端点。
            s++;
        }
        if (s==3) 
            break;             
            //找到三个就退出大概会省一点时间
    }
    return 0;
}