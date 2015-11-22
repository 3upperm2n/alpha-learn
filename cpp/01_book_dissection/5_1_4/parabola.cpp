#include <iostream>

using namespace std;

class point {
public:
	point():x(0), y(0) {} 
	point(double u) : x(u), y(0) {}
	point(double u, double v) : x(u), y(v) {}

	void print() const {cout << "(" << x << "," << y << ")" << endl;}

	void set(double u, double v) {x =u; y =v;}

	void plus(point c); 
	
private:
	double x,y;	
};


void point::plus(point c) {
	x += c.x;	
	y += c.y;	
}

double parabola(double x, double y) {
	return (x * x) / y;	
}

void graph(double a, double b, double incr, double f(double, double), 
	double p, point gr[]) {
	double x = a;	
	for(int i=0; x <= b;i++, x += incr)
		gr[i].set(x, f(x,p));
}

const int no_of_pts = 20;

int main() {
	point g[no_of_pts];

	graph(0, 2, 0.1, parabola, 5, g);

	cout << "first 20 samples" << endl;

	for(int i=0; i<no_of_pts; i++) {
		g[i].print();
		if((i%5) == 4)	
			cout << endl;
		else
			cout << " ";
	}

    return 0;
}
