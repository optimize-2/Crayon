#include<bits/stdc++.h>
#include"tools/lib/init.h"

#define CRAYON 2.2

//cyrand:
bool isInit;
int MTindex;
long long MT[624];

void MTsrand(int seed) {
	MTindex=0;
	isInit=1;
	MT[0]=seed;
	for(int i=1;i<624;i++) {
		int t=1812433253*(MT[i-1]^(MT[i-1]>>30))+i;
		MT[i]=t&0xffffffff;
	}
}

inline void generate() {
	for(int i=0;i<624;i++) {
		long long y=(MT[i]&0x80000000)+(MT[(i+1)%624]&0x7fffffff);
		MT[i]=MT[(i+397)%624]^(y>>1);
		if(y%2==1) MT[i]^=2147483647;
	}
}

inline int MTrand() {
	if(!isInit) MTsrand((int)time(NULL));
	if(MTindex==0) generate();
	int y=MT[MTindex];
	y=y^(y>>11);
	y=y^((y<<7)&1636928640);
	y=y^((y<<15)&1022730752);
	y=y^(y>>18);
	MTindex=(MTindex+1)%624;
	return y;
}

inline long long MTrand_ll() {
	return ((long long)(MTrand())<<31)+MTrand();
}

inline int cyrand(int a,int b) {
	if(a>b) a=b;
	if(a==b) return a;
	else return MTrand()%(b-a+1)+a;
}

inline long long cyrand_ll(long long a,long long b) {
	if(a>b) a=b;
	if(a==b) return a;
	else return MTrand_ll()%(b-a+1)+a;
}

namespace cymath {
	#define CRAYON_INT_INF 0x3f3f3f3f
	
	template<typename T>
	inline T crayon_abs(T a) {return a>0?a:-a;}
	inline int crayon_min(int a,int b) {return a<b?a:b;}
	inline int crayon_max(int a,int b) {return a>b?a:b;}
	inline int crayon_gcd(int a,int b) {return a==0?b:crayon_gcd(b%a,a);}
	int rand_prime1(int beg,int end) {
		return crayon_prime[cyrand(beg,end)];
	}
	int rand_prime2(int mn,int mx) {
		int itmin,itmax;
		int l=1;
		int r=prime_count;
		int mid=(l+r)>>1;
		while(l<=r) {
			if(crayon_prime[mid]>=mn) {
				r=mid-1;
			} else {
				l=mid+1;
			}
			mid=(l+r)>>1;
		}
		itmin=mid;
		
		l=1;
		r=prime_count;
		mid=(l+r)>>1;
		while(l<=r) {
			if(crayon_prime[mid]>=mx) {
				r=mid-1;
			} else {
				l=mid+1;
			}
			mid=(l+r)>>1;
		}
		itmax=mid;
		
		return rand_prime1(itmin,itmax);
	}
	std::string rand_string(int len,char mn,char mx) {
		
		std::string ret="";
		for(int i=1;i<=len;i++) {
			ret+=(char)cyrand(mn,mx);
		}
		return ret;
	}
}

namespace cystem {
	/*****/
	bool match_opt=true;
	int spfa_optimize;
	
	std::map<std::string,int>crayon_st;
	
	void init_system() {
		crayon_st["readme"]=1;
		crayon_st["opt on"]=2;
		crayon_st["opt off"]=3;
		crayon_st["spfa SLF"]=4;
	}
	/*****/
	int crayon_readmesize=16;
	std::string crayon_readme=
		"Crayon was done by optimize_2(Guid:224978)\n"
		"How to use it:\n"
		"#include<crayon.hpp>\n"
		"using namespace std;\n"
		"using namespace cy;\n"
		"\n"
		"int main()\n"
		"{\n"
		"	something...\n"
		"	return 0;\n"
		"}\n"
		"\n"
		"\n"
		"\n"
		"For exsample:\n"
		"You can use the struct \"graph\" to storage a graph.\n";
	void crayon_int_system(int t) {
		switch(t)
		{
		case 1:
			std::cout<<crayon_readme;
			break;
		case 2:
			match_opt=true;
			break;
		case 3:
			match_opt=false;
			break;
		case 4:
			spfa_optimize=1;
			break;
		/*
		case 5:
			
			break;
		case 6:
			
			break;
		case 7:
			
			break;
		*/
		default:
			break;
		}
	}
	
