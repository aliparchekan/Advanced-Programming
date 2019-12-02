UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Darwin)
		HEAD := \"sdlheaders/mac.hpp\"
  	CCFLAGS= -framework SDL2_mixer
else
		HEAD := \"sdlheaders/linux.hpp\"
		CCFLAGS += -l SDL2_mixer
endif

all:a.out

a.out:gerdabify_element.o gerdabPlayer.o queue.o user.o artist.o Database.o  music.o album.o playlist.o  places.o home.o library.o playlists.o album_place.o exceptions.o artist_place.o music_place.o playlist_place.o normal.o editor.o admin.o web++.o gerdabServer.o home_page_handler.o signup_handler.o login_handler.o search_handler.o music_page_handler.o album_page_handler.o artist_page_handler.o playlist_page_handler.o playlist_create_page.o main.o queue_place.o
	g++ gerdabify_element.o gerdabPlayer.o queue.o user.o artist.o Database.o music.o album.o playlist.o  places.o home.o library.o playlists.o album_place.o exceptions.o artist_place.o music_place.o playlist_place.o normal.o editor.o admin.o web++.o gerdabServer.o home_page_handler.o signup_handler.o login_handler.o search_handler.o music_page_handler.o album_page_handler.o artist_page_handler.o playlist_page_handler.o playlist_create_page.o main.o queue_place.o $(CCFLAGS)

gerdabify_element.o:gerdabify_element.hpp gerdabify_element.cpp user.hpp user.cpp
	g++ -c gerdabify_element.cpp $(CCFLAGS)
user.o:user.cpp user.hpp places.hpp places.cpp Database.hpp Database.cpp music.hpp music.cpp home.hpp home.cpp library.hpp library.cpp playlists.hpp playlists.cpp playlist.hpp playlist.cpp artist_place.hpp artist_place.cpp music_place.hpp music_place.cpp album_place.hpp album_place.cpp playlist_place.hpp playlist_place.cpp
	g++ -c user.cpp $(CCFLAGS)
Database.o:Database.cpp Database.hpp user.cpp user.hpp album.cpp album.hpp music.cpp music.hpp playlist.hpp playlist.cpp artist.cpp artist.hpp editor.hpp editor.cpp admin.hpp admin.cpp normal.hpp normal.cpp
	g++ -c Database.cpp $(CCFLAGS)
artist.o:gerdabify_element.hpp gerdabify_element.cpp user.hpp user.cpp artist.cpp artist.hpp album.cpp album.hpp music.cpp music.hpp
	g++ -c artist.cpp $(CCFLAGS)
music.o:gerdabify_element.hpp gerdabify_element.cpp artist.hpp artist.cpp album.cpp album.hpp music.hpp music.cpp
	g++ -c music.cpp $(CCFLAGS)
album.o:gerdabify_element.hpp gerdabify_element.cpp artist.cpp artist.hpp music.cpp music.hpp album.hpp album.cpp
	g++ -c album.cpp $(CCFLAGS)
playlist.o:gerdabify_element.hpp gerdabify_element.cpp music.hpp music.cpp playlist.hpp playlist.cpp
	g++ -c playlist.cpp $(CCFLAGS)
places.o:places.cpp places.hpp user.hpp user.cpp
	g++ -c places.cpp $(CCFLAGS)
home.o:home.cpp home.hpp places.cpp places.hpp user.hpp user.cpp
	g++ -c home.cpp $(CCFLAGS)
library.o:library.cpp library.hpp places.hpp places.cpp user.hpp user.cpp
	g++ -c library.cpp $(CCFLAGS)
playlists.o:playlists.hpp playlists.cpp places.hpp places.cpp user.hpp user.cpp playlist.cpp playlist.hpp
	g++ -c playlists.cpp $(CCFLAGS)
album_place.o:album_place.cpp album_place.hpp places.cpp places.hpp album.cpp album.hpp user.cpp user.hpp music.hpp music.cpp
	g++ -c album_place.cpp $(CCFLAGS)
exceptions.o:exceptions.hpp
	g++ -c exceptions.cpp $(CCFLAGS)
artist_place.o:artist_place.cpp artist_place.hpp places.cpp places.hpp artist.cpp artist.hpp user.cpp user.hpp Database.cpp Database.hpp
	g++ -c artist_place.cpp $(CCFLAGS)
music_place.o:music_place.cpp music_place.hpp music.cpp music.hpp places.hpp places.cpp user.cpp user.hpp
	g++ -c music_place.cpp $(CCFLAGS)
playlist_place.o:playlist_place.cpp playlist_place.hpp places.cpp places.hpp user.hpp user.cpp playlist.hpp playlist.cpp
	g++ -c playlist_place.cpp $(CCFLAGS)
normal.o:normal.cpp normal.hpp user.cpp user.hpp Database.cpp Database.hpp
	g++ -c normal.cpp $(CCFLAGS)
editor.o:editor.cpp editor.hpp user.cpp user.hpp Database.cpp Database.hpp
	g++ -c editor.cpp $(CCFLAGS)
admin.o:admin.cpp admin.hpp user.cpp user.hpp Database.cpp Database.hpp
	g++ -c admin.cpp $(CCFLAGS)
queue.o:queue.cpp queue.hpp playlist.cpp playlist.hpp user.cpp user.hpp music.cpp music.hpp
	g++ -std=c++11 -c queue.cpp $(CCFLAGS)
queue_place.o:queue_place.cpp queue_place.hpp places.hpp places.cpp
	g++ -c queue_place.cpp $(CCFLAGS)
gerdabServer.o:gerdabServer.cpp gerdabServer.hpp web++.cpp web++.hpp
	g++ -std=c++11 -c gerdabServer.cpp
web++.o: web++.cpp web++.hpp
	g++ -std=c++11 -c web++.cpp
home_page_handler.o: home_page_handler.cpp home_page_handler.hpp gerdabServer.cpp gerdabServer.hpp
	g++ -std=c++11 -c home_page_handler.cpp
signup_handler.o: signup_handler.cpp signup_handler.hpp gerdabServer.cpp gerdabServer.hpp
	g++ -std=c++11 -c signup_handler.cpp
login_handler.o: login_handler.cpp login_handler.hpp gerdabServer.cpp gerdabServer.hpp
	g++ -std=c++11 -c login_handler.cpp
search_handler.o: search_handler.cpp search_handler.hpp gerdabServer.cpp gerdabServer.hpp
	g++ -std=c++11 -c search_handler.cpp
music_page_handler.o: music_page_handler.cpp music_page_handler.hpp gerdabServer.hpp 
	g++ -std=c++11 -c music_page_handler.cpp
album_page_handler.o: album_page_handler.cpp album_page_handler.hpp gerdabServer.hpp
	g++ -std=c++11 -c album_page_handler.cpp	
artist_page_handler.o: artist_page_handler.cpp artist_page_handler.hpp gerdabServer.hpp
	g++ -std=c++11 -c artist_page_handler.cpp
playlist_page_handler.o:playlist_page_handler.cpp playlist_page_handler.hpp gerdabServer.o
	g++ -std=c++11 -c playlist_page_handler.cpp 
playlist_create_page.o: playlist_create_page.hpp playlist_create_page.cpp gerdabServer.o
	g++ -std=c++11 -c playlist_create_page.cpp

main.o:main.cpp main.hpp
	g++ -c main.cpp $(CCFLAGS)
gerdabPlayer.o:gerdabPlayer.cpp gerdabPlayer.hpp
	g++ -std=c++11 -c gerdabPlayer.cpp $(CCFLAGS)


clean:
	rm *.o
	rm *.out