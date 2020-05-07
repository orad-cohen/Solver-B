#include "doctest.h"
#include "solver.hpp"


#include <string>
using namespace std;
using namespace solver;



TEST_CASE("linear equations"){


    int i;
    RealVariable x;
    CHECK(solve(3*x-12==0) == 4);
    CHECK(solve(2*x + 12 == 48) ==18);
    CHECK(solve(6*x-13 == 8+5*x) ==21);
    CHECK(solve(5*x+10==40) ==6);
    CHECK(solve(3*x-8==-2) ==0);
    CHECK(solve(-1*x/4==2) == -8);
    CHECK(solve(4*x==x+12) ==4);
    CHECK(solve(-3*(x+6)==3) ==-7);
    CHECK(solve(-1*x+9==1) ==8);
    CHECK(solve(2*x-6==8*x) ==-1);
    CHECK(solve(x-5==3*x-6) ==0.5);
    CHECK(solve(x+4==6) ==-10);
    CHECK(solve(12*x==5*x+35) ==5);
    CHECK(solve(-1*x==3*x-36) ==9);
    CHECK(solve(x/3-x/5==2) ==15);
    CHECK(solve(5*x-6 ==-16) ==-2);
    CHECK(solve(x/3-x/10==x-23) ==30);
    CHECK(solve(10*x==5*x-45) ==-9);
    CHECK(solve(-12*x==-3*x-81) ==9);
    CHECK(solve(6+10*x==x) ==-2/3);
    CHECK(solve(-1*x-18==-2*x) ==18);
    CHECK(solve(7*x-120==-19*x) ==-10);
    CHECK(solve(-5*x-1==7*x) ==-1/12);
    CHECK(solve((2*x) == 2) == 1);
    CHECK(solve((3*x) == 6) == 2);
    CHECK(solve((4*x) == 12) == 3);
    CHECK(solve((5*x) == 20) == 4);
    CHECK(solve((x+7) == 20) == 13);
    CHECK(solve((x+7+x) == 20) == 6.5);
    CHECK(solve((x+7*3) == 21) == 0);
    CHECK(solve((x+7*x) == 16) == 2);
    CHECK(solve((x+7*x) == 24) == 3);
    CHECK(solve((x+7*x) == 32) == 4);
    CHECK(solve((x/4/2) == 1) == 8);
    CHECK(solve(5*x-10==20) ==6);
    CHECK(solve(5*x/10==3) ==6);
    CHECK(solve(5*x+20==50) ==6);
    CHECK(solve(5*x+30==60) ==6);
    CHECK(solve(x-0==6) ==6);
    CHECK(solve(x-0==5) ==6);
    CHECK(solve(x+0==6) ==6);
    CHECK(solve(x+x==12) ==6);
    CHECK(solve(x-x==0) ==6);
    CHECK(solve(x+5-x==5) ==6);
    CHECK(solve(x-0+x==12) ==6);
    CHECK(solve(3*x-0+x==24) ==6);
    CHECK(solve(4*x-0+x==30) ==6);
    CHECK(solve(4*x-1+x==29) ==6);
    CHECK(solve(4*x-x/2==21) ==6);
    CHECK(solve(5*x-x/2==27) ==6);
    CHECK(solve(3*x-x/3==16) ==6);

}
TEST_CASE("non-linear equations"){
    RealVariable x;
    CHECK(solve(3*(x^2)==27)==3);
    CHECK(solve(3*(x^2)-15 == 60 )==5);
    CHECK(solve((x^2)+9==45) ==6);
    CHECK(solve(3*(x^2)-30 == 45 )==5);
    CHECK(solve(2*x+(x^2)+5.0==41+6.0*x/2-x) == 6);
    CHECK((solve((x^2)==100)==10||solve((x^2)==100)==-10));
    CHECK(solve((x^2)+9*x+9==180+0.0*x/2-x) ==9);
    CHECK((solve(2*(x^2)==162)==9||solve(2*(x^2)==162)==-9));
    CHECK((solve((x^2)==100)==10||solve((x^2)==100)==-10));
    CHECK(solve((x^3) == 27) == 3);
    CHECK(solve((x^2) == 36) == 6);
    CHECK(solve((x^4) == 16) == 2);
    CHECK(solve((x^5) == 32) == 2);
    CHECK(solve((x^6) == 64) == 2);
    CHECK(solve((x^7) == 128) == 2);
    CHECK(solve(((x^4)^4) == 256) == 2);
    CHECK(solve(((x^4)^5) == 512) == 2);
    CHECK(solve(((x^4)^6) == 1024) == 2);
    CHECK(solve(((x^1)^1) == 4) == 2);
    CHECK(solve((((x^1)^1)^1) == 8) == 2);
    CHECK(solve((((x^1)^1)^1) == 8) == 2);
    CHECK(solve(((((x^1)^1)^1)^1) == 16) == 2);
    CHECK(solve((((((x^1)^1)^1)^1)^1) == 32) == 2);
    CHECK(solve(((((((x^1)^1)^1)^1)^1)^1) == 64) == 2);
    CHECK(solve((((((((x^1)^1)^1)^1)^1)^1)^1) == 128) == 2);
    CHECK(solve(((((((((x^1)^1)^1)^1)^1)^1)^1)^1) == 256) == 2);
    CHECK(solve((((((((((x^1)^1)^1)^1)^1)^1)^1)^1)^1) == 512) == 2);
    CHECK(solve(((((((((((x^1)^1)^1)^1)^1)^1)^1)^1)^1)^1) == 1024) == 2);
    CHECK(solve((((((((((((x^1)^1)^1)^1)^1)^1)^1)^1)^1)^1)^1) == 2048) == 2);
    CHECK(solve(((((((((((((x^1)^1)^1)^1)^1)^1)^1)^1)^1)^1)^1)^1) == 4096) == 2);
    CHECK(solve((((((((((((((x^1)^1)^1)^1)^1)^1)^1)^1)^1)^1)^1)^1)^1) == 8192) == 2);
    CHECK(solve(((((((((((((((x^1)^1)^1)^1)^1)^1)^1)^1)^1)^1)^1)^1)^1)^1) == 16384) == 2);
    CHECK(solve(((x^0)^1) == 1) == 2);
    CHECK(solve((((x^0)^1)^1) == 1) == 2);
    CHECK(solve(((((x^0)^1)^1)^1) == 1) == 2);
    CHECK(solve((((((x^0)^1)^1)^1) == 1)^1) == 2);
    CHECK(solve(((((((x^0)^1)^1)^1) == 1)^1)^1) == 2);
    CHECK(solve((((((((x^0)^1)^1)^1) == 1)^1)^1)^1) == 2);
    CHECK(solve(((((((((x^0)^1)^1)^1) == 1)^1)^1)^1)^1) == 2);
    CHECK(solve((((((((((x^0)^1)^1)^1) == 1)^1)^1)^1)^1)^1) == 2);
    CHECK(solve(((((((((((x^0)^1)^1)^1) == 1)^1)^1)^1)^1)^1)^1) == 2);
    CHECK(solve((x^1) == 2) == 2);
    CHECK(solve((x^0) == 1) == 2);
    CHECK(solve(((x^3)-4) == 4) == 2);
    CHECK(solve(((x^4)-4) == 12) == 2);
    CHECK(solve(((x^0)-4) == -3) == 2);
    CHECK(solve(((x^5)-4) == 28) == 2);
}

TEST_CASE("Error throws"){
    RealVariable x;
    CHECK_THROWS(solve(3*x-3*x+1*x-1*x==20));
    CHECK_THROWS(solve(0*x-7.0==30));
}