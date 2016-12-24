#include "include.h"

// IsLeapYear() - true for any leap year
static bool IsLeapYear(int year)
{
    bool result = false;

    if ((year % 4) == 0)
    {
        result = true;

        if (((year % 100) == 0) && ((year % 400) == 0))
        {
            result = false;
        }
    }
    return result;
}

// IsNewStyleDate() - true for any date starting at 14-SEP-1752
static bool IsNewStyleDate(int month, int day, int year)
{
    bool result = false;

    if (year < 1752)
    {
        result = false;
    }
    else if (year == 1752)
    {
        if (month < 9)
        {
            result = false;
        }
        else if (month == 9)
        {
            if (day < 14)
            {
                result = false;
            }
            else
            {
                result = true;
            }
        }
        else
        {
            result = true;
        }
    }
    else
    {
        result = true;
    }
    return result;
}

// IsValidDate() - validates m/d/y
static bool IsValidDate(int month, int day, int year)
{
    bool result = false;

    if (IsNewStyleDate(month, day, year))
    {
        switch (month)
        {
        case 1:
            result = ((day >= 1) && (day <= 31));
            break;
        case 2:
            if (IsLeapYear(year))
            {
                result = ((day >= 1) && (day <= 29));
            }
            else
            {
                result = ((day >= 1) && (day <= 28));
            }
            break;
        case 3:
            result = ((day >= 1) && (day <= 31));
            break;
        case 4:
            result = ((day >= 1) && (day <= 30));
            break;
        case 5:
            result = ((day >= 1) && (day <= 31));
            break;
        case 6:
            result = ((day >= 1) && (day <= 30));
            break;
        case 7:
            result = ((day >= 1) && (day <= 31));
            break;
        case 8:
            result = ((day >= 1) && (day <= 31));
            break;
        case 9:
            result = ((day >= 1) && (day <= 30));
            break;
        case 10:
            result = ((day >= 1) && (day <= 31));
            break;
        case 11:
            result = ((day >= 1) && (day <= 30));
            break;
        case 12:
            result = ((day >= 1) && (day <= 31));
            break;
        }
    }
    return result;
}

// Returns ordinal index [0..6] where 0 == Sunday, 1 == Monday, etc.
static int DayOfWeek(int month, int day, int year)
{
    int result = -1;

    if (IsValidDate(month, day, year))
    {
        result = ((day += month < 3 ? year-- : year - 2, 23 * month / 9 + day + 4 + year / 4 - year / 100 + year / 400) % 7);
    }
    return result;
}

static PyObject* pyDayOfWeek(PyObject* self, PyObject* args)
{
    PyObject *result = NULL;
    __int32 inputMonth;
    __int32 inputDay;
    __int32 inputYear;

    if (PyArg_ParseTuple(args, "lll", &inputMonth, &inputDay, &inputYear))
    {
        result = PyLong_FromLongLong(DayOfWeek(inputMonth, inputDay, inputYear));
    }
    return result;
}

static PyObject* pyIsValidDate(PyObject* self, PyObject* args)
{
    PyObject *result = NULL;
    __int32 inputMonth;
    __int32 inputDay;
    __int32 inputYear;

    if (PyArg_ParseTuple(args, "lll", &inputMonth, &inputDay, &inputYear))
    {
        result = PyBool_FromLong(IsValidDate(inputMonth, inputDay, inputYear));
    }
    return result;
}

static PyObject* pyIncrement(PyObject* self, PyObject* args)
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
    { "increment", pyIncrement, METH_VARARGS, "Perform a simple increment operation" },
    { "isValidDate", pyIsValidDate, METH_VARARGS, "Validate given date" },
    { "dow", pyDayOfWeek, METH_VARARGS, "Calculate day-of-week from given date" },
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