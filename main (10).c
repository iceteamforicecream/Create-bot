#include <kipr/wombat.h>
int pushdis=250;
int pulldis=20;
int pullerstart=770;
int pullerpos=1300;
int tstart=100;
int tdown=1170;
int tlift=680;
//int lightport=3;
int pport=0;
int tport=1;
int black=1020;
int trpos=600;

void drive_forward(int distance);
void turn_right(int degrees);
void turn_left(int degrees);
void drive_backwards(int distance);
void fdrive_backwards(int distance);
void fdrive_forward(int distance);

int main()
{
    create_connect();
   //wait_for_light(lightport);
   //shut_down_in(115);
   //--------RINGSTAND-------
    enable_servos();
    set_servo_position(tport,tstart);
    set_servo_position(pport,pullerstart);
    msleep(750);
    fdrive_forward(pushdis);
    msleep(500);
    set_servo_position(pport,pullerpos);
    msleep(500);
    drive_backwards(150);
    msleep(7000);
    drive_forward(150);
    drive_forward(115);
    msleep(1000);
    set_servo_position(pport,pullerstart);
    msleep(700);
    turn_left(180);
    msleep(250);
    set_servo_position(pport,1800);
    msleep(300);
  //--------PCR MACHINE-----
    turn_left(180);
    msleep(300);
    fdrive_forward(70);
    turn_left(80);
    drive_forward(800);
    turn_right(84);
    drive_backwards(100);
    set_servo_position(tport,tdown); 
    msleep(500);
    drive_forward(345);
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
    //turn_left(85);
    //drive_forward(700);
    //set_servo_position(pport,trpos);
    //msleep(1000);
    //fdrive_backwards(1000);
    disable_servos();
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
    while(abs(get_create_distance())<distance)
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
    while(abs(get_create_distance())<distance)
    {
        create_drive_direct(450,450);
        msleep(10);
         }
    create_stop();
}
     //-------------------------------DRIVE FAST FORWARDS-------------------------------
     void fdrive_forward(int distance)
{
    set_create_distance(0);
    while(abs(get_create_distance())<distance)
    {
        create_drive_direct(-350,-350);
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
            create_drive_direct(100,-100);
            msleep(10);
        }
        create_stop();
    } 
