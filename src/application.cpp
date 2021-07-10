#include <string>

#include "../include/application.hpp"

PApplication::PApplication(const char *name) 
    : name(name) 
{
    // TODO BAD(ish)! whatabout non unix-like?
    std::string prefix = "~/."+std::string(name)+"/";

    // TODO BAD! Language abuse and noob soydev move
    std::string scriptfile = (prefix+"script.js");
    std::string styledir = (prefix+"styles/");
    std::string certdir = (prefix+"certificates/");
    std::string cachedir = (prefix+"cache/");
    std::string cookiefile = (prefix+"cookies.txt");

    const StorePaths sp = {
        scriptfile.c_str(), 
        styledir.c_str(),
        certdir.c_str(), 
        cachedir.c_str(),
        cookiefile.c_str()
    };

    setup(name, &sp);
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

