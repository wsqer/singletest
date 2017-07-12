#ifndef XDATA_H
#define XDATA_H
#include "string"
#include "QString"
#include "vector"
using namespace std;
class Xdata
{

public:
    vector<QString> tit;
    vector<QString> As;
    vector<QString> Bs;
    vector<QString> Cs;
    vector<QString> Ds;
    vector<int> res;
    Xdata();

};

#endif // XDATA_H
