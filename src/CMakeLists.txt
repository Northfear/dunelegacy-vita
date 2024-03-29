cmake_minimum_required(VERSION 3.16)

set(TOP_SOURCES
	AStarSearch.cpp
	Bullet.cpp
	Choam.cpp
	Command.cpp
	CommandManager.cpp
	Explosion.cpp
	Game.cpp
	GameInitSettings.cpp
	GameInterface.cpp
	House.cpp
	Map.cpp
	MapSeed.cpp
	ObjectBase.cpp
	ObjectData.cpp
	ObjectManager.cpp
	ObjectPointer.cpp
	RadarView.cpp
	ScreenBorder.cpp
	SoundPlayer.cpp
	Tile.cpp
	globals.cpp
	mmath.cpp
	sand.cpp)

set(CUT_SCENES_SOURCES
	CutScenes/CrossBlendVideoEvent.cpp
	CutScenes/CutScene.cpp
	CutScenes/CutSceneTrigger.cpp
	CutScenes/FadeInVideoEvent.cpp
	CutScenes/FadeOutVideoEvent.cpp
	CutScenes/Finale.cpp
	CutScenes/HoldPictureVideoEvent.cpp
	CutScenes/Intro.cpp
	CutScenes/Meanwhile.cpp
	CutScenes/Scene.cpp
	CutScenes/TextEvent.cpp
	CutScenes/VideoEvent.cpp
	CutScenes/WSAVideoEvent.cpp)

set(FILE_CLASSES_SOURCES
	FileClasses/Animation.cpp
	FileClasses/Cpsfile.cpp
	FileClasses/Decode.cpp
	FileClasses/FileManager.cpp
	FileClasses/FontManager.cpp
	FileClasses/GFXManager.cpp
	FileClasses/INIFile.cpp
	FileClasses/Icnfile.cpp
	FileClasses/IndexedTextFile.cpp
	FileClasses/LoadSavePNG.cpp
	FileClasses/MentatTextFile.cpp
	FileClasses/POFile.cpp
	FileClasses/Pakfile.cpp
	FileClasses/Palfile.cpp
	FileClasses/PictureFactory.cpp
	FileClasses/SFXManager.cpp
	FileClasses/Shpfile.cpp
	FileClasses/TTFFont.cpp
	FileClasses/TextManager.cpp
	FileClasses/Vocfile.cpp
	FileClasses/Wsafile.cpp
	FileClasses/adl/sound_adlib.cpp
	FileClasses/adl/surroundopl.cpp
	FileClasses/adl/woodyopl.cpp
	FileClasses/lodepng.cpp
	FileClasses/music/ADLPlayer.cpp
	FileClasses/music/DirectoryPlayer.cpp
	FileClasses/music/XMIPlayer.cpp
	FileClasses/xmidi/xmidi.cpp)

set(GUI_SOURCES
	GUI/Button.cpp
	GUI/DropDownBox.cpp
	GUI/GUIStyle.cpp
	GUI/ListBox.cpp
	GUI/RadioButtonManager.cpp
	GUI/ScrollBar.cpp
	GUI/TextView.cpp
	GUI/Widget.cpp
	GUI/Window.cpp
	GUI/dune/BuilderList.cpp
	GUI/dune/ChatManager.cpp
	GUI/dune/DuneStyle.cpp
	GUI/dune/GameOptionsWindow.cpp
	GUI/dune/InGameMenu.cpp
	GUI/dune/InGameSettingsMenu.cpp
	GUI/dune/LoadSaveWindow.cpp
	GUI/dune/MessageTicker.cpp
	GUI/dune/NewsTicker.cpp
	GUI/dune/WaitingForOtherPlayers.cpp)

set(INIMAP_SOURCES
	INIMap/INIMapEditorLoader.cpp
	INIMap/INIMapLoader.cpp
	INIMap/INIMapPreviewCreator.cpp)

set(MAP_EDITOR_SOURCES
	MapEditor/ChoamWindow.cpp
	MapEditor/LoadMapWindow.cpp
	MapEditor/MapEditor.cpp
	MapEditor/MapEditorInterface.cpp
	MapEditor/MapEditorOperation.cpp
	MapEditor/MapEditorRadarView.cpp
	MapEditor/MapGenerator.cpp
	MapEditor/MapMirror.cpp
	MapEditor/MapSettingsWindow.cpp
	MapEditor/NewMapWindow.cpp
	MapEditor/PlayerSettingsWindow.cpp
	MapEditor/ReinforcementsWindow.cpp
	MapEditor/TeamsWindow.cpp)

