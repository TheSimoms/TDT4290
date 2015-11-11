/* Check if the compiler matches the one used to build the runtime */
#ifndef MAKEDEPEND_RUN



#if GCC_VERSION != 40800
#error The version of GCC does not match the expected version (GCC 4.8.2)
#endif

#endif