	void crayon_system(std::string a) {
		crayon_int_system(crayon_st[a]);
	}
	
	void crayon(std::string a) {
		crayon_system(a);
		return;
	}
}



namespace cydata {
<<<<<<< HEAD
	std::string database;
=======
	std::string __base;
>>>>>>> b55bc88cd74547039aa1e056aba33a054544c7b0
	inline void make_in(int id) {
		freopen("CON","r",stdin);
		freopen("CON","w",stdout);
		std::string _id;
		std::stringstream ss;
		ss<<id;
		ss>>_id; 
<<<<<<< HEAD
		std::string opentmp="testdata\\"+cydata::database+_id+".in";
=======
		std::string opentmp="testdata\\"+__base+_id+".in";
>>>>>>> b55bc88cd74547039aa1e056aba33a054544c7b0
		freopen(opentmp.c_str(),"w",stdout);
	}
	
	inline void make_in(std::string path) {
		freopen("CON","r",stdin);
		freopen("CON","w",stdout);
		freopen(path.c_str(),"w",stdout);
	}

	inline void end_in() {
		freopen("CON","r",stdin);
	}
	
	inline void close_file() {
		freopen("CON","r",stdin);
		freopen("CON","w",stdout);
	}

	inline void make_out(int id) {
		freopen("CON","r",stdin);
		freopen("CON","w",stdout);
		
		std::string _id,opentmp;
		std::stringstream ss;
		ss<<id;
		ss>>_id;
		
<<<<<<< HEAD
		opentmp="testdata\\"+cydata::database+_id+".in";
		freopen(opentmp.c_str(),"r",stdin);
		opentmp="testdata\\"+cydata::database+_id+".out";
=======
		opentmp="testdata\\"+__base+_id+".in";
		freopen(opentmp.c_str(),"r",stdin);
		opentmp="testdata\\"+__base+_id+".out";
>>>>>>> b55bc88cd74547039aa1e056aba33a054544c7b0
		freopen(opentmp.c_str(),"w",stdout);
		
		system("tools\\program\\std.exe");
		
		freopen("CON","r",stdin);
		freopen("CON","w",stdout);
	}
	
	inline void make_out(std::string path,int id) {
		freopen("CON","r",stdin);
		freopen("CON","w",stdout);
		
		std::string _id,opentmp;
		std::stringstream ss;
		ss<<id;
		ss>>_id;
		
		opentmp="testdata"+cydata::database+_id+".in";
		freopen(opentmp.c_str(),"r",stdin);
		opentmp="testdata"+cydata::database+_id+".out";
		freopen(opentmp.c_str(),"w",stdout);
		
		system(path.c_str());
		
		freopen("CON","r",stdin);
		freopen("CON","w",stdout);
	}
}

class cyinit {
	public:
		cyinit() {
<<<<<<< HEAD
			cydata::database="testdata";
=======
			cydata::__base="testdata";
>>>>>>> b55bc88cd74547039aa1e056aba33a054544c7b0
			srand(time(NULL));
			MTsrand(time(NULL));
			system("del testdata /q");
			cystem::init_system();
<<<<<<< HEAD
=======
			cydata::__base="testdata";
>>>>>>> b55bc88cd74547039aa1e056aba33a054544c7b0
		}
		
		~cyinit() {
			freopen("CON","r",stdin);
			freopen("CON","w",stdout);
		}
};

cyinit crayon_guard;

