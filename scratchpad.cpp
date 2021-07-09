#include <iostream>
#include "./include/application.hpp"

int main(int argc, char *argv[]) 
{
    PApplication a("hewo");

    PView v(&a, "view1");
    v.load("https://www.google.com");

    a.run();

    return 0;
}

