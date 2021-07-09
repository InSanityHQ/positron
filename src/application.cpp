#include "../include/application.hpp"

PApplication::PApplication(const char *name) 
    : name(name) 
{
    setup(name);
}

PApplication::~PApplication() 
{
    cleanup();
}

void PApplication::run() 
{
    gtk_main();
}

PView::PView(PApplication *app, 
            const char *title, 
            PDims dims)
    : app(app)
    , client(newclient(NULL))
{
    showview(NULL, client, dims.width, dims.height);
    updatetitle(title);
}

void PView::load(const char *url) 
{
    loaduri(client, url);
}

void PView::updatetitle(const char *url) 
{
    ::updatetitle(client, url);
}

