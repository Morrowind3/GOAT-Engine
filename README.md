# SpicH
## Informatie

- C++ versie: 17
- Compiler: MinGW-w64

## Opzetten - *Clion*

### Builden

- Build GOATEngine
- Build MountEverestimate
- Run MountEverestimate

### Regels

- [.h naar .hpp](https://stackoverflow.com/questions/45389553/set-clion-to-use-hpp-header-rather-than-h-header-when-creating-a-new-c-clas)
- Brackets komen achter de methode, dus niet onder
- Referenties worden vóór het attribuut geplaatst. `Renderer& renderer -> Renderer &renderer`
  - settings -> Editor -> C/C++ -> Other:
  - aan:
    - Before '*' in declarations
    - Before '&' in declarations
  - uit:
    - After '*' in declarations
    - After '&' in declarations

## Werkmethodes

- Er kan niet gepushed worden op master.

- We werken met feature-branches.

- Wanneer jouw branch is gemerged in development, verwijder dan deze branch.


## Engine - *library*

De GOATEngine is een library die een facade vormt door het combineren van andere libraries:

- SDL2
- SDL2_Image
- SDL2_TTF
- SDL2_Mixer
- Box2D
- SQLite

## Game - *executable*

MountEverestimate is de game die gebruikmaakt van de GOATEngine als library.
