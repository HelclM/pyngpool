#include <pybind11/pybind11.h>
#include "test.h"

namespace py = pybind11;

PYBIND11_MODULE(_pyngpool, m) {
    m.doc() = "Example C++ library with Python bindings";

    m.def("add", &add, "Add two numbers");
}
