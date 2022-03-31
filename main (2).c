#include <kipr/wombat.h>

int main()
{
    while(digital(0) !=1)
    {
        printf("reflectance %d\n", analog(0));
        msleep(100);
    }
}