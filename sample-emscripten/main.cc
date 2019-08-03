#include <stdio.h>
#include <emscripten/bind.h>
#include <iostream>
#include <vector>
#include <cstdint>

#define TYPED_ARRAY(type, fn_name, field_vec) \
    emscripten::val fn_name() { \
        return emscripten::val(emscripten::typed_memory_view( \
                this->field_vec.size() * sizeof(this->field_vec[0])/sizeof(type), \
                (type*) &this->field_vec[0]) \
        );\
    }

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
    os << '[';
    for(auto& e : vec) {
        os << e;
        if(&e != &vec.back())
            std::cout << ", ";
    }
    os << ']';
    return os;
}

struct ohlc {
    float open;
    float high;
    float low;
    float close;
    int64_t timestamp;
};

std::ostream& operator<<(std::ostream& os, const ohlc& val) {
    os << '{'
       << val.open << ", "
       << val.high << ", "
       << val.low  << ", "
       << val.close << ", "
       << val.timestamp
       << "}";
    return os;
}

struct OhlcBuffer {
    std::vector<ohlc> data;
    std::vector<float> vbuf;

    float max_x;
    float min_x;
    float max_y;
    float min_y;
    bool is_dirty;

    OhlcBuffer() : max_x{0}, min_x{0}, max_y{0}, min_y{0}, is_dirty{true}
    { }

    TYPED_ARRAY(float, data_f32view, data);
    TYPED_ARRAY(uint32_t, data_u32view, data);
    TYPED_ARRAY(float, vbuf_f32view, vbuf);

    unsigned int length() { return this->data.size(); }
    /* void print() { std::cout << this->data << std::endl; } */

    void data_resize(uint32_t len) {
        this->data.resize(len);
        this->is_dirty = true;
    }
};

int main() {
    printf("chart-wasm loaded!\n");
    return 0;
} 

using namespace emscripten;
EMSCRIPTEN_BINDINGS(my_module) {
    /* function("lerp", &lerp); */
    /*     .property("x", &MyClass::getX, &MyClass::setX) */
    /*     .class_function("getStringFromInstance", &MyClass::getStringFromInstance) */

    class_<OhlcBuffer>("OhlcBuffer")
        .constructor<>()
        .function("data_f32view", &OhlcBuffer::data_f32view)
        .function("data_u32view", &OhlcBuffer::data_u32view)
        .function("length",       &OhlcBuffer::length)
        /* .function("print",        &OhlcBuffer::print) */
        .function("data_resize",  &OhlcBuffer::data_resize)
    ;
}

