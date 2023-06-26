#include <iostream>
#include <string>
#include <vector>

using namespace std;

class A {
  private: string name;
  A * p;
  public: A(A * p, string name);
  A(A * p) {
    this -> p = p;
  }
  vector < A * > c;
  void detname(string name) {
    this -> name = name;
  }
  string getname() {
    return name;
  };
  void out();
};

A::A(A * p, string name1) {
  detname(name1);
  this -> p = p;
  if (p != 0)
    this -> p -> c.push_back(this);
}
class B: public A {
  public: using A::A;
  void bb();
  bool exec_app();
};

void A::out() {
  cout << this -> getname();
  for (int i = 0; i < this -> c.size(); i++)
    cout << " " << this -> c[i] -> getname();
  for (int i = 0; i < this -> c.size(); i++) {
    if (this -> c[i] -> c.size() != 0) {
      cout << endl;
      c[i] -> out();
    }
  }
};

void B::bb() {
  string r, pr, name;
  cin >> r;
  B * ob = new B(0, r);
  A * obr = ob;
  16 B * temp = 0;
  for (int i = 0;; i++) {
    cin >> pr >> name;
    if (pr == name)
      break;
    else if (i != 0 && ob -> getname() != pr)
      ob = temp;
    temp = new B(ob, name);
  }
  cout << obr -> getname() << endl;
  obr -> out();
}
bool B::exec_app() {
  return true;
}

int main() {
  B ob_c(nullptr);
  if (ob_c.exec_app() == true)
    ob_c.bb();
  return 0;
}
