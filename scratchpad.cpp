#include <iostream>
#include "./include/application.hpp"

int main(int argc, char *argv[]) 
{
    PApplication a("hewo");

    PView v1(&a, "view1");
    v1.load("https://www.google.com");

    PView v2(&a, "view2");
    v2.load("https://www.duckduckgo.com");

    a.run();

    return 0;
}

