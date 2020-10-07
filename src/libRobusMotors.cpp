/***********************************
 *             INCLUDES
 ***********************************/
#include <stdint.h>
#include <Arduino.h>
#include "LibRobus.h"
#include "libRobusMotors.h"
/***********************************
 *         DEFINES & MACROS
 ***********************************/
#define M_LEFT          0
#define M_RIGHT         1

#define KP              0.0005
#define KI              0.00001
/***********************************
 *             TYPEDEFS
 ***********************************/


/***********************************
 *        CONSTS & GLOBALS VARS
 ***********************************/
static float motorLeftSpeed     = 0;
static float motorRightSpeed    = 0;
static float actualdistance     = 0;
static float distanceGoal       = 0;
static bool  state = 0;

/***********************************
 *             ENUMS
 ***********************************/

/***********************************
 *             STRUCTS
 ***********************************/
static struct pidtime_t
{
    uint64_t    lastPIDtime;
    uint64_t    actualtime;
    bool        PIDenabled;
} pidInfos = {0};


/***********************************
 *         PRIVATES PROTOTYPES
 ***********************************/
static void PID(bool motorSide);
static void distanceCalculate();

/***********************************
 *         PUBLICS FUNCTIONS
 ***********************************/
bool motor_status(){
    pidInfos.actualtime = millis();
    distanceCalculate();
    if(actualdistance >= distanceGoal)
    {
        MOTOR_SetSpeed(M_LEFT,0);
        MOTOR_SetSpeed(M_RIGHT,0);
    }
    
    else if ((pidInfos.actualtime-1000) >= pidInfos.lastPIDtime)
    {
        PID(M_LEFT);
        PID(M_RIGHT);
        state = 0;
    }
    
    return state;
}



/***********************************
 *         PRIVATES FUNCTIONS
 ***********************************/
static void PID(bool motorSide)
{
    static float leftError = 0;
    static float rightError = 0;
    float error = 0;
    float lastError = 0;

    
    if(pidInfos.PIDenabled == true)
    {
        

    }
    
}

//prob qu'il faudrait calculer les 2 roues, on va voir
static void distanceCalculate()
{

}