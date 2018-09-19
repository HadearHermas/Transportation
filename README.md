# Transportation
Simple project that explains one important concept of object oriented programming: Inheritance

1.	The Transport class contains: 
•	A capacity variable that holds the maximum number of passengers. 
•	A passengers variable that holds the number of passengers that already booked tickets it this transport. 
•	A speed that holds the speed of the transport. 
•	A From_Location string that contains the name of departure. 
•	 A To_Location string that contains the name of arrival. 

Member functions are: 

•	A constructor to initialize the private data. 
•	An availableSpace function to return true if there is available ticket for booking. 
•	A book function to book a ticket and return its index from 1... capacity and return -1 if booking operation is failed (no available space) 
•	A print function to print all the transport information. 
•	A time function to return the travelling time. 

2.	The Taxi class that inherits Transport and adds to the transport information the driver name.It has: 
•	A constructor to initialize the Taxi information with a capacity of 4. 
•	A print function to print the Taxi information. 

3.	The Bus class that inherits Transport and adds to the transport information the driver name. It has: 
•	A constructor to initialize the bus information. There are four types of buses. 
Type 1 means capacity =40. 
Type 2 means capacity =50. 
Type 3 means capacity =60 
otherwise capacity =75. 
And the speed is always 10. 
•	A print function to print the Bus information. 

4.	The Ship class that inherits Transport. The ship is too large that it fits to any number of passengers. So that the capacity is ignored. The ship speed is 100 m/s. It has: 
•	A constructor that initialize the ship. 
•	Update the book function to ignore the capacity. 
•	A function to print the ship information. 

5- a findbest function that passes through the array t of length n and search for a Transport that moves from "from" string to "to" string with the highest speed and return its index. This transport should have empty spaces to book. The function returns -1 if found nothing 