namespace cydebug {
	bool match(int num) {
		int id=num;
		std::string _id;
		std::stringstream ss;
		ss<<id;
		ss>>_id;
		
		freopen("CON","r",stdin);
		freopen("CON","w",stdout);
		
		std::string opentmp="testdata\\"+cydata::database+_id+".in";
		freopen(opentmp.c_str(),"r",stdin);
		freopen("tools\\program\\match1.out","w",stdout);
		
		system("tools\\program\\prog1.exe");
		
		freopen("CON","r",stdin);
		freopen("CON","w",stdout);
		
		
		opentmp="testdata\\"+cydata::database+_id+".in";
		freopen(opentmp.c_str(),"r",stdin);
		freopen("tools\\program\\match2.out","w",stdout);
		
		system("tools\\program\\prog2.exe");
		
		freopen("CON","r",stdin);
		freopen("CON","w",stdout);
		
		freopen("tools\\program\\tmp.tmp","w",stdout);
		
		bool ret=system("tools\\bin\\fc.exe /W tools\\program\\match1.out tools\\program\\match2.out")==0?true:false;
		
		
		if(cystem::match_opt) {
			freopen("CON","w",stdout);
			std::cout<<"正在测试testdata"<<num<<"..."<<'\n';
			std::ifstream in("tools\\program\\tmp.tmp");
			std::ostringstream tmp;
			tmp<<in.rdbuf();
			std::string str=tmp.str();
			std::cout<<str<<'\n';
		}
		
		
		freopen("CON","r",stdin);
		freopen("CON","w",stdout);
		
		//system("del tools\\program\\match1.out /q");
		remove("tools\\program\\match1.out"); 
		remove("tools\\program\\match2.out"); 
		remove("tools\\program\\tmp.tmp"); 
		
		return ret;
	}
	
	void debug(int id) {
		std::string _id;
		std::stringstream ss;
		ss<<id;
		ss>>_id;
		
		freopen("CON","r",stdin);
		freopen("CON","w",stdout);
		
		std::string opentmp="testdata\\"+cydata::database+_id+".in";
		freopen(opentmp.c_str(),"r",stdin);
		
		
		
		std::cout<<"测试点 : "<<id<<'\n'<<"输出 : "<<'\n';
		
		freopen("tools\\program\\pp.out","w",stdout);
		
		long long clock1=clock();
		system("tools\\program\\prog1.exe");
		long long runtime=clock()-clock1;
		
		freopen("CON","r",stdin);
		freopen("CON","w",stdout);
		
		std::ifstream in("tools\\program\\pp.out");
		std::ostringstream tmp;
		tmp<<in.rdbuf();
		
		std::cout<<tmp.str();
		
		std::cout<<'\n'<<"用时 : "<<runtime<<'\n';
		remove("tools\\program\\pp.out");
		remove("tools\\program\\tmp.tmp");
	}
	
	void judge(int id,int timax) {
		std::string _id;
		std::stringstream ss;
		ss<<id;
		ss>>_id;
		
		freopen("CON","r",stdin);
		freopen("CON","w",stdout);
		
		std::string opentmp="testdata\\"+cydata::database+_id+".in";
		std::cout<<"测试点 : "<<id<<'\n';
		freopen(opentmp.c_str(),"r",stdin);
		freopen("tools\\program\\prog1.out","w",stdout);
		
		long long clock1=clock();
		system("tools\\program\\prog1.exe");
		long long runtime=clock()-clock1;
		
		freopen("CON","r",stdin);
		freopen("CON","w",stdout);
		
		freopen("tools\\program\\tmp.tmp","w",stdout);
		
		std::string dataid="testdata"+_id+".out";
		std::string command="tools\\bin\\fc.exe /W testdata\\"+dataid+" tools\\program\\prog1.out";
		
		int flag= system(command.c_str());
		
		
		freopen("CON","r",stdin);
		freopen("CON","w",stdout);
		
		
		
		if(flag==1) std::cout<<" Unknown Error"<<'\n'<<" 用时 : "<<runtime;
		else {
			if(runtime>timax) std::cout<<" Time Limit Exceeded"<<'\n'<<" 用时 : "<<runtime;
			else if(flag==0) std::cout<<" Accepted"<<'\n'<<" 用时 : "<<runtime;
			else std::cout<<" Wrong Answer"<<'\n'<<" 用时 : "<<runtime;
		}
		std::cout<<'\n';
		remove("tools\\program\\prog1.out");
		remove("tools\\program\\tmp.tmp");
	}
	
