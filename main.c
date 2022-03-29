#include <kipr/wombat.h>
int pushdis=10;
int pulldis=10;
int pullerstart=1000;
int pullerpos=500;
int lightport=3;
int pport=0;

void drive_forward(int distance);
void turn_right(int degrees);
void turn_left(int degrees);
void drive_backwards(int distance);

int main()
{
    create_connect();
    wait_for_light(lightport);
   //--------RINGSTAND-------
    set_servo_position(pport,pullerstart);
    drive_forward(pushdis);
    drive_backwards(10);
    set_servo_position(pport,pullerpos);
    drive_backwards(10);
    set_servo_position(pport,pullerstart);
  //--------PCR MACHINE-----
    return 0;
}
    //---------------------------------------FUNCTIONS-------------------------------------------
    
    //--------------------------------------DRIVE FORWARD----------------------------------------
    void drive_forward(int distance)
{
    set_create_distance(0);
    while(abs(get_create_distance())<distance*10)
    {
        create_drive_direct(200,200);
        msleep(10);
         }
    create_stop();
}
     //-----------------------------DRIVE BACKWARDS------------------------------------
     void drive_backwards(int distance)
{
    set_create_distance(0);
    while(abs(get_create_distance())<distance*10)
    {
        create_drive_direct(-200,-200);
        msleep(10);
         }
    create_stop();
}
     //-------------------------------------TURN RIGHT-----------------------------------
    void turn_right(int degrees)
    {
        set_create_total_angle(0);
        while(abs(get_create_total_angle())<degrees)
        {
            create_drive_direct(200,-200);
            msleep(10);
            
        }
        create_stop();
}
    //-------------------------------------TURN LEFT-----------------------------------
    void turn_left(int degrees)
    {
        set_create_total_angle(0);
        while(abs(get_create_total_angle())<degrees)
        {
            create_drive_direct(-200,200);
            msleep(10);
        }
        create_stop();
    } 
