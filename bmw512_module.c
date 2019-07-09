#include <Python.h>
#include "bmw512.h"

static PyObject *bmw512_getpowhash(PyObject *self, PyObject *args)
{
    char *output;
    PyObject *value;
#if PY_MAJOR_VERSION >= 3
    PyBytesObject *input;
#else
    PyStringObject *input;
#endif
    if (!PyArg_ParseTuple(args, "S", &input))
        return NULL;
    Py_INCREF(input);
    output = PyMem_Malloc(32);
#if PY_MAJOR_VERSION >= 3
    bmw512_hash((char *)PyBytes_AsString((PyObject*) input), output);
#else
    bmw512_hash((char *)PyString_AsString((PyObject*) input), output);
#endif
    Py_DECREF(input);
#if PY_MAJOR_VERSION >= 3
    value = Py_BuildValue("y#", output, 32);
#else
    value = Py_BuildValue("s#", output, 32);
#endif
    PyMem_Free(output);
    return value;
}

static PyMethodDef bmw512Methods[] = {
    { "getPoWHash", bmw512_getpowhash, METH_VARARGS, "Returns the proof of work hash using bmw512" },
    { NULL, NULL, 0, NULL }
};

#if PY_MAJOR_VERSION >= 3
static struct PyModuleDef bmw512Module = {
    PyModuleDef_HEAD_INIT,
    "bmw512_hash",
    "...",
    -1,
    bmw512Methods
};

PyMODINIT_FUNC PyInit_bmw512_hash(void) {
    return PyModule_Create(&bmw512Module);
}

#else

PyMODINIT_FUNC initbmw512_hash(void) {
    (void) Py_InitModule("bmw512_hash", bmw512Methods);
}
#endif
