sudo find /usr -name "libSDL3*" -delete
sudo find /usr -name "SDL3*" -path "*/pkgconfig/*" -delete
sudo ldconfig