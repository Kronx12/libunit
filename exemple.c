#include "./includes/libunit.h"

int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int segv() { return kill(getpid(), SIGSEGV); }
int abrt() { return kill(getpid(), SIGABRT); }
int buserror() { return kill(getpid(), SIGBUS); }
int sigpipe() { return kill(getpid(), SIGPIPE); }
int sigkill() { return kill(getpid(), SIGILL); }
int unsupported() { return kill(getpid(), SIGALRM); }

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

int test_buserror() {
    return (buserror());
}

int test_sigpipe() {
    return (sigpipe());
}

int test_sigkill() {
    return (sigkill());
}

int test_unsupported_error() {
    return (unsupported());
}

int main() {
    t_libunit *libunit = NULL;
    libunit_load_test(&libunit, "test_add", &test_add);
    libunit_load_test(&libunit, "test_sub", &test_sub);
    libunit_load_test(&libunit, "test_sub_false", &test_sub2);
    libunit_load_test(&libunit, "test_segv", &test_segv);
    libunit_load_test(&libunit, "test_abrt", &test_abrt);
    libunit_load_test(&libunit, "test_buserror", &test_buserror);
    libunit_load_test(&libunit, "test_sigpipe", &test_sigpipe);
    libunit_load_test(&libunit, "test_sigkill", &test_sigkill);
    libunit_load_test(&libunit, "test_unsupported_error", &test_unsupported_error);

    libunit_launch_tests(&libunit);
}