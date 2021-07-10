#include <iostream>
#include "./include/application.hpp"

int main(int argc, char *argv[]) 
{
    PApplication app("positron_scratchpad");

    PView view1(&app, "view1");
    view1.load("./index.html");

    app.run();

    return 0;
}

