/*
Polymorphism
    ->Runtime
        * Method Overriding
    ->Compile Time
        * Method Overloading
        * Operator Overloading
*/

//Method Overloading
int multiply(int a, int b) {
    return (a * b);
}

string multiply(string a, int time) {
    string ans;
    for (int i = 0; i < time; ++i) {
        ans += a;
    }
    return ans;
}

//Operator Overloading
class Complex {
public:
    int real;
    int complex;

    Complex(int r, int c) {
        real = r;
        complex = c;
    }

    Complex operator+(Complex rhs) {
        Complex temp((this->real + rhs.real), (this->complex + rhs.complex));
        return temp;
    }

    friend ostream & operator << (ostream &out, const Complex &c);
};

ostream & operator << (ostream &out, const Complex &c)
{
    out << c.real << " + " << c.complex << "i";
    return out;
}

//Method Overriding
class Base {
public:
    virtual void print() {
        cout << "Base class printing" << endl;
    }
};

class Derived: public Base {
public:
    void print() {
        cout << "Derived class printing" << endl;
    }
};

void solve() {
    cout << multiply(3, 2) << endl;
    cout << multiply("Hello", 3) << endl;

    Complex a(10, 12);
    Complex b(13, 14);
    cout << a << endl;
    cout << b << endl;
    Complex z = a + b;
    cout << z << endl;

    Base* bptr = new Derived();
    bptr->print();
}