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
//	queue<int> q;//�洢ģ
//	map<int, int> m;//�洢{ģ: ����}
//	q.push(x0);
//	m[x0] = 0;
//	while (!q.empty())
//	{
//		llint now = q.front();
//		q.pop();
//		if (now == 0)
//			return m[now];
//		if (m[now] > 100000)
//			continue;//��������һ������
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
//			cout << age << "���" << name << "���ɸ㶨C++" << endl;
//		}
//	};
//}
//int main()
//{
//	c::Student s1 = { "ܽ��", 18 };
//	using namespace c;
//	Student s2;
//strcpy(s2.name,"����");
//s2.age = 20;
//s1.show();
//s2.show();
//union{
//	int x;
//	char y[4];
//};//��������
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
//��̬�������ͷŶ���
#include<iostream>
#include<string>
using namespace std;
//class Buffer{
//	string name;
//public:
//	Buffer(const string& filename):name(filename)
//	{ 
//		cout << "Ϊ" << filename << "���仺����" << endl; 
//	}
//	~Buffer()
//	{
//		cout << "����" << name << "�Ļ�����" << endl;
//	}
//};
//class File{
//	string path;
//	Buffer* p;
//public:
//	File(const string& path = "����") :path(path), p(0)
//	{//:��ĵ�һ��path�ǳ�Ա����������β�
//		cout <<this<< "�����ļ�" << path << endl;
//	}
//	~File(){//�����������ͷ�ʱ�Զ�����
//		cout <<this<< path << "�ͷ�" << endl;
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
//	//	File* p1 = new File;//�����ſɼӿɲ���
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


















































































































