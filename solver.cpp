#include "solver.hpp"
#include <iostream>
#include <stdio.h>
#include<complex>
#include<math.h>
using namespace std;
using namespace solver;

double solver::solve(const RealVariable &r){
    
    if(r.exp_co()!=0&&r.co()!=0){
        double bsq = round(r.co() * r.co());
        double asq = round(r.exp_co());
        double fsq = round (r.at_free());
        double rside = sqrt(bsq - 4 * asq * fsq);
        double lside = -bsq;
        double div = 2*asq;
        
        return (lside+rside)/div;

        

    }
    else if (r.co()!=0){
        double rside = -r.at_free();
        rside/=r.co();
        return rside;
    }

    else if(r.exp_co()!=0){
        double rside = -r.at_free();
        rside/=r.exp_co();
        
        return sqrt(rside);
    }
    else{
        throw std::invalid_argument("");
    }

        return 1.0;

}
complex<double> solver::solve(const ComplexVariable &cmplx){

    return complex<double> (3);
}
const solver::RealVariable& solver::operator*(double r, const RealVariable &x){

    
    double nco = r * (x.co());
    double neco= x.exp_co() * r;
    double nat_free= r * x.at_free();
   
    return RealVariable(nco,nat_free ,neco);
    
}

const solver::RealVariable& solver::operator==(const solver::RealVariable& x5, double r){

    
    return RealVariable(x5.co(),x5.at_free()-r,x5.exp_co());}
const solver::RealVariable &solver::operator==(const solver::RealVariable &x, const solver::RealVariable &x2){
    return x-x2;}

const solver::RealVariable& solver::operator^(const solver::RealVariable& x, double r){
    if(r!=2){
        throw std::invalid_argument("Exponent cannot be anything besides 1 or 2");
    }
    else{ return RealVariable(0,x.at_free(),1);}
}

const solver::RealVariable& solver::operator-(const solver::RealVariable& x, double d){

    double newd= x.at_free()-d;
    return RealVariable(x.co(), newd, x.exp_co());

}
const solver::RealVariable &solver::operator-(const solver::RealVariable &x1, const solver::RealVariable &x2){
   
    return RealVariable(x1.co() - x2.co(), x1.at_free() - x2.at_free(), x1.exp_co() - x2.exp_co());
}
const solver::RealVariable& solver::operator+(const solver::RealVariable& x, double d){return RealVariable(x.co(), x.at_free() + d, x.exp_co());}
const solver::RealVariable& solver::operator+(const solver::RealVariable&  x1, const solver::RealVariable& x2){return RealVariable(x1.co()+x2.co(), x1.at_free() +x2.at_free(), x1.exp_co()+x2.exp_co());}

const solver::RealVariable& solver::operator+(double d1, const solver::RealVariable& x2){return RealVariable(x2.co(),x2.at_free()+d1,x2.exp_co());}
const solver::RealVariable& solver::operator/(const solver::RealVariable& x1, double d1){
    if(d1==0){
        throw std::invalid_argument("cannot devide by zero");
    }
    else{
        return RealVariable(x1.co()/d1,x1.at_free()/d1,x1.exp_co()/d1);
    }   
}



ComplexVariable C;
const solver::ComplexVariable& solver::operator*(double r, const ComplexVariable &x){ return C;}
const solver::ComplexVariable& solver::operator^(const ComplexVariable &r1, double r2){ return C;}
const solver::ComplexVariable& solver::operator/(const ComplexVariable &r1, double r2){ return C;}
const solver::ComplexVariable& solver::operator-(const ComplexVariable &r1, const ComplexVariable &r2){ return C;}
const solver::ComplexVariable& solver::operator-(const ComplexVariable &r1, double r2){ return C;}
const solver::ComplexVariable& solver::operator==(const ComplexVariable &r1, double r2){ return C;}
const solver::ComplexVariable& solver::operator==(const ComplexVariable &r1, const ComplexVariable &r2){ return C;}
const solver::ComplexVariable& solver::operator+(const ComplexVariable &r1, const ComplexVariable &r2){ return C;}
const solver::ComplexVariable& solver::operator+(const ComplexVariable &r1, double r2){ return C;}
const solver::ComplexVariable& solver::operator+(double r2, const ComplexVariable &r1){ return C;}
const solver::ComplexVariable& solver::operator+(const ComplexVariable &r1, complex<double> r2){ return C;}
