# CS210 Clock Project

# Summarize this project and what problem it solved.

This project involved making a clock that the user could update. Using the interface, the user is able to update the seconds, minutes and hours on the clock.

# What did you do particularly well?

The way the program updates the hours, minutes and seconds. I stacked the function definitions on top of each other, so if a second/minute/hour was over a certain amount
the next unit would update. I enjoyed putting that together.


# Where could you enhance your code? How would these improvements make your code more efficient, secure, etc?
I could use the header file correctly and use correct class and function definitions. The program also does not update the time dynamically. It is a static clock initialized with the local time. It would be better if it could refresh every second with the new time updated.


# Did you find any piece of this code challenging and how did you overcome this? What tools and/or resources are you adding to your support network?

Formatting the 12 hour clock was difficult. I wrote the math and logic on a notepad when I got stuck and followed my blueprint. I also had a hard time initializing the time. I used the C++ documentation as well as other sources on google to find out how to use the localtime functions.


# What skills from this project will be transferrable to other projects and/or coursework?

Modularizing code and manipulating an object to do different things. That was the biggest skill that I picked up from this project. I took a similar (and more refined) approach in latter projects.
