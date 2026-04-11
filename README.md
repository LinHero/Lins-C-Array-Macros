# Basic Memory Safe Arrays in C
A file I created inspired by the "Tips for C Programming" video by Nic Barker.
Creates some simple memory safe array macros, which allows bounds checking.
There are multiple array types, and with them their own macros.


type ARRAY_1D

To have an array, simply call mARRAY<SUFFIX>
Followed by the info you want.
If you want to pass a series of elements,    "mARRAY_DATA(type, name, {elements})"
If you want to pass a size,                  "mARRAY_SIZE(type, name, size)"
If you want both size and elements,          "mARRAY_SIZEDATA(type, name, size, {elements})"

If you want to use pointers in their stead, this is also easily done.
Simply append _PTR to any of the above. ie: mARRAY_DATA_PTR(type, name, {elements})
the _PTR suffix handles any data you wish to handle via pointers,
and is ideal over <type>* on the regular mARRAY.


To access the data in an array, either to read or write.
You can then call mARRAY_GET, mARRAY_SET, or mARRAY_GET_ADDR.
Args for Get                                  "mARRAY_GET(type, name, ind)"
Args for Set                                  "mARRAY_SET(type, name, ind, val)"
Args for Get_Addr                             "mARRAY_GET(type, name, ind)"

Like all others, _PTR can be appended at the end to access an array of pointers.
mARRAY_GET_ADDR returns a pointer to the address of an index for a given array





    - Lin Hero
