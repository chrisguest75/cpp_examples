with import <nixpkgs> {};

buildEnv {
  name = "buildjq";
  paths = [ 
    jq 
    gcc14
    cmake
    just
  ];
}
