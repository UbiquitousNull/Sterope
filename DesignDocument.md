# Planning Document

<details style="margin-top:30px;">
	<summary style="font-size:18px; font-weight:600;">Document Outline</b></summary>

1. [Introduction](#introduction)
2. [Objectives](#objectives)
3. [Core Features](#core-features)
4. [Technical Stack](#technical-stack)
5. [Architecture Overview](#architecture-overview)
6. [Project Scope](#project-scope)
7. [Development and Testing](#development-and-testing)
8. [Milestones](#milestones)
   - [Milestone 1: Create Basic Application](#milestone-1-create-basic-application)
   - [Milestone 2: Implement Basic Rendering](#milestone-2-implement-basic-rendering)
   - [Milestone 3: Add Input Handling and Game Loop](#milestone-3-add-input-handling-and-game-loop)
   - [Milestone 4: Implement Profile System](#milestone-4-implement-profile-system)
   - [Milestone 5: Integrate Asset Management](#milestone-5-integrate-asset-management)
   - [Milestone 6: Develop Scene and Entity Management](#milestone-6-develop-scene-and-entity-management)
   - [Milestone 7: Build a Simple Game](#milestone-7-build-a-simple-game)
   - [Milestone 8: Add User Interface Elements](#milestone-8-add-user-interface-elements)
   - [Milestone 9: Optimization and Refactoring](#milestone-9-optimization-and-refactoring)
   - [Milestone 10: Final Testing and Documentation](#milestone-10-final-testing-and-documentation)
9. [Documentation](#documentation)
10. [Future Work and Extensions](#future-work-and-extensions)

</details>
</br>
<hr><!-- <hr style="border-width:3px;"> -->
</br>

# Sterope Project Design Document

## 1. Introduction
<details open>
<summary>collapse/expand</summary>
</br>

- **Project Name**: Sterope
- **Project Description**: Development of a game engine and a basic game made in C, utilizing SDL2 for window management, input handling, and other multimedia functions, alongside GLAD2 for OpenGL 4.6 context and API management.
</details>


## 2. Objectives
<details open>
<summary>collapse/expand</summary>
</br>

- **Primary Objective**: Create a flexible, efficient game engine that serves as the foundation for developing 2D/3D games.
- **Secondary Objective**: Develop a basic game demonstrating the engine’s capabilities.
</details>


## 3. Core Features
<details open>
<summary>collapse/expand</summary>
</br>

- **Game Engine Features**:
  - **Window and Context Management**: Utilize SDL2 for cross-platform window creation and event handling.
  - **Rendering Pipeline**: Implement a basic OpenGL 4.6 rendering pipeline using GLAD2.
  - **Input Handling**: Handle keyboard, mouse, and potentially gamepad input via SDL2.
  - **Asset Management**: Basic asset loading and management system for textures, models, and other game assets.
  - **Scene Management**: Implement a system for managing game objects, entities, and scenes.

- **Game Features**:
  - **Game Loop**: A core game loop managing updates, rendering, and input handling.
  - **Basic Gameplay Mechanics**: Simple gameplay showcasing the engine’s features (e.g., character movement, object interaction).
  - **User Interface**: Simple UI elements like menus, health bars, and score displays.
</details>


## 4. Technical Stack
<details open>
<summary>collapse/expand</summary>
</br>

- **Programming Language**: C
- **Libraries/Frameworks**:
  - **SDL2**: For window creation, event handling, and basic 2D rendering.
  - **GLAD2**: For managing OpenGL 4.6 function pointers.
  - **OpenGL 4.6**: For rendering graphics (2D and possibly 3D).
- **Build System**: CMake for project configuration and build automation.
</details>


## 5. Architecture Overview
<details open>
<summary>collapse/expand</summary>
</br>

- **Engine Core**:
  - **Initialization/Shutdown Systems**: Managing SDL2 and OpenGL context creation and destruction.
  - **Subsystem Management**: Organize and manage different subsystems (rendering, input, etc.).
- **Rendering Engine**:
  - **Shader Management**: Compile, link, and use GLSL shaders.
  - **Rendering Pipeline**: Set up the basic rendering pipeline with vertex buffers, shaders, and draw calls.
- **Input System**: Abstract SDL2 input handling for ease of use in the game logic.
- **Entity-Component System (ECS)**: Potentially implement an ECS for flexible game object management.
</details>


## 6. Project Scope
<details open>
<summary>collapse/expand</summary>
</br>

- **Game Engine**:
  - Core engine functionalities (rendering, input, asset management).
  - Basic documentation and examples.
- **Game**:
  - A simple game utilizing the engine, including basic gameplay mechanics, UI, and assets.
</details>


## 7. Development and Testing
<details open>
<summary>collapse/expand</summary>
</br>

- **Version Control**: Git with a GitHub repository for code management.
- **Testing Strategy**:
  - Unit tests for critical engine components.
  - Integration tests for subsystems interaction.
  - Playtesting the game to ensure engine stability and gameplay functionality.
</details>

## 8. Milestones

<details open>
<summary>collapse/expand</summary>
</br>
<details open>
<summary><b>Milestone 1</b></summary>

- **Create Basic Application:**
    - Set up the project structure using CMake.
    - Initialize an SDL2 window and OpenGL context using GLAD2.
    - Create a basic application that opens a window and handles simple input (e.g., closing the window with the escape key).
</details>
</br>
<details open>
<summary><b>Milestone 2</b></summary>

- <b>Implement Basic Rendering</b>:
    - Set up a basic OpenGL 4.6 rendering pipeline.
    - Render simple geometric shapes (e.g., a triangle) on the screen.
    - Implement a basic shader management system.
</details>
</br>
<details open>
<summary><b>Milestone 3</b></summary>

- <b>Add Input Handling and Game Loop</b>:
    - Implement a robust game loop that handles updates, rendering, and input processing.
    - Develop an input handling system abstracting SDL2 input methods.
    - Test with simple interaction, such as moving a shape on the screen using keyboard input.
</details>
</br>
<details open>
<summary><b>Milestone 4</b></summary>

- <b>Implement Profiles System</b>:
    - Develop a system to save and load user profile preferences (e.g., settings like controls, graphics options, and saved games).
    - Ensure profiles can be loaded at startup and modified in-game.
    - Create a simple UI for managing user profiles.
</details>
</br>
<details open>
<summary><b>Milestone 5</b></summary>

- <b>Integrate Asset Management</b>:
    - Implement a basic asset management system for loading textures, models, and other game resources.
    - Test by loading and rendering a simple textured object.
</details>
</br>
<details open>
<summary><b>Milestone 6</b></summary>

- <b>Develop Scene and Entity Management</b>:
    - Implement a scene management system to handle different game states or levels.
    - Develop a basic entity-component system (ECS) or alternative structure to manage game objects.
    - Create a simple scene with multiple objects and demonstrate interaction between them.
</details>
</br>
<details open>
<summary><b>Milestone 7</b></summary>

- <b>Build a Simple Game</b>:
    - Create a basic game using the engine, showcasing movement, interaction, and rendering capabilities.
    - Include simple gameplay mechanics, such as player movement, collision detection, and scoring.
</details>
</br>
<details open>
<summary><b>Milestone 8</b></summary>

- <b>Add User Interface Elements</b>:
    - Implement basic UI components, such as menus, health bars, and score displays.
    - Integrate these components into the game.
</details>
</br>
<details open>
<summary><b>Milestone 9</b></summary>

- <b>Optimization and Refactoring</b>:
    - Optimize the engine’s performance, focusing on rendering and input handling.
    - Refactor the codebase for better modularity and maintainability.
</details>
</br>
<details open>
<summary><b>Milestone 10</b></summary>

- <b>Final Testing and Documentation</b>:
	- Conduct extensive testing to ensure stability and performance.
    - Complete documentation for engine usage, including setup, core features, and code architecture.
    - Prepare a final demo game that highlights the engine’s capabilities.
</details>
</details>

## 9. Documentation
<details open>
<summary>collapse/expand</summary>
</br>

- **Code Documentation**: Inline comments, function headers.
- **User Documentation**: How to use the engine, build the project, and understand the basic structure.
- **Development Documentation**: Design decisions, architecture overview, and future work suggestions.
</details>


## 10. Future Work and Extensions
<details open>
<summary>collapse/expand</summary>
</br>

- **Advanced Rendering Features**: Shadows, reflections, and other graphical effects.
- **Physics Engine Integration**: Consider integrating a physics engine like Box2D or Bullet (Currnetly just going to rely on my own).
- **Networking Capabilities**: Add support for multiplayer features (local and/or online).
</details>