# notes
## Table of Contents
- [Declaring Variables](#declaring-variables)
- [Scope](#scope)
- [Storage Duration](#storage-duration)
- [Alignment](#alignment)
- [Object Types](#object-types)

### <b>Declaring Variables</b>
- Variables are objects with a declared type
- Type is important since another type will interpret the bit pattern differently
- Functions are not objects but do have return types and a number of types as parameter
- <b>Pointers</b> = adress in memory
- Pointer type derived from object or function called referenced type
- Pointer from referenced type T = pointer to T
- Object pointers != function pointers
- Function arguments are copies of the original variable
- <b>\*</b> = points to memory address of an object or function
- <b>Dereferencing</b> = accessing the value stored at the memory address the pointer points to
- <b>&</b> = creates a pointer to its address

### <b>Scope</b>
- <b>Scope</b> = Region where a C identifier (variable, function, ...) can be accessed
- C has 4 types of scope:
  - <b>File Scope:</b><br>
    Scope is entire text file and any files that appear afterwards.
  - <b>Block Scope:</b>
    Identifier is only accessible within the block it's defined in.
  - <b>Function Prototype Scope:</b>
    Allows functions to be defined before they are called. (no {} with logic)
  - <b>Function Scope:</b>
    Function scope is logic between {}.
    Labels also have function scope.

- Scopes can be nested with inner and outer scopes.
- Best practice is to use different identifiers to avoid confusion.
- Identifiers in large scopes need to be descriptive/longer.

### <b>Storage Duration</b>
- four storage durations exist:
  - <b>Automatic:</b><br>
    Lifetime begins when the block where it's declared begins execution and ends when execution of this block ends.
  - <b>Static:</b><br>
    Static lifespan is during the <b>entire execution of the program</b>. Objects in file scope are static. By specifying `static` you can make block-scoped variables static. Static objects cannot be declared with a variable.
  - <b>Thread:</b><br>
    Used in <b>concurrent programming</b>. (Not seen in this book)
  - <b>Allocated:</b><br>
    Deals with <b>dynamically allocated memory</b>. Seen in chapter 6.

### <b>Alignment</b>
- Alignment is the number of bytes between successive addresses which objects can be allocated to. This differs from cpu to cpu.
- Alignments are always a non-negative multiple of 2.
- Dynamically allocated memory using `malloc` is required to be alligned for all standards.
- `_Alignas` = Controls the alignment of a variable or type explicitly. Overrides the default alignment.<br>
Is usually used when you need to meet specific hardware requirements or use specific operations.
- Stricter alignment = the variable needs to be placed at a memory address that are a multiple of a specific value

### <b>Object Types</b>
- `_Bool` = objects can only store 0 and 1 (underscore is to separate from existing programs that already have bool or boolean declared)
- Identifiers beginning with `_` and followed by another `_` or an uppercase letter is always reserved by the C standard committee
- `#include <stdbool.h>` adds the `bool` and `true` and `false` global identifiers. (`bool` is recommended as type)
