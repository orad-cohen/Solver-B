#include "solver.hpp"
#include <iostream>
#include <stdio.h>
#include<complex>
using namespace std;
using namespace solver;

double solver::solve(const RealVariable &r){

    return 1.0;

}
complex<double> solver::solve(const ComplexVariable &cmplx){

    return complex<double> (3);
}
const solver::RealVariable& operator*(double r, const RealVariable &x){return RealVariable(r * (x._co()), r * x._free(), x._exp_co() * r);}

const solver::RealVariable& solver::operator==(const solver::RealVariable& x, double r){return x-r;}
const solver::RealVariable &solver::operator==(const solver::RealVariable &x, const solver::RealVariable &x2){return x-x2;}

const solver::RealVariable& solver::operator^(const solver::RealVariable& x, double r){
    if(r!=2){
        throw std::invalid_argument("Exponent cannot be anything besides 1 or 2");
    }
    else{ return RealVariable(x._co(),x._free(),1);}
}

const solver::RealVariable& solver::operator-(const solver::RealVariable& x, double d){return RealVariable(x._co(),x._free()-d,x._exp_co());}
const solver::RealVariable &solver::operator-(const solver::RealVariable &x1, const solver::RealVariable &x2){
    return RealVariable(x1._co() - x2._co(), x1._free() - x1._free(), x1._exp_co() - x1._exp_co());
}
const solver::RealVariable& solver::operator+(const solver::RealVariable& x, double d){return RealVariable(x._co(), x._free() + d, x._exp_co());}
const solver::RealVariable& solver::operator+(const solver::RealVariable&  x1, const solver::RealVariable& x2){return RealVariable(x1._co()+x2._co(), x1._free() +x2._free(), x1._exp_co()+x2._exp_co());}

const solver::RealVariable& solver::operator+(double d1, const solver::RealVariable& x2){return RealVariable(x2._co(),x2._free()+d1,x2._exp_co());}
const solver::RealVariable& solver::operator/(const solver::RealVariable& x1, double d1){
    if(d1==0){
        throw std::invalid_argument("cannot devide by zero");
    }
    else{
        return RealVariable(x1._co()/d1,x1._free()/d1,x1._exp_co()/d1);
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