	double SA_max(double begin,double end,double delta,double answer,double (*func)(double)) {
		double ans=answer;
		double t=begin;
		while(t>=end) {
			double flag=cyrand(0,1)?1:-1;
			//cout<<flag<<endl;
			double now=ans+flag*cyrand(1,t)/2;
			double comp=func(ans)-func(now);
			if(comp<0) ans=now;
			else {
				if(exp(-comp/t)*0x7fffffff>cyrand(1,0x7fffffff)) {
					ans=now;
				}
			}
			t*=delta;
		}
		return ans;
	}
	
	double SA_min(double begin,double end,double delta,double answer,double (*func)(double)) {
		double ans=answer;
		double t=begin;
		while(t>=end) {
			double flag=cyrand(0,1)?1:-1;
			//cout<<flag<<endl;
			double now=ans+flag*cyrand(1,t)/2;
			double comp=func(ans)-func(now);
			if(comp>0) ans=now;
			else {
				if(exp(comp/t)*0x7fffffff>cyrand(1,0x7fffffff)) {
					ans=now;
				}
			}
			t*=delta;
		}
		return ans;
	}
}

namespace cyfrac {
	bool frac_input_mode=0;
	
	struct frac{
		int x,y;
		inline frac redu() {frac ret;ret.x=x/cymath::crayon_gcd(x,y);ret.y=y/cymath::crayon_gcd(x,y);return ret;}
		inline frac back() {frac ret;ret.x=y;ret.y=x;return ret;}
		inline bool operator<(frac a) const{return x*a.y<y*a.x;}
		inline bool operator==(frac a) const{return x*a.y==y*a.x;}
		inline bool operator<=(frac a) const{return *this<a||*this==a;}
		inline bool operator>(frac a) const{return !(*this<=a);}
		inline bool operator>=(frac a) const{return !(*this<a);}
		inline bool operator!=(frac a) const{return !(*this==a);}
		operator double() {return (double)x/y;}
		operator int() {return (int)x/y;}
		inline int it(frac a) const{return (int)x/y;}
		inline frac operator+(frac a) const{frac ret;ret.x=x*a.y+y*a.x;ret.y=y*a.y;return ret.redu();}
		inline frac operator+=(frac a) {frac ret;ret.x=x*a.y+y*a.x;ret.y=y*a.y;ret=ret.redu();x=ret.x;y=ret.y;return ret;}
		inline frac operator-(frac a) const{frac ret;ret.x=x*a.y-y*a.x;ret.y=y*a.y;return ret.redu();}
		inline frac operator-=(frac a) {frac ret;ret.x=x*a.y-y*a.x;ret.y=y*a.y;x=ret.x;y=ret.y;return ret;}
		inline frac operator*(frac a) const{frac ret;ret.x=x*a.x;ret.y=y*a.y;return ret.redu();}
		inline frac operator*=(frac a) {frac ret;ret.x=x*a.x;ret.y=y*a.y;x=ret.x;y=ret.y;return ret;}
		inline frac operator/(frac a) const{return *this*a.back();}
		friend std::ostream&operator<<(std::ostream&os,const frac&c);
		friend std::istream&operator>>(std::istream&is,frac&c);
	};
	
	std::ostream&operator<<(std::ostream&os,const frac&c) {
		os<<c.x<<"/"<<c.y;
		return os;
	}
	
