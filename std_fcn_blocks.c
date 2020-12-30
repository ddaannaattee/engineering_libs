
/*
Create function that takes error value, looks up error message in table (which exists
only in function), and returns pointer to string

Create definitions for timer types (as integers)
*/


//Standard Function Blocks
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

//INT: 16-bit integer
//DINT: 32-bit integer


//SR Bistable
//(SR)


//RS Bistable
//(RS)


//Semaphore
//(SEMA)


//Rising Trigger
//(R_TRIG)


//Falling Trigger
//(F_TRIG)


//Count Up
//(CTU)


//Count Down
//(CTD)


//Count Up/Down
//(CTUD)

struct s_timer
{
	int16_t type;		//Timer type (TP, TON, TOF)
	int32_t preset;		//Time value at which timer function changes
	int16_t preset_units;	//Units of preset variable
	bool start;		//Control for "first time activation" of timer
	clock_t t_start;	//Program time when start variable is first activated
	bool running;		//Indicator that timer is active and updating its counts
	clock_t t_elapsed;	//Timer counter
	bool output;		//Output value based on timer logic
}

int16_t updateTimer( struct s_timer * sp_timer )
{
	/*Error value to be returned*/
	int16_t err_val = 0;
	
	/*Get wall time*/
	clock_t t_program = clock_gettime( CLOCK_MONOTONIC, );
	
	/*If "Start" is activated for the first time...*/
	if( (sp_timer->start == true) &&
	    (sp_timer->running == false) )
	{
		//Save program time to t_start
		sp_timer->t_start = t_program;
		
		//Turn on "running" indicator
		sp_timer->running = true;
	}
			
	/*Update timer values
	--------------------*/
	switch( sp_timer->type )
	{
		/*Pulse Timer*/
		case 0:
			/*If timer is "Running", no matter what "Start" is...*/
			if( sp_timer->running == true )
			{
				//Account for rollover (program time is less than elapsed time)...
				//and calculate new elapsed time
				if( t_program < sp_timer->t_elapsed )
				{
					sp_timer->t_elapsed = MAX_CLOCKS + t_program;
				}
				else
				{
					sp_timer->t_elapsed = t_program;
				}
			}
			break;
		
		/*On-Delay Timer*/
		case 1:
			if( sp_timer->start == true )
			{
				sp_timer->t_elapsed = t_program;
			}
			break;
		
		/*Off-Delay Timer*/
		case 2:
		
			break;
			
		/*Defaults*/
		default:
			//Set error value
	}
	
	return err_val;
}

/*Timer Pulse (TP)*/
int16_t timerPulse( struct s_timer * sp_TP )
{
	/*Update timer variables*/
	updateTimer( sp_TP );
		
	
	/*Timer Pulse Logic
	-------------------------------------*/
	/*If the "Start" is on/true...*/
	if( sp_TP->start == true )
	{
		//Turn on "output"
		sp_timer->output = true;
	}
	/*If the elapsed time is greater than the preset
	and the timer is "Running"...*/
	else if( sp_TP->running == true &&
			 (sp_TP->t_elapsed - sp_TP->t_start) >= sp_TP->preset )
	{
		//Turn off "output"
		sp_TP->output = false;
		
		//Turn off "running" indicator
		sp_TP->running = false;
		
		//Set start and elapsed times to zero
		sp_TP->t_start = 0;
		sp_TP->t_elapsed = 0;
	}
	/*Else "Start" is off; "Running" is off OR timer hasn't overflowed*/
	else
	{
		//Do nothing
	}
}


//Timer ON
//(TON)
//Preset Time, Preset Units, Run, Count, Output
//Turning ON "Run" allows "Count" to increment; if "Preset" reached, "Output" goes ON
//Turning OFF "Run" resets "Count" to zero; also sets "Output" to OFF
int16_t timerOn( struct s_timer * sp_TON )
{
	/*Update timer if applicable*/
	updateTimer( sp_TP );
		
	
	/*Check conditions for output changes
	-------------------------------------*/
	
	
	
}

//Timer OFF
//(TOF)
//Preset Time, Preset Units, Run, Count, Output
//Turning ON "Run" sets "Output" to ON, sets "Count" to zero
//Turning OFF "Run" allows "Count" to increment; if "Preset" reached, "Output" goes OFF


//Real Time Clock
//(RTC)


//Integral


//Derivative


//PID


//Ramp


//Hysteresis
