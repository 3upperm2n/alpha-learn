#include <iostream>

//using namespace std;

class rational {
private:
	long a, q;
	enum {BIG=100};	

public:
	rational(int n = 0): a(n), q(1) {}
	rational(int i, int j) : a(i), q(j) {}
	rational(double k) : a(static_cast<long>(k * BIG)), q(BIG) {}
	void print() const {std::cout << a << " / " << q;}
	operator double() {
		return static_cast<double>(a) / q;	
	}
};


inline int greater(int i, int j) {
	return (i > j) ? i:j;	
}

inline double greater(double i, double j) {
	return (i > j) ? i:j;	
}

inline rational greater(rational i, rational j) {
	return (i > j) ? i:j;	
}


int main() {
	int i = 10, j = 5;	
	float x = 7.0;
	double y = 14.5;
	rational w(10), z(3.5), zmax;

	std::cout << "greater (" << i << " , " << j << ") = " << greater(i, j) << std::endl;

	std::cout << "greater (" << x << " , " << y << ") = " << greater(x, y) << std::endl;

	std::cout << "greater (" << i << " , ";
	z.print();
	std::cout << ") = " << greater(static_cast<rational>(i), z) << std::endl;
	
	zmax = greater(w, z);
	std::cout << "greateri(";
	w.print();
	std::cout << " , ";
	z.print();
	std::cout << ") =  ";
	zmax.print();
	std::cout << std::endl;


	return 0;	
}
