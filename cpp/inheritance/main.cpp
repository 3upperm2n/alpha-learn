#include <iostream>

class Alpha {
public:
  virtual void foo(int i) {
	std::cout << "alpha::foo(int)" << std::endl;	  
  }	
	
  virtual void foo(char c) {
	std::cout << "alpha::foo(char)" << std::endl;	  
  }	

  virtual void foo(float f) {
	std::cout << "alpha::foo(float)" << std::endl;	  
  }	

  virtual void foo(const char *cc) {
	std::cout << "alpha::foo(string/constant char)" << std::endl;	  
  }	
};


class Beta : public Alpha {
public:
  void foo(int i) {
	std::cout << "Beta::foo(int)" << std::endl;	  
  }
	
  void foo(char c) {
	std::cout << "Beta::foo(char)" << std::endl;	  
  }
};


int main(int argc, char **argv) {

  Beta *b = new Beta();	
  std::cout << "size of Beta class : " << sizeof(b) << " bytes\n";
	
  b->foo((int)1);
  b->foo('A');

  // since Beta doesn't support the other two input data type, the overloading 
  // doesn't work
  // b->foo((float)1.1);
  // b->foo("mystring");

  Alpha *a = b;
  a->foo((int)1);
  a->foo((float)1.1);


  delete b;
	
  return 0;
}
