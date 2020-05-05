#include <iostream>
#include <stdio.h>
#include <complex>
using namespace std;




typedef struct eq_side{





}eq_side;


namespace solver
{
    
    
    class RealVariable
    {
        double _co;
        double _free;
        double _exp_co;
        
        



        public:
            
            RealVariable(){
                this->_co=1;
                this->_free=0;
                this->_exp_co=0;
            }
            RealVariable(const double& co = 1, const double& free = 0,
             const double& exp_co = 0) : _co(co), _free(free), _exp_co(exp_co){ };

            double _co() const{
                return this->_co;
            }
            double _free() const
            {
                return this->_free;
            }
            double _exp_co() const
            {
                return this->_co;
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
        
            ComplexVariable(){
                this->_im=0.0;
                this->_re=0.0;
            }
            double _re(){
                return _re;
            }
            double _im()
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