set(MENU_SOURCES
	Menu/AboutMenu.cpp
	Menu/BriefingMenu.cpp
	Menu/CampaignStatsMenu.cpp
	Menu/CustomGameMenu.cpp
	Menu/CustomGamePlayers.cpp
	Menu/CustomGameStatsMenu.cpp
	Menu/HouseChoiceInfoMenu.cpp
	Menu/HouseChoiceMenu.cpp
	Menu/MainMenu.cpp
	Menu/MapChoice.cpp
	Menu/MentatHelp.cpp
	Menu/MentatMenu.cpp
	Menu/MenuBase.cpp
	Menu/MultiPlayerMenu.cpp
	Menu/OptionsMenu.cpp
	Menu/SinglePlayerMenu.cpp
	Menu/SinglePlayerSkirmishMenu.cpp)

set(NETWORK_SOURCES
	Network/ENetHttp.cpp
	Network/LANGameFinderAndAnnouncer.cpp
	Network/MetaServerClient.cpp
	Network/NetworkManager.cpp)

set(TRIGGER_SOURCES
	Trigger/ReinforcementTrigger.cpp
	Trigger/TimeoutTrigger.cpp
	Trigger/TriggerManager.cpp)

set(FIX_MATH_SOURCES
	fixmath/fix16.c
	fixmath/fix16_exp.c
	fixmath/fix16_sqrt.c
	fixmath/fix16_str.c
	fixmath/fix16_trig.c
	fixmath/fix32.c
	fixmath/fix32_exp.c
	fixmath/fix32_sqrt.c
	fixmath/fix32_str.c
	fixmath/fix32_trig.c)

set(MISC_SOURCES
	misc/FileSystem.cpp
	misc/IFileStream.cpp
	misc/OFileStream.cpp
	misc/Random.cpp
	misc/Scaler.cpp
	misc/draw_util.cpp
	misc/fnkdat.cpp
	misc/format.cpp
	misc/md5.cpp
	misc/sound_util.cpp
	misc/string_util.cpp)

set(ENET_SOURCES
	enet/callbacks.c
	enet/compress.c
	enet/host.c
	enet/list.c
	enet/packet.c
	enet/peer.c
	enet/protocol.c
	enet/unix.c
	enet/win32.c)

set(PLAYERS_SOURCES
	players/AIPlayer.cpp
	players/CampaignAIPlayer.cpp
	players/HumanPlayer.cpp
	players/Player.cpp
	players/PlayerFactory.cpp
	players/QuantBot.cpp
	players/SmartBot.cpp)

set(STRUCTURES_SOURCES
	structures/Barracks.cpp
	structures/BuilderBase.cpp
	structures/ConstructionYard.cpp
	structures/GunTurret.cpp
	structures/HeavyFactory.cpp
	structures/HighTechFactory.cpp
	structures/IX.cpp
	structures/LightFactory.cpp
	structures/Palace.cpp
	structures/Radar.cpp
	structures/Refinery.cpp
	structures/RepairYard.cpp
	structures/RocketTurret.cpp
	structures/Silo.cpp
	structures/StarPort.cpp
	structures/StructureBase.cpp
	structures/TurretBase.cpp
	structures/WOR.cpp
	structures/Wall.cpp
	structures/WindTrap.cpp)

set(UNITS_SOURCES
	units/AirUnit.cpp
	units/Carryall.cpp
	units/Devastator.cpp
	units/Deviator.cpp
	units/Frigate.cpp
	units/GroundUnit.cpp
	units/Harvester.cpp
	units/InfantryBase.cpp
	units/Launcher.cpp
	units/MCV.cpp
	units/Ornithopter.cpp
	units/Quad.cpp
	units/RaiderTrike.cpp
	units/Saboteur.cpp
	units/SandWorm.cpp
	units/SiegeTank.cpp
	units/Soldier.cpp
	units/SonicTank.cpp
	units/Tank.cpp
	units/TankBase.cpp
	units/TrackedUnit.cpp
	units/Trike.cpp
	units/Trooper.cpp
	units/UnitBase.cpp)

