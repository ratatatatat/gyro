
#ifndef _Gyro_h_
#define _Gyro_h_

//Purpose of library is to calculate drift for a gyroscope
//Have an iterative function that takes in a angular position reading. 
//***Add another function to prepare kalman variables. 

///Doesn't need the Sensor Library Yet!


template<class T>
class Gyro{
	public:
        Gyro(int z); //Initialize the gyro,set the zeros, run the function to get the bias.
        T getCali(); //Return caliOffset
        void caliLoop();//Gets called, passses in the raw measurement, meant to be used in a loop
        void setAngle(T ang); //Set the angle and caliLoop will call on the set angle.  
        //while(bOffset==false)
        // {
        // 	caliLoop(measurement)
        // }
        bool bOffset;


	private:
                T angle;
		T caliOffset;
		int counter;
		int zeros;//The number of recurring zeros 
		void setZeros(int n);//Gets called in constructor

};
#endif
