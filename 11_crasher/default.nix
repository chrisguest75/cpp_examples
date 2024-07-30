{ pkgs ? import <nixpkgs> {} }:

pkgs.mkShell {
  name = "my-test-shell";

  buildInputs = [
    pkgs.jq 
    pkgs.cmake
    pkgs.just
    pkgs.gcc14
    pkgs.conan
  ];

  MY_ENVIRONMENT_VARIABLE = "world";  

  shellHook = ''
    echo "***************************************************"
    echo "*** 11_crasher!"
    echo "***************************************************"
    gcc --version
    cmake --version
    just --version

    echo "Use 'just create'"
  '';
}

