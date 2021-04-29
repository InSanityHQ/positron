#include <tuple>
#include <string>
#include <vector>

typedef enum {
    INTERGER,
    FLOATING_POINT,
    STRING
} ShitArrayTypes;

class ShitArray {
    public:
        std::vector<std::tuple<int, float, std::string>> elemVector;
        std::vector<ShitArrayTypes> types;

        template<typename T>
        void append(T content) {
            int * int_cast_value = dynamic_cast<int*>(content);
            if (int_cast_value != nullptr) 
                return elemVector.push_back(std::make_tuple(*int_cast_value, -1.0, "")),
                       types.push_back(INTERGER);

            float * float_cast_value = dynamic_cast<float*>(content);
            if (float_cast_value != nullptr) 
                return elemVector.push_back(std::make_tuple(-1, *float_cast_value, "")),
                       types.push_back(FLOATING_POINT);
        }
};

