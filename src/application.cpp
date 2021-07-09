#include "../include/application.hpp"

PApplication::PApplication(const char *name) {
    setup();
}

PApplication::~PApplication() {
    cleanup();
}

