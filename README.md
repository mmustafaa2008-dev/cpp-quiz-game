Pro-Level README: C++ Quiz Engine
📖 Overview
This repository contains a C++ Quiz Engine designed with a focus on Object-Oriented Design (OOD) and structured software architecture. By leveraging the power of Class Composition, the system manages complex relationships between player data, question banks, and difficulty-based logic within a streamlined console interface.

🛠 Technical Architecture
1. Architectural Pattern: Composition over Inheritance
Unlike basic student projects that over-rely on inheritance, this project implements Composition.

The quiz class acts as the controller, maintaining a player instance and an array of questions.

Benefit: This provides better encapsulation and avoids the "Diamond Problem" associated with complex inheritance trees, making the codebase easier to maintain.

2. Robust Input Validation
The project includes a dedicated validation layer (check function) to ensure data integrity:

Heuristic checks: Filters for non-alphabetic characters during name entry.

State Management: Prevents the game from progressing with empty or invalid user profiles.

3. Memory & Efficiency
Constructors: Uses parameterized constructors for efficient object initialization.

Static Arrays: Optimized for fixed-size question banks (5 per level) to minimize heap fragmentation.
