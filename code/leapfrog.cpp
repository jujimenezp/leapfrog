#include "leapfrog.hpp"

int main(int argc, char** argv){
    double x=7, y=5;
    double vx=0.5, vy=0;
    double R=2;
    double dt=0.01;
    int t_end=10, imps=500;
    double x_center=5, k=pow(2*M_PI,2);
    particle bolita(R,x,y,vx,vy,dt);

    std::ofstream file("results/result.dat");
    file << "dt" <<"\tx" << "\ty" << "\tvx" << "\tvy" <<"\n";
    bolita.update_F(x_center, k);
    bolita.initialize_v();
    for(double t=0; t < t_end; t+=dt){
        std::cout << "\r" << "t = " << t << std::flush;
        if(int(t/dt)%int(t_end/(dt*imps)) == 0){
            file << t <<"\t"<< bolita.get_x() <<"\t"<< bolita.get_y() <<"\t"
                 << bolita.get_vx() <<"\t" << bolita.get_vy() << "\n";
        }
        bolita.update_x();
        bolita.update_F(x_center, k);
        bolita.update_v();
    }
    return 0;
}
