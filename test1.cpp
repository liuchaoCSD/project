#include<iostream>
#include<ctime>
#include<string>
#pragma warning(disable:4996)
using namespace std;
//typedef int T;
//class A{
//	T* a;
//	int len;
//public:
//	A(int n, T init = T()) :a(new T[n]){
//		for (int i = 0; i < n; ++i)a[i] = init;
//			len = n;
//		cout << "创建数组" << len << "个元素i" << init << endl;
//	}
//	~A(){
//		cout << "释放数组" << a << endl;
//		delete[] a; a = NULL;
//	}
//	T& at(int idx){
//		if (idx < 0 || idx >= len) throw idx;
//		return a[idx];
//	}
//	int size(){
//		return len;
//	}
//	void resize(int newsize, const T& val = T()){
//		if (newsize <= len)len = newsize;
//		else{
//			T* np = new T[newsize];
//			for (int i = 0; i < len; i++)
//				np[i] = a[i];
//			for (int j = len; j < newsize; ++j)
//				np[j] = val;
//			delete[]a;
//			a = np;
//			len = newsize;
//		}
//	}
//	void print(){
//		for (int i = 0; i < len; ++i)
//			cout << a[i] << ' ';
//		cout << endl;
//	}
//	void fill(const T& start, const T& step = T()){
//		for (int i = 0; i < len; ++i)
//			a[i] = start + step*i;
//	}
//	A(const A& r)
//	{
//		len = r.len;
//		a = new T[len];
//		for (int i = 0; i < len; ++i)
//			a[i] = r.a[i];
//		cout << a << "创建一个数组对象复制" << r.a << endl;
//	}
//	};
//A filter(A arr)//过滤
//{
//	for (int i = 0;i<arr.size();i++)
//	if (arr.at(i) % 2 == 0)
//		cout << arr.at(i) << ' ';
//	cout << endl;
//	return arr;
//}
//int main()
//{
//	A x(20);
//	x.fill(11, 1);
//	
//	//x.at(3) = 5;
//	x.print();
//	filter(x).print();
//	return 0;
//}


//class A{
//	int* a;
//	int len;
//	
//public:
//	A(int n, int init =0) :a(new int[n]),len(n){
//		for (int i = 0; i < n; i++)a[i] = init;
//	
//	}
//	~A(){
//		
//		delete[] a; a = NULL;
//	}
//	void set(int idx, int val)
//	{
//		a[idx] = val;
//	}
//	int get(int idx)
//	{
//		return a[idx];
//	}
//	void randfill(){
//		srand(time(NULL));
//		for (int i = 0; i < len; i++)
//			a[i] = rand()%100;
//	}
//	int size(){
//		return len;
//	}
//	
//	int next(){
//		return a[cur++%len];
//	}
//	int cur;
//};
//void use( A& x)
//{
//	for (int i = 0; i < 3;++i)
//	cout<<x.next()<<' ';
//	cout << endl;
//	for (int i = 0; i < 4; ++i)
//		cout << x.next()<<' ';
//	cout << endl;
//	for (int i = 0; i < 5; ++i)
//		cout << x.next() << ' ';
//	cout << endl;
//}
//int main()
//{
//	A x(10);
//	x.randfill();
//	for (int i = 0; i < x.size(); i++)
//		cout << x.get(i) << ' ';
//	cout << endl;
//    use(x);
//	return 0;
//}
//class R{
////public:
//	int n;
//	int d;
//public:
//	friend ostream& operator<<(ostream& o, const R& x);//友元声明，向这个函数授权允许其访问本类c
//    friend R operator+(const R& lh, const R& rh);
//    friend R operator-(const R& lh, const R& rh);
//	R(int cn, int cd = 1) :n(cn), d(cd){
//		if (d < 0)n = -n, d = -d;
//		for (int i = d; i>1; i--){
// 				break;
//			
//		}
//	}
//	friend istream& operator>>(istream& i, R& x){
//		char c;
//		int n, d;
//		i >> n >> c >> d;
//		x = R(n, d);
//		return i;
//	}
//};
//ostream& operator<<(ostream& o, const R& x)
//{
//	o << x.n << '/' << x.d;
//	return o;
//}
//R operator+(const R& lh, const R& rh){
//	return R(lh.n*rh.d + lh.d*rh.n, lh.d*rh.d);
//}
//R operator-(const R& lh, const R& rh){
//	return R(lh.n*rh.d - lh.d*rh.n, lh.d*rh.d);
//}
//int main()
//{
//	R a(6, 8), b(8, -12);
//	cout << a;//operator<<(cout<<a)
//	
//	cout << b;
//	cout << endl;
//	cin >> a >> b;
//	cout << a + b << endl;//operator<<(operator<<(cout,operator+(a,b)),endl);
//	cout << a - b << endl;
//	return 0;
//}
//[]()->=type 只能是成员函数
//class S{
//	char* p;
//	int len;
//private:
//	S(const S& x);
//public:
//	S(const char* str = ""){
//		len = strlen(str);
//		p = new char[len + 1];
//		strcpy(p, str);
//	}
//	~S(){
//		delete[] p; p = NULL;
//	}
//	S&	operator= (const S& x){
//		if (&x == this)return *this;
//		len = x.len;
//		delete[]p;//释放旧的动态内存
//		p = new char[len + 1];//为p开辟新动态内存
//		strcpy(p, x.p);//复制动态内存中的字符串
//		return *this;
//	}
//	friend ostream& operator<<(ostream&o, const S& x){
//		return o << x.p;
//	}
//  char& operator[](int idx){
//		return p[idx];//keyi先做越界检查
//	}
//	};
//int main()
//{
//	S a, b = "furong"; 
//	S c;
//	c = a = b;
//	cout << a << ' ' << b <<' '<<c<< endl;
//	cout << a[3] << endl;
//	a[1] = 'o';
//	cout << a << endl;
//	return 0;
//}
//class P{
//	string name;
//	int age;
//	float salary;
//public:
//	P(const char* n, int a, float s) :name(n), age(a), salary(s){}
//	operator double(){//不写返回类型
//		return salary;
//	}
//	operator int(){//不写返回类型
//		return age;
//	}
//	operator string(){//不写返回类型
//		return name;
//	}
//};
//int main()
//{
//	P a("芙蓉", 18, 80000);
//	string info = a;//(string)a,a.operator string()
//	double money = a;//（double)a ,a.operator double()
//    int age = a;//(int)a,a.operator int()
//	cout << info << ' ' << money << ' ' << age << endl;
//	return 0;
//}
class A{
	int *p;
	int len;
public:
	A(int n, int v = 0) :p(new int[n]), len(n){
		for (int i = 0; i < n; i++)p[i] = v;
	}
	void	operator()(int start, int step){
		for (int i = 0; i < len; i++)
			p[i] = start + i*step;
	}
int 	operator()(){
		int sum = 0;
		for (int i = 0; i < len; i++)
			sum += p[i];
		return sum;
	}
friend ostream& operator<<(ostream& o, const A& x){
	for (int i = 0; i < x.len; i++)
		o << x.p[i] << ' ';
	return o;
}
};
int main()
{
	A a(10);
	a(5, 1);//从5开始步长为1填充数组
	//operator() (5,1)
	cout << a << endl;
	cout << a() << endl;
	return 0;
}















































