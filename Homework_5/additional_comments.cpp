// Dynamically allocate memory for a character array (C-style string) based on the length of userInputString.
// The `userInputString.length()` gives the length of the std::string (not counting the null terminator),
// and we add +1 to accommodate the null terminator ('\0') required for a valid C-style string.
/*
            ----------SYNTAX----------
char* characterStorageArray = new char[userInputString.length() + 1];  
            ----------SYNTAX----------
            
            // +1 for the null terminator
// Explanation of `new char[userInputString.length() + 1]`:
// - `new`:                                     This keyword dynamically allocates memory on the heap. We use dynamic memory allocation 
//   because the size of the array is determined at runtime (based on the length of userInputString).
// - `char`:                                    This defines the type of elements being allocated, which is a `char` (character).
// - `userInputString.length()`:                This function from the `std::string` class returns the number of 
//   characters in `userInputString`. For example, if the input string is "Hello", `userInputString.length()`
//   would return 5.
// - `+ 1`:                                     This ensures that there's an extra byte allocated to store the null terminator `'\0'`,
//   which is required to properly terminate a C-style string (so functions like `strlen()` can know where the string ends).


// Now, we copy the contents of the std::string (userInputString) into the newly allocated char array (characterStorageArray).
// `std::strcpy()`                              is used to copy C-style strings (null-terminated arrays of `char`), so we need to convert the
// std::string into a C-style string using the `.c_str()` method, which provides a pointer to a null-terminated array of characters.

            ----------SYNTAX----------
std::strcpy(characterStorageArray, userInputString.c_str());
            ----------SYNTAX----------

            // Copy std::string to char array
// Explanation of `std::strcpy(characterStorageArray, userInputString.c_str())`:
// - `std::strcpy`:                     This is a function from the C Standard Library (<cstring> in C++) used to copy 
//   C-style strings (null-terminated `char` arrays). It copies characters from the source string to 
//   the destination array, including the null terminator.
// - `characterStorageArray`:               This is the destination array where the characters will be copied. 
//   It's the dynamically allocated `char[]` that will hold the string.
// - `userInputString.c_str()`:                 The `.c_str()` method is called on `std::string` to get a pointer 
//   to a null-terminated C-style string (i.e., a `const char*`). 
This provides the source string for `strcpy()`.    Without `.c_str()`, we would be passing an incompatible type (a `std::string`) 
//   to a function that expects a `const char*` (C-style string).
*/