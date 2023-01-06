# design-patterns
This project is for practicing object-oriented design patterns.

Strategy: Initially, I used explicit new commands to create new instances of ShareBehavior, but it seemed unsafe to expose memory management.  I decided to replace all that with an enum ShareType that will take care of allocating and deallocating memory with the user only needing to enter the enum.
