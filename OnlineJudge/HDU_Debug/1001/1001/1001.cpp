#include<bits/stdc++.h>
#define f(x) for(x=1;x<=4;x++)
using namespace std;
map<string,int> q;
char o[5]="+-*/";
int tot=0;
bool flag=false;
double myabs(double x){return x>0?x:-x;}
bool check(double x){return myabs(x-24)<0.000001;}
double Add(double a, double b){return a+b;}
double Sub(double a, double b){return a-b;}
double Mul(double a, double b){return a*b;}
double Div(double a, double b){if(!b)return -100000;return a/b;} 
double(*op[4])(double,double) = {Add, Sub, Mul, Div};//函数指针。C++确实强大 
void Game24Points(double a, double b, double c, double d)
{
     for(int i=0; i<4; i++)
     {
          for(int j=0; j<4; j++)
          {
               for(int k=0; k<4; k++)
               {
                    //((a#b)#c)#d
                    double ret = op[k](op[j](op[i](a, b), c) , d);
                    if(check(ret))
                    {
                    	printf("\n第%d种:\n((%0.0lf%c%0.0lf)%c%0.0lf)%c%0.0lf=24\n",++tot,a,o[i],b,o[j],c,o[k],d);
                    	flag=true;
					}
                    //(a#(b#c))#d
                    ret = op[k](op[i](a, op[j](b, c)) , d);
                    if(check(ret))
                    {
                    	printf("\n第%d种:\n(%0.0lf%c(%0.0lf%c%0.0lf))%c%0.0lf=24\n",++tot,a,o[i],b,o[j],c,o[k],d);
                    	flag=true;
					}
                    //a#((b#c)#d)
                    ret = op[i](a, op[k](op[j](b, c) , d));
                    if(check(ret))
                    {
                    	printf("\n第%d种:\n%0.0lf%c((%0.0lf%c%0.0lf)%c%0.0lf)=24\n",++tot,a,o[i],b,o[j],c,o[k],d);
                    	flag=true;
					}
                    //(a#b)#(c#d)
                    ret = op[j](op[i](a, b), op[k](c, d));
                    if(check(ret))
                    {
                    	printf("\n第%d种:\n(%0.0lf%c%0.0lf)%c(%0.0lf%c%0.0lf)=24\n",++tot,a,o[i],b,o[j],c,o[k],d);
                    	flag=true;
					}
                    //a#(b#(c#d))
                    ret = op[i](a, op[j](b, op[k](c, d)));
                    if(check(ret))
                    {
                    	printf("\n第%d种:\n%0.0lf%c(%0.0lf%c(%0.0lf%c%0.0lf))=24\n",++tot,a,o[i],b,o[j],c,o[k],d);
                    	flag=true;
					}
               }
          }
     }
}
int main()
{
    double a[5];
	int i,j,k;
    f(i)cin>>a[i];
    bool s=false;
    f(i)
    {
		f(j)
		{
			if(i==j)continue;
			f(k)
			{
    			if(i==k||i==10-i-j-k||j==k||j==10-j-k-i||k==10-j-i-k)
				continue;
    			string a1,b1,c1,d1,f1; 
    			a1=char(a[i]+'0');b1=char(a[j]+'0');c1=char(a[k]+'0');d1=char(a[10-i-j-k]+'0');
    			f1=a1+' '+b1+' '+c1+' '+d1;
    			if(q[f1])
				continue;
    			q[f1]=1;
    			Game24Points(a[i],a[j],a[k],a[10-i-j-k]);
			}
		}
	}
	if(flag)
    printf("\n共%d个解\n",tot);
    else printf("此题无解\n");
	return 0;
}