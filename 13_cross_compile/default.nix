{ pkgs ? import <nixpkgs> {} }:

pkgs.mkShell {
  name = "my-test-shell";

  buildInputs = [
    pkgs.jq 
    pkgs.cmake
    pkgs.just
    pkgs.clang
  ];

  MY_ENVIRONMENT_VARIABLE = "world";  

  shellHook = ''
    echo "***************************************************"
    echo "*** 13_cross_compile!"
    echo "***************************************************"
    clang --version
    cmake --version
    just --version

    echo "Use 'just create'"
  '';
}

