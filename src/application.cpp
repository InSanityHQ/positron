#include <string>

#include "../include/application.hpp"

PApplication::PApplication(const char *name) 
    : name(name) 
{
    // TODO BAD(ish)! non unix-like?
    std::string prefix = "~/."+std::string(name)+"/";

    scriptfile = (char *) (prefix+"script.js").c_str();
    styledir = (char *) (prefix+"styles/").c_str();
    certdir = (char *) (prefix+"certificates/").c_str();
    cachedir = (char *) (prefix+"cache/").c_str();
    cookiefile = (char *) (prefix+"cookies.txt").c_str();

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

