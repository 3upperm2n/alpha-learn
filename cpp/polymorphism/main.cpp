#include <iostream>


class Contact {
public:
  void say_hello() {
	std::cout << "contact say hello\n";	  
  }	

  virtual void say_bye() {
	std::cout << "contact say goodbye\n";	  
  }	
};


class Friend : public Contact {
private:
  int a;
  
public:
  void say_hello () {
	std::cout << "friend say hello\n";	  
  }	
	
  void say_yes() {
	std::cout << "friend say yes\n";	  
  }

  void say_bye() {
	std::cout << "friend say goodbye\n";	  
  }
};


int main(int argc, char **argv) {
  Contact *c = new Friend();
  // C is the base class pointer, say_hello() is not a virtual function
  c->say_hello(); // use base class
  c->say_bye();	  // use virtual function for friend class
	
  // inherited class can't point to base class, Friend *f = c won't work
  Friend *f = static_cast<Friend *>(c);	
  f->say_hello();

  
  Contact *d = new Contact;
  Friend *e = static_cast<Friend*> (d);

  // the pointer always traces back to the original class
  e->say_bye();
  e->say_yes();


  delete c,d;

  return 0;	
}
