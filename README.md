# Welcome to GreyBeard's Compiler!
What exactly is GreyBeard's compiler? Well, even I dont know the full answer to that question yet. What I know for certain is this will be a C Language focused program, that will present a UI to the end user. In this UI, the user will be able to select a markdown file and have the program generate a HTML file from that and place it into a directory chosen by the user in the UI. More features and functionality may be added as I work through this build.

#### This is currently a work in progress

#### ||Current tasks in progress||
**textnode object:**
1. Struct with contents, text type, and url
2. Function to create textNode object
3. Function that can compare 2 textnode objects for equality (all 3 fields must equal)
4. Function to print the string representation of a textnode object. Example: return f"TextNode({self.text}, {self.text_type.value}, {self.url})"
5. Function that returns the html data member(contents) of an object. Not sure this would be needed?

**leafnode object:**
1. Struct with tag, contents, children, props
2. Function to create leafNode object
3. Function that can compare 2 leafNode objects for equality
4. Function to print the string representation of a leafNode object
5. Function that returns the html data member(contents) of an object - should be needed on leafnodes and parentnodes
6. Function that returns the html data member(props) of an object - should be needed on leafnodes and parentnodes
7. Require checks in place to ensure data integrity on these nodes, need to make sure required data is not missing or if it is what to do to handle that.
**Hashmap implementation required**
1. Implement hashmaps
2. Lots more stuff here

#### ||High Level Project Overview||
##### To Do list:
1. Create a very simple UI
    - Destination Selection (drop down??)
    - Destination file name (part of drop down or seperate?)
    - Source Selection (drop down??)
    - Checks for valid file paths/names in ui and does not allow user to submit invalid entries
    - Compile button (uses input source file, generates html file, and puts the new file into the destination folder with chosen name.)
    - Checks for success or failure. Prompts user appropriately.
2. Add logic for source and destination drop down selections. (recursive checks for directories and files)
3. Add input validation of any directories/file paths/file names.
4. Add compile button logic (this will be a big one)
5. Add checks for success or failure of compile process and/or file writing process.
    - Possibly need to add a way for the compiler to save a compiled file to a temp directory somewhere. In case final file write fails, we dont lose the compiled file.
6. Add a logger and logs to write out events to a log file.
    - Need to decide if logger should store historical logs or if previous logs are overritten when a new compile happens.
    - Additionally if historical logs are kept, when do we auto clear previous logs? 30 days? Check for logs older than x days and delete first before writing more logs?
7. Implement hashmaps for TomeLoader
8. Implement textNodes
9. Implement leafNodes
10. Implement parentNodes
11. More stuff that im sure im forgetting...

##### Nice to have feature possibilities:
- A navigation system
- Support for multiple pages
- Handling of blog posts and/or edits to existing html documents
- Custom layouts for different types of content

##### Project Goals (subject to change over time)
###### Get better with:
- The C programming language
- File handleing and manipulation
- String manipulation
- Pointers
- Structs
- Testing
- And...More?

