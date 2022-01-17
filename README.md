# Penguin Game in C

This project is a penguin game for first semester of University implemented in C using terminal graphics to display a board 

Compilation:
```shell
	git clone https://github.com/h4ppyr0gu3/c_test
	cd c_test
	make
```
Advanced compilation options:
```
	make rebuild    removes compiled binaries and object files and recompiles
	make clean      removes compiled binaries and object files
```
Usage:
    `./penguins [options]`

Options:
```
-d, --default                default game parameters:
                             x=10, y=10, penguins=3, players=2
-t, --test                   test game parameters:
                             x=3, y=3, penguins=1, players=2
-h, --help                   print help and exit
-x <integer>                 set number of columns
-y <integer>                 set number of rows
--player-count <integer>     set player count (< 6)
--penguin-count <integer>    set penguins per player
name                         prints name of group
```
Auto Options:
```
phase=movement <input_file> <output_file>
phase=placement penguins=<integer> <input_file> <output_file>
```

How to Play:
- After the game parameters have been set (by command line arguments or in dialogue) each player is asked to choose an avatar
- The Players then place there penguin (avatar) on a location with 1 fish (integers)
- After all penguins have been placed the movement phase starts
- The player selects a location with their penguin and a destination which has either 1, 2 or 3 on the board, 
`**Note**: this location has to be in either the same column or same row and cannot be impeded by ice (x), the distance you can move is only limited by board size`
- The score is the summation of the fish collected by the penguin on its destination 

Game Play Examples:


![select_avatar](https://github.com/h4ppyr0gu3/c_test/blob/master/select_avatar.png?raw=true)
- Here you can see the avatar selection screen   
![place_penguin](https://github.com/h4ppyr0gu3/c_test/blob/master/place_penguin.png?raw=true)
- This is the placing of penguins phase   
![ask_for_penguin_selection](https://github.com/h4ppyr0gu3/c_test/blob/master/ask_for_penguin_selection.png?raw=true)
- Movement phase with penguin selection   
![informative_error](https://github.com/h4ppyr0gu3/c_test/blob/master/informative_error.png?raw=true)
- Informative error messages in game   
![select_source_and_destination](https://github.com/h4ppyr0gu3/c_test/blob/master/select_source_and_destination.png?raw=true)
- Inputing the coordinates of the source and destination results in penguin movement   
![after_eating_fish_ice_remains](https://github.com/h4ppyr0gu3/c_test/blob/master/after_eating_fish_ice_remains.png?raw=true)
- After penguin has moved the source is changed to ice   
