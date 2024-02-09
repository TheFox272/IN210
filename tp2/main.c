
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

void recupAge(int *age){
    *age = (int)mock();
}
// void __wrap_recupAge(int *age){
//     *age = (int)mock();
// }

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
    float epsilon = 0.001;
    float basePrice = 1.2;

    will_return(recupAge, 12);
    actual = computePrice(12, 1);
    expected = basePrice;
    assert_float_equal (expected, actual, epsilon);

    will_return(recupAge, 12);
    actual = computePrice(12, 0);
    expected = basePrice / 2;
    assert_float_equal (expected, actual, epsilon);

    will_return(recupAge, 12);
    actual = computePrice(13, 0);
    expected = basePrice;
    assert_float_equal (expected, actual, epsilon);

    will_return(recupAge, 12);
    actual = computePrice(13, 1);
    expected = basePrice * 2;
    assert_float_equal (expected, actual, epsilon);
}



int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(null_test_success),
        cmocka_unit_test_setup_teardown(testComputePrice, setup, teardown),
    };
 //   cmocka_set_message_output(CM_OUTPUT_XML);
    return cmocka_run_group_tests_name("toto", tests, setup, teardown);
}
