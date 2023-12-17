TARGET=gamemodes/gamemode.amx
SOURCE=src/gamemode.pwn
PC:=pawncc 
PC_FLAGS=-iinclude -w

all: release

release:
	$(PC) $(SOURCE) $(PC_FLAGS) -o$(TARGET)

debug:
	$(PC) $(SOURCE) $(PC_FLAGS) -d3 -o$(TARGET)