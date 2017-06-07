#include <iostream>
#include <set>
#include <map>

using namespace std;

class point {
	int x, y;
public:
	point(int argX, int argy): x(argX), y(argy){}
	void setX(int argX) { x = argX; }
	void setY(int argY) { y = argY; }
	int  getX() const { return x; }
	int const getY() const { return y; }
	bool operator < (const point& other) const {
		if (x == other.x)
			return y < other.y;
		return x < other.x;
	}
};

struct pointComparer {
	bool operator() (const point &first, const point &second) const{
		first.getX();
		if (first.getX() == second.getX())
			return first.getY() < second.getY();
		return first.getX() < second.getX();
	}
};

int main() {
	map<point, point> mymap;
	point p1(1,2), p2(3,4);
	point p3(5, 6), p4(7, 8);
	mymap.insert(make_pair(p3, p4));
	mymap.insert(make_pair(p1, p2));

	map<point, point, pointComparer> mymap2;
	return 0;
}