#include "Gyro.h"
#include <iostream>
using namespace std;

template<class T>
Gyro<T>::Gyro(int z){
	setZeros(z);
	//Need to set kalman variables
	//Set to false, its to tell if caliOffset is valid
	bOffset = false;
}

template<class T>
void Gyro<T>::serZeros(int n){
    this->zeros = n;
}
template<class T>
void Gyro<T>::setAngle(T ang){
	//Set the angle internally. 
	this->angle = ang;
}

template<class T>
T Gyro<T>::getCali(int n){
	if(bOffset==true){
		return this->caliOffset; 
	}
	else{
		return;
	}
}
template<class T>
void Gyro<T>::caliLoop(){
	//Calibration should only occur when the its stationary. 
	T angle;
	T meas = this->angle; 
	angle = meas + caliOffset;
	if(angle > 0){
		// Turn down calibration constant 
		caliOffset-=1.0;
		counter = 0;
	}
	else if(angle < 0){
		// Turn up the calibration constant
		caliOffset+=1.0;
		counter = 0;
	}
	else if(angle == 0.0){
		counter++;
		if(counter == zeros){
			bOffset = true;
			counter = 0;
		}
	}
}
