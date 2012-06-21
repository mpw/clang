// RUN: %clang -### -Wlarge-by-value-copy %s 2>&1 | FileCheck -check-prefix=LARGE_VALUE_COPY_DEFAULT %s
// LARGE_VALUE_COPY_DEFAULT: -Wlarge-by-value-copy=64
// RUN: %clang -### -Wlarge-by-value-copy=128 %s 2>&1 | FileCheck -check-prefix=LARGE_VALUE_COPY_JOINED %s
// LARGE_VALUE_COPY_JOINED: -Wlarge-by-value-copy=128

// RUN: %clang -c -Wmonkey -Wno-monkey -Wno-unused-command-line-arguments \
// RUN:        -Wno-unused-command-line-argument %s 2>&1 | FileCheck %s
// CHECK: unknown warning option '-Wmonkey'
// CHECK: unknown warning option '-Wno-monkey'
// CHECK: unknown warning option '-Wno-unused-command-line-arguments'; did you mean '-Wno-unused-command-line-argument'?

// RUN: %clang -### -pedantic -no-pedantic %s 2>&1 | FileCheck -check-prefix=NO_PEDANTIC %s
// NO_PEDANTIC-NOT: -pedantic
// RUN: %clang -### -pedantic -pedantic -no-pedantic -pedantic %s 2>&1 | FileCheck -check-prefix=PEDANTIC %s
// PEDANTIC: -pedantic

// PR12920: They use gcc driver. Clang tends to pass -pedantic to gcc-as and gcc-ld.
// XFAIL: cygwin,mingw32