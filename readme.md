This is an example on how to emulate a U8G2 display

---
## Instructions

You need SDL and CMake first, if you're on linux try the following based on your distribution:
```sh
$ sudo apt install libsdl2-dev cmake make     # Ubuntu
$ sudo dnf install SDL2-devel cmake make      # Red Hat / Fedora
$ sudo pacman -S sdl2 cmake make              # Arch Linux (btw)
```

```sh
$ git clone --recursive https://github.com/ironlungx/u8g2_sdl.git
$ cd u8g2_sdl/
$ mkdir build/ && cd build/
$ cmake ..
$ make -j
```
