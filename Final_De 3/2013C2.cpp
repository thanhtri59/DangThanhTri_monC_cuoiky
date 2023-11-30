#include <iostream>
using namespace std;

//----------------Vi du ham huy ao ----------------------
class SucVat {
public:
    virtual ~SucVat() {
        cout << "Ham huy SucVat" << endl;
    }
};

class Meo : public SucVat {
public:
    ~Meo() {
        cout << "Ham huy Meo" << endl;
    }
};
//---------------------------------------------------------

//---------------Vi du khong goi ham huy ao------------
class SucVat {
public:
    ~SucVat() {
        cout << "Ham huy SucVat" << endl;
    }
};

class Meo : public SucVat {
public:
    ~Meo() {
        cout << "Ham huy Meo" << endl;
    }
};
//----------------------------------------------------------
int main() {
    SucVat* ptr = new Meo();
    delete ptr;  // chi goi ham huy cua lop SucVat
    return 0;
}
