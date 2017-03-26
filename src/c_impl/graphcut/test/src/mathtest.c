/**
 * Unit testing for mathutils.c functions
**/

#include <testing.h>
#include <stdlib.h>
#include <stdio.h>
#include <utils/mathutils.h>

static size_t testpos1 = 0;
static size_t testpos2 = 0;
static size_t *testarr1 = NULL;
static size_t *testarr2 = NULL;
static size_t arrsize1 = 0;
static size_t arrsize2 = 0;
static size_t *testdim1 = NULL;
static size_t *testdim2 = NULL;

static double bigcap = 0.0;
static double smallcap = 0.0;
static size_t bigval = 0;
static size_t smallval = 0;

/**
 * Set up the arrays and positions for back-and-forth conversion (asserts should be symmetrical)
 *
**/
void test_setup() {
	printf("Setting up math test...\n");
	//set up comparison values
	bigcap = 100.0;
	smallcap = 10.0;

	bigval = 100;
	smallval = 5;

	//setup dimension arrays
	testdim1 = (size_t *) malloc(sizeof(size_t)*2);
	testdim2 = (size_t *) malloc(sizeof(size_t)*3);
	testdim1[0] = 5;
	testdim1[1] = 4;
	testdim2[0] = 3;
	testdim2[1] = 3;
	testdim2[2] = 3;

	//setup position arrays
	testarr1 = (size_t *) malloc(sizeof(size_t)*2);
	testarr2 = (size_t *) malloc(sizeof(size_t)*3);
	testarr1[0] = 3;
	testarr1[1] = 2;
	testarr2[0] = 2;
	testarr2[1] = 1;
	testarr2[2] = 1;

	//set dimension sizes
	arrsize1 = 2;
	arrsize2 = 3;

	testpos1 = 13;
	testpos2 = 14;
	
}


/**
 * Clean up memory and test data
**/
void test_teardown() {
	printf("Tearing down math test...\n");
	free(testdim1);
	free(testdim2);
	free(testarr1);
	free(testarr2);
}

/**
 * Test minCapacity function
**/
MU_TEST(test_min_cap) {
	double *mincap;
	mincap = minCapacity(&bigcap, &smallcap);
	printf("%d == %d\n",*mincap, smallcap);
	mu_check(*mincap == smallcap);
	//test the other way
	mincap = minCapacity(&smallcap, &bigcap);
	printf("%d == %d\n", *mincap, smallcap);
	mu_check(*mincap == smallcap);
}

/**
 * Test maxCapacity function
**/
MU_TEST(test_max_cap) {
	double *maxcap;
	maxcap = maxCapacity(&bigcap, &smallcap);
	printf("%d == %d\n",*maxcap, bigcap);
	mu_check(*maxcap == bigcap);
	//test the other way
	maxcap = maxCapacity(&smallcap, &bigcap);
	printf("%d == %d\n", *maxcap, bigcap);
	mu_check(*maxcap == bigcap);
}

/**
 * Test min function
**/
MU_TEST(test_min_val) {
	size_t *minval;
	minval = min(&bigval, &smallval);
	printf("%i == %i\n",*minval, smallval);
	mu_check(*minval == smallval);
	//test the other way
	minval = min(&smallval, &bigval);
	printf("%i == %i\n",*minval, smallval);
	mu_check(*minval == smallval);
}

/**
 * Test max function
**/
MU_TEST(test_max_val) {
	size_t *maxval;
	maxval = max(&bigval, &smallval);
	printf("%i == %i\n",*maxval, bigval);
	mu_check(*maxval == bigval);
	//test the other way
	maxval = max(&smallval, &bigval);
	printf("%i == %i\n",*maxval, bigval);
	mu_check(*maxval == bigval);
}



MU_TEST_SUITE(test_suite) {
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(test_min_cap);
	MU_RUN_TEST(test_max_cap);
	MU_RUN_TEST(test_min_val);
	MU_RUN_TEST(test_max_val);
}


int main(int argc, char *argv[]) {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return 0;
}