	std::istream&operator>>(std::istream&is,frac&c) {
		if(frac_input_mode) {
			is>>c.x ;
			char qwq;
			is>>qwq ;
			is>>c.y ;
			return is;
		} else {
			is>>c.x ;
			is>>c.y ;
			return is;
		}
	}
}

namespace cygraph{
	template<typename T>
	struct edge {
		int v;
		T w;
		edge() {}
		edge(int a,T b) {v=a,w=b;}
		
		bool operator<(const edge& rw )const
		{
			return w>rw.w;
		}
	};
	
	template<typename T>
	struct U {
		std::vector<edge<T> >u;
	};
	
	template<typename T>
	struct graph {
	 	int n,m;
		std::vector<U<T> >g;
		graph() {}

		void update(int ntemp) {
			U<T> updatemp;
			updatemp.u.clear();
			while(g.size()<=ntemp) g.push_back(updatemp);
		}
		
		std::vector<T> dijkstra(int beg) {
			std::priority_queue< edge<T> >q;
			bool vst[n+1];
			std::vector<T>dis;
			for(int i=0;i<=n;i++) {
				dis.push_back(T(CRAYON_INT_INF));
				vst[i]=false;
			}
			dis[beg]=0;
			edge<T> tmp;
			tmp.v=beg;
			tmp.w=0;
			q.push(tmp);
			while(!q.empty()) {
				edge<T> tmp2=q.top();
				q.pop();
				if(vst[tmp2.v]==1) continue;
				vst[tmp2.v]=1;
				for(int i=0; i<g[tmp2.v].u.size(); i++) {
					edge<T> y=g[tmp2.v].u[i];
					if(dis[y.v]>y.w+tmp2.w)
					{
						dis[y.v]=y.w+tmp2.w;
						tmp.v=y.v;
						tmp.w=dis[y.v];
						q.push(tmp);
					}
				}
			}
			return dis;
		}
		
		void addedge(int u,int v,T w) {
			n=cymath::crayon_max(n,u);
			n=cymath::crayon_max(n,v);
			update(cymath::crayon_max(u,v));
			m++;
			edge<T> tmp;tmp.v=v,tmp.w=w;
			g[u].u.push_back(tmp);
		}
		
		std::vector<T> spfa(int beg) {
			int p;
			std::deque<int>q;
			std::vector<T>dis;
			std::vector<bool>vis;
			
			switch(cystem::spfa_optimize)
			{
			case 0:
				for(int i=0;i<=n;i++) {
					dis.push_back(T(CRAYON_INT_INF));
					vis.push_back(false);
				}
				q.push_back(beg);
				dis[beg]=0;
				vis[beg]=1;
				while(!q.empty())
				{
					p=q.front();q.pop_front();
					vis[p]=0;
					for(int i=0;i<g[p].u.size();i++) {
						vis[g[p].u[i].v]=1;
						if(dis[p]+g[p].u[i].w<dis[g[p].u[i].v]) {
							q.push_back(g[p].u[i].v);
							dis[g[p].u[i].v]=dis[p]+g[p].u[i].w;
						}
					}
				}
				return dis;
			case 1:
				for(int i=0;i<=n;i++) {
					dis[i].push_back(T(CRAYON_INT_INF));
					vis.push_back(false);
				}
				q.push_back(beg);
				dis[beg]=0;
				vis[beg]=1;
				while(!q.empty())
				{
					p=q.front();q.pop_front();
					vis[p]=0;
					for(int i=0;i<g[p].u.size();i++) {
						vis[g[p].u[i].v]=1;
						if(dis[p]+g[p].u[i].w<dis[g[p].u[i].v]) {
							if(q.front()<g[p].u[i].v) q.push_front(g[p].u[i].v);
							else q.push_back(g[p].u[i].v);
							dis[g[p].u[i].v]=dis[p]+g[p].u[i].w;
						}
					}
				}
				return dis;
			}
		}
		
		
		bool is_connect() {
			const int vstsize=n+1;
			int vstn=0;
			bool vst[vstsize];
			memset(vst,false,sizeof(vst));
			std::queue<int>q;
			int begin=cyrand(1,n);
			vst[begin]=true;
			vstn=1;
			q.push(begin);
			
			while(!q.empty()) {
				int tmp=q.front();
				q.pop();
				for(int i=0;i<g[tmp].u.size();i++) {
					if(!vst[g[tmp].u[i].v]) {
						vst[g[tmp].u[i].v]=true;
						vstn++;
						q.push(g[tmp].u[i].v);
					}
				}
			}
			
			return((vstn==n)?true:false);
		}
	};
	
