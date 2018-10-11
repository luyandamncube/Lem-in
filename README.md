# wethinkcode_ Johannesburg

![wethinkcode_ logo](resources/wtc.gif)

## Lem-in

![final mark](resources/Lem-in-finalmark.png)

Lem-in Project

based on the this traversal method: `https://www.geeksforgeeks.org/iterative-depth-first-traversal/`

- This project is about analyzing a unique input with a variable number of ants and helps the colony navigate from the start of a maze to the end. 
- The solver is multi-pathed, iterative, and weighted for distance. 
- It doesn't forget about avoiding traffic jams as well as walking all over their fellow ants

## Ant farm rules
- all ants start in `##start room`,
- lines starting with `##` are commands modifying the line that comes right after,
- `##start` signals the ant farm’s entrance and `##end` its exit,
- `#` means comment till the end of the line,
- all unknown commands are ignored,
- non compliant or empty lines will stop the ant farm’s reading,
- each room can contain only one ant at a time (excluding `##start` and `##end`).

### ./Lem-in commands
Maps are stored in `marking/`
- `make`  Compiles `./Lem-in` binary
- `./Lem-in < marking/map_name` Runs a selected map  
- `./Lem-in` Allows user to type map directly into stdin   

Concepts tested:
- Algorithms (Depth-First-Search)
- Data Structures (Stacks, Graphs)
