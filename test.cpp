//#include <algorithm>
//#include<iostream>
//
//int main()
//{
//	char str[] = "abcdefg";
//	std::reverse(str, str + strlen(str));
//	std::cout << str <<std::endl;
//	return 0;
//}
//#include <iostream>
//#include <queue>
//#include <map>
//using namespace std;
//
//typedef long long llint;
//const llint base = 1000000007LL;
//
//int solve(int x0)
//{
//	queue<int> q;//存储模
//	map<int, int> m;//存储{模: 数量}
//	q.push(x0);
//	m[x0] = 0;
//	while (!q.empty())
//	{
//		llint now = q.front();
//		q.pop();
//		if (now == 0)
//			return m[now];
//		if (m[now] > 100000)
//			continue;//不计算下一个数了
//		int next0 = (now * 4 + 3) % base;
//		if (!m[next0])
//		{
//			m[next0] = m[now] + 1;
//			q.push(next0);
//		}
//		int next1 = (now * 8 + 7) % base;
//		if (!m[next1])
//		{
//			m[next1] = m[now] + 1;
//			q.push(next1);
//		}
//	}
//	return -1;
//}
//
//int main()
//{
//	int x0;
//	while (cin >> x0)
//	{
//		cout << solve(x0) << endl;
//	}
//	return 0;
//}
//#include<iostream>
//#include<memory>
//using namespace std;
//struct ListNode{
//
//};
//void test_std_ptr()
//{
//	auto_ptr<ListNode> ap1(new ListNode);
//	
//}
//int main()
//{
//	test_std_ptr();
//	return 0;
//}
//#include <iostream>
//#include <cstdio>
//using namespace std;
//int main()
//{
//	int n, ans = 0;
//	cin >> n;
//	for (int i = 0; i < n; i++){
//		for (int j = 0; j < n; j++){
//			int x; 
//			scanf_s("%d", &x);
//			ans += x;
//		}
//	}
//	cout << ans << endl;
//	return 0;
//}
//#include<iostream>
//#include<cstring>
//#pragma  warning(disable:4996)
//using namespace std;
//namespace c{
//	struct Student{ 
//		char name[20];
//		int age;
//		void show(){
//			cout << age << "岁的" << name << "轻松搞定C++" << endl;
//		}
//	};
//}
//int main()
//{
//	c::Student s1 = { "芙蓉", 18 };
//	using namespace c;
//	Student s2;
//strcpy(s2.name,"刘超");
//s2.age = 20;
//s1.show();
//s2.show();
//union{
//	int x;
//	char y[4];
//};//匿名联合
//x = 0x61626364;
//cout << y[0] << endl;
//y[1] = '0';//0x30
//cout << hex <<showbase<< x << endl;
//return 0;
//}
//#include<iostream>
//using namespace std;
//enum Color{
//	RED=9,
//	GREEN,
//	BLUE
//};
//int main()
//{
//	enum Color c;
//	cout << RED << endl;
//	cout << GREEN << endl;
//	cout << BLUE << endl;
//	return 0;
//}
//动态创建和释放对象
#include<iostream>
#include<string>
using namespace std;
//class Buffer{
//	string name;
//public:
//	Buffer(const string& filename):name(filename)
//	{ 
//		cout << "为" << filename << "分配缓冲区" << endl; 
//	}
//	~Buffer()
//	{
//		cout << "清理" << name << "的缓冲区" << endl;
//	}
//};
//class File{
//	string path;
//	Buffer* p;
//public:
//	File(const string& path = "无名") :path(path), p(0)
//	{//:后的第一个path是成员，里面的是形参
//		cout <<this<< "创建文件" << path << endl;
//	}
//	~File(){//析构，对象释放时自动调用
//		cout <<this<< path << "释放" << endl;
//	}
//	void open(){
//		p = new Buffer(path);
//
//	}
//	void close(){
//		delete p; p = NULL;
//	}
//};
//			int main()
//	{
//				File a("a");
//	//	File* p1 = new File;//空括号可加可不加
//		File* p2 = new File("/etc/passwd");
//		/*File* p3 = new File[3];
//		delete[] p3;
//		p3 = NULL*/; 
//		a.open();
//		p2->open();
//		delete p2; 
//		p2 = NULL;
//		/*delete p1;
//		p1 = NULL;*/
//		return 0;
//	}
class R{
	int n;
	int d;
public:
	R(int n, int d = 1) :n(n), d(d){
		cout << "R(" << n << '/'<<d << ")"<< endl;
	}
	R add(const R& r2){
		int nd = d*r2.d;
		int nn = d*r2.n + n*r2.d;
		R result(nn, nd);
		return result;
	}
	void show(){
		cout << n << '/' << d << endl;
	}
	~R(){
		cout << "R(" << n << '/' << d << ")" << endl;
	}

};
int main()
{
	R a(1, 2), b(3, 6);
	a.add(b).show();
	cout << "---------------" << endl;
	a.add(R(3, 8)).show();
	cout << "---------------" << endl;
	a.add(R(3)).show();
	cout << "---------------" << endl;
	return 0;
}


















































































