	template<typename T>
	std::ostream&operator<<(std::ostream&os,const graph<T>&c) {
		os<<c.n<<' '<<c.m<<'\n';
		for(int i=1;i<=c.n;i++)
		{
			for(int j=0;j<c.g[i].u.size();j++) os<<i<<' '<<c.g[i].u[j].v<<' '<<c.g[i].u[j].w<<'\n';
		}
		return os;
	}
	
	template<typename T>
	std::istream&operator>>(std::istream&is,graph<T>&c) {
		is>>c.n>>c.m;
		update(c.n);
		for(int i=1;i<=c.m;i++) {
			edge<T> tmp;
			int utmp;
			is>>utmp;
			is>>tmp.v;
			is>>tmp.w;
			c.g[utmp].u.push_back(tmp);
		}
		return is;
	}

	template<typename T>
	graph<T> operator+(graph<T> a,graph<T> b) {
		graph<T> ret;
		ret=a;
		ret.m=a.m+b.m;
		ret.update(ret.n);
		for(int i=1;i<=b.n;i++) {
			for(int j=0;j<b.g[i].u.size();j++) {
				ret.g[i].u.push_back(b.g[i].u[j]);
			}
		}
		return ret;
	}
	
	template<typename T>
	graph<T> rand_graph(int n,int m,T mn,T mx,T (*randfunc)(T,T)) {
		graph<T> ret;
		ret.n=n;
		ret.m=m;
		
		
		ret.update(n);
		
		for(int i=1;i<=m;i++) {
			edge<T> tmp; 
			tmp.v=cyrand(1,m);
			tmp.w=randfunc(mn,mx);
			ret.g[cyrand(1,n)].u.push_back(tmp);
		}
		return ret;
	}
	
	struct crayon_node2{
		int num,id1,id2;
	};
	
	bool crayon_cmp1(crayon_node2 a,crayon_node2 b) {return a.num<b.num;}

	template<typename T>
	graph<T> rand_dag(int n,int m,T mn,T mx,T (*randfunc)(T,T)) {
		graph<T> ret;
		ret.update(n);
		ret.n=n;
		ret.m=m;
		/*
		vector<crayon_node2>a;
		for(int i=0;i<=n;i++) {
			crayon_node2 tmp;
			tmp.id1=n;
			a.push_back(tmp);
		}
		*/
		for(int i=1;i<=m;i++) {
			edge<T> tmp;
			int utmp=cyrand(1,cyrand(1,n-1));
			tmp.v=cyrand(utmp+1,n);
			tmp.w=randfunc(mn,mx);
			ret.g[utmp].u.push_back(tmp);
		}
		return ret;
	}
	
	struct crayon_node1 {
		int id;
		int soncnt;
	};
	
	template<typename T>
	graph<T> rand_tree(int n,int k,T mn,T mx,T (*randfunc)(T,T)) {
		graph<T> ret;
		ret.n=n;
		ret.m=n-1;
		ret.update(n);
		std::vector<crayon_node1>t;
		std::vector<int>hash;
		for(int i=1;i<=n;i++) {
			hash.push_back(i);
		}
		random_shuffle(hash.begin(),hash.end());
		crayon_node1 updatemp;
		updatemp.id=hash[0];
		updatemp.soncnt=0;
		t.push_back(updatemp);
		for(int j=2;j<=n;j++) {
			int i=hash[j-1];
			std::swap(t[cyrand(0,t.size()-1)],t[t.size()-1]);
			t[t.size()-1].soncnt++;
			if(t[t.size()-1].soncnt==k) t.pop_back();
			edge<T> tmp;
			tmp.v=t[t.size()-1].id;
			tmp.w=randfunc(mn,mx);
			ret.g[i].u.push_back(tmp);
			updatemp.id=i;
			updatemp.soncnt=0;
			t.push_back(updatemp);
		}
		return ret;
	}
	
