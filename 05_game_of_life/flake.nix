# flake.nix
{
    description = "A flake for developing with gcc";
  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
  };

  outputs = {nixpkgs, ...}: let
    system = "x86_64-linux";
    #       ↑ Swap it for your system if needed
    #       "aarch64-linux" / "x86_64-darwin" / "aarch64-darwin"
    pkgs = nixpkgs.legacyPackages.${system};
  in {
    devShells.${system}.default = pkgs.mkShell {

      packages = [ 
          pkgs.libgcc
          pkgs.cmake 
          pkgs.gnumake 
       ];

      env = {
        PIPENV_VENV_IN_PROJECT=1;
      };

      shellHook = ''
        echo "***************************************************"
        echo "*** Welcome to game of life"
        echo "***************************************************"
        echo ""
        gcc --version
        cmake --version
      '';       
    };
  };
}
