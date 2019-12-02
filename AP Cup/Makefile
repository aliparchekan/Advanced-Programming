all:a.out

a.out: Player.o Stadium.o Team.o Game.o Match.o Round.o Simulation.o Tournament.o main.o
	g++ main.o Tournament.o Simulation.o Round.o Match.o Game.o Team.o Player.o Stadium.o       
Player.o: Player.hpp Player.cpp
	g++ -c Player.cpp
Stadium.o: Stadium.hpp Stadium.cpp
	g++ -c Stadium.cpp
Team.o:Player.hpp Stadium.hpp Team.hpp Player.cpp Stadium.cpp Team.cpp
	g++ -c Team.cpp		
Game.o:Team.hpp Team.cpp Game.hpp Game.cpp
	g++ -c Game.cpp
Match.o:Game.hpp Game.cpp Match.cpp Match.hpp Team.hpp Team.cpp 
	g++ -c Match.cpp		
Round.o:Match.cpp Match.hpp Round.hpp Round.cpp
	g++ -c Round.cpp	
Simulation.o:Round.cpp Round.hpp Team.cpp Team.hpp
	g++ -c Simulation.cpp
Tournament.o:Simulation.cpp Simulation.hpp
	g++ -c Tournament.cpp	
main.o: Player.cpp Player.hpp Stadium.hpp Stadium.cpp Team.cpp Team.hpp Game.cpp Game.hpp Match.cpp Match.hpp Round.cpp Round.hpp Simulation.cpp Simulation.hpp Tournament.cpp Tournament.h main.cpp
	g++ -c main.cpp


clean:
	rm *.o
	rm *.out


