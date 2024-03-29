# design-patterns
This project is for practicing object-oriented design patterns.

Strategy: Initially, I used explicit new commands to create new instances of ShareBehavior, but it seemed unsafe to expose memory management.  I decided to replace all that with an enum ShareType that will take care of allocating and deallocating memory with the user only needing to enter the enum.

Adapter:  The Duck class uses the Strategy pattern above.  For the DroneAdapter class, I made every necessary member function of the Duck interface into a virtual function.  Otherwise, I would have had to make derived classes of FlyBehavior and QuackBehavior.

Observer: I initially used copies of the subject's variables in each observer child object, but the Observer pattern recommends each concrete observer having a copy of the concrete subject in its class.  I used a reference to the concrete subject and used its public methods instead of the copies of the concrete subject's member variables.
