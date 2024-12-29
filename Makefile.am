AUTOMAKE_OPTIONS = foreign

bin_PROGRAMS = hyperbolic_series
hyperbolic_series_SOURCES = FuncA.cpp main.cpp

prefix = /usr/local
bindir = $(prefix)/bin

# Пакетні файли Debian
dist_noinst_DATA = debian/changelog debian/control debian/copyright

# Правила для створення пакету
MAINTAINERCLEANFILES = debian/changelog debian/control debian/copyright

noinst_PROGRAMS =
