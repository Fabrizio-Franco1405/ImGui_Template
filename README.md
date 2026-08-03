# ImGui Template

<div align="center">
  <br>
  <h1>🖼️ ImGui Template</h1>
  <p><strong>Plantilla moderna y minimalista para crear aplicaciones con interfaz grafica en C++ usando Dear ImGui, OpenGL y GLFW.</strong></p>
  <p>
    <img src="https://img.shields.io/badge/C%2B%2B-23-00599C?style=flat&logo=c%2B%2B" alt="C++23">
    <img src="https://img.shields.io/badge/CMake-3.28+-064F8C?style=flat&logo=cmake" alt="CMake 3.28+">
    <img src="https://img.shields.io/badge/Dear%20ImGui-1.91+-e34f26?style=flat" alt="Dear ImGui 1.91+">
    <img src="https://img.shields.io/badge/OpenGL-3.0+-5586A4?style=flat&logo=opengl" alt="OpenGL 3.0+">
    <img src="https://img.shields.io/badge/GLFW-3.4+-DF1642?style=flat" alt="GLFW 3.4+">
    <img src="https://img.shields.io/badge/license-MIT-blue?style=flat" alt="License MIT">
  </p>
  <br>
</div>

---

## Indice

- [Descripcion](#descripcion)
- [Requisitos del sistema](#requisitos-del-sistema)
- [Estructura del proyecto](#estructura-del-proyecto)
- [Guia de instalacion](#guia-de-instalacion)
  - [1. Instalar vcpkg](#1-instalar-vcpkg)
  - [2. Instalar Visual Studio 2026](#2-instalar-visual-studio-2026)
  - [3. Clonar el repositorio](#3-clonar-el-repositorio)
  - [4. Configurar CMakePresets.json](#4-configurar-cmakepresetsjson)
  - [5. Generar el proyecto](#5-generar-el-proyecto)
  - [6. Compilar y ejecutar](#6-compilar-y-ejecutar)
- [Personalizacion](#personalizacion)
- [Licencia](#licencia)

---

## Descripcion

Esta plantilla te permite **empezar a programar tu interfaz grafica en cuestion de segundos** sin perder tiempo configurando _build systems_, dependencias o _backends_ de renderizado. Incluye:

- **Dear ImGui** con los _backends_ `glfw-binding` y `opengl3-binding` activados.
- **GLFW 3.4+** para la creacion de ventanas y captura de eventos (teclado, raton, _gamepad_).
- **OpenGL 3.0+** como _backend_ de renderizado.
- **CMake 3.28** con un _preset_ listo para **Visual Studio 2026 + Ninja**.
- **vcpkg** como gestor de dependencias (_manifest mode_).
- **Estilo oscuro por defecto** (`StyleColorsDark`), listo para cambiar a claro o personalizar.
- **Compilacion con C++23**.
- **Licencia MIT** (ver `LICENSE`).

Todo esta integrado y funcionando: abres el archivo, compilas y ya tienes una ventana con Dear ImGui renderizando.

---

## Requisitos del sistema

| Herramienta               | Version minima | Descripcion                                       |
| ------------------------- | -------------- | ------------------------------------------------- |
| **Windows**               | 10 / 11        | Sistema operativo soportado                       |
| **Visual Studio 2026**    | 17.0+          | Compilador MSVC y herramientas de CMake           |
| **CMake**                 | 3.28           | Generador del _build system_                      |
| **vcpkg**                 | _ultimo_       | Gestor de dependencias en C++                     |
| **Git**                   | 2.30+          | Control de versiones y clonado del repositorio    |

> **Nota:** En Linux/macOS solo necesitas `g++`/`clang++`, `CMake` y `vcpkg`. Los pasos son identicos cambiando el compilador en `CMakePresets.json`.

---

## Estructura del proyecto

```
Imgui_Template/
├── .gitignore                  # Archivos que Git debe ignorar
├── CMakeLists.txt              # Configuracion del build con CMake
├── CMakePresets.json           # Presets de compilacion (MSVC + Ninja)
├── main.cpp                    # Punto de entrada con el loop de Dear ImGui
├── vcpkg.json                  # Dependencias gestionadas por vcpkg
├── vcpkg-configuration.json    # Configuracion del registro de vcpkg
├── out/                        # Directorio de salida de la compilacion (ignorado)
│   └── build/
└── .vs/                        # Archivos internos de Visual Studio (ignorado)
```

### Descripcion de archivos clave

| Archivo                       | Proposito                                                             |
| ----------------------------- | --------------------------------------------------------------------- |
| `CMakeLists.txt`              | Declara el proyecto, busca las dependencias y enlaza el ejecutable.   |
| `CMakePresets.json`           | Predefine la configuracion de CMake para compilar con MSVC + Ninja.   |
| `main.cpp`                    | Contiene el bucle principal de la aplicacion con ImGui + GLFW + OpenGL. |
| `vcpkg.json`                  | Lista las dependencias (_glfw3_, _opengl_, _imgui_ con sus _features_). |
| `vcpkg-configuration.json`    | Apunta al registro oficial de vcpkg en GitHub.                        |

---

## Guia de instalacion

### 1. Instalar vcpkg

Abre una **PowerShell** (o _Command Prompt_) y ejecuta:

```powershell
git clone https://github.com/microsoft/vcpkg.git C:\vcpkg
C:\vcpkg\bootstrap-vcpkg.bat
```

Agrega `C:\vcpkg` a tu `PATH` de usuario (o de sistema) para poder invocar `vcpkg` desde cualquier terminal:

```powershell
[System.Environment]::SetEnvironmentVariable("Path", $env:Path + ";C:\vcpkg", "User")
```

Verifica que quedo instalado correctamente:

```powershell
vcpkg --version
```

> **Importante:** Anota la ruta completa donde clonaste vcpkg (ej. `C:/vcpkg`). La necesitaras en el paso 4.

---

### 2. Instalar Visual Studio 2026

Descarga e instala [Visual Studio 2026 Community](https://visualstudio.microsoft.com/vs/community/) (gratuito).

Durante la instalacion asegurate de incluir:

- **Desarrollo de escritorio con C++** (incluye el compilador MSVC, CMake y Ninja).
- **SDK de Windows 10/11**.

Para verificar que CMake y Ninja estan disponibles:

```powershell
cmake --version
ninja --version
```

Si no aparecen, abre el _Developer Command Prompt for VS 2022_ o ejecuta:

```powershell
& "C:\Program Files\Microsoft Visual Studio\2026\Community\Common7\Tools\Launch-VsDevShell.ps1"
```

---

### 3. Clonar el repositorio

```powershell
git clone https://github.com/tu-usuario/Imgui_Template.git
cd Imgui_Template
```

> Reemplaza la URL por la de tu repositorio real.

---

### 4. Configurar CMakePresets.json

Abre el archivo `CMakePresets.json` y ajusta la ruta de `CMAKE_TOOLCHAIN_FILE` a la ruta donde instalaste vcpkg:

```json
{
  "version": 3,
  "configurePresets": [
    {
      "name": "vcpkg-x64-debug",
      "displayName": "x64 Debug con vcpkg",
      "generator": "Ninja",
      "binaryDir": "${sourceDir}/out/build/${presetName}",
      "architecture": {
        "value": "x64",
        "strategy": "external"
      },
      "cacheVariables": {
        "CMAKE_BUILD_TYPE": "Debug",
        "CMAKE_C_COMPILER": "cl.exe",
        "CMAKE_CXX_COMPILER": "cl.exe",
        "CMAKE_TOOLCHAIN_FILE": "C:/vcpkg/scripts/buildsystems/vcpkg.cmake"
      }
    }
  ]
}
```

> **Importante:** Usa barras normales `/` o dobles barras invertidas `\\` en la ruta. Las barras simples invertidas `\` causaran errores en JSON.

---

### 5. Generar el proyecto

Estando en la raiz del repositorio, ejecuta:

```powershell
cmake --preset vcpkg-x64-debug
```

Este comando hara lo siguiente:

1. **Ejecuta vcpkg en modo manifest** — lee `vcpkg.json` y descarga/compila automaticamente:
   - `glfw3` (ventanas y _input_).
   - `opengl` (_bindings_ de OpenGL).
   - `imgui` con las _features_ `glfw-binding` y `opengl3-binding` (los _backends_ necesarios para conectar ImGui con GLFW y OpenGL).
2. **Genera los archivos Ninja** dentro de `out/build/vcpkg-x64-debug/`.
3. **Descarga las dependencias una sola vez** — en proximas ejecuciones vcpkg reusara lo que ya tiene en su carpeta `packages`.

Si todo sale bien veras un mensaje como:

```
Preset CMake variables:
  CMAKE_BUILD_TYPE:STRING=Debug
  CMAKE_C_COMPILER:FILEPATH=cl.exe
  CMAKE_CXX_COMPILER:FILEPATH=cl.exe
  CMAKE_TOOLCHAIN_FILE:FILEPATH=C:/vcpkg/scripts/buildsystems/vcpkg.cmake
Configuring done (X.Xs)
```

---

### 6. Compilar y ejecutar

Una vez configurado el proyecto, compilalo con:

```powershell
cmake --build out/build/vcpkg-x64-debug
```

Esto invocara **Ninja** (que viene con Visual Studio) para compilar `main.cpp` y enlazar todas las dependencias. El ejecutable se generara en:

```
out/build/vcpkg-x64-debug/ImGui_Template.exe
```

Para ejecutarlo directamente desde la terminal:

```powershell
.\out\build\vcpkg-x64-debug\ImGui_Template.exe
```

Deberias ver una ventana como esta:

```
┌─────────────────────────────────┐
│  Mi Aplicacion ImGui            │
│  ┌───────────────────────────┐  │
│  │ Panel Principal           │  │
│  │ ¡Hola, esta es una        │  │
│  │ ventana limpia!           │  │
│  └───────────────────────────┘  │
└─────────────────────────────────┘
```

---

### Resumen visual del flujo de trabajo

```
[git clone]
     │
     v
[cmake --preset vcpkg-x64-debug]  ← vcpkg descarga glfw3, opengl, imgui
     │
     v
[cmake --build out/build/...  ]   ← Ninja compila main.cpp y enlaza
     │
     v
[./ImGui_Template.exe]            ← ¡Ventana con Dear ImGui lista!
```

---

## Personalizacion

### Cambiar el estilo

En `main.cpp`, linea 39, reemplaza:

```cpp
ImGui::StyleColorsDark();
```

por:

```cpp
ImGui::StyleColorsLight();    // Estilo claro
```

o usa `ImGui::GetStyle()` para personalizar cada color y medida a tu gusto.

### Cambiar el titulo y tamano de la ventana GLFW

```cpp
GLFWwindow* window = glfwCreateWindow(1280, 800, "Mi App", nullptr, nullptr);
//                                     ^^^^  ^^^  ^^^^^^^^^
//                                   ancho alto    titulo
```

### Agregar nuevas imagenes, texturas o fuentes

Consulta la [documentacion oficial de Dear ImGui](https://github.com/ocornut/imgui):
- Carga de fuentes: `ImGui::GetIO().Fonts->AddFontFromFileTTF(...)`.
- Carga de texturas OpenGL: usa `glGenTextures` + `ImGui::Image()`.
- Ventanas acoplables (_docking_): habilita `ImGuiConfigFlags_DockingEnable`.

### Agregar mas dependencias con vcpkg

Edita `vcpkg.json`:

```json
{
  "dependencies": [
    "glfw3",
    "opengl",
    {
      "name": "imgui",
      "features": [
        "glfw-binding", 
        "opengl3-binding",
        "docking-experimental" // Para activar el Docking Experimental de ImGui (Opcional)
      ]
    },
    "fmt",
    "spdlog"
  ]
}
```

Luego vuelve a ejecutar `cmake --preset ...` y vcpkg las descargara automaticamente.

---

## Licencia

Este proyecto se distribuye bajo la licencia **MIT**. Consulta el archivo `LICENSE` para mas detalles.

---

<div align="center">
  <sub>Hecho con ❤️ usando <a href="https://github.com/ocornut/imgui">Dear ImGui</a>, <a href="https://www.glfw.org/">GLFW</a> y <a href="https://www.opengl.org/">OpenGL</a>.</sub>
</div>
