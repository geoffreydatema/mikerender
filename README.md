# mikerender

## build
g++ src/*.cpp -o build/mike.exe -Iinclude

## run
./build/mike.exe
../uafviewer/build/uafviewer.exe ./renders/render.uaf

## backlog
- change colour cast to int to be the Colour class's responsibility
- review variable and callable names
- simplify as much as possible
