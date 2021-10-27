# raylib-template
A CMake raylib template using EnTT with support for MinGW, Linux and HTML5.

Probably shouldn't be used, so don't.

But if you insist, here's how:

## Instructions

```
git clone https://github.com/Skyliegirl33/raylib-template.git
cd raylib-template/
mkdir build && cd build
conan install ..
```

HTML5:
```
emcmake cmake ..
make
```

Linux:
```
cmake ..
make
```

MinGW:
```
x86_64-w64-mingw32-cmake ..
make
```