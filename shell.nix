with import <nixpkgs> { };
mkShell {
  buildInputs = [
    cmake
    gnumake
    SDL2
    SDL2.dev
    gcc
  ];
}

