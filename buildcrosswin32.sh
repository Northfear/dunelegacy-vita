#!/bin/bash

mkdir -p build

mkdir -p build/x86
if [ ! -e build/x86/SDL2.dll ]
then
	ZIP_FILE=SDL2-2.0.14-win32-x86.zip
	echo "Downloading 32-bit ${ZIP_FILE}..."
	wget -c http://libsdl.org/release/${ZIP_FILE} -O build/x86/${ZIP_FILE}
	unzip -q build/x86/${ZIP_FILE} -d build/x86 SDL2.dll
	rm build/x86/${ZIP_FILE}
fi

if [ ! -e build/x86/SDL2_mixer.dll ]
then
	ZIP_FILE=SDL2_mixer-2.0.4-win32-x86.zip
	echo "Downloading 32-bit ${ZIP_FILE}..."
	wget -c https://www.libsdl.org/projects/SDL_mixer/release/${ZIP_FILE} -O build/x86/${ZIP_FILE}
	unzip -q build/x86/${ZIP_FILE} -d build/x86 SDL2_mixer.dll libmpg123-0.dll libvorbisfile-3.dll libvorbis-0.dll libogg-0.dll libFLAC-8.dll libmodplug-1.dll
	rm build/x86/${ZIP_FILE}
fi

if [ ! -e build/x86/SDL2_ttf.dll ]
then
	ZIP_FILE=SDL2_ttf-2.0.15-win32-x86.zip
	echo "Downloading 32-bit ${ZIP_FILE}..."
	wget -c https://www.libsdl.org/projects/SDL_ttf/release/${ZIP_FILE} -O build/x86/${ZIP_FILE}
	unzip -q build/x86/${ZIP_FILE} -d build/x86 SDL2_ttf.dll libfreetype-6.dll zlib1.dll
	rm build/x86/${ZIP_FILE}
fi

mkdir -p build/x64
if [ ! -e build/x64/SDL2.dll ]
then
	ZIP_FILE=SDL2-2.0.14-win32-x64.zip
	echo "Downloading 64-bit ${ZIP_FILE}..."
	wget -c http://libsdl.org/release/${ZIP_FILE} -O build/x64/${ZIP_FILE}
	unzip -q build/x64/${ZIP_FILE} -d build/x64 SDL2.dll
	rm build/x64/${ZIP_FILE}
fi

if [ ! -e build/x64/SDL2_mixer.dll ]
then
	ZIP_FILE=SDL2_mixer-2.0.4-win32-x64.zip
	echo "Downloading 64-bit ${ZIP_FILE}..."
	wget -c https://www.libsdl.org/projects/SDL_mixer/release/${ZIP_FILE} -O build/x64/${ZIP_FILE}
	unzip -q build/x64/${ZIP_FILE} -d build/x64 SDL2_mixer.dll libmpg123-0.dll libvorbisfile-3.dll libvorbis-0.dll libogg-0.dll libFLAC-8.dll libmodplug-1.dll
	rm build/x64/${ZIP_FILE}
fi

if [ ! -e build/x64/SDL2_ttf.dll ]
then
	ZIP_FILE=SDL2_ttf-2.0.15-win32-x64.zip
	echo "Downloading 64-bit ${ZIP_FILE}..."
	wget -c https://www.libsdl.org/projects/SDL_ttf/release/${ZIP_FILE} -O build/x64/${ZIP_FILE}
	unzip -q build/x64/${ZIP_FILE} -d build/x64 SDL2_ttf.dll libfreetype-6.dll zlib1.dll
	rm build/x64/${ZIP_FILE}
fi

autoreconf --install
mkdir -p build/src
i686-w64-mingw32-windres -o build/src/resource.o resource.rc
cd build
../configure --prefix="" --host=i686-w64-mingw32 --with-sdl-prefix=/usr/local/sdl/i686-w64-mingw32 --disable-sdltest && make $1 && cp src/dunelegacy.exe x86/
cd ..

cd build
make distclean
cd ..

autoreconf --install
mkdir -p build/src
x86_64-w64-mingw32-windres -o build/src/resource.o resource.rc
cd build
../configure --prefix="" --host=x86_64-w64-mingw32 --with-sdl-prefix=/usr/local/sdl/x86_64-w64-mingw32 --disable-sdltest && make $1 && cp src/dunelegacy.exe x64/
cd ..

makensis dunelegacy.nsi
