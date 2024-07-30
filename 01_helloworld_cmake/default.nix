{ pkgs ? import <nixpkgs> {} }:

pkgs.mkShell {
  name = "my-test-shell";

  buildInputs = [
    pkgs.jq 
    pkgs.cmake
    pkgs.just
    pkgs.gcc14
  ];

  MY_ENVIRONMENT_VARIABLE = "world";  

  shellHook = ''
    echo "***************************************************"
    echo "*** 01_helloworld_cmake!"
    echo "***************************************************"
    gcc --version
    cmake --version
    just --version

    echo "Use 'just create'"
  '';
}

