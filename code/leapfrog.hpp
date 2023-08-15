#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

#ifndef LEAPFROG_H_
#define LEAPFROG_H_

class particle{
    private:
        double R;
        double x,y;
        double vx,vy;
        double Fx, Fy;
        double dt;
    public:
        particle(double Ri, double xi, double yi, double vxi, double vyi, double dti)
        {R=Ri; x=xi; y=yi; vx=vxi; vy=vyi; dt=dti; Fx=0; Fy=0;}
        void update_F(double x_center, double k);
        void initialize_v();
        void update_v();
        void update_x();
        double get_x(){return x;}
        double get_y(){return y;}
        double get_vx(){return vx;}
        double get_vy(){return vy;}
};

//Harmonic Oscillator in x
void particle::update_F(double x_center, double k){
    Fx=-k*(x-x_center);
    Fy=0;
}
//Update rule from leapfrog algorithm
void particle::update_x(){
    x += dt*vx;
    y += dt*vy;
}
// Half step of Euler method to initialize v(1/2)
void particle::initialize_v(){
    vx += 0.5*dt*Fx;
    vy += 0.5*dt*Fy;
}
// Update rule for velocity
void particle::update_v(){
    vx += dt*Fx;
    vy += dt*Fy;
}

#endif // LEAPFROG_H_
