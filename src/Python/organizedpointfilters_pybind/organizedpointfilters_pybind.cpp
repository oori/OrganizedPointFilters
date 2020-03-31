
#include "organizedpointfilters_pybind/organizedpointfilters_pybind.hpp"
#include "organizedpointfilters_pybind/docstring/docstring.hpp"

using namespace OrganizedPointFilters;

PYBIND11_MODULE(organizedpointfilters, m)
{
    m.doc() = "Python binding of OrganizedPointFilters";

    py::bind_vector<std::vector<double>>(m, "VectorDouble", py::buffer_protocol());
    py::bind_vector<std::vector<int>>(m, "VectorInt", py::buffer_protocol());
    py::bind_vector<std::vector<std::size_t>>(m, "VectorULongInt", py::buffer_protocol());

    m.def("hello", &OrganizedPointFilters::Hello, "name"_a, "Says hello to name");
    docstring::FunctionDocInject(m, "hello", {{"name", "The name to say hello with"}});

    // You *can* use use function overload with same name, but python documentation doesn't support function overload
    // Here I choose to make multiple function with different names
    m.def("multiply_by_scalar_double", &OrganizedPointFilters::MultiplyByScalar<double>, "vec"_a, "scalar"_a, "Multiplies a double vector");
    m.def("multiply_by_scalar_int", &OrganizedPointFilters::MultiplyByScalar<int>, "vec"_a, "scalar"_a, "Multiplies an int vector");
    m.def("multiply_by_scalar_size_t", &OrganizedPointFilters::MultiplyByScalar<size_t>, "vec"_a, "scalar"_a, "Multiplies a size_t vector");
    docstring::FunctionDocInject(
        m, "multiply_by_scalar_double",
        {{"vec", "A list of double numbers "}, {"scalar", "A scalar number to multiply the list by."}});
    docstring::FunctionDocInject(
        m, "multiply_by_scalar_int",
        {{"vec", "A list of int numbers "}, {"scalar", "A scalar number to multiply the list by."}});
    docstring::FunctionDocInject(
        m, "multiply_by_scalar_size_t",
        {{"vec", "A list of size_t numbers "}, {"scalar", "A scalar number to multiply the list by."}});
    // Heres an example to overload, but the documentation is wonky
    // m.def("multiply_by_scalar", &OrganizedPointFilters::MultiplyByScalar<double>, "vec"_a, "scalar"_a, "Multiplies a vector");
    // m.def("multiply_by_scalar", &OrganizedPointFilters::MultiplyByScalar<int>, "vec"_a, "scalar"_a, "Multiplies a vector");
    // m.def("multiply_by_scalar", &OrganizedPointFilters::MultiplyByScalar<size_t>, "vec"_a, "scalar"_a, "Multiplies a vector");
    // docstring::FunctionDocInject(
    //     m, "multiply_by_scalar",
    //     {{"vec", "A list of numbers (double, int, size_t)"}, {"scalar", "A scalar number to multiply the list by."}});
}