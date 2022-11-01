#!/bin/sh

debug() {
    set -o xtrace
    cmake -DBUILD_SHARED_LIBS=False \
          -S . -B ./Build \
          -D CMAKE_BUILD_TYPE=Debug \
    && make -j -C ./Build
}

build() {
    set -o xtrace
    cmake -DBUILD_SHARED_LIBS=False \
          -S . -B ./Build \
          -D CMAKE_BUILD_TYPE=Release \
    && make -j -C ./Build
}

clean() {
    set -o xtrace
    rm -rf ./Build
}

help() {
    echo "Использование:"
    echo "./maker.sh build -> Собрать проект с помощью CMake и make -C ./Build/"
    echo "./maker.sh debug -> Собрать проект с сохранением информации для отладки"
    echo "./maker.sh clean -> Удалить содержимое директории ./Build/"
}

case "$1" in
    build) build ;;
    release) release ;;
    winbuild) winbuild ;;
    clean) clean ;;
    *) help ;;
esac

