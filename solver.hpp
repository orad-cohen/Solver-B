#include <iostream>
#include <stdio.h>
#include <complex>
using namespace std;





namespace solver
{

    
    
    class RealVariable
    {
        double _co;
        double _free;
        double _exp_co;
        double rounder(double d)
        {
            double scale = 0.000001; // i.e. round to nearest one-hundreth
            int s = (int)d*10000;
            d = double(s/10000);
            return d;
        }

        public:
            
            
            RealVariable(const double& co = 1.0, const double& free = 0.0,
             const double& exp_co = 0.0) : _co(co), _free(free), _exp_co(exp_co){
                 this->_free = rounder(free);
                 this->_exp_co = rounder(exp_co);
                 this->_co = rounder(co);
                 cout << "constructor co: " <<_co << " exp_co: " << _exp_co << " at_free: " << _free << endl;
              };

            double co() const{
                return round(_co);
            }
            double at_free() const
            {
                return round(_free);
            }
            double exp_co() const
            {
                return round(_exp_co);
            }
            friend const RealVariable &operator*(double r, const RealVariable &x);
            friend const RealVariable &operator==(const RealVariable &x, double r);
            friend const RealVariable &operator==(const RealVariable &x, const RealVariable &x2);
            friend const RealVariable &operator-(const RealVariable &r, double d);
            friend const RealVariable &operator^(const RealVariable &x, double r);

            friend const RealVariable &operator+(const RealVariable &r1, double d1);
            friend const RealVariable &operator+(const RealVariable &r1, const RealVariable &r2);
            friend const RealVariable &operator+(double d1, const RealVariable &r2);
            friend const RealVariable &operator/(const RealVariable &r1, double d1);
            
            friend const RealVariable &operator-(const RealVariable &r1, const RealVariable &d1);
            friend const RealVariable &operator==(const RealVariable &r1, const RealVariable &r2);
    };

    class ComplexVariable
    {
        double _re,_im;

        public:
        
            ComplexVariable(const double& re = 1.0, const double& im = 0.0):
            _re(re),_im(im){
                this->_im=im;
                this->_re=re;
            }
            double re(){
                return _re;
            }
            double im()
            {
                return _im;
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
    };
   

    

    complex<double> solve(const ComplexVariable &cmplx);
    double solve(const RealVariable &r);
        
    


    
    
}