set(VITA_SOURCES
	vita/VitaInput.cpp)

set(HEADERS
../include/AITeamInfo.h
../include/AStarSearch.h
../include/Bullet.h
../include/Choam.h
../include/Colors.h
../include/Command.h
../include/CommandManager.h
../include/config.h
../include/CutScenes/CrossBlendVideoEvent.h
../include/CutScenes/CutScene.h
../include/CutScenes/CutSceneMusicTrigger.h
../include/CutScenes/CutSceneSoundTrigger.h
../include/CutScenes/CutSceneTrigger.h
../include/CutScenes/FadeInVideoEvent.h
../include/CutScenes/FadeOutVideoEvent.h
../include/CutScenes/Finale.h
../include/CutScenes/HoldPictureVideoEvent.h
../include/CutScenes/Intro.h
../include/CutScenes/Meanwhile.h
../include/CutScenes/Scene.h
../include/CutScenes/TextEvent.h
../include/CutScenes/VideoEvent.h
../include/CutScenes/WSAVideoEvent.h
../include/data.h
../include/DataTypes.h
../include/Definitions.h
../include/Explosion.h
../include/FileClasses/adl/opl.h
../include/FileClasses/adl/sound_adlib.h
../include/FileClasses/adl/surroundopl.h
../include/FileClasses/adl/wemuopl.h
../include/FileClasses/adl/woodyopl.h
../include/FileClasses/Animation.h
../include/FileClasses/Cpsfile.h
../include/FileClasses/Decode.h
../include/FileClasses/FileManager.h
../include/FileClasses/Font.h
../include/FileClasses/FontManager.h
../include/FileClasses/GFXManager.h
../include/FileClasses/Icnfile.h
../include/FileClasses/IndexedTextFile.h
../include/FileClasses/INIFile.h
../include/FileClasses/LoadSavePNG.h
../include/FileClasses/lodepng.h
../include/FileClasses/MentatTextFile.h
../include/FileClasses/music/ADLPlayer.h
../include/FileClasses/music/DirectoryPlayer.h
../include/FileClasses/music/MusicPlayer.h
../include/FileClasses/music/XMIPlayer.h
../include/FileClasses/Pakfile.h
../include/FileClasses/Palette.h
../include/FileClasses/Palfile.h
../include/FileClasses/PictureFactory.h
../include/FileClasses/POFile.h
../include/FileClasses/SFXManager.h
../include/FileClasses/Shpfile.h
../include/FileClasses/TextManager.h
../include/FileClasses/TTFFont.h
../include/FileClasses/Vocfile.h
../include/FileClasses/Wsafile.h
../include/FileClasses/xmidi/databuf.h
../include/FileClasses/xmidi/xmidi.h
../include/fixmath/fix16.h
../include/fixmath/fix16_trig_sin_lut.h
../include/fixmath/fix32.h
../include/fixmath/fixmath.h
../include/fixmath/FixPoint.h
../include/fixmath/FixPoint16.h
../include/fixmath/FixPoint32.h
../include/fixmath/int64.h
../include/Game.h
../include/GameInitSettings.h
../include/GameInterface.h
../include/globals.h
../include/GUI/Button.h
../include/GUI/Checkbox.h
../include/GUI/ClickMap.h
../include/GUI/Container.h
../include/GUI/DropDownBox.h
../include/GUI/dune/AnimationLabel.h
../include/GUI/dune/BuilderList.h
../include/GUI/dune/ChatManager.h
../include/GUI/dune/DigitsCounter.h
../include/GUI/dune/DigitsTextBox.h
../include/GUI/dune/DuneStyle.h
../include/GUI/dune/GameOptionsWindow.h
../include/GUI/dune/InGameMenu.h
../include/GUI/dune/InGameSettingsMenu.h
../include/GUI/dune/LoadSaveWindow.h
../include/GUI/dune/MessageTicker.h
../include/GUI/dune/NewsTicker.h
../include/GUI/dune/WaitingForOtherPlayers.h
../include/GUI/GUIStyle.h
../include/GUI/HBox.h
../include/GUI/InvisibleButton.h
../include/GUI/Label.h
../include/GUI/ListBox.h
../include/GUI/MsgBox.h
../include/GUI/ObjectInterfaces/BuilderInterface.h
../include/GUI/ObjectInterfaces/DefaultObjectInterface.h
../include/GUI/ObjectInterfaces/DefaultStructureInterface.h
../include/GUI/ObjectInterfaces/MultiUnitInterface.h
../include/GUI/ObjectInterfaces/ObjectInterface.h
../include/GUI/ObjectInterfaces/PalaceInterface.h
../include/GUI/ObjectInterfaces/RadarInterface.h
../include/GUI/ObjectInterfaces/RefineryAndSiloInterface.h
../include/GUI/ObjectInterfaces/RepairYardInterface.h
../include/GUI/ObjectInterfaces/UnitInterface.h
../include/GUI/ObjectInterfaces/WindTrapInterface.h
../include/GUI/PictureButton.h
../include/GUI/PictureLabel.h
../include/GUI/ProgressBar.h
../include/GUI/QstBox.h
../include/GUI/RadioButton.h
../include/GUI/RadioButtonManager.h
../include/GUI/ScrollBar.h
../include/GUI/Spacer.h
../include/GUI/StaticContainer.h
../include/GUI/SymbolButton.h
../include/GUI/TextBox.h
../include/GUI/TextButton.h
../include/GUI/TextView.h
../include/GUI/VBox.h
../include/GUI/Widget.h
../include/GUI/Window.h
../include/House.h
../include/INIMap/INIMap.h
../include/INIMap/INIMapEditorLoader.h
../include/INIMap/INIMapLoader.h
../include/INIMap/INIMapPreviewCreator.h
../include/Map.h
../include/MapEditor/ChoamWindow.h
../include/MapEditor/LoadMapWindow.h
../include/MapEditor/MapData.h
../include/MapEditor/MapEditor.h
../include/MapEditor/MapEditorInterface.h
../include/MapEditor/MapEditorOperation.h
../include/MapEditor/MapEditorRadarView.h
../include/MapEditor/MapGenerator.h
../include/MapEditor/MapInfo.h
../include/MapEditor/MapMirror.h
../include/MapEditor/MapSettingsWindow.h
../include/MapEditor/NewMapWindow.h
../include/MapEditor/PlayerSettingsWindow.h
../include/MapEditor/ReinforcementInfo.h
../include/MapEditor/ReinforcementsWindow.h
../include/MapEditor/TeamsWindow.h
../include/MapSeed.h
../include/Menu/AboutMenu.h
../include/Menu/BriefingMenu.h
../include/Menu/CampaignStatsMenu.h
../include/Menu/CustomGameMenu.h
../include/Menu/CustomGamePlayers.h
../include/Menu/CustomGameStatsMenu.h
../include/Menu/HouseChoiceInfoMenu.h
../include/Menu/HouseChoiceMenu.h
../include/Menu/MainMenu.h
../include/Menu/MapChoice.h
../include/Menu/MentatHelp.h
../include/Menu/MentatMenu.h
../include/Menu/MenuBase.h
../include/Menu/MultiPlayerMenu.h
../include/Menu/OptionsMenu.h
../include/Menu/SinglePlayerMenu.h
../include/Menu/SinglePlayerSkirmishMenu.h
../include/misc/BlendBlitter.h
../include/misc/DrawingRectHelper.h
../include/misc/draw_util.h
../include/misc/exceptions.h
../include/misc/FileSystem.h
../include/misc/fnkdat.h
../include/misc/IFileStream.h
../include/misc/IMemoryStream.h
../include/misc/InputStream.h
../include/misc/md5.h
../include/misc/OFileStream.h
../include/misc/OMemoryStream.h
../include/misc/OutputStream.h
../include/misc/Random.h
../include/misc/RobustList.h
../include/misc/Scaler.h
../include/misc/SDL2pp.h
../include/misc/sound_util.h
../include/misc/string_util.h
../include/misc/unique_or_nonowning_ptr.h
../include/mmath.h
../include/Network/ChangeEventList.h
../include/Network/CommandList.h
../include/Network/ENetHelper.h
../include/Network/ENetHttp.h
../include/Network/ENetPacketIStream.h
../include/Network/ENetPacketOStream.h
../include/Network/GameServerInfo.h
../include/Network/LANGameFinderAndAnnouncer.h
../include/Network/MetaServerClient.h
../include/Network/MetaServerCommands.h
../include/Network/NetworkManager.h
../include/ObjectBase.h
../include/ObjectData.h
../include/ObjectManager.h
../include/ObjectPointer.h
../include/players/AIPlayer.h
../include/players/CampaignAIPlayer.h
../include/players/HumanPlayer.h
../include/players/Player.h
../include/players/PlayerFactory.h
../include/players/QuantBot.h
../include/players/SmartBot.h
../include/RadarView.h
../include/RadarViewBase.h
../include/sand.h
../include/ScreenBorder.h
../include/SoundPlayer.h
../include/structures/Barracks.h
../include/structures/BuilderBase.h
../include/structures/ConstructionYard.h
../include/structures/GunTurret.h
../include/structures/HeavyFactory.h
../include/structures/HighTechFactory.h
../include/structures/IX.h
../include/structures/LightFactory.h
../include/structures/Palace.h
../include/structures/Radar.h
../include/structures/Refinery.h
../include/structures/RepairYard.h
../include/structures/RocketTurret.h
../include/structures/Silo.h
../include/structures/StarPort.h
../include/structures/StructureBase.h
../include/structures/TurretBase.h
../include/structures/Wall.h
../include/structures/WindTrap.h
../include/structures/WOR.h
../include/Tile.h
../include/Trigger/ReinforcementTrigger.h
../include/Trigger/TimeoutTrigger.h
../include/Trigger/Trigger.h
../include/Trigger/TriggerManager.h
../include/units/AirUnit.h
../include/units/Carryall.h
../include/units/Devastator.h
../include/units/Deviator.h
../include/units/Frigate.h
../include/units/GroundUnit.h
../include/units/Harvester.h
../include/units/InfantryBase.h
../include/units/Launcher.h
../include/units/MCV.h
../include/units/Ornithopter.h
../include/units/Quad.h
../include/units/RaiderTrike.h
../include/units/Saboteur.h
../include/units/SandWorm.h
../include/units/SiegeTank.h
../include/units/Soldier.h
../include/units/SonicTank.h
../include/units/Tank.h
../include/units/TankBase.h
../include/units/TrackedUnit.h
../include/units/Trike.h
../include/units/Trooper.h
../include/units/UnitBase.h
../include/enet/callbacks.h
../include/enet/enet.h
../include/enet/enettime.h
../include/enet/list.h
../include/enet/protocol.h
../include/enet/types.h
../include/enet/unix.h
../include/enet/utility.h
../include/enet/win32.h
../include/vita/VitaInput.h)

