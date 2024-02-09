
#include <stdio.h>
#include <stdint.h>
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include "cmocka.h"
#include <string.h>
#include "ratp.h"
#include <stdbool.h>

/* A test case that does nothing and succeeds. */



static int setup(void **state) {
    (void) state;
    printf("setUp");
 return 0;
}
static int teardown(void **state) {
    (void) state;
    printf("tearDown");
     return 0;
}
static void null_test_success(void **state) {
    (void) state;
}

static void testComputePrice(void **){
    float actual, expected;
    float epsilon = 0.01;
    float basePrice = 1.2;

    actual = computePrice(12, 1);
    expected = basePrice * 2;
    // assert_float_equal (expected, actual, epsilon);

    assert_true (expected == actual);
}



int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(null_test_success),
        cmocka_unit_test_setup(testComputePrice, setup),
    };
 //   cmocka_set_message_output(CM_OUTPUT_XML);
    return cmocka_run_group_tests_name("toto", tests, setup, teardown);
}
