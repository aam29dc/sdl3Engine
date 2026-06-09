```
include
├── core
│   ├── camera.hpp
│   ├── context
│   │   ├── command.hpp
│   │   ├── frame.hpp
│   │   ├── render.hpp
│   │   ├── resource.hpp
│   │   ├── update.hpp
│   │   └── world.hpp
│   ├── engine.hpp
│   ├── handles.hpp
│   ├── renderer.hpp
│   ├── time.hpp
│   ├── types.hpp
│   └── window.hpp
├── input
│   ├── binds.hpp
│   ├── commands.hpp
│   ├── console.hpp
│   ├── inputbuffer.hpp
│   ├── input.hpp
│   └── inputrouter.hpp
├── render
│   ├── rect.hpp
│   ├── renderable.hpp
│   ├── rendersystem.hpp
│   └── sprite.hpp
├── resources
│   ├── fontmanager.hpp
│   └── texturemanager.hpp
├── states
│   ├── gameState.hpp
│   └── playState.hpp
├── ui
│   ├── colors.hpp
│   ├── content
│   │   ├── content.hpp
│   │   ├── image.hpp
│   │   └── text.hpp
│   ├── dirty.hpp
│   ├── elements
│   │   ├── button.hpp
│   │   ├── container.hpp
│   │   └── element.hpp
│   ├── eventsink.hpp
│   ├── hud.hpp
│   ├── layout.hpp
│   ├── menu
│   │   ├── id.hpp
│   │   ├── mainMenu.hpp
│   │   ├── menu.hpp
│   │   └── playMenu.hpp
│   ├── style
│   │   ├── solid.hpp
│   │   ├── style.hpp
│   │   └── textured.hpp
│   └── ui.hpp
└── world
    ├── entity.hpp
    └── entitymanager.hpp
src
├── core
│   ├── camera.cpp
│   ├── engine.cpp
│   ├── renderer.cpp
│   ├── time.cpp
│   └── window.cpp
├── input
│   ├── binds.cpp
│   ├── commands.cpp
│   ├── console.cpp
│   ├── inputbuffer.cpp
│   ├── input.cpp
│   └── inputrouter.cpp
├── main.cpp
├── render
│   ├── rect.cpp
│   ├── rendersystem.cpp
│   └── sprite.cpp
├── resources
│   ├── fontmanager.cpp
│   └── texturemanager.cpp
├── states
│   └── playState.cpp
├── ui
│   ├── content
│   │   ├── image.cpp
│   │   └── text.cpp
│   ├── elements
│   │   ├── button.cpp
│   │   ├── container.cpp
│   │   └── element.cpp
│   ├── layout.cpp
│   ├── menu
│   │   ├── mainMenu.cpp
│   │   ├── menu.cpp
│   │   └── playMenu.cpp
│   ├── style
│   │   ├── solid.cpp
│   │   └── textured.cpp
│   └── ui.cpp
└── world
    ├── entity.cpp
    └── entitymanager.cpp

25 directories, 80 files
```
