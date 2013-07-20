CS240_Lab06
===========

Description:

- A set of parallel vectors, one for each kind ([T]itle,[R]ating,[D]irectors,[S]tars).
- Each vector element is a struct{} that contains a std::string() and a *MoviePtr
- The latter three vectors (R,D,S) have their pointers point to the movie that that string refers to.
- The T-vector will contain structs of the same, but their pointers will point to themselves.
  - This will maintain search&print simplicity
- Search within all vectors will be binary.
- Upon finding a match in a binary search, a linear search will be conducted upon the indecies above and below to find other matches (if the search string is a partial sub-string).
- Every match will result in the printing of the movie that the contained *MoviePtr points to.

Functions:

- readFile()
  - Takes initialization file as input and returns it (one line at a time).  
- addNew()
  - parseCommas()
    - Takes raw string from readFile() and parses it into category substrings by comma delimination.
  - For each category:
    - std::vector::insert()
    - setPtr() to movie
- 
