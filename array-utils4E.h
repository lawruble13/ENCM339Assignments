// array-utils-4E.h
// ENCM 339 Fall 2016 Lab 4 Exercise E

int decreasing(const int *a, int n);
// REQUIRES: n >= 1. Elements a[0] ... a[n-1] exist. 
// PROMISES
//   Return value is  1 if n == 1, or if n > 1 and all of 
//   a[0] > a[1] ... a[n-2] > a[n-1] are true.  
//   Otherwise, return value is 0.

int all_unique(const int *a, int n);
// REQUIRES: n >= 1. Elements a[0] ... a[n-1] exist. 
// PROMISES: Return value is 1 if no two elements among 
// a[0] ... a[n-1] are equal to each other. 
//   Otherwise, return value is 0.

int in_range(const int *a, int n, int min, int max);
// REQUIRES: n >= 1. Elements a[0] ... a[n-1] exist. min <= max.
// PROMISES: Return value is 1 if it is true that
//   element among a[0] ... a[n-1] is >= min and <= max.
//   Otherwise, return value is 0.
