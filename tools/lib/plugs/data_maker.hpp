//for https://www.luogu.org/problem/T106958
namespace data_maker{
	void make_data(int id){
		std::string in;
		while(in!="ans"){
			std::cin>>in;
			if(in=="ans") break;
			printf("p[pb].data[%d].in.push(",id);
			std::cout<<in<<");\n";
		}
		std::cin>>in;
		printf("p[pb].data[%d].ans=\"",id);
		std::cout<<in<<"\";\n";
	}
} 
