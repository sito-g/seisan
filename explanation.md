# How my code works?
For this project array structure can also be used but it won't be dynamic. Array structure have fix memory so, there can overflow of memory or opposite. And instering elements in between the array is difficult to achive. In order to over come this I have used linked list. There might be other option availble. But using linked list we can take as much as data from user without wasting memory. It updates data/memory during runtime of the program. And we easily manipulate the data in the linked list like inserting, deleting, etc.
**What is linked list?**
A linked list is a linear data structure that includes a series of connected nodes. Here, each node stores the **data** and the **address** of the next node.![Source from tutorialspoint.com](https://www.tutorialspoint.com/data_structures_algorithms/images/linked_list.jpg)
As per the above illustration, following are the important points to be considered.

-   Linked List contains a link element called first.
    
-   Each link carries a data field(s) and a link field called next.
    
-   Each link is linked with its next link using its next link.
    
-   Last link carries a link as null to mark the end of the list.

Each node link contains the memory address of other node. And in this they are connected. At first we create head pointer which point memory adress of node 1, which link contains the address of the other and continues in the same way. A node can contain one or more than one data and data type but there is only one pointer defined in node for contaning memory address. 
A node can be created by using structure because structure can be for used for multiple data types input. ![enter image description here](https://i.ibb.co/f2skGHf/struct.png)
Here the node is created. Count is used for for keep track the of the data numerically, data is used for string input. At last there self refrence pointer link which point to the structure.
![enter image description here](https://i.ibb.co/k6ZDYkj/initi.png)
This is the initilization part of the node. Pointer1 is declared and used to point the address of the structure(node). The memory address of the structure is refrenced by calloc() function which is defined under **<stdlib.h>**  libraray. 

The calloc() function in C is **used to allocate a specified amount of memory and then initialize it to zero**. The function returns a void pointer to this memory location, which can then be cast to the desired type. The function takes in two parameters that collectively specify the amount of memory ​​to be allocated. 

Similarly we can use other pointers and create another node by linking address. Here we have to use arrow operator( -> ) inorder to access the data or link of the node using pointer. Example Head->data gives the data contained in the first node.
Using **while loop** we can make user to insert as much as node user can.
For performing manipulation like inserting, deleteing data we can define pointers and use it. for example you want to insert the new node at specific position in the list. Assuming we have the number where we want to store the new node. 
![enter image description here](https://i.ibb.co/d0RVj8C/insert.png)
Using for loop we can intsert the data in between the list. This is my logic you can come up with your own logic. Two pointers are defined, one for storing the new node and other is for looping through the list ponting nodes. At last by managing the link pontiing node and new node we can insert the data between the nodes.

Similarly we can delete, update, count the linked list.

**Exporting the list**
![enter image description here](https://i.ibb.co/dBrLr04/expot.png)
For exporting the list, file handling in C is very useful. We first declare the file and open it in write mode. Using fprintf() function we can write inside the file and finally export it to .txt file.

For list it is set to string data type. For marking completion strcat() function is used which is defined under the <string.h> library.


**fflush(stdin)**=fflush() is typically used for output stream only. Its purpose is to clear (or flush) the output buffer and move the buffered data to console (in case of stdout) or disk (in case of file output stream). 
Refrence [stackoverflow](https://stackoverflow.com/questions/18170410/what-is-the-use-of-fflushstdin-in-c-programming)


**system("cls")**=Clears the screen.
**system("pause")**=Holds the screen until you press any key. 
