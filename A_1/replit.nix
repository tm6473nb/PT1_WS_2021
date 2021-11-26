{ pkgs }: {
	deps = [
    pkgs.fontconfig
		pkgs.cairo
    pkgs.gtk3-x11
    pkgs.pkg-config
	];
}