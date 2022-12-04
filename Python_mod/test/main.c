#include <Python.h>
// 没错，这就够了，什么stdio.h就都有


static PyObject* say_hello(PyObject* self, PyObject* args){
    printf("Hello world, I just a demo.");
}

static PyMethodDef my_methods[] = {
    { "say", say_hello, 0, "Just show a greeting." },
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef my_module = {
    PyModuleDef_HEAD_INIT,
    "dummy",
    NULL,
    -1,
    my_methods
};

PyMODINIT_FUNC PyInit_mymodule(void) {
    return PyModule_Create(&my_module);
}