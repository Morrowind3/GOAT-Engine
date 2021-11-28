# SpicH
## Information

- C++ version: 17
- Compiler: MinGW-w64

## Setup - *Clion*

### Build

- Build GOATEngine
- Build MountEverestimate
- Run MountEverestimate

### Coding guidelines

- [.h to .hpp](https://stackoverflow.com/questions/45389553/set-clion-to-use-hpp-header-rather-than-h-header-when-creating-a-new-c-clas)
- 1TBS (OTBS) intendation wherever possible
- camelCase method names wherever possible
- PascalCase class name wherever possible
- camelCase public attributes wherever possible
- \_camelCaseWithUnderscorePrefix protected/private attributes wherever possible
- Reference symbols are put before the attribute, as in: `Renderer& renderer -> Renderer &renderer`
  - settings -> Editor -> C/C++ -> Other:
  - turn on:
    - Before '*' in declarations
    - Before '&' in declarations
  - turn off:
    - After '*' in declarations
    - After '&' in declarations

## Git

- You cannot push to master, this is reserved for the final version of the engine.
- Use feature branches.
- When your branch is merged with development, delete the feature branch from GitHub.


## Engine - *library*

The GOATEngine is a library that forms a facade towards the following libraries:

- SDL2
- SDL2_Image
- SDL2_TTF
- SDL2_Mixer
- Box2D
- SQLite
- Tessil

## Game - *executable*

MountEverestimate is the game that uses the GOATEngine library as its engine.
