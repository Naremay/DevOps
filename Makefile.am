AUTOMAKE_OPTIONS = foreign

bin_PROGRAMS = hyperbolic_series
hyperbolic_series_SOURCES = FuncA.cpp main.cpp

bindir = app/usr/bin

# Пакетні файли Debian
dist_noinst_DATA = app/debian/changelog app/debian/control app/debian/copyright

# Правила для створення пакету
MAINTAINERCLEANFILES = app/debian/changelog app/debian/control app/debian/copyright

TESTS = tests/test_funcA
check_PROGRAMS = tests/test_funcA

# Джерельні файли для тесту
tests_test_funcA_SOURCES = tests/test_funcA.cpp FuncA.cpp
tests_test_funcA_CPPFLAGS = -I.  # Вказує на поточний каталог для заголовкових файлів
tests_test_funcA_LDADD =
