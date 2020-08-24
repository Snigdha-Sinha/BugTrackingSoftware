# BugTrackingSoftware

The code makes use of array of structures. The names, priority, status, type, id of the bug (randomly generated) are stored in different arrays.
When the user enters a bug, the system time gets displayed, which becomes the "time of bug filing."

The main function has a menu-driven code (i.e, switch-case statements)

Case 1: To file a bug :-
	This option asks the user to enter their name, type, status and priority of the bug. System time also gets generated. 
	A randomly generated bug id also gets stored in an array.

Case 2: To change the status of the bug :-
	This option asks for the id of the bug whose status is to be changed. When we enter the bug id, it asks for the new status.
	The code searches for the bug id entered and it changes its status in the array.

Case 3: To display list of bugs filed by specific user :-
	This option asks for the user name. Once the name is enetered, it displays all the details of the bugs filed by that user.

Case 4: To display list of bugs of same category :-
	This option asks for the required category. Once entered, it displays the id number of the bugs which belong to that category.

Case 5: To display list of bugs having same status :-
	This option asks for the required status. Once entered, it displays the id of the bugs which belong to that status.
