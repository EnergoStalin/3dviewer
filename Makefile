.PHONY: all build debug valgrind gdb clean lint dvi dist test install uninstall intellisense
.RECIPEPREFIX = >

LINTFILES=$(wildcard Back/*.hpp Back/*.cpp QT_3D_VIEWER/*.hpp QT_3D_VIEWER/*.h QT_3D_VIEWER/*.c)
CLANG_FORMAT_EXECUTABLE = $(shell which clang-format)
INSTALL_DIR ?= ./install

DISTFILE=dist.tar
.RECIPEPREFIX=>

XFLAGS ?=

all: build test gcov_report

build:
> xmake config $(XFLAGS) -y -m release
> xmake build $(XFLAGS) -g bin

debug:
> xmake config $(XFLAGS) -y -m debug
> xmake build $(XFLAGS) -g bin

gdb:
> xmake config $(XFLAGS) -y -m debug
> xmake build $(XFLAGS) -g bin
> xmake run $(XFLAGS) -g test -d

clean:
> xmake clean $(XFLAGS)

format:
> xmake format $(XFLAGS) --all -s Google

lint:
> $(CLANG_FORMAT_EXECUTABLE) -n --Werror --style=Google $(LINTFILES)
> if which s21lint; then s21lint $(LINTFILES); fi

dvi:
> xmake doxygen $(XFLAGS)

dist: install
> mkdir -p $(INSTALL_DIR)/dist
> cp $(INSTALL_DIR)/bin/* $(INSTALL_DIR)/lib/* $(INSTALL_DIR)/dist
> tar -c $(INSTALL_DIR)/dist -f $(DISTFILE)

test:
> xmake config $(XFLAGS) -y -m release
> xmake build $(XFLAGS) -g test
> xmake run $(XFLAGS) -g test

testdbg:
> xmake config $(XFLAGS) -y -m debug
> xmake build $(XFLAGS) -g test
> xmake run $(XFLAGS) -g test

valgrind:
> xmake config $(XFLAGS) -y -m valgrind
> xmake build $(XFLAGS) -g test
> xmake run $(XFLAGS) -g test

install: build
> mkdir -p $(INSTALL_DIR)
> cp -rf docs $(INSTALL_DIR) || true
> xmake install $(XFLAGS) -o $(INSTALL_DIR) -g bin

run:
> xmake build $(XFLAGS) -g bin
> xmake run $(XFLAGS) -g bin

uninstall:
> rm -r $(INSTALL_DIR)

gcov_report:
> xmake config $(XFLAGS) -y -m coverage
> xmake build $(XFLAGS) -g test
> xmake run $(XFLAGS) -g test
> xdg-open report/index.html

fclean:
> xmake clean $(XFLAGS) --all
> rm -rf build $(DISTFILE) report docs

intellisense:
> xmake project $(XFLAGS) -k compile_commands

