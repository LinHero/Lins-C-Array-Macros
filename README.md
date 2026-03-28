# Basic Memory Safe Arrays in C
A file I created inspired by the "Tips for C Programming" video by Nic Barker.
Creates some simple memory safe array macros, which allows bounds checking.

Their use is very easy, and a few examples are in the "arrays.h" file.
To have an array, simply call mARRAY<SUFFIX>
Followed by the info you want.
If you want to pass a series of elements,    "mARRAY_DATA(type, name, {elements})"
If you want to pass a size,                  "mARRAY_SIZE(type, name, size)"
If you want both size and elements,          "mARRAY_SIZEDATA(type, name, size, {elements})"

If you want to use pointers in their stead, this is also easily done.
Simply append _PTR to any of the above. ie: mARRAY_DATA_PTR(type, name, {elements})
the _PTR suffix handles any data you wish to handle via pointers,
and is ideal over <type>* on the regular mARRAY.


To access the arrays, you need to define 1 thing,
the type's GETSET functions, which can be done via mCREATE_GETSET(type)
mCREATE_GETSET does not automatically create pointer types.
Append _PTR, like above, to create the GETSET routines. "mCREATE_GETSET_PTR(type)"

To access the data in an array, either to read or write.
You can then call mARRAY_GET, or mARRAY_SET.
Args for Get                                  "mARRAY_GET(type, name, ind)"
Args for Set                                  "mARRAY_SET(type, name, ind, val)"

Like all others, _PTR can be appended at the end to access an array of pointers.

    - Lin Hero
