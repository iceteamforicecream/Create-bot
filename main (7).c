#include <kipr/wombat.h>
int pushdis=300;
int pulldis=20;
int pullerstart=740;
int pullerpos=1300;
int tstart=100;
int tdown=950;
int tlift=300;
int lightport=3;
int pport=0;
int tport=1;
int black=1020;
int trpos=600;

void drive_forward(int distance);
void turn_right(int degrees);
void turn_left(int degrees);
void drive_backwards(int distance);
void fdrive_backwards(int distance);

int main()
{
    create_connect();
   // wait_for_light(lightport);
   //--------RINGSTAND-------
    enable_servos();
    set_servo_position(tport,tstart);
    set_servo_position(pport,pullerstart);
    msleep(750);
    drive_forward(pushdis);
    msleep(500);
    set_servo_position(pport,pullerpos);
    msleep(500);
    drive_backwards(14);
    msleep(5000);
    drive_forward(14);
    drive_forward(130);
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
    turn_left(90);
    while(analog(0)<black)
    {
        create_drive_direct(-500,-500);
        msleep(10);
    }
    drive_forward(400);
    turn_left(95);
    drive_forward(1000);
    turn_right(105);
    drive_backwards(10);
    set_servo_position(tport,tdown);
    msleep(500);
    drive_forward(180);
    msleep(400);
    set_servo_position(tport,tlift);
    msleep(500);
    set_servo_position(tport,tdown);
    msleep(500);
    set_servo_position(tport,tlift);
    msleep(500);
    set_servo_position(tport,tdown);
    msleep(500);
    set_servo_position(tport,tlift);
    msleep(500);
    set_servo_position(tport,tdown);
    msleep(500);
    //----------------------TRANSPORTER------------------------
    drive_backwards(40);
    turn_left(85);
    drive_forward(700);
    set_servo_position(pport,trpos);
    msleep(1000);
    fdrive_backwards(1000);
    create_stop();
    return 0;
}
    //---------------------------------------FUNCTIONS-------------------------------------------
    
    //--------------------------------------DRIVE FORWARD----------------------------------------
    void drive_forward(int distance)
{
    set_create_distance(0);
    while(abs(get_create_distance())<distance)
    {
        create_drive_direct(-400,-400);
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
     //-------------------------------DRIVE FAST BACKWARDS-------------------------------
     void fdrive_backwards(int distance)
{
    set_create_distance(0);
    while(abs(get_create_distance())<distance*10)
    {
        create_drive_direct(450,450);
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
