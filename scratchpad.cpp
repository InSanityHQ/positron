#include <iostream>
#include <unistd.h>
#include "./include/application.hpp"

int main(int argc, char *argv[]) 
{
    PApplication app("positron_scratchpad");

    PView view1(&app, "view1");
    view1.load("./condution/index.html");

    app.run();
    sleep(1);
    view1.toggleInspector();
    view1.toggleInspector();

    return 0;
}

