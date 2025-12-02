# ROCKET PROPELLED GAME

### A GAME PROPELLED BY ROCKETS

Featuring non-existent EPICNESS.  
Currently in development, so don't expect the game to actually work.

### Compiling the game

First, download the game.  
If you want to clone the repo, clone it.  
Then, follow the instructions for your OS.

#### Linux

1. Install GCC if you don't have it installed.  
  The complete instructions can be found here https://gcc.gnu.org/install/
2. Compile the game with the following command  
  `gcc -c newton.c -o newton.o && gcc -c ROCKETGAME.c -o ROCKETGAME.o && gcc newton.o ROCKETGAME.o -o ROCKETGAME -lm && rm newton.o ROCKETGAME.o`
3. Run the game with `./ROCKETGAME`

#### Windows

1. I really don't know what compliers there are for Windows, so find your own.
2. Compile the game with the compiler of your choice.
3. Run the game.
