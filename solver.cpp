#include "solver.hpp"
#include <iostream>
#include <stdio.h>
#include<complex>
#include<math.h>
using namespace std;
using namespace solver;

double solver::solve(const RealVariable &r){
    if(r.a()!=0&&r.b()!=0){
        double bsq = round(r.b() * r.b());
        double asq = round(r.a());
        double fsq = round (r.c());
        double rside = sqrt(bsq - 4 * asq * fsq);
        double lside = -bsq;
        double div = 2*asq;
        return (lside+rside)/div;
    }
    else if (r.b()!=0){
        double rside = -r.c();
        rside/=r.b();
        return rside;
    }

    else if(r.a()!=0){
        double rside = -r.c();
        rside/=r.a();
        if(rside < 0) throw std::invalid_argument("There is no real solution");
        else return sqrt(rside);
    }
    else{
        throw std::invalid_argument("");
    }
        return 1.0;
}
const RealVariable &operator*(const RealVariable &x, double r)
{
    RealVariable *tmp = new RealVariable(x.a()*r,x.b()*r,x.c()*r);
    RealVariable &tmpo = *tmp; 
    return tmpo;
}
const solver::RealVariable& solver::operator*(double r, const RealVariable &x){
    RealVariable *tmp = new RealVariable(x.a()*r,x.b()*r,x.c()*r);
    RealVariable &tmpo = *tmp; 
    return tmpo;
}
const solver::RealVariable& solver::operator==(const solver::RealVariable& x5, double r){ 
    RealVariable *tmp = new RealVariable(x5.a(),x5.b(),x5.c()-r);
    RealVariable &tmpo = *tmp; 
    return tmpo;}
const solver::RealVariable &solver::operator==(const solver::RealVariable &x, const solver::RealVariable &x2){
    RealVariable *tmp = new RealVariable(x.a()-x2.a(),x.b()-x2.b(),x.c()-x2.c());
    RealVariable &tmpo = *tmp; 
    return tmpo;}
const solver::RealVariable& solver::operator^(const solver::RealVariable& x, double r){
    if(r!=2) throw std::invalid_argument("Exponent cannot be anything besides 1 or 2");
    else{
        RealVariable *tmp = new RealVariable(1,0,x.c());
        RealVariable &tmpo = *tmp;  
        return tmpo;   
    }
}
const solver::RealVariable& solver::operator-(const solver::RealVariable& x, double d){
    RealVariable *tmp = new RealVariable(x.a(), x.b(), x.c() - d);
    RealVariable &tmpo = *tmp;  
    return tmpo; 
}
const solver::RealVariable &solver::operator-(const solver::RealVariable &x1, const solver::RealVariable &x2){
    RealVariable *tmp = new RealVariable(x1.a() - x2.a(), x1.b() - x2.b(), x1.c() - x2.c());
    RealVariable &tmpo = *tmp;  
    return tmpo; 
}
const solver::RealVariable& solver::operator+(const solver::RealVariable& x, double d){
    RealVariable *tmp = new RealVariable(x.a(),x.b(),x.c()+d);
    RealVariable &tmpo = *tmp;  
    return tmpo;}
const solver::RealVariable& solver::operator+(const solver::RealVariable&  x1, const solver::RealVariable& x2){
    RealVariable *tmp = new RealVariable(x1.a() + x2.a(), x1.b() + x2.b(), x1.c() + x2.c());
    RealVariable &tmpo = *tmp;  
    return tmpo;}

const solver::RealVariable& solver::operator+(double d1, const solver::RealVariable& x2){
    RealVariable *tmp = new RealVariable(x2.a(),x2.b(),x2.c()+d1);
    RealVariable &tmpo = *tmp;  
    return tmpo;}
const solver::RealVariable& solver::operator/(const solver::RealVariable& x1, double d1){
    if(d1==0){
        throw std::invalid_argument("cannot devide by zero");
    }
    else{
         RealVariable *tmp = new RealVariable(x1.a()/d1,x1.b()/d1,x1.c()/d1);
         RealVariable &tmpo = *tmp;  
         return tmpo;}}   
