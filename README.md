# Cpp_Simple_MusicRoom_Booking_Sys
- I sightread easy piano pieces on my free time, inspiring me to develop a simple music room booking app
- It is clearly made to be simple and in no way shape or form is my solution the most efficient.
- Databases is much better but i want to try purely with c++
- I will not be implementing a way to save and load the data. It is unfortunate but i need to work on java in order to increase the chances of getting hired. Employers looking for c++ employees normally look for degrees with YEARS of experience, which i don't have.

- Switched stoi to streams due to compiling issues with other compilers

## Music Room Booking App
- Owner owns two music rooms
- Owner needs to book for musicians
- Owner needs to check-in for musicians
- Owner needs to see details of booking with a given date

# My Comments/Improvements
- I admit i myself don't like the way i code most of the things
-- When accessing the vectors of objects, checking if it is empty or only has one object is "reusable code". But when i was implementing it, i was like nahhh there is NO WAY i will be reusing this in the future.... Basically if anything FEELS reusable, turn it into a function, even if it is like 5 lines of code.
- I do not like the way i retrieve the objects in the vector. I don't know how to explain it, but it is like solutions on stack overflow and online change the vector where mid becomes the last object of the vector. However when i implement it, the last object of the vector is always whatever is the furthest booking date made. I change mid to mid-1 when i have to traverse to the left while other solutions made the next mid the last object of the vector.
- I also found out that best practice is to separate the other codes in a separate otherFunctions.h file and do a #include<otherFunctions.h> or something
