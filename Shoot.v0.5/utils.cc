#include <sys/time.h>
#include <iostream>
#include <stdlib.h>
#include "utils.h"

using namespace std;

//cherche un nb aléatoire entre a et b
int Random(int a, int b)
{	
    return rand()%(b-a)+a;
}
//donne un temps en miliseconde
unsigned int getTime()
{
    timeval t;
    gettimeofday(&t , NULL);
    return (t.tv_sec*1000+t.tv_usec/1000);
}
