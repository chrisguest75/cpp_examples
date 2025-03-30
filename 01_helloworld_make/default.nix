{ pkgs ? import <nixpkgs> {} }:

pkgs.mkShell {
  name = "my-test-shell";

  buildInputs = [
    pkgs.jq 
    pkgs.just
    pkgs.gnumake
    pkgs.clang
    pkgs.gcc14
  ];

  MY_ENVIRONMENT_VARIABLE = "world";  

  shellHook = ''
    echo "***************************************************"
    echo "*** 01_helloworld_make!"
    echo "***************************************************"
    gcc --version
    clang --version
    make --version
    just --version
  '';
}

