#include "./includes/libunit.h"

int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int segv() { return kill(getpid(), SIGSEGV); }
int abrt() { return kill(getpid(), SIGABRT); }

int test_add() {
    if (add(10, 3) == 13)
        return (0);
    return (1);
}

int test_sub() {
    if (sub(10, 3) == 13)
        return (0);
    return (1);
}

int test_sub2() {
    if (sub(10, 3) == 13)
        return (0);
    return (2);
}

int test_segv() {
    return (segv());
}

int test_abrt() {
    return (abrt());
}

int main() {
    t_libunit *libunit = NULL;
    libunit_load_test(&libunit, "test_add", &test_add);
    libunit_load_test(&libunit, "test_sub", &test_sub);
    libunit_load_test(&libunit, "test_sub_false", &test_sub2);
    libunit_load_test(&libunit, "test_segv", &test_segv);
    libunit_load_test(&libunit, "test_abrt", &test_abrt);

    libunit_load_test(&libunit, "test_add", &test_add);
    libunit_load_test(&libunit, "test_sub", &test_sub);
    libunit_load_test(&libunit, "test_sub_false", &test_sub2);
    libunit_load_test(&libunit, "test_segv", &test_segv);
    libunit_load_test(&libunit, "test_abrt", &test_abrt);

    libunit_load_test(&libunit, "test_add", &test_add);
    libunit_load_test(&libunit, "test_sub", &test_sub);
    libunit_load_test(&libunit, "test_sub_false", &test_sub2);
    libunit_load_test(&libunit, "test_segv", &test_segv);
    libunit_load_test(&libunit, "test_abrt", &test_abrt);

    libunit_load_test(&libunit, "test_add", &test_add);
    libunit_load_test(&libunit, "test_sub", &test_sub);
    libunit_load_test(&libunit, "test_sub_false", &test_sub2);
    libunit_load_test(&libunit, "test_segv", &test_segv);
    libunit_load_test(&libunit, "test_abrt", &test_abrt);

    libunit_launch_tests(&libunit);
}