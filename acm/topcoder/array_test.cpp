#ifdef do_not_compile_this_file
#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<iterator>
#include<ostream>
#include<fstream>
#include<deque>
#include<stack>
#include<queue>
#include<functional>
using namespace std;


template<typename T>
struct point{
	point(T X = 0, T Y = 0) : x(X), y(Y){}
	T x, y;
};

template<typename T>
struct line {
	line(point<T> a, point<T> b) : left(a), right(b){}
	point<T> left, right;
};

template<typename T>
ostream& operator<<(ostream& os,const point<T>& p){
	os << '(' << p.x << ',' << p.y << ')';
	return os;
}

template<typename T>
ostream& operator<<(ostream& os, line<T>& l){
	os << '[' << l.left << "..." << l.right << ']';
	return os;
}

template<typename T>
point<T> operator+(point<T>& a, point<T>& b){
	return point<T>(a.x + b.x, a.y + b.y);
}

template<typename T>
int operator*(point<T>& a, point<T>& b){
	return a.x *b.x + a.y*a.y;
}

template<typename T>
ostream& operator<<(ostream& os, vector<T>& v){
	for (auto e : v) os << e << ' ';
	return os;
}

template<typename T>
bool operator<(const point<T>& a, const  point<T>& b){
	if (a.x != b.x) return a.x < b.x;
	return a.y < b.y;
}
template<typename T>
bool operator>(const point<T>& a, const  point<T>& b){
	return b < a;
}


int main(){
	ios_base::sync_with_stdio(false);
	//{
	//	point<int> p(3), p2(2, 5);
	//	cout << p << ' ' << p2 << ' ' << p2 + p << ' ' << p*p2 << endl;
	//	line<int> l(p, p2);

	//	cout << l << endl;
	//};
	//{
	//	typedef point<double> pd;
	//	typedef line<double > ld;
	//	pd a(2.3, 4.1), b(8.2, -3.1);
	//	cout << a << b << a + b << a*b << endl;
	//	ld l(a, b);
	//	cout << l << endl;
	//}

	//vector<int> v;
	//for (int i = 1; i < 15; i += 3)
	//	v.push_back(i);

	////for (int elem : v) cout << elem << endl;
	//cout << v << endl;

	vector<point<float>> v(1);

	for (int i = 0; i < 8; ++i)
		v.push_back(point<float>(
		(rand() % 20 - 10)*1.1,
		(rand() % 20 - 10)*1.1
		));

	sort(v.begin(), v.end(), greater<point<float>>());
	//cout << v << endl;
	copy(v.begin(), v.end(), ostream_iterator<point<float>>(cout));

	//map<string, int> m;
	//m["amin"] = 1;
	//m["ali"] = 2;

	//cout << m["amin"] + m["ali"] << endl;
	return 0;
}

#endif