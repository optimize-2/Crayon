//Luogu P1001
#include"crayon.hpp"
/*
crayon.hpp中包含bits/stdc++.h
*/
using namespace std;
using namespace cy;
/*
namespace cy中包含了crayon的所有namespace(s).
*/

int a,b;

int main() {
	for(int data=1;data<=10;data++) {
		make_in(data);
		/*
		make_in(data);
		把输入定向到testdata(data).in中.
		如make_in(5);就是把输入定向到了testdata5.in中.
		*/
 	 	a=cyrand(1,pow(2,data+7));
		b=cyrand(1,pow(2,data+7));
		/*
		cyrand(a,b) 产生一个[a,b]之间的随机数
		(a<=b , b>=0 , a,b<INTMAX)

		另有cyrand_ll(a,b) 产生一个[a,b]之间的随机数
		(a<=b , b>=0 , a,b<LONGLONGMAX)

		pow(2,data+7)是为了证数据有梯度.
		*/
		cout<<a<<" "<<b;
		/*
		输出a和b.
		*/
		end_in();
		/*
		取消定向(相当于freopen("CON","r",stdin);)
		*/
		make_out(data);
		/*
		使用tools//program//std.exe对testdata(data).in做出testdata(data).out.
		在本例中,std.cpp应该是这样的:

		//Luogu P1001
		#include<bits/stdc++.h>
		using namespace std;

		int a,b;

		int main() {
			//不需要freopen!
			cin>>a>>b;
			cout<<a+b;
			return 0;
		}

		特别注意:在std.cpp中不需要freopen.
		*/
	}
	return 0;
}
