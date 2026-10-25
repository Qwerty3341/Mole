# compile_flags.txt

The file contains the flags for gcc compiler:

- Iinclude: Adds the include/ directory to the header search path, so headers can be included by name (#include "calc_filesize.h") from any source file.
- Wall: This enables all the warnings about constructions that some users consider questionable
- Wextra: Enables extra flags not enabled by -Wall
- Werror: Turn any warning into a compilation error.

## References

- [GCC directory options (-I)](https://gcc.gnu.org/onlinedocs/gcc/Directory-Options.html)
- [GCC warning options (-Wall, -Wextra, -Werror)](https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html)
