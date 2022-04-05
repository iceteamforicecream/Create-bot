#include <kipr/wombat.h>
int pushdis=200;
int pulldis=10;
int pullerstart=740;
int pullerpos=1300;
int lightport=3;
int pport=0;
int black=1020;

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
    msleep(1000);
    set_servo_position(pport,pullerstart);
    msleep(300);
    turn_left(180);
    msleep(250);
    set_servo_position(pport,1800);
    msleep(300);
  //--------PCR MACHINE-----
  drive_forward(30);
    turn_left(90);
    drive_forward(220);
    turn_left(100);
    while(analog(0)<black)
    {
        create_drive_direct(-500,-500);
        msleep(10);
    }
    drive_forward(375);
    turn_left(90);
    drive_forward(850);
    turn_right(115);
    set_servo_position(pport,pullerstart);
    msleep(750);
    return 0;
}
    //---------------------------------------FUNCTIONS-------------------------------------------
    
    //--------------------------------------DRIVE FORWARD----------------------------------------
    void drive_forward(int distance)
{
    set_create_distance(0);
    while(abs(get_create_distance())<distance)
    {
        create_drive_direct(-500,-500);
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
