#include <tuple>
#include <string>
#include <vector>

typedef enum {
    INTERGER,
    FLOATING_POINT,
    STRING
} SoytypeCompatibles;

class Soytype {
    public:
        int intStore;
        float floatStore;
        std::string stringStore;

        SoytypeCompatibles typeCompatInfo;

        template<typename T>
        Soytype(T data) {
            if (std::is_same<T, int>::value)
                intStore=data;
            else if (std::is_same<T, int>::value)
                return floatStore=data;
        };
};

int main() {
    Soytype hewo = Soytype(12);
}


