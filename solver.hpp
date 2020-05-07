#include <iostream>
#include <stdio.h>
#include <complex>
using namespace std;
namespace solver
{    
    class RealVariable
    {
        double _a,_b,_c;
        public:   
            RealVariable(const double& a = 0.0, const double& b = 1.0,const double& c = 0.0) :
             _a(a), _b(b), _c(c){}

            double a() const{
                return _a;
            }
            double b() const
            {
                return _b;
            }
            double c() const
            {
                return _c;
            }
            friend const RealVariable &operator*(double r, const RealVariable &x);
            friend const RealVariable &operator*(const RealVariable &x, double r);
            friend const RealVariable &operator==(const RealVariable &x, double r);
            friend const RealVariable &operator==(const RealVariable &x, const RealVariable &x2);
            friend const RealVariable &operator==(const RealVariable &r1, const RealVariable &r2);
            friend const RealVariable &operator-(const RealVariable &r, double d);
            friend const RealVariable &operator-(const RealVariable &r1, const RealVariable &d1);
            friend const RealVariable &operator^(const RealVariable &x, double r);
            friend const RealVariable &operator+(const RealVariable &r1, double d1);
            friend const RealVariable &operator+(const RealVariable &r1, const RealVariable &r2);
            friend const RealVariable &operator+(double d1, const RealVariable &r2);
            friend const RealVariable &operator/(const RealVariable &r1, double d1);
    };
    class ComplexVariable
    {
         double _a,_b,_c,_i;
        public:   
            ComplexVariable(const double& a = 0.0, const double& b = 1.0,const double& c = 0.0, const double& i=0.0) :
             _a(a), _b(b), _c(c), _i(i){}

            double a() const{
                return _a;
            }
            double b() const
            {
                return _b;
            }
            double c() const
            {
                return _c;
            }
            double i() const
            {
                return _i;
            }
            friend const ComplexVariable &operator*(double r, const ComplexVariable &x);
            friend const ComplexVariable &operator^(const ComplexVariable &r1, double r2);
            friend const ComplexVariable &operator/(const ComplexVariable &r1, double r2);
            friend const ComplexVariable &operator-(const ComplexVariable &r1, const ComplexVariable &r2);
            friend const ComplexVariable &operator-(const ComplexVariable &r1, double r2);
            friend const ComplexVariable &operator==(const ComplexVariable &r1, double r2);
            friend const ComplexVariable &operator==(const ComplexVariable &r1, const ComplexVariable &r2);
            friend const ComplexVariable &operator+(const ComplexVariable &r1, const ComplexVariable &r2);
            friend const ComplexVariable &operator+(const ComplexVariable &r1, double r2);
            friend const ComplexVariable &operator+(double r2, const ComplexVariable &r1);
            friend const ComplexVariable &operator+(const ComplexVariable &r1, complex<double> r2);
            friend const ComplexVariable &operator+(complex<double> r2, const ComplexVariable &r1);
            friend const ComplexVariable &operator"" _i(long double d);
    };
    complex<double> solve(const ComplexVariable &cmplx);
    double solve(const RealVariable &r); 
}