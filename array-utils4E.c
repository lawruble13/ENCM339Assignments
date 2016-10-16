// array-utils-4E.c
// ENCM 339 Fall 2016 Lab 4 Exercise E

#include <assert.h>

#include "array-utils4E.h"

int decreasing(const int *a, int n)
{
  assert (n >= 1);

  int i, result = 1;
  for (i = 0; i < n - 1; i++) {
    if (!(a[i] > a[i + 1]))
      result = 0;
  }
  return result;
}

int all_unique(const int *a, int n)
{
  assert(n >= 1);

  int result = 1, i, j;
  for (i = 0; i < n; i++)
    for (j = i+1; j < n; j++)
      if (a[i] == a[j])
	result = 0;
  return result;
}

int in_range(const int* a, int n, int min, int max)
{
	assert(n >= 1);
	
	int i,result=1;
	for (i=0;i<n;i++)
		result=(a[i] >= min && a[i] <= max)?result:0;
	return result;
}
  
#ifdef UNIT_TESTS
#include <stdio.h>

// This macro works for variables declared to be arrays. (DON'T try to
// use it for function parameters declared to be arrays!)
#define COUNT(x) (sizeof(x)/sizeof(x[0]))

void test_decreasing(const char *tag, 
		     const int *a, int n, int expected_rv);

void test_all_unique(const char *tag, 
		     const int *a, int n, int expected_rv);

void test_in_range(const char *tag,
		   const int *a, int n, int min, int max, int expected_rv);

int main(void)
{
  int test_01[] = { 50, 40, 30, 20, 10 };
  int test_02[] = { 10 };
  int test_03[] = { 99, 98, 97, 96, 96 };
  int test_04[] = { 10, 11, 10, 9, 8 };
  int test_05[] = { 20, 19, 18, 19, 17 };
  test_decreasing("test_01", test_01, COUNT(test_01), 1);
  test_decreasing("test_02", test_02, COUNT(test_02), 1);
  test_decreasing("test_03", test_03, COUNT(test_03), 0);
  test_decreasing("test_04", test_04, COUNT(test_04), 0);
  test_decreasing("test_05", test_05, COUNT(test_05), 0);
  fputc('\n', stdout);

  int test_06[] = { 10, 7, 8, 9, 10 };
  int test_07[] = { 11, 12, 13, 13, 14 };
  int test_08[] = { 15, 16, 17, 18, 16, 19 };
  int test_09[] = { 20 };
  int test_10[] = { 20, 21, 22, 23, 24 };
  test_all_unique("test_06", test_06, COUNT(test_06), 0);
  test_all_unique("test_07", test_07, COUNT(test_07), 0);
  test_all_unique("test_08", test_08, COUNT(test_08), 0);
  test_all_unique("test_09", test_09, COUNT(test_09), 1);
  test_all_unique("test_10", test_10, COUNT(test_10), 1);
  fputc('\n', stdout);

  int test_11[] = { 10, 9, 8, 7, 11 }, min_11=7, max_11=11; //1
  int test_12[] = { -1, 12, 30, 7, 42 }, min_12=0, max_12=100; //0
  int test_13[] = { -20, 14, -7, 0, -2 }, min_13=-100, max_13=0; //0
  int test_14[] = { 4 }, min_14=4, max_14 = 4; // 1
  int test_15[] = { -1, -2, -3, 11, 12 }, min_15=0, max_15=10; //0
  test_in_range("test_11", test_11, COUNT(test_11), min_11, max_11, 1);
  test_in_range("test_12", test_12, COUNT(test_12), min_12, max_12, 0);
  test_in_range("test_13", test_13, COUNT(test_13), min_13, max_13, 0);
  test_in_range("test_14", test_14, COUNT(test_14), min_14, max_14, 1);
  test_in_range("test_15", test_15, COUNT(test_15), min_15, max_15, 0);
  fputc('\n', stdout);

  return 0;
}

void test_decreasing(const char *tag, 
		     const int *a, int n, int expected_rv)
{
  printf("Testing decreasing for case with tag \"%s\":", tag);
  if (expected_rv == decreasing(a, n))
    printf(" Pass.\n");
  else
    printf(" FAIL!\n");
}

void test_all_unique(const char *tag, 
		     const int *a, int n, int expected_rv)
{
  printf("Testing all_unique for case with tag \"%s\":", tag);
  if (expected_rv == all_unique(a, n))
    printf(" Pass.\n");
  else
    printf(" FAIL!\n");
}

void test_in_range(const char *tag,
		   const int *a, int n, int min, int max, int expected_rv)
{
  printf("Testing in_range for case with tag \"%s\", min %d, max %d:\n", 
tag, min, max);
  if(expected_rv == in_range(a, n, min, max))
    printf("Pass.\n");
  else
    printf("FAIL!\n");
}

#endif // #ifdef UNIT_TESTS
