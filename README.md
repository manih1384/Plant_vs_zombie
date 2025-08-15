# 🌱 Plants vs. Zombies - SFML Edition

A C++ implementation of the classic tower defense game using SFML, developed for the Advanced Programming course at University of Tehran.

**Developed by:**
- [Mani Hosseini](https://github.com/manih1384)
- [Shayan Maleki](https://github.com/maleki-shayan)

## Features
- **Core Gameplay**:
  - 5 unique plant types (Peashooter, Snowpea, KernelPult, Sunflower, Walnut)
  - 2 zombie types (Regular, Gargantuan) with different behaviors
  - Sun resource collection system
  - Wave-based zombie attacks with increasing difficulty
  - Configurable game settings via external file

- **Technical Highlights**:
  - Event-driven architecture using SFML
  - Custom physics for projectile trajectories
  - Object-oriented design with inheritance
  - Dynamic game state management
  - Config file parsing for game balance

## Tech Stack
| Component       | Technologies               |
|-----------------|----------------------------|
| Core Framework  | C++20                      |
| Graphics/Audio  | SFML 2.5+                  |
| Build System    | Makefile                   |



##  Installation
### Prerequisites
- Linux environment
- SFML 2.5+ libraries
- GCC/G++ with C++20 support
- Make

### Build & Run
```sh
# Clone repository
git clone https://github.com/manih1384/plants-vs-zombies.git
cd plants-vs-zombies

# Build project
make

# Run game
./pvz.out
```

## Game Mechanics
### Plants
| Plant        | Cost | Damage | Special Ability          |
|--------------|------|--------|---------------------------|
| Peashooter   | 100  | 5      | Basic projectile          |
| Snowpea      | 150  | 8      | Slows zombies             |
| KernelPult   | 200  | 15     | Parabolic trajectory      |
| Sunflower    | 50   | 0      | Generates sun             |
| Walnut       | 50   | 0      | High health blocker       |

### Zombies
| Zombie       | Health | Damage | Speed |
|--------------|--------|--------|-------|
| Regular      | 50     | 5      | 7     |
| Gargantuan   | 80     | 6      | 5     |




## Course Context
Developed for Advanced Programming (Spring 2024) at University of Tehran under Professor Ramin Khosravi.
