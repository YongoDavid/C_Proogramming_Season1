#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
int my_printf(char * restrict format, ...) {
    va_list args;
    va_start(args, format);
    int The_Written_ = 0;
    while (*format) {
        if (*format == '%') {
            format++;
            switch (*format) {
                case 'd': {
                    int D_argmnt = va_arg(args, int);
                    char The_Buffer_[32];
                    char *poitr = The_Buffer_ + 31;
                    *poitr = '\0';
                    if (D_argmnt < 0) {
                        The_Written_ += write(1, "-", 1);
                        D_argmnt = -D_argmnt;
                    }
                    if (D_argmnt == 0) {
                        The_Written_ += write(1, "0", 1);
                    } else {
                        while (D_argmnt > 0) {
                            *--poitr = D_argmnt % 10 + '0';
                            D_argmnt /= 10;
                        }
                        The_Written_ += write(1, poitr, strlen(poitr));
                    }
                    break;
                }
                case 'o': {
                    unsigned int O_argmnt = va_arg(args, unsigned int);
                    char The_Buffer_[32];
                    char *poitr = The_Buffer_ + 31;
                    *poitr = '\0';
                    if (O_argmnt == 0) {
                        The_Written_ += write(1, "0", 1);
                    } else {
                        while (O_argmnt > 0) {
                            *--poitr = (O_argmnt % 8) + '0';
                            O_argmnt /= 8;
                        }
                        The_Written_ += write(1, poitr, strlen(poitr));
                    }
                    break;
                }
                case 'u': {
                    unsigned int U_argmnt = va_arg(args, unsigned int);
                    char The_Buffer_[32];
                    char *poitr = The_Buffer_ + 31;
                    *poitr = '\0';
                    if (U_argmnt == 0) {
                        The_Written_ += write(1, "0", 1);
                    } else {
                        while (U_argmnt > 0) {
                            *--poitr = (U_argmnt % 10) + '0';
                            U_argmnt /= 10;
                        }
                        The_Written_ += write(1, poitr, strlen(poitr));
                    }
                    break;
                }
                case 'x': {
                    unsigned int X_argmnt = va_arg(args, unsigned int);
                    char The_Buffer_[32];
                    char *poitr = The_Buffer_ + 31;
                    *poitr = '\0';
                    if (X_argmnt == 0) {
                        The_Written_ += write(1, "0", 1);
                    } else {
                        while (X_argmnt > 0) {
                            char c = X_argmnt % 16;
                            *--poitr = c < 10 ? c + '0' : c - 10 + 'A';
                            X_argmnt /= 16;
                        }
                        The_Written_ += write(1, poitr, strlen(poitr));
                    }
                    break;
                }
                case 'c': {
                    char C_argmnt = (char) va_arg(args, int);
                    The_Written_ += write(1, &C_argmnt, 1);
                    break;
                }
                case 's': {
                    const char *S_argmnt = va_arg(args, const char *);
                    if (S_argmnt == NULL) {
                        The_Written_ += write(1, "(null)", 6);
                    } else {
                        The_Written_ += write(1, S_argmnt, strlen(S_argmnt));
                    }
                    break;
                }
                case 'p': {
                    void *P_argmnt = va_arg(args, void *);
                    unsigned long long addr = (unsigned long long) P_argmnt;
                    char The_Buffer_[32];
                    char *poitr = The_Buffer_ + 31;
                    *poitr = '\0';
                    if (addr == 0) {
                        The_Written_ += write(1, "0x0", 3);
                    } else {
                        while (addr > 0) {
                            char c = addr % 16;
                            *--poitr = c < 10 ? c + '0' : c - 10 + 'a';
                            addr /= 16;
                        }
                        The_Written_ += write(1, "0x", 2);
                        The_Written_ += write(1, poitr, strlen(poitr));
                    }
                    break;
                }
                default: {
                    The_Written_ += write(1, "%", 1);
                    The_Written_ += write(1, format, 1);
                    break;
                }
            }
        } else {
            The_Written_ += write(1, format, 1);
        }
        format++;
    }
    va_end(args);
    return The_Written_;
}

int main() {
    my_printf("Hello, %s!\n", "world");
    my_printf("The answer is %d\n", 42);
    my_printf("Unsigned: %u\n", 4294967295U);
    my_printf("Octal: %o\n", 255);
    my_printf("Hex: %x\n", 255);
    my_printf("Char: %c\n", 'A');
    my_printf("Pointer: %p\n", (void *)main);
    return 0;
}
