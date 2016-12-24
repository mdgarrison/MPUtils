#include "include.h"

static PyObject* increment(PyObject* self, PyObject* args)
{
	PyObject *result = NULL;
	__int64 inputValue;

	if (PyArg_ParseTuple(args, "L", &inputValue))
	{
		result = PyLong_FromLongLong(inputValue + 1);
	}
	return result;
}

PyMethodDef mputilsmethods[] =
{
	{ "increment", increment, METH_VARARGS, "Perform a simple increment operation" },
	{ 0,0,0,0 }
};

static struct PyModuleDef mputilsmodule = {
	PyModuleDef_HEAD_INIT,
	"mputils",
	"Mike's Python Utilities",
	-1,
	mputilsmethods
};

PyMODINIT_FUNC
PyInit_mputils(void)
{
	return PyModule_Create(&mputilsmodule);
}