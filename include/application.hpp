#ifndef __APPLICATION_HPP
#define __APPLICATION_HPP

#include "../surf/surf.h"

class PApplication {
public:
    const char *name;

    PApplication(const char *name);
    ~PApplication();

    void run();
};

struct PDims {
    PDims(int width, int height)
        : width(width)
        , height(height) {}

    int width;
    int height;
};

class PView {
public:
    PView(PApplication *app, 
            const char *title, 
            PDims dims=PDims(250, 128)); 
            // TODO are these defaults sane?
            
    PView(PApplication *app, PDims dims=PDims(250, 128))
        : PView(app, app->name, dims) {}

    void load(const char *url);
    void updatetitle(const char *title);
    void toggleInspector();
    void kill();

private:
    PApplication* app;
    Client *client;

    friend class PApplication;
};

#endif

