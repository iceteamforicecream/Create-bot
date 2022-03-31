#include <kipr/wombat.h>
int pushdis=200;
int pulldis=10;
int pullerstart=740;
int pullerpos=1300;
int lightport=3;
int pport=0;

void drive_forward(int distance);
void turn_right(int degrees);
void turn_left(int degrees);
void drive_backwards(int distance);

int main()
{
    create_connect();
   // wait_for_light(lightport);
   //--------RINGSTAND-------
    enable_servos();
    set_servo_position(pport,pullerstart);
    msleep(750);
    drive_forward(pushdis);
    msleep(500);
    set_servo_position(pport,pullerpos);
    //drive_backwards();
    msleep(2000);
    drive_forward(30);
    msleep(1500);
    set_servo_position(pport,pullerstart);
    msleep(300);
    turn_left(180);
    msleep(250);
    set_servo_position(pport,pullerpos);
  //--------PCR MACHINE-----
    return 0;
}
    //---------------------------------------FUNCTIONS-------------------------------------------
    
    //--------------------------------------DRIVE FORWARD----------------------------------------
    void drive_forward(int distance)
{
    set_create_distance(0);
    while(abs(get_create_distance())<distance)
    {
        create_drive_direct(-300,-300);
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
        create_drive_direct(200,200);
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
            create_drive_direct(-100,100);
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
            create_drive_direct(200,-200);
            msleep(10);
        }
        create_stop();
    } 