set(EXE_SOURCES main.cpp)

set(SOURCES
	${TOP_SOURCES}
	${CUT_SCENES_SOURCES}
	${FILE_CLASSES_SOURCES}
	${GUI_SOURCES}
	${INIMAP_SOURCES}
	${MAP_EDITOR_SOURCES}
	${MENU_SOURCES}
	${NETWORK_SOURCES}
	${TRIGGER_SOURCES}
	${FIX_MATH_SOURCES}
	${MISC_SOURCES}
	${ENET_SOURCES}
	${PLAYERS_SOURCES}
	${STRUCTURES_SOURCES}
	${RENDERER_SOURCES}
	${UNITS_SOURCES}
	${VITA_SOURCES})

find_package(SDL2 REQUIRED)
#find_package(sdl2-mixer REQUIRED)
#find_package(sdl2-ttf REQUIRED)

set(LIBS
	SDL2
	SDL2_mixer
	SDL2_ttf
)

add_library(dune ${SOURCES} ${HEADERS})
target_include_directories(dune PUBLIC ../include PRIVATE)

if(VITA)
	target_link_libraries (dune PUBLIC
		SDL2_mixer
		SDL2_ttf
		SDL2::SDL2
		opusfile
		opus
		xmp
		freetype
		bz2
		png
		FLAC
		mikmod
		modplug
		mpg123
		vorbisfile
		vorbis
		ogg
		pthread
		z
	)
else()
	target_link_libraries(dune PUBLIC ${LIBS})
endif()

add_executable(dunelegacy ${EXE_SOURCES} ../include/main.h)
target_link_libraries(dunelegacy PRIVATE dune)