complex<double> solver::solve(const ComplexVariable &cmplx){
    return complex<double> (3);}
const solver::ComplexVariable& solver::operator*(double r, const ComplexVariable &r1){ 
     ComplexVariable *tmp = new ComplexVariable(r1.a()*r,r1.b()*r,r1.c()*r,r1.i()*r);
     ComplexVariable &tmpo = *tmp;
     return tmpo;}
const solver::ComplexVariable& solver::operator^(const ComplexVariable &r1, double r2){
    if(r2!=2) throw std::invalid_argument("Exponent cannot be anything besides 1 or 2");
    else{
        ComplexVariable *tmp = new ComplexVariable(1,0,r1.c(),r1.i());
        ComplexVariable &tmpo = *tmp;  
        return tmpo;}}
const solver::ComplexVariable& solver::operator/(const ComplexVariable &r1, double r){
    ComplexVariable *tmp = new ComplexVariable(r1.a()/r,r1.b()/r,r1.c()/r,r1.i()/r);
    ComplexVariable &tmpo = *tmp;  
    return tmpo;}
const solver::ComplexVariable& solver::operator-(const ComplexVariable &r1, const ComplexVariable &r2){ 
     ComplexVariable *tmp = new ComplexVariable(r1.a() - r2.a(), r1.b() - r2.b(), r1.c() - r2.c() , r1.i() - r2.i());
     ComplexVariable &tmpo = *tmp;
     return tmpo;}
const solver::ComplexVariable& solver::operator-(const ComplexVariable &r1, double r2){ 
     ComplexVariable *tmp = new ComplexVariable(r1.a(),r1.b(),r1.c()-r2,r1.i());
     ComplexVariable &tmpo = *tmp;
     return tmpo;}
const solver::ComplexVariable& solver::operator==(const ComplexVariable &r1, double r2){ 
     ComplexVariable *tmp = new ComplexVariable(r1.a(),r1.b(),r1.c()-r2,r1.i());
     ComplexVariable &tmpo = *tmp; 
     return tmpo;}
const solver::ComplexVariable& solver::operator==(const ComplexVariable &r1, const ComplexVariable &r2){ 
     ComplexVariable *tmp = new ComplexVariable(r1.a()-r2.a(),r1.b()-r2.b(),r1.c()-r2.c(),r1.i()-r2.i());
     ComplexVariable &tmpo = *tmp; 
     return tmpo;}
const solver::ComplexVariable& solver::operator+(const ComplexVariable &r1, const ComplexVariable &r2){
     ComplexVariable *tmp = new ComplexVariable(r1.a() + r2.a(), r1.b() + r2.b(), r1.c() + r2.c() , r1.i() + r2.i());
     ComplexVariable &tmpo = *tmp;
     return tmpo;}
const solver::ComplexVariable& solver::operator+(const ComplexVariable &r1, double r2){ 
     ComplexVariable *tmp = new ComplexVariable(r1.a(),r1.b(),r1.c()+r2, r1.i());
     ComplexVariable &tmpo = *tmp;
     return tmpo;}
const solver::ComplexVariable& solver::operator+(double r2, const ComplexVariable &r1){
     ComplexVariable *tmp = new ComplexVariable(r1.a(),r1.b(),r1.c()+r2, r1.i());
     ComplexVariable &tmpo = *tmp;
     return tmpo;}

const solver::ComplexVariable& solver::operator+(const ComplexVariable &r1, complex<double> r2)
{
     ComplexVariable *tmp = new ComplexVariable(r1.a(),r1.b(),r1.c()+r2.real(), r1.i() + r2.imag());
     ComplexVariable &tmpo = *tmp;
     return tmpo;}
const solver::ComplexVariable& solver::operator+(complex<double> r2, const ComplexVariable &r1)
{
     ComplexVariable *tmp = new ComplexVariable(r1.a(),r1.b(),r1.c()+r2.real(), r1.i() + r2.imag());
     ComplexVariable &tmpo = *tmp;
     return tmpo;}

const solver::ComplexVariable& solver::operator"" _i(long double d)
{
}