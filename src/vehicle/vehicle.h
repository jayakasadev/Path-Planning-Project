//
// Created by jay on 12/5/17.
//

#ifndef PATH_PLANNING_VEHICLE_H
#define PATH_PLANNING_VEHICLE_H

#include <iostream>
#include <vector>
#include "../utilities/utilities.h"

struct vehicle{
protected:
    double x;
    double y;

    double s;
    double d;

    double ps;
    double pd;

    double yaw;

    double velocity_s; // in m/s
    double velocity_d; // in m/s

    double acceleration_s; // in m/s^2
    double acceleration_d; // in m/s^2

    bool first;

public:
    vehicle(){
        x = 0;
        y = 0;
        s = 0;
        d = 0;
        ps = 0;
        pd = 0;
        yaw = 0;
        velocity_s = 0;
        velocity_d = 0;
        acceleration_s = 0;
        acceleration_d = 0;
        first = true;
    }
    ~vehicle(){}

    inline double getS(){
        return s;
    }

    inline double getD(){
        return d;
    }

    inline double getYaw(){
        return yaw;
    }

    inline short getLane(){
        return calculateLane(d);
    }

    inline double getVelocityS(){
        return velocity_s;
    }

    inline void setVelocityS(double velocity_s){
        this->velocity_s = velocity_s;
    }

    inline double getAccelerationS(){
        return acceleration_s;
    }

    inline void setAccelerationS(double acceleration_s){
        this->acceleration_s = acceleration_s;
    }

    inline double getVelocityD(){
        return velocity_d;
    }

    inline void setVelocityD(double velocity_d){
        this->velocity_d = velocity_d;
    }

    inline double getAccelerationD(){
        return acceleration_d;
    }

    inline void setAccelerationD(double acceleration_d){
        this->acceleration_d = acceleration_d;
    }

    inline std::vector<double> getPredicted(){
        ps = calculateFutureS(s + this->velocity_s * time_period + .5 * this->acceleration_s * pow(time_period, 2));
        pd = d + this->velocity_d * time_period + .5 * this->acceleration_d * pow(time_period, 2);
        return {ps, pd};
    }

    inline double getPredictedVelocityS(double time){
        return velocity_s + acceleration_s * time;
    }

    inline double getPredictedVelocityD(double time){
        return velocity_d + acceleration_d * time;
    }

    inline double getPredictedS(double time){
        return s + velocity_s * time;
    }

    inline double getPredictedD(double time){
        return d + velocity_d * time;
    }

    inline void print(){
        std::cout << "[ s = " << s << ", d = " << d << ", yaw = " << yaw
                  << ", velocity_s = " << velocity_s << ", acceleration_s = " << acceleration_s
                  << ", velocity_d = " << velocity_d << ", acceleration_d = " << acceleration_d
                  << ", predicted_s = " << ps << ", predicted_d = " << pd << " ]" << std::endl;
    }
};

#endif //PATH_PLANNING_VEHICLE_H
