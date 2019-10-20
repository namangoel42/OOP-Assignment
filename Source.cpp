#include<iostream>
using namespace std;
class Shape {
	virtual bool overlap() = 0;
	//bool overlap(rectangle r1,rectangle r2) {}
	//bool overlap(circle c1, circle c2){}
};
class rectangle : public Shape {
public:
	int l1, l2, b1, b2;//l1 l2 and b1 b2 are the cordinates in ascending order
	rectangle(){}
	rectangle(int l1, int l2, int b1, int b2) {
		this->l1 = l1;
		this->l2 = l2;
		this->b1 = b1;
		this->b2 = b1;
	}
	bool overlap() {
		return true;
	}
	/*bool overlap(circle c1,circle c2){
	}*/
	bool overlap(rectangle r1,rectangle r2) {
		// r1 is in r2 or not
		if ((r2.l1 <= r1.l1 or r1.l1 <= r2.l2) or (r2.b1 <= r1.b1 or r1.b1 <= r2.b2)) {
			return true;
		}
		else {
			return false;
		}
	}
};
class circle : public Shape {
public:
	int ce, r;
	circle(){}
	circle(int ce,int r){
		this->ce = ce;
		this->r = r;
	}
	bool overlap() {
		return true;
	}
	bool overlap(rectangle r1, rectangle r2){}
	bool overlap(circle c1, circle c2) {
		if ((c2.ce - c2.r <= c1.ce) or (c1.ce <= c2.ce + r)) {
			return true;
		}
		else {
			return false;
		}
	}
};
int main() {
	cout << "Enter the coordinates of length and breadth in ascending order"<<endl;
	int l1, l2, b1, b2;
	int l3, l4, b3, b4;
	cin >> l1 >> l2 >> b1 >> b2;
	cout << "Enter coordinates of second rectangle";
	rectangle r1(l1, l2, b1, b2);
	cin >> l3 >> l4 >> b3 >> b4;
	rectangle r2(l3, l4, b3, b4);
	if (r1.overlap(r1, r2)) {
		cout << "Rectangles overlap";
	}
	else {
		cout << "Rectangles don't overlap";
	}
	cout << "Enter centeres and radius of circles in ascending order";
	int ce1, ra1, ce2, ra2;
	cin >> ce1 >> ra1 >> ce2 >> ra2;
	circle c1(ce1, ra1), c2(ce2, ra2);
	if (c1.overlap(c1, c2)) {
		cout << "Circles overlap";
	}
	else {
		cout << "Circles don't overlap";
	}
}