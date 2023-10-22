# cs210

-- Summarize the project and what problem it was solving.

Grocery Tracker application that analyzes text files that represent the items purchased at a hypothetical grocery store. The program allows for the user to get an accurate report on the frequency at which certain items are purchased - allowing the grocer to better understand their operation and make more informed stocking/general business decisions.

-- What did you do particularly well?

I think the way I aligned the histogram was OK. The program goes through the keys within the GroceryTracker class' map and uses the longest key length (strings) to set the width/format the output.

-- Where could you enhance your code?

I should probably have used try/catch blocks for validation, instead of writing out the values expected. The comments could be more descriptive. The menu isn't very intuitive, you sort of need to know what the program was made to do before using it. An idea I wish I had implemented would be when searching for certain items, having the ability to match results whether they are spelled out in the singular or plural - for instance if you search for "pumpkin" you'll get no match, as the key within the map is "pumpkins" - in a similar vein, I've only made the first letter in the search term case-insenstive, and should probably just have dealt with each character's case. It could be modularized more, as there's functions that do multiple things that aren't explicitly named in the function - e.g. parseInputFile also outputs a .dat file. I also didn't do any sort of permissions checks when handling the txt file. The histogram relies on an excessive amount of string concatenation, which I think is pretty slow. There's plenty of room for improvement. 

-- Which pieces of the code did you find most challenging to write, and how did you overcome this?
The input process was a little challenging, I think I've sort of pigeonholed myself into a certain way of handling input using while loops and switch cases, which works I guess - but I should look into other ways of doing it. I also probably should have made separate functions to deal with each switch case's actions, for the sake of readability. The input works but seems sloppily written. 

-- What skills from this project will be particularly transferable to other projects or course work?
Working with files. Also writing the documentation was a good exercise, which I should get used to in order to make the stuff I write be able to be understood (hopefully) by others. 

-- How did you make this program maintainable, readable, and adaptable?

Just by virtue of using a class for the functionality, the program is fairly clear in its purpose. I tried to name each method/member appropriately, so that its purpose is understandable to an outside observer. Along with that, I think it's modularized fairly well, although as I mentioned I could have gone further with that. Including a few error messages should make it easier to identify issues when the program's running. The input validation I think is fairly easily understood, as it's written with pretty basic logic, so it should be easy for an outsider to look at. 