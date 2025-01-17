#include "FileSys.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{

    const char* inif = "config.ini";
    const char* jsonf = "config.json"; 

    WriteJSONint(jsonf,"Three",114514);
    WriteJSONfloat(jsonf,"Two",1.0f);
    WriteJSONstring(jsonf,"One","This is JSON!");

    WriteINIint(inif,"main","three",1919);
    WriteINIfloat(inif,"main","two",3.1415926f);
    WriteINIstring(inif,"main","one","This is INI!");
    
    printf("One: %s \n",GetJSONstring(jsonf,"One"));
    printf("Two: %f \n",GetJSONfloat(jsonf,"Two"));
    printf("Three: %d \n",GetJSONint(jsonf,"Three"));

    printf("\n");

    printf("One: %s \n",GetINIstring(inif,"main","one"));
    printf("Two: %f \n",GetINIfloat(inif,"main","two"));
    printf("Three: %d \n",GetINIint(inif,"main","three"));

    system("pause");

    return 0;
}


