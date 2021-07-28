// Decleration of global variables


/*
  Valves openings will be a number from 0-100 where 0 is fully closed and 100 fully open.
  To be able to use the pid to control two valves we need the WaterMixer to understand how to convert 
  desired temperature to a linear opening of the valves.


  
 */

/**
 * @brief  Values used by the proportional integral derivative controller (PID controller).
 * 
 */
struct PID_STRUCT {
    double input;       // current temperature
    double setpoint;    // desired temperature
    double output;      // suggested temperature from the pid.
                        
    // outputMin and outputMax are the range of values your output can be set to.
    double outputMin;   // outputMin is the lowest value your output can be set to.  (Should use the same units as output)
    double outputMax;   // outputMax is the highest value your output can be set to.  (Should use the same units as output)
    double Kp;          //  proportional gain
    double Ki;          // integral gain
    double Kd;          // derivative gain
};

/**
 * @brief Global variables in the program
 * 
 */
struct GLOBAL_STRUCT {
    float temperature = 0;   // Current temperature read from the Temperature sensor.
    float desiredTemp = 24;  // The desired temperature which should be fed as the setpoint to the PID controller.
    float coldValveFlow = 0; // A number from 0 to 100 describing the opening of the COLD valve, 0 is fully closed and 100 fully open.
    float hotValveFlow = 0;  // A number from 0 to 100 describing the opening of the HOT  valve, 0 is fully closed and 100 fully open.
    PID_STRUCT pid;
} values;