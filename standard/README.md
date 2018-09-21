# About standards

I have planned to write the standard for language icL in 3 languages:
engish, russian and moldavian.

# Requests

__18.09.2018__

 * Rename _tab.get -> _tab.load. **[approved]** [+]
 * Add new method _tab.get, which doesn't generate signals, just return true
   on success otherwise false. **[approved]** [+]
 * Remove _stacks'(int). **[approved]** [+]
 * Remove _stacks.if. **[approved]** [+]
 * Remove _stacks.ifexists. **[approved]** [+]
 * Remove _stacks.loop. **[approved]** [+]
 * Remove _stacks.while. **[approved]** [+]
 * Remove _stacks.dowhile. **[approved]** [+]
 * Remove _stacks.for. **[approved]** [+]
 * Remove _stacks.forany. **[approved]** [+]
 * Remove _stacks.range. **[approved]** [+]
 * Remove _stacks.filter. **[approved]** [+]
 * Change _stacks.break -> aviable just for loops. **[approved]** [+]
 * Add _stack.return -> especially for functions. **[approved]** [+]
 * Rename all System data types to first uppercase names and remove underline
   (_)  **[approved]** [+]
 * Add States'first, States'last, States'next, States'prev : object, to get
   access to data, which can be important. **[approved]**

All approved changes will be applicated in Standard for icL RC 2.

__21.09.2018__

 * Add comma delimiter beetwen grouped values, the list changes from
   ["str1" "str2" "str3"] to ["str1", "str2", "str3"]
 * Change object field syntax from <value>name to name = value, the objects
   changes from [<23>age <"Alice">name] to [age = 23, name = "Alice"],
   the empty object will look like [=]
 * Change parameter syntax from <type>name to name : type, the set changes from
   [<int>age <string>name] to [age : int, name : string], the empty set will
   look like [:]
 * Change function syntax from !name = params : type {} to name = (params) 
   : type {}, restict first upper case letter in function name, with the 
   previous changes the function declaration will look like func = (arg1 : int,
   arg2) : string {}
 * Add new function call syntax instead !name args... use name (args..), beetwen
   arguments needs to be comma delimiter
 * Change the operator << to < and >> to >