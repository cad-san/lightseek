#!/bin/bash
# build script for Travis CI

if [ "$BUILD_TARGET" = "test" ]; then
    if [ "$CC" = "gcc" ]; then
        make gcov || exit 1
    else
        make test || exit 1
    fi
fi

if [ "$BUILD_TARGET" = "release" ]; then
	make release || exit 1
fi

if [ "$BUILD_TARGET" = "sample_qt" ]; then
    make release || exit 1
    cd sample/sample_qt
    qmake-qt4 sample_qt.pro || exit 1
    make || exit 1
fi
