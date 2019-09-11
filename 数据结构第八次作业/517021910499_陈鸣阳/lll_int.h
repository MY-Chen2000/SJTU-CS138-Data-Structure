#ifndef LLL_INT_H_INCLUDED
#define LLL_INT_H_INCLUDED



#include<iostream>
#include<string>
#include<algorithm>


using namespace std;
#define jinwei 10


string dezero(string a)//用来去掉正数前面的0，也就是说可以输入000001类似这样的数字
{
	long int i;
	for(i=0;i<a.length();i++)
	{
		if(a.at(i)>48) break;
	}
	if(i==a.length()) return "0";
	a.erase(0,i);
	return a;
}

int judge(string a,string b)//判断两个正数的大小
{
	if(a.length()>b.length()) return 1;
	if(a.length()<b.length()) return -1;
	long int i;
	for(i=0;i<a.length();i++)
	{
		if(a.at(i)>b.at(i)) return 1;
		if(a.at(i)<b.at(i)) return -1;
	}
	return 0;
}


string add(string a,string b)//自然数加法
{
	a=dezero(a);
	b=dezero(b);
	string c;
	string d="0";
	long int kmin,kmax,i;
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	if(a.length()>b.length()) {kmin=b.length();kmax=a.length();c=a;}
	else {kmin=a.length();kmax=b.length();c=b;}
	c.insert(c.length(),d);
	for(i=0;i<kmin;i++)
	{
		if(a.at(i)>=48&&a.at(i)<=57) a.at(i)-=48;
		if(a.at(i)>=97&&a.at(i)<=122) a.at(i)-=87;
		if(b.at(i)>=48&&b.at(i)<=57) b.at(i)-=48;
		if(b.at(i)>=97&&b.at(i)<=122) b.at(i)-=87;
		c.at(i)=a.at(i)+b.at(i);
	}
	for(i=kmin;i<kmax+1;i++)
	{
		if(c.at(i)>=48&&c.at(i)<=57) c.at(i)-=48;
		if(c.at(i)>=97&&c.at(i)<=122) c.at(i)-=87;
	}
	for(i=0;i<kmax;i++)
	{
		if(c.at(i)>=jinwei)
		{
			c.at(i+1)+=c.at(i)/jinwei;
			c.at(i)=c.at(i)%jinwei;
		}
	}
	if(c.at(kmax)==0)
	{
		c.erase(kmax,kmax+1);
	}
	for(i=0;i<c.length();i++)
	{
		if(c.at(i)>=10) c.at(i)+=87;
		if(c.at(i)<10) c.at(i)+=48;
	}
	reverse(c.begin(),c.end());
	return c;
}



string Minus(string a,string b)//自然数减法
{
	a=dezero(a);
	b=dezero(b);
	long int i,j=0;
	string c="0";
	string c1,c2;
	string d="-";
	if(judge(a,b)==0) return c;
	if(judge(a,b)==1)
	{
		c1=a;
		c2=b;
	}
	if(judge(a,b)==-1)
	{
		c1=b;
		c2=a;
		j=-1;
	}
	reverse(c1.begin(),c1.end());
	reverse(c2.begin(),c2.end());
	for(i=0;i<c2.length();i++)
	{
		if(c2.at(i)>=48&&c2.at(i)<=57) c2.at(i)-=48;
		if(c2.at(i)>=97&&c2.at(i)<=122) c2.at(i)-=87;
	}
	for(i=0;i<c1.length();i++)
	{
		if(c1.at(i)>=48&&c1.at(i)<=57) c1.at(i)-=48;
		if(c1.at(i)>=97&&c1.at(i)<=122) c1.at(i)-=87;
	}
	for(i=0;i<c2.length();i++)
	{
		c1.at(i)=c1.at(i)-c2.at(i);
	}
	for(i=0;i<c1.length()-1;i++)
	{
		if(c1.at(i)<0)
		{
			c1.at(i)+=jinwei;
			c1.at(i+1)--;
		}
	}
	for(i=c1.length()-1;i>=0;i--)
	{
		if(c1.at(i)>0) break;
	}
	c1.erase(i+1,c1.length());
	for(i=0;i<c1.length();i++)
	{
		if(c1.at(i)>=10) c1.at(i)+=87;
		if(c1.at(i)<10) c1.at(i)+=48;
	}
	reverse(c1.begin(),c1.end());
	if(j==-1) c1.insert(0,d);
	return c1;
}



string multiply(string a,string b)//整数
{
	long int i,j,k,yao=0,kai;
	string c1,c2;
	string c3=a+b;
	if(a.at(0)=='-')
	{
		a.erase(0,1);
		yao++;
	}
	if(b.at(0)=='-')
	{
		b.erase(0,1);
		yao++;
	}
	a=dezero(a);
	b=dezero(b);
	if(a.at(0)==48||b.at(0)==48) return "0";
	if(a.length()>b.length())
	{
		c1=a;
		c2=b;
	}
	else
	{
		c1=b;
		c2=a;
	}
	reverse(c1.begin(),c1.end());
	reverse(c2.begin(),c2.end());
	for(i=0;i<c2.length();i++)
	{
		if(c2.at(i)>=48&&c2.at(i)<=57) c2.at(i)-=48;
		if(c2.at(i)>=97&&c2.at(i)<=122) c2.at(i)-=87;
	}
	for(i=0;i<c1.length();i++)
	{
		if(c1.at(i)>=48&&c1.at(i)<=57) c1.at(i)-=48;
		if(c1.at(i)>=97&&c1.at(i)<=122) c1.at(i)-=87;
	}
	for(i=0;i<c3.length();i++) c3.at(i)=0;
	for(i=0;i<c2.length();i++)
	{
		for(j=0;j<c1.length();j++)
		{
			kai=c2.at(i)*c1.at(j);
			c3.at(i+j+1)+=kai/jinwei;
			c3.at(i+j)+=kai%jinwei;
			for(k=i+j;k<c3.length()-1;k++)
			{
				if(c3.at(k)>=jinwei)
				{
					c3.at(k+1)+=c3.at(k)/jinwei;
					c3.at(k)=c3.at(k)%jinwei;
				}
				else
				{
					break;
				}
			}
		}
	}
	for(i=c3.length()-1;i>=0;i--)
	{
		if(c3.at(i)>0) break;
	}
	c3.erase(i+1,c3.length());
	for(i=0;i<c3.length();i++)
	{
		if(c3.at(i)>=10) c3.at(i)+=87;
		if(c3.at(i)<10) c3.at(i)+=48;
	}
	reverse(c3.begin(),c3.end());
	if(yao==1) c3="-"+c3;
	return c3;
}


string mod(string a,string b)//取模运算
{
	long int i,j=0;
	string c1,c2,c3,d;
	if(a.at(0)=='-') j=1;
	if(judge(a,b)==0) return "0";
	if(judge(a,b)==-1)
	{
		return a;
	}
	c1=dezero(a);
	c2=dezero(b);
	d="";
	for(i=0;i<c1.length();i++)
	{
		d=d+c1.at(i);
		while(judge(d,b)>=0)
		{
			d=Minus(d,b);
			d=dezero(d);
		}
	}
	if(j==1) d=Minus(b,d);
	return dezero(d);
}




#endif // LLL_INT_H_INCLUDED
