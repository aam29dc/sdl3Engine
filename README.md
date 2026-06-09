```
include
├── core
│   ├── camera.hpp
│   ├── commands.hpp
│   ├── console.hpp
│   ├── context
│   │   ├── command.hpp
│   │   ├── frame.hpp
│   │   ├── render.hpp
│   │   ├── resource.hpp
│   │   ├── update.hpp
│   │   └── world.hpp
│   ├── engine.hpp
│   ├── handles.hpp
│   ├── inputbuffer.hpp
│   ├── input.hpp
│   ├── inputrouter.hpp
│   ├── renderer.hpp
│   ├── time.hpp
│   ├── types.hpp
│   └── window.hpp
├── managers
│   ├── binds.hpp
│   ├── entity.hpp
│   ├── font.hpp
│   └── texture.hpp
├── objects
│   └── entity.hpp
├── render
│   ├── rect.hpp
│   ├── renderable.hpp
│   ├── sprite.hpp
│   └── system.hpp
├── states
│   ├── gameState.hpp
│   └── playState.hpp
└── ui
    ├── colors.hpp
    ├── content
    │   ├── content.hpp
    │   ├── image.hpp
    │   └── text.hpp
    ├── dirty.hpp
    ├── elements
    │   ├── button.hpp
    │   ├── container.hpp
    │   └── element.hpp
    ├── eventsink.hpp
    ├── hud.hpp
    ├── layout.hpp
    ├── menu
    │   ├── id.hpp
    │   ├── mainMenu.hpp
    │   ├── menu.hpp
    │   └── playMenu.hpp
    ├── style
    │   ├── solid.hpp
    │   ├── style.hpp
    │   └── textured.hpp
    └── ui.hpp
src
├── core
│   ├── camera.cpp
│   ├── commands.cpp
│   ├── console.cpp
│   ├── engine.cpp
│   ├── inputbuffer.cpp
│   ├── input.cpp
│   ├── inputrouter.cpp
│   ├── renderer.cpp
│   ├── time.cpp
│   └── window.cpp
├── main.cpp
├── managers
│   ├── binds.cpp
│   ├── entity.cpp
│   ├── font.cpp
│   └── texture.cpp
├── objects
│   └── entity.cpp
├── render
│   ├── rect.cpp
│   ├── sprite.cpp
│   └── system.cpp
├── states
│   └── playState.cpp
└── ui
    ├── content
    │   ├── image.cpp
    │   └── text.cpp
    ├── elements
    │   ├── button.cpp
    │   ├── container.cpp
    │   └── element.cpp
    ├── layout.cpp
    ├── menu
    │   ├── mainMenu.cpp
    │   ├── menu.cpp
    │   └── playMenu.cpp
    ├── style
    │   ├── solid.cpp
    │   └── textured.cpp
    └── ui.cpp

23 directories, 80 files
```
