# About standards

I have planned to write the standard for language icL in 3 languages:
engish, russian and moldavian.

# Requests

__18.09.2018__

 * Add new method _tab.goto, which doesn't generate signals, just resturn true 
   on success otherwise false. **[approved]**
 * Remove _stacks'(int). **[approved]**
 * Remove _stacks.if. **[approved]**
 * Remove _stacks.ifexists. **[approved]**
 * Remove _stacks.loop. **[approved]**
 * Remove _stacks.while. **[approved]**
 * Remove _stacks.dowhile. **[approved]**
 * Remove _stacks.for. **[approved]**
 * Remove _stacks.forany. **[approved]**
 * Remove _stacks.range. **[approved]**
 * Remove _stacks.filter. **[approved]**
 * Change _stacks.break -> aviable just for loops. **[approved]**
 * Add _stacks.return -> especially for functions. **[approved]**
 * Rename all System data types to first uppercase names and remove underline
   (_)  **[approved]**
 * Add States'first, States'last, States'next, States'prev : object, to get
   access to data, which can be important. **[approved]**

All approved changes will be applicated in Standard for icL RC 2.