	template<typename T>
	graph<T> connect_graph(int n,int m,T mn,T mx,T (*randfunc)(T,T)) {
		int k=cyrand(1,n);
 		graph<T> ret;
		ret=rand_tree(n,k,mn,mx,randfunc);
		ret.m=m;
		for(int i=n;i<=m;i++) {
			edge<T> tmp;
			tmp.v=cyrand(1,n);
			tmp.w=randfunc(mn,mx);
			ret.g[cyrand(1,n)].u.push_back(tmp);
		}
		return ret;
	}
	
	/*
	graph hack_spfa(int n,int m,int mn,int mx,int lvl) {
		graph ret;
		
		int mid;
		
		
		switch(lvl)
		{
		case 1:
			ret=rand_graph(n,m,mn,mx);
			return ret;
		case 2:
			if(n<=1) {
				cydata::close_file();
				std::cout<<"[Error]点数过小";
				exit(0);
			}
			mid=cyrand(1,n);
			if(m>=n) {
				ret.n=n;
				ret.m=m;
				ret.update(n);
				for(int i=1;i<=n;i++) {
					if(i==mid) continue;
					edge tmp;
					tmp.v=i;
					tmp.w=cyrand(mn,(mn+mx)/2);
					ret.g[mid].u.push_back(tmp);
				}
				for(int i=1;i<=m-n;i++) {
					if(i==mid) continue;
					edge tmp;
					tmp.v=i;
					tmp.w=mx;
					ret.g[mid].u.push_back(tmp);
				}
				return ret;
			}
			else{
				for(int i=1;i<=m;i++) {
					if(i==mid) continue;
					edge tmp;
					tmp.v=i;
					tmp.w=cyrand(mn,(mn+mx)/2);
					ret.g[mid].u.push_back(tmp);
				}
				return ret;
			}
		case 3:
			ret.n=n;
			ret.m=m;
			ret.update(n);
			if(m<n*2) {
				cydata::close_file();
				std::cout<<"[Error]边数过小";
				exit(0);
			}
			if(n<=1) {
				cydata::close_file();
				std::cout<<"[Error]点数过小";
				exit(0);
			}
			int mid1=cyrand(1,n);
			int mid2=cyrand(1,n);
			if(mid1==mid2) ++mid2;
			for(int i=1;i<=n;i++) {
				if(i==mid1) continue;
				if(i==mid2) continue;
				edge tmp;
				tmp.v=i;
				tmp.w=cyrand((mn+mx)/2,mx);
				ret.g[mid1].u.push_back(tmp);
			}
			edge tmp;
			tmp.v=mid2;
			tmp.w=cyrand(mn,(mn+mx)/2);
			ret.g[mid1].u.push_back(tmp);
			for(int i=1;i<=n;i++) {
				if(i==mid1) continue;
				if(i==mid2) continue;
				edge tmp;
				tmp.v=i;
				tmp.w=cyrand((mn+mx)/2,mx);
				ret.g[mid2].u.push_back(tmp);
			}
			for(int i=1;i<=m-n*2;i++) {
				edge tmp;
				tmp.v=cyrand(1,n);
				tmp.w=cyrand((mn+mx)/3*2,mx);
				ret.g[cyrand(1,n)].u.push_back(tmp);
			}
		}
	}
	*/
}

