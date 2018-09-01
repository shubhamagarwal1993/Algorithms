#### GPU
  - Has 2 more key components within it
    - VRAM
    - processor
  - This piece of hardware renders the actual image on screen. What is seen by you is computed by the GPU
  - All shading and ripple effects are calculated on the PhysX chip, which is usually integrated on to the graphics card, but older systems have a dedicated PhysX card
  - Only the looks are calculated on the GPU. All the actual logic happens on the CPU

#### CPU
  - handles game logic
    - It calculates how much damage is dealt, what happens when you walk in to the tall grass, etc
  - co-ordinates with the BIOS (Basic Input/Output System) to compute and process your commands like mouse clicks and key presses

#### VRAM/Graphics memory
  - The graphics memory holds graphical information like the terrain around you
  - The bandwidth of this memory is awesome, several times better than system memory. This dedicated memory is only used by the GPU. When the memory is full and the GPU needs to store more, it sends it to the system RAM, which is slower. This is why running out of VRAM causes lag and other undesirable effects

#### RAM/Memory
  - The system RAM holds data on the logic computed by the CPU
  - This is the other player’s location, the amount of money in your in-game account, how much ammunition you have left, etc
  - Large games with tons of carnage (Star Wars Battlefront) have huge RAM requirements to store all that data
  - If you run out of RAM, the CPU sends it to the hard disk (e.g. your Solid State Drive or your hard disk drive). The hard disk is massively slower than the memory cells in RAM sticks, so running out of RAM will drastically reduce performance