namespace cygeom {
	#define CRAYON_PI 3.141592653589793238462643383279
	#define ORIGIN point(0,0)
	struct point {
		double x;
		double y;
		point(double xx=0,double yy=0) {x=xx,y=yy;}
		double dis(point a) {return sqrt(abs(x-a.x)*abs(x-a.x)+abs(y-a.y)*abs(y-a.y));}
		friend std::ostream&operator<<(std::ostream&os,const point&p);
		friend std::istream&operator>>(std::istream&is,point&p);
	};
	std::ostream&operator<<(std::ostream&os,const point&p) {
		os<<p.x<<" "<<p.y;
		return os;
	}
	std::istream&operator>>(std::istream&is,point&p) {
		is>>p.x>>p.y;
		return is;
	}
	
	double dis(point a,point b) {return sqrt(abs(a.x-b.x)*abs(a.x-b.x)+abs(a.y-b.y)*abs(a.y-b.y));}
	
	struct cyvector {
		int x,y;
		cyvector(double xx=0,double yy=0) {x=xx,y=yy;}
		double len() {return dis(point(x,y),ORIGIN);}
	};
	/*
	cyvector operator+(crayon_vector a,crayon_vector b) {
		crayon_vector ret;
		ret.u=a.u;
		ret.v=
		return 0;
	}
	
	cyvector operator-(crayon_vector a,crayon_vector b) {
		return 0;
	}
	crayon_vector operator*(crayon_vector a,crayon_vector b) {//点积
		return 0;
	}
	crayon_vector operator^(crayon_vector a,crayon_vector b) {//叉积
		return 0;
	}
	*/
	
	struct triangle {
		point a,b,c;
		double circ() {return dis(a,b)+dis(b,c)+dis(c,a);}
		double area() {int P=circ()/2,A=dis(b,c),B=dis(a,c),C=dis(a,b);return sqrt(P*(P-A)*(P-B)*(P-C));}
		friend std::ostream&operator<<(std::ostream&os,const triangle&t);
		friend std::istream&operator>>(std::istream&is,triangle&t);
	};
	std::ostream&operator<<(std::ostream&os,const triangle&t) {
		os<<t.a<<'\n'<<t.b<<'\n'<<t.c;
		return os;
	}
	std::istream&operator>>(std::istream&is,triangle&t) {
		is>>t.a>>t.b>>t.c;
		return is;
	}
	
	struct circle {
		double r;
		double circ() {return CRAYON_PI*r*2;}
		double area() {return CRAYON_PI*r*r;}
		friend std::ostream&operator<<(std::ostream&os,const circle&c);
		friend std::istream&operator>>(std::istream&is,circle&c);
	};
	std::ostream&operator<<(std::ostream&os,const circle&c) {
		os<<c.r;
		return os;
	}
	std::istream&operator>>(std::istream&is,circle&c) {
		is>>c.r;
		return is;
	}
	
	/*
	struct polygon {
		int n;
		std::vector<point>a;
		dbx() {
			n=0;
			a.clear();
		}
		void update(int now) {
			point updatemp;
			while(a.size()<now) a.push_back(updatemp);
		}
	};
	*/
}

#if __cplusplus == 201103
namespace crayon_for_Cpp_11 {
	template<typename T>
	T choice(std::initializer_list<T>a) {
		std::vector<T>b;
		for(auto i:a) {
			b.push_back(i);
		}
		return b[cyrand(1,b.size())-1];
	}
	
	std::string rand_string(int len,std::initializer_list<char>charset) {
		std::string ret="";
		for(int i=1;i<=len;i++) {
			ret+=choice(charset);
		}
		return ret;
	}
}
#endif

#include"tools/lib/plugs/includes.hpp"//for your plugs

namespace cy {
	using namespace cymath;
	using namespace cystem;
	using namespace cydata;
	using namespace cydebug;
	using namespace cyfrac;
	using namespace cygraph;
	using namespace cygeom;
	
#if __cplusplus == 201103
	using namespace crayon_for_Cpp_11;
#endif
	#include"tools/lib/plugs/namespaces.hpp"
}
